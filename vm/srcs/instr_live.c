/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:07 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 08:36:34 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		instr_live_inner(t_storage **st, t_champion **current)
{
	(*st)->nb_champ_last_live = (*current)->number;
	(*current)->last_live = (*st)->cycle;
	(*current)->current_lives += 1;
	ft_putstr("un processus dit que le joueur ");
	ft_putnbr((*current)->number);
	ft_putchar('(');
	ft_putstr((*current)->name);
	ft_putchar(')');
	ft_putstr(" est en vie\n");
	return (SUCCESS);
}

int				instr_live(t_storage **st, t_thread **th)
{
	t_champion	*current;
	int			value;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 0) != VALID_FULL
		|| storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 1));
	value = read_in_grid(&(*st)->grid, (*th)->pc + 1, 4);
	(*th)->live = 1;
	(*st)->nb_live_current += 1;
	current = (*st)->first_champion;
	while (current != NULL)
	{
		if (current->number == value
			&& instr_live_inner(st, &current) != SUCCESS)
			return (CALL_FAILED);
		current = current->next;
	}
	if (thread_change_where(th, &(*st)->grid, (*th)->pc + 1 + 4) != SUCCESS)
		return (failed_action_move(st, th, 1));
	return (SUCCESS);
}
