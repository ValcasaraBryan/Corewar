/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:05:49 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/13 19:47:42 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_add(t_thread **th, int ***gr)
{
	int		*tab;
	int		r1;
	int		r2;
	int		r3;

	if (UT_PRINT >= 1)
		ft_putstr("instr_add\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != REG_CODE || tab[1] != REG_CODE || tab[2] != REG_CODE)
	{
		free(tab);
		return (NO_CHANGE);
	}
	free(tab);
	if ((r1 = read_in_grid(gr, (*th)->where + 1 + 1, 1)) < NO_CHANGE
		|| (r2 = read_in_grid(gr, (*th)->where + 1 + 1 + 1, 1)) < NO_CHANGE
		|| (r3 = read_in_grid(gr, (*th)->where + 1 + 1 + 1 + 1, 1)) < NO_CHANGE)
		return (CALL_FAILED);
	if (thread_change_value_reg(th, r3, thread_get_value_reg(th, r1)
		+ thread_get_value_reg(th, r2)) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
