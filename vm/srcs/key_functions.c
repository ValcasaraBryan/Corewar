/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/12 11:29:05 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cycle_threads(t_storage **st)
{
	t_thread	*current;
	int			i;

	if (storage_check(st, 2) != VALID_FULL)
		return (BAD_PARAM);
	i = -1;
	//a changer par "tant qu'il ne reste pas qu'un seul champion" et autres
	while (++i < 50)
	{
		current = (*st)->first_thread;
		while (current != NULL)
		{
			if (thread_change_cycle(&current, &((*st)->grid), 1) < SUCCESS)
				return (CALL_FAILED);
			current = current->next;
		}
	}
	return (SUCCESS);
}

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
	res = nb == 4 && value < 0 ? 9223372036854775807 - (-1 * value) : res;
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
