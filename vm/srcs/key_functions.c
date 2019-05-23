/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/21 18:53:27 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		write_in_grid(int ***grid, int value, int where)
{
	int		col;
	int		line;

	if (grid != NULL && (*grid) != NULL)
	{
		where = where % (GRID_SIZE * GRID_SIZE);
		col = where % GRID_SIZE;
		line = where / GRID_SIZE;
		(*grid)[line][col] = value;
	}
	return (0);
}
