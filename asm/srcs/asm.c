/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/19 00:58:28 by bryanvalcas      ###   ########.fr       */
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
	new->index = -1;
	new->n_line = n_line;
	new->next = NULL;
	return (new);
}

t_file		*add_file(t_file **old, char *line, int n_line)
{
	t_file	*tmp;

	if (!*old)
		return (new_file(line, n_line));
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_file(line, n_line);
		return (*old);
	}
}

void		print_list(t_data *data)
{
	int		i;
	t_file	*tmp;

	if (data->file)
	{
		tmp = data->file;
		while (tmp)
		{
			printf("%-50s|%-30d\n", tmp->line, tmp->n_line);
			tmp = tmp->next;
		}
	}
	i = -1;
	while (++i < REG_NUMBER)
		printf("%02x\n", data->instruction[i]);
}

char	*init_instruction(void)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * (REG_NUMBER + 1))))
		return (NULL);
	str[REG_NUMBER] = 0;
	str[LIVE - 1] = LIVE;
	str[LD - 1] = LD;
	str[ST - 1] = ST;
	str[ADD - 1] = ADD;
	str[SUB - 1] = SUB;
	str[AND - 1] = AND;
	str[OR - 1] = OR;
	str[XOR - 1] = XOR;
	str[ZJMP - 1] = ZJMP;
	str[LDI - 1] = LDI;
	str[STI - 1] = STI;
	str[FORK - 1] = FORK;
	str[LLD - 1] = LLD;
	str[LLDI - 1] = LLDI;
	str[LFORK - 1] = LFORK;
	str[AFF - 1] = AFF;
	return (str);
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
	data->instruction = NULL;
	data->instruction = init_instruction();
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

t_error		get_error(t_file *file, char *token)
{
	t_error	error;

	(void)token;
	error.type = NULL;
	error.token = NULL;
	error.n_line = file->n_line;
	error.index = file->index;
	return (error);
}

int		get_data(t_data *data, t_file *file)
{
	int		bin;
	int		end_word;
	char	*tmp;

	(void)data;
	while (file)
	{
		bin = 8;
		while (++file->index < file->len)
		{
			file->index += skip_whitespace(file->line + file->index, 0);
			end_word = skip_whitespace(file->line + file->index, 1);
			if (file->len + end_word == file->len)
				break ;
			tmp = ft_strcut(file->line + file->index, 0, end_word);
			ft_printf("%s|", tmp);
			// if (!tmp)
			// {
				// data->error = get_error(file, tmp);
				// return (0);
			// }
			file->token.params += add_params(tmp, &bin);
			file->index += skip_whitespace(file->line + file->index, 1);
		}
		ft_printf("\n");
		file = file->next;
	}
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
		data->file = add_file(&data->file, line, ++n_line);
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
			// print_list(&data);
			ft_printf(SUCCESS, data.name_cor);
		}
		erase_all(&data);
		// sleep(2);
	}
	return (0);
}