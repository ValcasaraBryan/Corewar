/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:05:49 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/21 10:39:26 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			instr_add_inner(t_storage **st, t_thread **th)
{
	int		reg1;
	int		reg2;
	int		reg3;
	int		value1;
	int		value2;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	reg1 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1, 1);
	reg2 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1, 1);
	reg3 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1 + 1, 1);
	value1 = thread_get_value_reg(th, reg1);
	value2 = thread_get_value_reg(th, reg2);
	if (thread_change_value_reg(th, reg3, value1 + value2) != SUCCESS)
		return (CALL_FAILED);
	if (thread_change_where(th, &(*st)->grid,
		(*th)->where + 1 + 1 + 1 + 1 + 1) != SUCCESS)
		return (CALL_FAILED);
	(*th)->carry = value1 + value2 == 0 ? 1 : 0;
	return (SUCCESS);
}

int			instr_add(t_storage **st, t_thread **th)
{
	int		*tab;

	if (UT_PRINT >= 1)
		ft_putstr("instr_add\n");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != REG_CODE || tab[1] != REG_CODE || tab[2] != REG_CODE)
	{
		free(tab);
		return (NO_CHANGE);
	}
	free(tab);
	return (instr_add_inner(st, th));
}
