/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:15:11 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/29 16:11:44 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		thread_change_action(t_thread **th, int new_action)
{
	if (thread_check(th) >= 0)
	{
		(*th)->action = new_action;
		if ((*th)->action >= 0 && (*th)->action <= 16)
			return (1);
		return (0);
	}
	return (-1);
}

int		thread_change_cycle(t_thread **th, int type)
{
	if (thread_check(th) >= 0)
	{
		if (type == 0)
			(*th)->cycle = 0;
		else if (type == 1)
		{
			(*th)->cycle += 1;
			if ((*th)->cycle >= g_tab_instructions[(*th)->action].cycles_nb)
				g_tab_instructions[(*th)->action].fct_ptr(1, 2, 3);
		}
		else
			return (0);
		return (1);
	}
	return (-1);
}

int		thread_change_nb_champion(t_thread **th, int new_nb)
{
	if (thread_check(th) >= 0)
	{
		(*th)->nb_champion = new_nb;
		if ((*th)->nb_champion >= 1 && (*th)->nb_champion <= 4)
			return (1);
		return (0);
	}
	return (-1);
}

int		thread_change_where(t_thread **th, int new_where)
{
	if (thread_check(th) >= 0)
	{
		(*th)->where = new_where % (GRID_SIZE * GRID_SIZE);
		if ((*th)->where >= 0 && (*th)->where < GRID_SIZE * GRID_SIZE)
			return (1);
		return (0);
	}
	return (-1);
}

int		thread_check(t_thread **th)
{
	if (th != NULL && *th != NULL)
		return (1);
	return (-1);
}
