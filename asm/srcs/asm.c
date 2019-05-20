/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/20 21:29:07 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_file		*new_file(char *line, int n_line)
{
	t_file	*new;

	if (!(new = malloc(sizeof(t_file))))
		return (NULL);
	new->line = line;
	new->len = (line) ? ft_strlen(line) : 0;
	new->index = 0;
	new->n_line = n_line;
	new->next = NULL;
	return (new);
}

void		add_file(t_file **old, char *line, int n_line)
{
	t_file	*tmp;

	if (!*old)
		*old = new_file(line, n_line);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_file(line, n_line);
	}
}

t_token		*new_token(t_token token)
{
	t_token	*new;

	if (!(new = malloc(sizeof(t_token))))
		return (NULL);
	new->cut = token.cut;
	new->start = token.start;
	new->end = token.end;
	new->file = token.file;
	new->next = token.next;
	return (new);
}

void		add_token(t_token **old, t_token token)
{
	t_token	*tmp;

	if (!*old)
		*old = new_token(token);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token(token);
	}
}

t_ins		*new_instruction(unsigned char token)
{
	t_ins	*new;

	if (!(new = malloc(sizeof(t_ins))))
		return (NULL);
	new->token = token;
	new->params = 0;
	new->direct = 0;
	new->indirect = 0;
	new->registre = 0;
	new->len_octet = 0;
	new->next = NULL;
	return (new);
}

void		add_instruction(t_ins **old, unsigned char token)
{
	t_ins	*tmp;

	if (!*old)
		*old = new_instruction(token);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_instruction(token);
	}
}

void		print_list(t_data *data)
{
	t_file	*tmp;

	if (data->file)
	{
		tmp = data->file;
		while (tmp)
		{
			// printf("%-50s|%-30d\n", tmp->line, tmp->n_line);
			tmp = tmp->next;
		}
	}
	while (data->token)
	{
		// ft_printf("[%s]\t\t\t[%03d-%03d]\n", data->token->cut, data->token->file->n_line, data->token->start + 1);
		data->token = data->token->next;
	}
}

void	init_data(t_data *data, char *av)
{
	data->fd = -1;
	data->ret = -1;
	data->name_s = av;
	data->name_cor = NULL;
	data->name = NULL;
	data->comment = NULL;
	data->file = NULL;
	data->token = NULL;
	data->instruction = NULL;
}

int		suffix_name(t_data *data, const char *s)
{
	int		i;
	char	*name;

	if (!data->name_s)
		return (0);
	i = ft_strlen(data->name_s) + 1;
	while (--i >= 0)
		if (!ft_strcmp(data->name_s + i, SUFF_F))
			break ;
	name = ft_strcut(data->name_s, 0, i);
	data->name_cor = ft_strndup((const char *)name, i + COR);
	free_line(&name);
	ft_strcat(data->name_cor, (char *)s);
	return (1);	
}

void	erase_all(t_data *data)
{
	t_file	*tmp;

	free_line(&data->name_cor);
	if (data->file)
	{
		while (data->file)
		{
			tmp = data->file->next;
			free_line(&data->file->line);
			free(data->file);
			data->file = NULL;
			data->file = tmp;
		}
	}
}

unsigned char		add_params(char *str, int *bin)
{
	if (!str)
		return (0);
	if (str[0] == '%')
		return (DIR_CODE << (*bin -= 2));
	else if (str[0] == 'r')
		return (REG_CODE << (*bin -= 2));
	else
		return (IND_CODE << (*bin -= 2));
}

int		ft_is_virgule(char c)
{
	int	i;

	i = -1;
	if (c == ',')
		return (1);
	else
		return (0);
}

int		skip_whitespace(char *str, int val)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (ft_is_whitespace(str[i]) == val)
			break ;
	return (i);
}

int			ft_str_is(char *str, const char *cmp)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (!params(str[i], cmp))
			return (0);
	return (1);
}

int			ft_skip_word(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (!params(str[i], LABEL_CHARS) && str[i] != COMMENT_CHAR
			&& str[i] != LABEL_CHAR && str[i] != DIRECT_CHAR)
			break ;
	}
	return (i);
}

t_error		get_error(t_file *file, char *token)
{
	t_error	error;

	(void)token;
	error.type = NULL;
	error.instruction = NULL;
	error.n_line = file->n_line;
	error.index = file->index;
	return (error);
}

int		check_op(const char *str)
{
	int	len;
	int	i;

	if (!str)
		return (0);
	i = -1;
	len = (int)ft_strlen(str);
	while (++i < REG_NUMBER)
		if (len == op_tab[i].len
			&& ft_strcmp(op_tab[i].op, str) == 0)
			return (1);
	return (0);
}

void	get_token(t_data *data, t_file *file)
{
	t_token	token;
	int	end_word;
	
	while (file->index < file->len)
	{
		file->index += skip_whitespace(file->line + file->index, 0);
		end_word = skip_whitespace(file->line + file->index, 1) + file->index;
		if (end_word == file->index)
			break ;
		token.cut = ft_strcut(file->line, file->index, end_word);
		token.start = file->index;
		token.end = end_word;
		token.file = file;
		token.next = NULL;
		add_token(&data->token, token);
		file->index = end_word;
	}
}

int		check_type(char *str, int i, int *check, int type)
{
	while (str[++i])
		if (str[i] == type)
		{
			(*check)++;
			break ;
		}
	return (i);
}

char	*get_name(t_token *token, int nb_char, char type, int check)
{
	char	*str;
	int		j;
	int		i;

	str = ft_strdup("");
	i = check_type(token->file->line, -1, &check, type);
	j = check_type(token->file->line, i++, &check, type);
	if (check == nb_char)
		return (ft_strjoin_free(str, ft_strcut(token->file->line, i, j), 3));
	while (token->file)
	{
		str = ft_strjoin_free(str, ft_strcut(token->file->line, i, j), 3);
		if (check == 1 && token->file->next)
			str = ft_strjoin_free(str, "\n", 1);
		if (check == nb_char)
			break ;
		token->file = token->file->next;
		if (!token->file)
			break ;
		j = check_type(token->file->line, (i = 0), &check, type);
	}
	return ((check == nb_char) ? str : NULL);
}

int		check_cmd(t_data *data, t_token *token)
{
	while (token)
	{
		if (ft_strncmp(token->cut, NAME_CMD_STRING, 5) == 0)
			data->name = get_name(token, 2, CMD_CHAR, 0);
		if (ft_strncmp(token->cut, COMMENT_CMD_STRING, 8) == 0)
			data->comment = get_name(token, 2, CMD_CHAR, 0);
		token = token->next;
	}
	ft_printf("DATA NAME = |%s|\n", data->name);
	ft_printf("DATA COMMENT = |%s|\n", data->comment);
	return (1);
}

int		get_data(t_data *data, t_file *file)
{
	while (file)
	{
		get_token(data, file);
		file = file->next;
	}
	check_cmd(data, data->token);
	return (1);
}

int		parsing_asm(t_data *data)
{
	int		n_line;
	char	*line;

	if ((data->fd = open(data->name_s, O_RDONLY)) == -1)
	{
		ft_fprintf(NO_FILE, S_ERR, data->name_s);
		return (0);
	}
	n_line = 0;
	while ((data->ret = get_next_line(data->fd, &line)) > 0)
		add_file(&data->file, line, ++n_line);
	if (!(get_data(data, data->file)))
		return (0);
	if (!(suffix_name(data, SUFFIX)))
		return (0);
	if (data->ret == -1)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	else
	{
		init_data(&data, argv[argc - 1]);
		if (!(parsing_asm(&data)))
		{
			// ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"%s\"\n", data.error.n_line, data.error.index, data.error.type, data.error.token);
		}
		else
		{
			print_list(&data);
			ft_printf(SUCCESS, data.name_cor);
		}
		erase_all(&data);
		// sleep(2);
	}
	return (0);
}