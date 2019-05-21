/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:21:48 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/21 18:10:02 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		fill_grid(int ***new_grid, int i, int j)
{
	int			*new_line;

	i = -1;
	while (++i < GRID_SIZE)
	{
		if (!(new_line = (int *)malloc(sizeof(int) * (GRID_SIZE + 1))))
		{
			j = -1;
			while (++j < i)
			{
				free((*new_grid)[j]);
				(*new_grid)[j] = NULL;
			}
			return (0);
		}
		j = -1;
		while (++j < GRID_SIZE)
			new_line[j] = 254;
		new_line[j] = -1;
		(*new_grid)[i] = new_line;
	}
	(*new_grid)[i] = 0;
	return (1);
}

static int		**create_grid(void)
{
	int			**new_grid;

	if (!(new_grid = (int **)malloc(sizeof(int *) * (GRID_SIZE + 1))))
		return (NULL);
	if (fill_grid(&new_grid, 0, 0) == 0)
	{
		free(new_grid);
		new_grid = NULL;
		return (NULL);
	}
	return (new_grid);
}

int				add_grid(int ***grid)
{
	int		**new_grid;

	if (grid != NULL)
	{
		new_grid = create_grid();
		if (new_grid != NULL)
		{
			(*grid) = new_grid;
			return (1);
		}
	}
	return (0);
}

void			free_grid(int ***grid)
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
	}
}

void			print_grid(int ***grid)
{
	int			i;
	int			j;

	i = -1;
	while ((*grid)[++i] != 0)
	{
		j = -1;
		while ((*grid)[i][++j] != -1)
		{
			print_nb_hexa((*grid)[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
