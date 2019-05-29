/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/29 16:20:11 by jdurand-         ###   ########.fr       */
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
		return (1);
	}
	return (0);
}

int		decrypt_op_code(int **tab, int nb)
{
	char	*r;
	int		i;

	if (tab != NULL)
	{
		*tab = NULL;
		if (!((*tab) = malloc(sizeof(**tab) * 4)))
			return (-1);
		if (convert_to_binary(&r, nb) == -1)
			return (-1);
		i = -1;
		while (i <= 3)
		{
			(*tab)[++i] = 0;
			(*tab)[i] = r[2 * i] == '0' && r[2 * i + 1] == '1' ? 1 : (*tab)[i];
			(*tab)[i] = r[2 * i] == '1' && r[2 * i + 1] == '0' ? 2 : (*tab)[i];
			(*tab)[i] = r[2 * i] == '1' && r[2 * i + 1] == '1' ? 3 : (*tab)[i];
		}
		free(r);
		return (1);
	}
	return (0);
}
