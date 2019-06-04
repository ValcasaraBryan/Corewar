/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:00:24 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/04 20:01:32 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		byte_check(t_byte **bt)
{
	if (bt != NULL && *bt != NULL)
		return (1);
	return (-1);
}

int		champion_check(t_champion **ch)
{
	if (ch != NULL && *ch != NULL)
	{
		if ((*ch)->first_byte != NULL && (*ch)->last_byte != NULL)
			return (1);
		return (0);
	}
	return (-1);
}

int		grid_check(int ***gr)
{
	int		i;
	int		j;

	if (gr != NULL && *gr != NULL)
	{
		i = -1;
		while ((*gr)[++i] != 0)
		{
			j = 0;
			while ((*gr)[i][j] != -1)
				j++;
			if (j != GRID_SIZE)
				return (-1);
		}
		if (i == GRID_SIZE)
			return (1);
		return (-2);
	}
	return (0);
}

int		thread_check(t_thread **th)
{
	if (th != NULL && *th != NULL)
		return (1);
	return (-1);
}

int		storage_check(t_storage **st, int type)
{
	if (st != NULL && *st != NULL)
	{
		if (type == 0)
		{
			if ((*st)->first_champion != NULL && (*st)->last_champion != NULL)
				return (1);
			return (0);
		}
		else if (type == 1)
		{
			if ((*st)->grid != NULL)
				return (1);
			return (0);
		}
		else if (type == 2)
		{
			if ((*st)->first_thread != NULL && (*st)->last_thread != NULL)
				return (1);
			return (0);
		}
		return (-2);
	}
	return (-1);
}
