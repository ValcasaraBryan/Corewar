/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:07 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/21 13:09:07 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_live(t_storage **st, t_thread **th)
{
	t_champion	*current;
	int			value;

	if (UT_PRINT >= 1)
		ft_putstr("instr_live\n");
	if (thread_check(th) < VALID_EMPTY
		|| storage_check(st, 0) != VALID_FULL
		|| storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	value = read_in_grid(&(*st)->grid, (*th)->where + 1, 4);
	(*th)->live = 1;
	current = (*st)->first_champion;
	while (current != NULL)
	{
		if (current->number == value)
			current->last_live = (*st)->cycle;
		current = current->next;
	}
	if (thread_change_where(th, &(*st)->grid, (*th)->where + 1 + 4) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
