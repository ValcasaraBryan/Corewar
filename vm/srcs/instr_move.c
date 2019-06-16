/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:19:03 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/16 19:36:22 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_move(t_thread **th, int ***gr)
{
	(void)th;
	(void)gr;
	if (UT_PRINT >= 1)
		ft_putstr("instr_move\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (thread_change_where(th, gr, (*th)->where + 1) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
