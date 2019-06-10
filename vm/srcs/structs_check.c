/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:00:24 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/10 17:59:04 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		byte_check(t_byte **bt)
{
	if (bt == NULL || *bt == NULL)
		return (BAD_PARAM);
	return (VALID_FULL);
}

int		champion_check(t_champion **ch)
{
	if (ch == NULL || *ch == NULL)
		return (BAD_PARAM);
	if ((*ch)->first_byte == NULL || (*ch)->last_byte == NULL)
		return (VALID_EMPTY);
	return (VALID_FULL);
}

int		grid_check(int ***gr)
{
	int		i;
	int		j;

	if (gr == NULL || *gr == NULL)
		return (BAD_PARAM);
	i = -1;
	while ((*gr)[++i] != NULL)
	{
		j = 0;
		while ((*gr)[i][j] != -1)
			j++;
		if (j != GRID_SIZE)
			return (BAD_PARAM);
	}
	if (i != GRID_SIZE)
		return (BAD_PARAM);
	return (VALID_FULL);
}

int		thread_check(t_thread **th)
{
	if (th == NULL || *th == NULL)
		return (BAD_PARAM);
	return (VALID_FULL);
}

int		storage_check(t_storage **st, int type)
{
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
