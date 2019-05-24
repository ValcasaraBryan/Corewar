/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:21:48 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/24 17:06:22 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		free_grid_item(int ***grid)
{
	int		i;

	if (grid != NULL && (*grid) != NULL)
	{
		i = -1;
		while (++i < GRID_SIZE)
		{
			free((*grid)[i]);
			(*grid)[i] = NULL;
		}
		free(*grid);
		(*grid) = NULL;
		return (1);
	}
	return (0);
}

static int		setup_empty_grid(int ***grid, int i, int j)
{
	int			*line;

	i = -1;
	while (++i < GRID_SIZE)
	{
		if (!(line = (int *)malloc(sizeof(int) * (GRID_SIZE + 1))))
		{
			j = -1;
			while (++j < i)
			{
				free((*grid)[j]);
				(*grid)[j] = NULL;
			}
			return (0);
		}
		j = -1;
		while (++j < GRID_SIZE)
			line[j] = 0;
		line[j] = -1;
		(*grid)[i] = line;
	}
	(*grid)[i] = 0;
	return (1);
}

static int		**create_grid(t_storage **st)
{
	int			**grid;
	int			result;

	result = storage_check(st, 1);
	if (result >= 0)
	{
		if (!(grid = (int **)malloc(sizeof(int *) * (GRID_SIZE + 1))))
			return (NULL);
		if (setup_empty_grid(&grid, 0, 0) == 0)
		{
			free_grid_item(&grid);
			return (NULL);
		}
		return (grid);
	}
	return (NULL);
}

int				add_grid(t_storage **st)
{
	int			**grid;
	int			result;

	grid = create_grid(st);
	if (grid != NULL)
	{
		result = storage_check(st, 1);
		if (result >= 0)
		{
			(*st)->grid = grid;
			return (1);
		}
		free_grid_item(&grid);
		return (0);
	}
	return (-1);
}

int				free_grid(t_storage **st)
{
	if (storage_check(st, 1) == 1)
	{
		free_grid_item(&((*st)->grid));
		return (1);
	}
	return (0);
}

int				print_grid(t_storage **st)
{
	int			i;
	int			j;

	i = -1;
	if (storage_check(st, 1) == 1)
	{
		while (((*st)->grid)[++i] != 0)
		{
			j = -1;
			while (((*st)->grid)[i][++j] != -1)
			{
				print_nb_hexa(((*st)->grid)[i][j]);
				ft_putchar(' ');
			}
			ft_putchar('\n');
		}
		return (1);
	}
	return (0);
}
