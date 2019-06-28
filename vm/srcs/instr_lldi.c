/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_lldi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:19 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/28 12:47:36 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_lldi_inner(t_storage **st, t_thread **th, int size1,
	int size2)
{
	int		reg;
	int		total;
	int		value1;
	int		value2;

	print_function_state("instr_lldi_inner", "START");
	value1 = set_value_spe(th, &(*st)->grid, size1, (*th)->where + 1 + 1);
	size1 = size1 == 4 ? 2 : size1;
	value2 = set_value_spe(th, &(*st)->grid, size2,
		(*th)->where + 1 + 1 + size1);
	size2 = size2 == 4 ? 2 : size2;
	reg = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + size1 + size2, 1);
	total = read_in_grid(&(*st)->grid, (*th)->where + value1 + value2, 4);
	if (thread_change_value_reg(th, reg, total) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (thread_change_where(th, &(*st)->grid,
		(*th)->where + 1 + 1 + size1 + size2 + 1) != SUCCESS)
		return (failed_action_move(st, th, 2));
	print_function_state("instr_lldi_inner", "END");
	return (SUCCESS);
}

int			instr_lldi(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size1;
	int		size2;

	print_function_state("instr_lldi", "START");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->where + 1, 1)) != SUCCESS)
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
	print_function_state("instr_lldi", "END");
	return (instr_lldi_inner(st, th, size1, size2));
}
