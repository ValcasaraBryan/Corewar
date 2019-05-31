/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/31 16:03:19 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cycle_threads(t_storage **st)
{
	t_thread	*current;
	int			result;
	int			i;

	if (storage_check(st, 2) == 1)
	{
		i = -1;
		//a changer par "tant qu'il ne reste pas qu'un seul champion" et autres
		while (++i < 50)
		{
			current = (*st)->first_thread;
			while (current != NULL)
			{
				result = thread_change_cycle(&current, &((*st)->grid), 1);
				if (result < 1)
					return (-1);
				current = current->next;
			}
		}
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

int		read_in_grid(int ***gr, int where)
{
	int		col;
	int		line;

	if (grid_check(gr) == 1)
	{
		if (where < 0)
			return (-1);
		where = where % (GRID_SIZE * GRID_SIZE);
		col = where % GRID_SIZE;
		line = where / GRID_SIZE;
		return ((*gr)[line][col]);
	}
	return (0);
}

int		write_in_grid(int ***gr, int value, int where)
{
	int		col;
	int		line;

	if (grid_check(gr) == 1)
	{
		if (where < 0)
			return (-1);
		if (value < 0 || value > 255)
			return (-2);
		where = where % (GRID_SIZE * GRID_SIZE);
		col = where % GRID_SIZE;
		line = where / GRID_SIZE;
		(*gr)[line][col] = value;
		return (1);
	}
	return (0);
}
