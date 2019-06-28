/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:08:31 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/28 12:39:42 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			instr_ld_inner(t_storage **st, t_thread **th, int size)
{
	short	reg;
	int		value;

	print_function_state("instr_ld_inner", "START");
	value = set_value_mod(th, &(*st)->grid, size, (*th)->where + 1 + 1);
	reg = read_in_grid(&(*st)->grid, (*th)->where + 1 + size + 1, 1);
	if (thread_change_value_reg(th, reg, value) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (thread_change_where(th, &(*st)->grid,
		(*th)->where + 1 + size + 1 + 1) != SUCCESS)
		return (failed_action_move(st, th, 2));
	(*th)->carry = value == 0 ? 1 : 0;
	print_function_state("instr_ld_inner", "END");
	return (SUCCESS);
}

int			instr_ld(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size;

	print_function_state("instr_ld", "START");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->where + 1, 1)) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if ((tab[0] != DIR_CODE && tab[0] != IND_CODE)
		|| tab[1] != REG_CODE || tab[2] != NO_CODE)
	{
		free(tab);
		return (failed_action_move(st, th, 2));
	}
	size = get_size_int(tab[0], 4);
	free(tab);
	print_function_state("instr_ld", "END");
	return (instr_ld_inner(st, th, size));
}
