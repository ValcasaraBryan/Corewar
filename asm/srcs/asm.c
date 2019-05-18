/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/18 03:38:21 by bryanvalcas      ###   ########.fr       */
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
	data->name_cor = av;
	data->name_s = NULL;
	data->file = NULL;
}

int		suffix_name(t_data *data, const char *s)
{
	int		i;

	if (!data->name_cor)
		return (0);
	i = ft_strnchr(data->name_cor, '.');
	if (ft_strcmp(data->name_cor + i, SUFF_F) == 0)
		data->name_s = ft_strjoin_free(ft_strcut(data->name_cor, 0, i), (char *)s, 1);
	else
		return (0);
	return (1);	
}

void	erase_all(t_data *data)
{
	t_file	*tmp;

	if (data->name_s)
	{
		free(data->name_s);
		data->name_s = NULL;
	}
	if (data->file)
	{
		while (data->file)
		{
			tmp = data->file->next;
			free(data->file->line);
			data->file->line = NULL;
			free(data->file);
			data->file = NULL;
			data->file = tmp;
		}
	}
}

int		parsing_asm(int ac, char **av)
{
	t_data	data;
	char	*line;

	init_data(&data, av[ac - 1]);
	if ((data.fd = open(data.name_cor, O_RDONLY)) == -1)
	{
		ft_fprintf(NO_FILE, S_ERR, data.name_cor);
		return (0);
	}
	while ((data.ret = get_next_line(data.fd, &line)) > 0)
		data.file = add_file(&data.file, line);
	suffix_name(&data, SUFFIX);
	print_list(&data);
	if (data.ret == -1)
	{
		erase_all(&data);
		return (0);
	}
	ft_printf(SUCCESS, data.name_s);
	erase_all(&data);
		while (1);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	else
		if (!(parsing_asm(argc, argv)))
			return (0);
	return (0);
}