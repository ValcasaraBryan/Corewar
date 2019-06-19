/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:08:57 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/19 17:42:41 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_lfork_inner(t_thread **th, int ***gr)
{
	t_thread	*new_thread;
	int			value;

	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (dup_thread(th) != SUCCESS)
		return (CALL_FAILED);
	value = read_in_grid(gr, (*th)->where + 1, 2);
	new_thread = (*th)->next;
	if (new_thread == NULL)
		return (FAILURE);
	if (thread_change_where(&new_thread, gr,
		new_thread->where + value) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

int		instr_lfork(t_thread **th, int ***gr)
{
	if (UT_PRINT >= 1)
		ft_putstr("instr_lfork\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (instr_lfork_inner(th, gr) != SUCCESS)
		return (CALL_FAILED);
	if (thread_change_where(th, gr, (*th)->where + 1 + 2) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
