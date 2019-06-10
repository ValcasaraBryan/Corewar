/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:21:48 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/10 18:09:15 by jdurand-         ###   ########.fr       */
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
		if (!(line = (int *)malloc(sizeof(int) * (GRID_SIZE + 1))))
		{
			j = -1;
			while (++j < i)
			{
				free((*gr)[j]);
				(*gr)[j] = NULL;
			}
			free (*gr);
			*gr = NULL;
			return (MALLOC_FAILED);
		}
		j = -1;
		while (++j < GRID_SIZE)
			line[j] = 0;
		line[j] = -1;
		(*gr)[i] = line;
	}
	(*gr)[i] = NULL;
	return (SUCCESS);
}

static int		**create_grid(t_storage **st)
{
	int			**grid;
	int			result;

	if ((result = storage_check(st, 1)) < VALID_EMPTY)
		return (NULL);
	if (!(grid = (int **)malloc(sizeof(int *) * (GRID_SIZE + 1))))
		return (NULL);
	if (setup_empty_grid(&grid, 0, 0) != SUCCESS)
		return (NULL);
	return (grid);
}

int				add_grid(t_storage **st)
{
	int			**grid;
	int			result;

	if ((result = storage_check(st, 1)) < VALID_EMPTY)
		return (BAD_PARAM);
	if ((grid = create_grid(st)) == NULL)
		return (CALL_FAILED);
	(*st)->grid = grid;
	return (SUCCESS);
}

int				free_grid(t_storage **st)
{
	if (storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	free_grid_item(&((*st)->grid));
	return (SUCCESS);
}
