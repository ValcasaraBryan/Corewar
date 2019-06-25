/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:05:49 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/25 17:44:25 by jdurand-         ###   ########.fr       */
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
		return (failed_action_move(st, th, 2));
	reg1 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1, 1);
	reg2 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1, 1);
	reg3 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1 + 1, 1);
	value1 = thread_get_value_reg(th, reg1);
	value2 = thread_get_value_reg(th, reg2);
	if (reg1 < 0 || reg1 > REG_NUMBER - 1 || reg2 < 0 || reg2 > REG_NUMBER - 1)
	{
		value1 = 0;
		value2 = 0;
	}
	if (thread_change_value_reg(th, reg3, value1 + value2) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (thread_change_where(th, &(*st)->grid,
		(*th)->where + 1 + 1 + 1 + 1 + 1) != SUCCESS)
		return (failed_action_move(st, th, 2));
	(*th)->carry = value1 + value2 == 0 ? 1 : 0;
	return (SUCCESS);
}

int			instr_add(t_storage **st, t_thread **th)
{
	int		*tab;

	if (UT_PRINT >= 1)
		ft_putstr("instr_add\n");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->where + 1, 1)) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (tab[0] != REG_CODE || tab[1] != REG_CODE || tab[2] != REG_CODE)
	{
		free(tab);
		return (failed_action_move(st, th, 2));
	}
	free(tab);
	return (instr_add_inner(st, th));
}
