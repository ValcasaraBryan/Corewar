/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:48 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/10 22:05:05 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_sub(t_thread **th, int ***gr)
{
	int		*tab;
	int		r1;
	int		r2;
	int		r3;

	if (UT_PRINT >= 1)
		ft_putstr("instr_sub\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != 1 || tab[1] != 1 || tab[2] != 1)
	{
		free(tab);
		return (NO_CHANGE);
	}
	free(tab);
	if ((r1 = read_in_grid(gr, (*th)->where + 2)) < NO_CHANGE
		|| (r2 = read_in_grid(gr, (*th)->where + 3)) < NO_CHANGE
		|| (r3 = read_in_grid(gr, (*th)->where + 4)) < NO_CHANGE)
		return (CALL_FAILED);
	if (thread_change_value_reg(th, r3, thread_get_value_reg(th, r1)
		- thread_get_value_reg(th, r2)) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}