/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:15:11 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 16:12:43 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		thread_change_action(t_thread **th, int new_action)
{
	print_function_state("thread_change_action", "START");
	if (thread_check(th) < VALID_EMPTY)
		return (BAD_PARAM);
	if (new_action < 0 || new_action > 16)
		(*th)->action = 0;
	else
		(*th)->action = new_action;
	print_function_state("thread_change_action", "END");
	return (SUCCESS);
}

int		thread_change_cycle(t_thread **th, t_storage **st, int type)
{
	print_function_state("thread_change_cycle", "START");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	if (type == 0)
		(*th)->cycle = 0;
	else if (type == 1)
	{
		(*th)->cycle += 1;
		if ((*th)->cycle >= g_tab_instructions[(*th)->action].cycles_nb)
		{
			if (thread_change_cycle(th, st, 0) != SUCCESS)
				return (CALL_FAILED);
			if (g_tab_instructions[(*th)->action].fct_ptr(st, th) != SUCCESS)
				if (thread_change_where(th, &((*st)->grid), (*th)->where + 1) != SUCCESS)
					return (CALL_FAILED);
		}
	}
	else
		return (BAD_PARAM);
	print_function_state("thread_change_cycle", "END");
	return (SUCCESS);
}

int		thread_change_value_reg(t_thread **th, int reg, int new_value)
{
	print_function_state("thread_change_value_reg", "START");
	if (thread_check(th) < VALID_EMPTY || reg <= 0 || reg > REG_NUMBER)
		return (BAD_PARAM);
	(*th)->reg[reg - 1] = new_value;
	print_function_state("thread_change_value_reg", "END");
	return (SUCCESS);
}

int		thread_change_where(t_thread **th, int ***gr, int new_where)
{
	int		new_action;
	int		tempo;

	print_function_state("thread_change_where", "START");
	if (GRID_SIZE <= 0)
		return (BAD_PARAM);
	tempo = new_where % (GRID_SIZE * GRID_SIZE);
	if (tempo < 0 || tempo >= GRID_SIZE * GRID_SIZE
		|| thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	(*th)->where = tempo;
	new_action = read_in_grid(gr, (*th)->where, 1);
	if (thread_change_action(th, new_action) != SUCCESS)
		return (CALL_FAILED);
	print_function_state("thread_change_where", "END");
	return (SUCCESS);
}

int		thread_get_value_reg(t_thread **th, int reg)
{
	print_function_state("thread_get_value_reg", "START");
	if (thread_check(th) < VALID_EMPTY || reg <= 0 || reg > REG_NUMBER)
		return (BAD_PARAM);
	print_function_state("thread_get_value_reg", "END");
	return ((*th)->reg[reg - 1]);
}
