/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_read_write.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:28:41 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 09:05:21 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				read_in_grid(int ***gr, int where, int nb)
{
	int			col;
	int			i;
	int			line;
	int			res;

	if (grid_check(gr) != VALID_FULL || (nb != 1 && nb != 2 && nb != 4))
		return (BAD_PARAM);
	where = where < 0 ? GRID_SIZE * GRID_SIZE + where : where;
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

int				write_in_grid(int ***gr, long value, int where, int nb)
{
	int			col;
	int			i;
	int			line;
	long		res;

	if (grid_check(gr) != VALID_FULL || (nb != 1 && nb != 2 && nb != 4))
		return (BAD_PARAM);
	where = where < 0 ? GRID_SIZE * GRID_SIZE + where : where;
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
		res = res / 256;
	}
	return (SUCCESS);
}

int				write_in_grid_color(t_storage **st, int t_where, int where)
{
	int			col;
	int			i;
	int			line;
	long		res;

	if (st == NULL || (*st) == NULL || storage_check(st, 3) != VALID_FULL)
		return (BAD_PARAM);
	col = t_where % GRID_SIZE;
	line = t_where / GRID_SIZE;
	res = ((*st)->color_grid)[line][col];
	where = where < 0 ? GRID_SIZE * GRID_SIZE + where : where;
	where += 4;
	i = -1;
	while (++i < 4)
	{
		where = (where - 1) % (GRID_SIZE * GRID_SIZE);
		col = where % GRID_SIZE;
		line = where / GRID_SIZE;
		((*st)->color_grid)[line][col] = (int)res;
	}
	return (SUCCESS);
}
