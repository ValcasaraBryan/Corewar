/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:15:11 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/05 20:02:34 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		thread_change_action(t_thread **th, int new_action)
{
	if (thread_check(th) >= 0)
	{
		if (new_action >= 0 && new_action <= 16)
		{
			(*th)->action = new_action;
			return (1);
		}
		return (0);
	}
	return (-1);
}

int		thread_change_cycle(t_thread **th, int ***gr, int type)
{
	if (thread_check(th) >= 0 && grid_check(gr) == 1)
	{
		if (type == 0)
			(*th)->cycle = 0;
		else if (type == 1)
		{
			(*th)->cycle += 1;
			if ((*th)->cycle >= g_tab_instructions[(*th)->action].cycles_nb)
			{
				if (thread_change_cycle(th, gr, 0) == 1)
				{
					g_tab_instructions[(*th)->action].fct_ptr(th, gr);
					if (thread_change_where(th, gr, (*th)->where + 1) == 1)
						return (2);
					return (-3);
				}
				return (-2);
			}
		}
		else
			return (0);
		return (1);
	}
	return (-1);
}

int		thread_change_reg(t_thread **th, int reg, int new_value)
{
	if (thread_check(th) >= 0)
	{
		if (reg >= 0 && reg <= 15)
		{
			(*th)->reg[reg] = new_value;
			return (1);
		}
		return (0);
	}
	return (-1);
}

int		thread_change_where(t_thread **th, int ***gr, int new_where)
{
	int		new_action;
	int		tempo;

	if (thread_check(th) >= 0 && grid_check(gr) == 1)
	{
		tempo = new_where % (GRID_SIZE * GRID_SIZE);
		if (tempo >= 0 && tempo < GRID_SIZE * GRID_SIZE)
		{
			(*th)->where = tempo;
			new_action = read_in_grid(gr, (*th)->where);
			if (new_action >= 0 && thread_change_action(th, new_action) == 1)
				return (1);
			return (-2);
		}
		return (0);
	}
	return (-1);
}

int		thread_get_value_reg(t_thread **th, int reg)
{
	if (thread_check(th) >= 0)
	{
		if (reg >= 0 && reg <= 15)
			return ((*th)->reg[reg]);
		return (0);
	}
	return (-1);
}
