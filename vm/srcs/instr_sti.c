/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:42 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 08:28:13 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_sti_inner(t_storage **st, t_thread **th, int size1, int size2)
{
	short	reg;
	int		value;
	short	where1;
	short	where2;

	reg = read_in_grid(&(*st)->grid, (*th)->pc + 1 + 1, 1);
	if (reg <= 0 || reg > REG_NUMBER)
		return (SUCCESS);
	value = thread_get_value_reg(th, reg);
	where1 = set_value_mod_spe(th, &(*st)->grid, size1,
		(*th)->pc + 1 + 1 + 1);
	size1 = size1 == 4 ? 2 : size1;
	where2 = set_value_mod_spe(th, &(*st)->grid, size2,
		(*th)->pc + 1 + 1 + 1 + size1);
	size2 = size2 == 4 ? 2 : size2;
	if (write_in_grid(&(*st)->grid, value,
		(*th)->pc + (where1 + where2) % IDX_MOD, 4) != SUCCESS)
		return (failed_action_move(st, th, 2));
	write_in_grid_color(st, (*th)->pc,
		(*th)->pc + (where1 + where2) % IDX_MOD);
	if (thread_change_where(th, &(*st)->grid,
		(*th)->pc + 1 + 1 + 1 + size1 + size2) != SUCCESS)
		return (failed_action_move(st, th, 2));
	return (SUCCESS);
}

int			instr_sti(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size1;
	int		size2;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->pc + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != REG_CODE
		|| (tab[1] != REG_CODE && tab[1] != DIR_CODE && tab[1] != IND_CODE)
		|| (tab[2] != DIR_CODE && tab[2] != REG_CODE))
	{
		free(tab);
		return (failed_action_move(st, th, 2));
	}
	size1 = get_size_int(tab[1], 4);
	size2 = get_size_int(tab[2], 4);
	free(tab);
	return (instr_sti_inner(st, th, size1, size2));
}
