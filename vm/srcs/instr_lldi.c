/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:19 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 09:14:16 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_lldi_inner(t_storage **st, t_thread **th, int size1,
	int size2)
{
	short	reg;
	int		total;
	int		value1;
	int		value2;

	value1 = set_value_spe(th, &(*st)->grid, size1, (*th)->pc + 1 + 1);
	size1 = size1 == 4 ? 2 : size1;
	value2 = set_value_spe(th, &(*st)->grid, size2,
		(*th)->pc + 1 + 1 + size1);
	size2 = size2 == 4 ? 2 : size2;
	reg = (short)read_in_grid(&(*st)->grid, (*th)->pc + 2 + size1 + size2, 1);
	total = 0;
	if (check_reg(reg) == SUCCESS)
	{
		total = read_in_grid(&(*st)->grid, (*th)->pc + value1 + value2, 4);
		if (thread_change_value_reg(th, reg, total) != SUCCESS)
			return (failed_action_move(st, th, 2));
	}
	if (thread_change_where(th, &(*st)->grid,
		(*th)->pc + 1 + 1 + size1 + size2 + 1) != SUCCESS)
		return (failed_action_move(st, th, 2));
	(*th)->carry = total == 0 ? 1 : 0;
	return (SUCCESS);
}

int			instr_lldi(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size1;
	int		size2;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->pc + 1, 1)) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if ((tab[0] != REG_CODE && tab[0] != DIR_CODE && tab[0] != IND_CODE)
		|| (tab[1] != REG_CODE && tab[1] != DIR_CODE)
		|| tab[2] != REG_CODE)
	{
		free(tab);
		return (failed_action_move(st, th, 2));
	}
	size1 = get_size_int(tab[0], 4);
	size2 = get_size_int(tab[1], 4);
	free(tab);
	return (instr_lldi_inner(st, th, size1, size2));
}
