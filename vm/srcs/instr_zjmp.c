/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:10:04 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/26 11:32:55 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_zjmp(t_storage **st, t_thread **th)
{
	int		value;

	if (UT_PRINT >= 1)
		ft_putstr("instr_zjmp\n");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 1));
	value = read_in_grid(&(*st)->grid, (*th)->where + 1, 2);
	if ((*th)->carry != 1)
		return (failed_action_move(st, th, 1));
	if (thread_change_where(th, &(*st)->grid, (*th)->where + value) != SUCCESS)
		return (failed_action_move(st, th, 1));
	return (SUCCESS);
}
