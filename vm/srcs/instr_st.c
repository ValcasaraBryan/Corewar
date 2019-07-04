/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:34 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 18:00:24 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_st_inner(t_storage **st, t_thread **th, int size)
{
	short	reg;
	int		value;
	int		where;

	reg = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1, 1);
	if (reg <= 0 || reg > REG_NUMBER)
		return (SUCCESS);
	value = thread_get_value_reg(th, reg);
	where = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1, size);
	if (size == 2)
	{
		if (write_in_grid(&(*st)->grid, value,
			(*th)->where + (short)where % IDX_MOD, 4) != SUCCESS)
			return (failed_action_move(st, th, 2));
		write_in_grid_color(st, (*th)->where,
			(*th)->where + (short)where % IDX_MOD);
	}
	else if (thread_change_value_reg(th, where % IDX_MOD, value) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (thread_change_where(th, &(*st)->grid,
		(*th)->where + 1 + 1 + size + 1) != SUCCESS)
		return (failed_action_move(st, th, 2));
	return (SUCCESS);
}

int			instr_st(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->where + 1, 1)) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (tab[0] != REG_CODE || (tab[1] != IND_CODE && tab[1] != REG_CODE)
		|| tab[2] != NO_CODE)
	{
		free(tab);
		return (failed_action_move(st, th, 2));
	}
	size = get_size_int(tab[1], 4);
	free(tab);
	return (instr_st_inner(st, th, size));
}
