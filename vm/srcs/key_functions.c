/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/11 16:06:46 by jdurand-         ###   ########.fr       */
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

int		decrypt_op_code(int **tab, int nb)
{
	char	*r;
	int		i;

	if (tab == NULL || nb < 0 || nb > 255)
		return (BAD_PARAM);
	*tab = NULL;
	if (!((*tab) = malloc(sizeof(**tab) * 4)))
		return (MALLOC_FAILED);
	if (convert_to_binary(&r, nb) != SUCCESS)
		return (CALL_FAILED);
	i = -1;
	while (i <= 3)
	{
		(*tab)[++i] = 0;
		(*tab)[i] = r[2 * i] == '0' && r[2 * i + 1] == '1' ? 1 : (*tab)[i];
		(*tab)[i] = r[2 * i] == '1' && r[2 * i + 1] == '0' ? 2 : (*tab)[i];
		(*tab)[i] = r[2 * i] == '1' && r[2 * i + 1] == '1' ? 3 : (*tab)[i];
	}
	free(r);
	return (SUCCESS);
}

int		read_in_grid(int ***gr, int where)
{
	int		col;
	int		line;

	if (grid_check(gr) != VALID_FULL || where < 0)
		return (BAD_PARAM);
	where = where % (GRID_SIZE * GRID_SIZE);
	col = where % GRID_SIZE;
	line = where / GRID_SIZE;
	return ((*gr)[line][col]);
}

int		write_in_grid(int ***gr, int value, int where)
{
	int		col;
	int		line;

	if (grid_check(gr) != VALID_FULL || where < 0 || value < 0 || value > 255)
		return (BAD_PARAM);
	where = where % (GRID_SIZE * GRID_SIZE);
	col = where % GRID_SIZE;
	line = where / GRID_SIZE;
	(*gr)[line][col] = value;
	return (SUCCESS);
}

int		read_four_in_grid(int ***gr, int where)
{
	int		col;
	int		i;
	int		line;
	int		res;

	if (grid_check(gr) != VALID_FULL || where < 0)
		return (BAD_PARAM);
	i = -1;
	res = 0;
	while (++i < 4)
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

int		write_four_in_grid(int ***gr, int value, int where)
{
	int		col;
	int		i;
	int		line;
	long	res;

	if (grid_check(gr) != VALID_FULL || where < 0)
		return (BAD_PARAM);
	i = -1;
	where += 4;
	res = value < 0 ? 4294967296 - (-1 * value) : value;
	while (++i < 4)
	{
		where = (where - 1) % (GRID_SIZE * GRID_SIZE);
		col = where % GRID_SIZE;
		line = where / GRID_SIZE;
		(*gr)[line][col] = res % 256;
		res /= 256;
	}
	return (SUCCESS);
}
