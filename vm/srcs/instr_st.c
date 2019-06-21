/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:34 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/21 13:22:33 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_st_inner(t_storage **st, t_thread **th, int size)
{
	int		reg;
	int		value;
	int		where;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	reg = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1, 1);
	value = thread_get_value_reg(th, reg);
	value = value % IDX_MOD;
	where = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + 1, size);
	if (size == 2)
	{
		if (write_in_grid(&(*st)->grid, value, (*th)->where + where, 4) != SUCCESS)
			return (CALL_FAILED);
	}
	else
	{
		if (thread_change_value_reg(th, where, value) != SUCCESS)
			return (CALL_FAILED);
	}
	if (thread_change_where(th, &(*st)->grid, (*th)->where + 1 + 1 + size + 1) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

int			instr_st(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size;

	if (UT_PRINT >= 1)
		ft_putstr("instr_st\n");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid, (*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != REG_CODE || (tab[1] != IND_CODE && tab[1] != REG_CODE)
		|| tab[2] != NO_CODE)
	{
		free(tab);
		return (NO_CHANGE);
	}
	size = get_size_int(tab[1], 4);
	free(tab);
	return (instr_st_inner(st, th, size));
}
