/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:13 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 09:09:39 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			instr_lld_inner(t_storage **st, t_thread **th, int size)
{
	short	reg;
	int		value;

	if (size == 4)
	{
		value = read_in_grid(&(*st)->grid, (*th)->pc + 1 + 1, 4);
	}
	else
	{
		value = read_in_grid(&(*st)->grid, (*th)->pc + 1 + 1, size);
		value = read_in_grid(&(*st)->grid, (*th)->pc + value, 2);
	}
	reg = (short)read_in_grid(&(*st)->grid, (*th)->pc + 1 + 1 + size, 1);
	if (check_reg(reg) == SUCCESS)
	{
		if (thread_change_value_reg(th, reg, value) != SUCCESS)
			return (failed_action_move(st, th, 2));
	}
	if (thread_change_where(th, &(*st)->grid,
		(*th)->pc + 1 + size + 1 + 1) != SUCCESS)
		return (failed_action_move(st, th, 2));
	(*th)->carry = value == 0 ? 1 : 0;
	return (SUCCESS);
}

int			instr_lld(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->pc + 1, 1)) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if ((tab[0] != DIR_CODE && tab[0] != IND_CODE)
		|| tab[1] != REG_CODE || tab[2] != NO_CODE)
	{
		free(tab);
		return (failed_action_move(st, th, 3));
	}
	size = get_size_int(tab[0], 4);
	free(tab);
	return (instr_lld_inner(st, th, size));
}
