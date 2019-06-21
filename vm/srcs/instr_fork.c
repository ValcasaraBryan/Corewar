/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:08:19 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/21 13:15:14 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_fork_inner(t_storage **st, t_thread **th)
{
	t_thread	*new_thread;
	int			value;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	if (add_thread(st) != SUCCESS)
		return (CALL_FAILED);
	value = read_in_grid(&(*st)->grid, (*th)->where + 1, 2);
	new_thread = (*st)->last_thread;
	if (new_thread == NULL)
		return (FAILURE);
	new_thread->action = 0;
	new_thread->cycle = 0;
	new_thread->carry = 0;
	new_thread->live = 0;
	new_thread->where = (*th)->where;
	if (thread_change_where(&new_thread, &(*st)->grid,
		new_thread->where + (value % IDX_MOD) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

int		instr_fork(t_storage **st, t_thread **th)
{
	t_thread	*old_thread;

	if (UT_PRINT >= 1)
		ft_putstr("instr_fork\n");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	old_thread = *th;
	if (instr_fork_inner(st, th) != SUCCESS)
		return (CALL_FAILED);
	if (thread_change_where(&old_thread, &(*st)->grid, old_thread->where + 1 + 2) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
