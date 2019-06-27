/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:00:24 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 18:07:49 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		byte_check(t_byte **bt)
{
	print_function_state("byte_check", "START");
	if (bt == NULL || *bt == NULL)
		return (BAD_PARAM);
	print_function_state("byte_check", "END");
	return (VALID_FULL);
}

int		champion_check(t_champion **ch)
{
	print_function_state("champion_check", "START");
	if (ch == NULL || *ch == NULL)
		return (BAD_PARAM);
	if ((*ch)->first_byte == NULL || (*ch)->last_byte == NULL)
		return (VALID_EMPTY);
	print_function_state("champion_check", "END");
	return (VALID_FULL);
}

int		grid_check(int ***gr)
{
	int		i;
	int		j;

	print_function_state("grid_check", "START");
	if (gr == NULL || *gr == NULL)
		return (BAD_PARAM);
	i = -1;
	while (++i < GRID_SIZE)
	{
		if ((*gr)[i] == NULL)
			return (FAILURE);
		j = 0;
		while (++j < GRID_SIZE)
		{
			if ((*gr)[i][j] < 0)
				return (FAILURE);
		}
	}
	print_function_state("grid_check", "END");
	return (VALID_FULL);
}

int		thread_check(t_thread **th)
{
	print_function_state("thread_check", "START");
	if (th == NULL || *th == NULL)
		return (BAD_PARAM);
	print_function_state("thread_check", "END");
	return (VALID_FULL);
}

int		storage_check(t_storage **st, int type)
{
	print_function_state("storage_check", "START");
	if (st == NULL || *st == NULL || type < 0 || type > 2)
		return (BAD_PARAM);
	if (type == 0)
		return (((*st)->first_champion == NULL || (*st)->last_champion == NULL)
			? VALID_EMPTY : VALID_FULL);
	else if (type == 1)
		return ((*st)->grid == NULL ? VALID_EMPTY : VALID_FULL);
	else
		return (((*st)->first_thread == NULL || (*st)->last_thread == NULL)
			? VALID_EMPTY : VALID_FULL);
}
