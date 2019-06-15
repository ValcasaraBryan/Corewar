/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:34 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/15 18:25:34 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			instr_st(t_thread **th, int ***gr)
{
	int		*tab;
	int		size;
	int		value;
	int		where;

	if (UT_PRINT >= 1)
		ft_putstr("instr_st\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != REG_CODE || (tab[1] != IND_CODE && tab[1] != REG_CODE)
		|| tab[2] != NO_CODE)
	{
		free(tab);
		return (NO_CHANGE);
	}
	size = get_size_int(tab[1], 4);
	free(tab);
	value = thread_get_value_reg(th, read_in_grid(gr, (*th)->where + 1 + 1, 1));
	where = read_in_grid(gr, (*th)->where + 1 + 1 + 1, size);
	if (size == 2)
	{
		if (write_in_grid(gr, value, (*th)->where + where, 4) != SUCCESS)
			return (CALL_FAILED);
	}
	else
	{
		if (thread_change_value_reg(th, read_in_grid(gr, (*th)->where + 1 + 1 + 1, 1), value) != SUCCESS)
			return (CALL_FAILED);
	}
	return (SUCCESS);
}