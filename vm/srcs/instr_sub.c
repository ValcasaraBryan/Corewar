/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:48 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 18:00:39 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			instr_sub_inner(t_storage **st, t_thread **th)
{
	int		reg1;
	int		reg2;
	int		reg3;
	int		value1;
	int		value2;

	reg1 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1, 1);
	reg2 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1, 1);
	reg3 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1 + 1, 1);
	value1 = reg1 <= 0 || reg1 > REG_NUMBER || reg2 <= 0 || reg2 > REG_NUMBER
		? 0 : thread_get_value_reg(th, reg1);
	value2 = reg1 <= 0 || reg1 > REG_NUMBER || reg2 <= 0 || reg2 > REG_NUMBER
		? 0 : thread_get_value_reg(th, reg2);
	if (thread_change_value_reg(th, reg3, value1 - value2) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (thread_change_where(th, &(*st)->grid,
		(*th)->where + 1 + 1 + 1 + 1 + 1) != SUCCESS)
		return (failed_action_move(st, th, 2));
	(*th)->carry = value1 - value2 == 0 ? 1 : 0;
	return (SUCCESS);
}

int			instr_sub(t_storage **st, t_thread **th)
{
	int		*tab;

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
	return (instr_sub_inner(st, th));
}
