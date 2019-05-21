/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/21 19:55:11 by brvalcas         ###   ########.fr       */
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
	while (data->name)
	{
		ft_printf("[%s]\t\t\t[%03d-%03d][%03d-%03d]\n", data->name->cut, data->name->file->n_line, data->name->start + 1, data->name->file->n_line, data->name->end + 1);
		data->name = data->name->next;
	}
	while (data->comment)
	{
		ft_printf("[%s]\t\t\t[%03d-%03d][%03d-%03d]\n", data->comment->cut, data->comment->file->n_line, data->comment->start + 1, data->comment->file->n_line, data->comment->end + 1);
		data->comment = data->comment->next;
	}
	while (data->token)
	{
		ft_printf("\t\t[%s]\t\t\t[%03d-%03d]\n", data->token->cut, data->token->file->n_line, data->token->start + 1);
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


t_token		token_val(t_token add, int start, int end, t_file *file)
{
	add.start = start;
	add.end = end;
	add.file = file;
	add.next = NULL;
	return (add);
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
		token = token_val(token, file->index, end_word, file);
		add_token(&data->token, token);
		file->index = end_word;
	}
}

t_file	*comment(t_token **token, t_file *file, int start)
{
	t_token	add;
	int		end;

	end = 0;
	while (file->line[++start])
		if (file->line[start] == CMD_CHAR)
			break ;
	end = start++ + 1;
	while (file)
	{
		while (file->line[end] && file->line[end] != CMD_CHAR)
			end++;
		add.cut = (start < end) ? ft_strcut(file->line, start, end) : ft_strdup("");
		add = token_val(add, start, end, file);
		if (file->line[end] != CMD_CHAR)
		{
			add.cut = ft_strjoin_free(add.cut, "\n", 1);
			add = token_val(add, start + 1, end + 1, file);
			add_token(token, add);
		}
		else if (file->line[end] == CMD_CHAR)
		{
			add_token(token, add);
			file->index = end + 1;
			break ;
		}
		if (file->next)
		{
			file = file->next;
			start = 0;
			end = 0;
		}
		else
			break ;
	}
	file->index = file->len;
	return (file);
}

t_file	*get_comment_name(t_data *data, t_file *file)
{
	t_token	add;

	while (file->index < file->len)
	{
		file->index += skip_whitespace(file->line + file->index, 0);
		if (ft_strncmp(file->line + file->index, NAME_CMD_STRING, 5) == 0)
		{
			add.cut = ft_strcut(file->line, file->index, file->index + 5);
			add_token(&data->name, token_val(add, file->index, file->index + 5, file));
			file = comment(&data->name, file, file->index - 1);
		}
		else if (ft_strncmp(file->line + file->index, COMMENT_CMD_STRING, 8) == 0)
		{
			add.cut = ft_strcut(file->line, file->index, file->index + 8);
			add_token(&data->comment, token_val(add, file->index, file->index + 8, file));
			file = comment(&data->comment, file, file->index - 1);
		}
		else
			get_token(data, file);
	}
	return (file);
}

int		get_data(t_data *data, t_file *file)
{
	while (file)
	{
		file = get_comment_name(data, file);
		if (data->name && data->comment)
			get_token(data, file);
		file = file->next;
	}
	// ft_printf(".name [%s]\n", data->name);
	// ft_printf(".comment [%s]\n", data->comment);
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