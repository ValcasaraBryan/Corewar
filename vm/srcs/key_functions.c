/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/16 18:00:25 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		read_in_grid(int ***gr, int where, int nb)
{
	int		col;
	int		i;
	int		line;
	int		res;

	if (grid_check(gr) != VALID_FULL || where < 0
		|| (nb != 1 && nb != 2 && nb != 4))
		return (BAD_PARAM);
	i = -1;
	res = 0;
	while (++i < nb)
	{
		res = i != 0 ? res << 8 : res;
		where = where % (GRID_SIZE * GRID_SIZE);
		col = where % GRID_SIZE;
		line = where / GRID_SIZE;
		res += (*gr)[line][col];
		where += 1;
	}
	return (res);
}

int		write_in_grid(int ***gr, long value, int where, int nb)
{
	int		col;
	int		i;
	int		line;
	long	res;

	if (grid_check(gr) != VALID_FULL || where < 0
		|| (nb != 1 && nb != 2 && nb != 4))
		return (BAD_PARAM);
	i = -1;
	where += nb;
	res = value;
	res = nb == 4 && value < 0 ? 9223372036854775807 - (-1 * value) + 1 : res;
	res = nb == 2 && value < 0 ? 65536 - (-1 * value) : res;
	res = nb == 1 && value < 0 ? 256 - (-1 * value) : res;
	while (++i < nb)
	{
		where = (where - 1) % (GRID_SIZE * GRID_SIZE);
		col = where % GRID_SIZE;
		line = where / GRID_SIZE;
		(*gr)[line][col] = res % 256;
		res /= 256;
	}
	return (SUCCESS);
}
