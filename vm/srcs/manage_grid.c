/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:21:48 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 18:01:53 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		free_grid_item(int ***gr)
{
	int		i;

	if (grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	i = -1;
	while (++i < GRID_SIZE)
	{
		free((*gr)[i]);
		(*gr)[i] = NULL;
	}
	free(*gr);
	*gr = NULL;
	return (VALID_FULL);
}

static int		setup_empty_grid(int ***gr, int i, int j)
{
	int			*line;

	i = -1;
	while (++i < GRID_SIZE)
	{
		if (!(line = (int *)malloc(sizeof(int) * (GRID_SIZE))))
		{
			j = -1;
			while (++j < i)
			{
				free((*gr)[j]);
				(*gr)[j] = NULL;
			}
			free(*gr);
			*gr = NULL;
			return (MALLOC_FAILED);
		}
		ft_bzero(line, sizeof(int) * (GRID_SIZE));
		j = -1;
		while (++j < GRID_SIZE)
			line[j] = 0;
		(*gr)[i] = line;
	}
	return (SUCCESS);
}

static int		**create_grid(t_storage **st, int type)
{
	int			**grid;
	int			result;

	if ((type != 1 && type != 3)
		|| (result = storage_check(st, type)) != VALID_EMPTY)
		return (NULL);
	if (!(grid = (int **)malloc(sizeof(int *) * (GRID_SIZE + 1))))
		return (NULL);
	ft_bzero(grid, sizeof(int *) * (GRID_SIZE + 1));
	if (setup_empty_grid(&grid, 0, 0) != SUCCESS)
		return (NULL);
	return (grid);
}

int				add_grid(t_storage **st, int type)
{
	int			**grid;
	int			result;

	if ((type != 1 && type != 3)
		|| (result = storage_check(st, type)) != VALID_EMPTY)
		return (BAD_PARAM);
	if ((grid = create_grid(st, type)) == NULL)
		return (CALL_FAILED);
	if (type == 1)
		(*st)->grid = grid;
	else
		(*st)->color_grid = grid;
	return (SUCCESS);
}

int				free_grid(t_storage **st, int type)
{
	if ((type != 1 && type != 3)
		|| storage_check(st, type) != VALID_FULL)
		return (BAD_PARAM);
	if (type == 1)
		free_grid_item(&((*st)->grid));
	else
		free_grid_item(&((*st)->color_grid));
	return (SUCCESS);
}
