/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/17 18:13:50 by brvalcas         ###   ########.fr       */
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

void	init_data(t_data *data)
{
	data->fd = -1;
	data->ret = -1;
	data->file = NULL;
}

int		parsing_asm(int ac, char **av)
{
	t_data	data;
	char	*line;

	init_data(&data);
	if ((data.fd = open(av[ac - 1], O_RDONLY)) == -1)
	{
		ft_fprintf(NO_FILE, S_ERR, av[ac - 1]);
		return (0);
	}
	while ((data.ret = get_next_line(data.fd, &line)) > 0)
	{
		data.file = add_file(&data.file, line);
	}
	print_list(&data);
	if (data.ret == -1)
		return (0);
	ft_printf(SUCCESS, NULL);
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