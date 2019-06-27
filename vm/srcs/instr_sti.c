/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:42 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 17:46:18 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_sti_inner(t_storage **st, t_thread **th, int size1, int size2)
{
	short	reg;
	int		value;
	short	where1;
	short	where2;

	print_function_state("instr_sti_inner", "START");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	reg = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1, 1);
	if (reg <= 0 || reg > REG_NUMBER)
		return (SUCCESS);
	value = thread_get_value_reg(th, reg);
	where1 = size1 == 4 ? read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1, 2)
		: read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1, size1);
	where1 = size1 == 1 ? thread_get_value_reg(th, where1) : where1;
	where1 = size1 == 2 ? read_in_grid(&(*st)->grid, (*th)->where + where1, 4) : where1;
	//where1 = where1 % IDX_MOD;
	size1 = size1 == 4 ? 2 : size1;
	where2 = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1 + size1, size2);
	where2 = size2 == 1 ? thread_get_value_reg(th, where2) : where2;
	//where2 = where2 % IDX_MOD;
	//if (value == 0)
	//	return (SUCCESS);
	if (write_in_grid(&(*st)->grid, value, (*th)->where + (where1 + where2) % IDX_MOD, 4) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (thread_change_where(th, &(*st)->grid,
		(*th)->where + 1 + 1 + 1 + size1 + size2) != SUCCESS)
		return (failed_action_move(st, th, 2));
	print_function_state("instr_sti_inner", "END");
	return (SUCCESS);
}

int			instr_sti(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size1;
	int		size2;

	print_function_state("instr_sti", "START");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid, (*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != REG_CODE
		|| (tab[1] != REG_CODE && tab[1] != DIR_CODE && tab[1] != IND_CODE)
		|| (tab[2] != DIR_CODE && tab[2] != REG_CODE))
	{
		free(tab);
		return (failed_action_move(st, th, 2));
	}
	size1 = get_size_int(tab[1], 4);
	size2 = get_size_int(tab[2], 2);
	free(tab);
	print_function_state("instr_sti", "END");
	return (instr_sti_inner(st, th, size1, size2));
}
