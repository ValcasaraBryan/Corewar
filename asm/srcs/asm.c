/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/18 05:35:43 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_file		*new_file(char *line)
{
	t_file	*new;

	if (!(new = malloc(sizeof(t_file))))
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

t_file		*add_file(t_file **old, char *line)
{
	t_file	*tmp;

	if (!*old)
		return (new_file(line));
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_file(line);
		return (*old);
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
			ft_printf("%s\n", tmp->line);
			tmp = tmp->next;
		}
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
	data->error = 1;
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

int		get_data(t_file *file)
{
	while (file)
	{
		file = file->next;
	}
	return (1);
}

int		parsing_asm(t_data *data)
{
	char	*line;

	if ((data->fd = open(data->name_s, O_RDONLY)) == -1)
	{
		ft_fprintf(NO_FILE, S_ERR, data->name_s);
		return (0);
	}
	while ((data->ret = get_next_line(data->fd, &line)) > 0)
		data->file = add_file(&data->file, line);
	get_data(data->file);
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
			ft_printf("ERROR\n");
		else
		{
			print_list(&data);
			ft_printf(SUCCESS, data.name_cor);
		}
		erase_all(&data);
		sleep(2);
	}
	return (0);
}