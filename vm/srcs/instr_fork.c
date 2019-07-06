/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:08:19 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 08:27:38 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_fork_inner(t_storage **st, t_thread **th)
{
	t_thread	*new_thread;
	short		value;
	int			i;

	if (add_thread(st) != SUCCESS)
		return (failed_action_move(st, th, 1));
	value = read_in_grid(&(*st)->grid, (*th)->pc + 1, 2);
	if ((new_thread = (*st)->first_thread) == NULL)
		return (failed_action_move(st, th, 1));
	new_thread->action = 0;
	new_thread->cycle = 0;
	new_thread->pc = (*th)->pc;
	new_thread->carry = (*th)->carry;
	new_thread->live = (*th)->live;
	i = -1;
	while (++i < REG_NUMBER)
		new_thread->reg[i] = (*th)->reg[i];
	if (thread_change_where(&new_thread, &(*st)->grid,
		new_thread->pc + (value % IDX_MOD)) != SUCCESS)
		return (failed_action_move(st, th, 1));
	return (SUCCESS);
}

int		instr_fork(t_storage **st, t_thread **th)
{
	t_thread	*old;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 1));
	old = *th;
	if (instr_fork_inner(st, th) != SUCCESS)
		return (failed_action_move(st, th, 1));
	if (thread_change_where(&old, &(*st)->grid, old->pc + 1 + 2) != SUCCESS)
		return (failed_action_move(st, th, 1));
	return (SUCCESS);
}
