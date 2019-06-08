/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:15:11 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/08 21:54:47 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		thread_change_action(t_thread **th, int new_action)
{
	if (thread_check(th) < 0 || new_action < 0 || new_action > 16)
		return (BAD_VALUE);
	(*th)->action = new_action;
	return (SUCCESS);
}

int		thread_change_cycle(t_thread **th, int ***gr, int type)
{
	if (thread_check(th) < 0 || grid_check(gr) != 1)
		return (BAD_VALUE);
	if (type == 0)
		(*th)->cycle = 0;
	else if (type == 1)
	{
		(*th)->cycle += 1;
		if ((*th)->cycle >= g_tab_instructions[(*th)->action].cycles_nb)
		{
			if (thread_change_cycle(th, gr, 0) != SUCCESS)
				return (CALL_FAILED);
			g_tab_instructions[(*th)->action].fct_ptr(th, gr);
			if (thread_change_where(th, gr, (*th)->where + 1) != SUCCESS)
				return (CALL_FAILED);
			return (2);
		}
	}
	else
		return (BAD_VALUE);
	return (SUCCESS);
}

int		thread_change_value_reg(t_thread **th, int reg, int new_value)
{
	if (thread_check(th) < 0 || reg < 0 || reg > 15)
		return (BAD_VALUE);
	(*th)->reg[reg] = new_value;
	return (SUCCESS);
}

int		thread_change_where(t_thread **th, int ***gr, int new_where)
{
	int		new_action;
	int		tempo;

	if (GRID_SIZE <= 0)
		return (BAD_VALUE);
	tempo = new_where % (GRID_SIZE * GRID_SIZE);
	if (tempo < 0 || tempo >= GRID_SIZE * GRID_SIZE
		|| thread_check(th) < 0 || grid_check(gr) != 1)
		return (BAD_VALUE);
	(*th)->where = tempo;
	if ((new_action = read_in_grid(gr, (*th)->where)) < 0
		|| thread_change_action(th, new_action) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

int		thread_get_value_reg(t_thread **th, int reg)
{
	if (thread_check(th) < 0 || reg < 0 || reg > 15)
		return (BAD_VALUE);
	return ((*th)->reg[reg]);
}
