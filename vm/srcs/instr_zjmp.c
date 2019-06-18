/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_zjmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:10:04 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/18 16:48:45 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_zjmp(t_thread **th, int ***gr)
{
	int		value;

	if (UT_PRINT >= 1)
		ft_putstr("instr_zjmp\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	value = read_in_grid(gr, (*th)->where + 1, 2);
	if ((*th)->carry != 1)
		return (NO_CHANGE);
	if (thread_change_where(th, gr, (*th)->where + value) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
