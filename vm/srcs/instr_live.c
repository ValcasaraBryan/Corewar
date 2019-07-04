/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:07 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 11:27:42 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_live(t_storage **st, t_thread **th)
{
	t_champion	*current;
	int			value;

	print_function_state("instr_live", "START");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 0) != VALID_FULL
		|| storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 1));
	value = read_in_grid(&(*st)->grid, (*th)->where + 1, 4);
	(*th)->live = 1;
	(*st)->nb_live_current += 1;
	current = (*st)->first_champion;
	while (current != NULL)
	{
		if (current->number == value)
		{
			(*st)->nb_champ_last_live = current->number;
			current->last_live = (*st)->cycle;
			current->current_lives += 1;
		}
		current = current->next;
	}
	if (thread_change_where(th, &(*st)->grid, (*th)->where + 1 + 4) != SUCCESS)
		return (failed_action_move(st, th, 1));
	print_function_state("instr_live", "END");
	return (SUCCESS);
}
