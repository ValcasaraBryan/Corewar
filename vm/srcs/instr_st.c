/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_st.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:34 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/13 19:59:19 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_st_case_one(t_thread **th, int ***gr)
{
	int		reg;
	int		value;
	int		where;

	if ((reg = read_in_grid(gr, (*th)->where + 1 + 1, 1)) < NO_CHANGE)
		return (CALL_FAILED);
	value = thread_get_value_reg(th, reg);
	if ((where = read_in_grid(gr, (*th)->where + 1 + 1 + 1, 2)) < NO_CHANGE)
		return (CALL_FAILED);
	if (write_in_grid(gr, value, (*th)->where + where, 4) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

static int	instr_st_case_two(t_thread **th, int ***gr)
{
	int		reg;
	int		value;
	int		where;

	if ((reg = read_in_grid(gr, (*th)->where + 1 + 1, 1)) < NO_CHANGE)
		return (CALL_FAILED);
	value = thread_get_value_reg(th, reg);
	if ((where = read_in_grid(gr, (*th)->where + 1 + 1 + 1, 1)) < NO_CHANGE)
		return (CALL_FAILED);
	if (thread_change_value_reg(th, where, value) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

int			instr_st(t_thread **th, int ***gr)
{
	int		*tab;
	int		res;

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
	res = tab[1] == IND_CODE
		? instr_st_case_one(th, gr) : instr_st_case_two(th, gr);
	free(tab);
	return (res);
}