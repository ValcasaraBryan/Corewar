/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:27 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/28 12:38:49 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_or_inner(t_storage **st, t_thread **th, int size1, int size2)
{
	int		value1;
	int		value2;

	print_function_state("instr_or_inner", "START");
	value1 = set_value_mod(th, &(*st)->grid, size1, (*th)->where + 1 + 1);
	value2 = set_value_mod(th, &(*st)->grid, size2,
		(*th)->where + 1 + 1 + size1);
	if (thread_change_value_reg(th, read_in_grid(&(*st)->grid, (*th)->where
		+ 1 + 1 + size1 + size2, 1), (value1 | value2)) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (thread_change_where(th, &(*st)->grid,
		(*th)->where + 1 + size1 + size2 + 1 + 1) != SUCCESS)
		return (failed_action_move(st, th, 2));
	(*th)->carry = (value1 | value2) == 0 ? 1 : 0;
	print_function_state("instr_or_inner", "END");
	return (SUCCESS);
}

int			instr_or(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size1;
	int		size2;

	print_function_state("instr_or", "START");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->where + 1, 1)) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if ((tab[0] != DIR_CODE && tab[0] != IND_CODE && tab[0] != REG_CODE)
		|| (tab[1] != DIR_CODE && tab[1] != IND_CODE && tab[1] != REG_CODE)
		|| tab[2] != REG_CODE)
	{
		free(tab);
		return (failed_action_move(st, th, 2));
	}
	size1 = get_size_int(tab[0], 4);
	size2 = get_size_int(tab[1], 4);
	free(tab);
	print_function_state("instr_or", "END");
	return (instr_or_inner(st, th, size1, size2));
}
