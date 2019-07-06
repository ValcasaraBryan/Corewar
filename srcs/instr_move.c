/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:19:03 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 08:28:04 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_move(t_storage **st, t_thread **th)
{
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	if (thread_change_where(th, &(*st)->grid, (*th)->pc + 1) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
