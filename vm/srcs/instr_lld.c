/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:13 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/13 20:03:30 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_lld_case_one(t_thread **th, int ***gr)
{
	int		reg;
	int		value;

	value = read_in_grid(gr, (*th)->where + 1 + 1, 2);
	if ((reg = read_in_grid(gr, (*th)->where + 1 + 1 + 2, 1)) < NO_CHANGE)
		return (CALL_FAILED);
	if (thread_change_value_reg(th, reg, value) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

static int	instr_lld_case_two(t_thread **th, int ***gr)
{
	int		reg;
	int		value;

	value = read_in_grid(gr, (*th)->where + 1 + 1, 4);
	if ((reg = read_in_grid(gr, (*th)->where + 1 + 1 + 4, 1)) < NO_CHANGE)
		return (CALL_FAILED);
	if (thread_change_value_reg(th, reg, value) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

int			instr_lld(t_thread **th, int ***gr)
{
	int		*tab;
	int		res;

	if (UT_PRINT >= 1)
		ft_putstr("instr_lld\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if ((tab[0] != DIR_CODE && tab[0] != IND_CODE)
		|| tab[1] != REG_CODE || tab[2] != NO_CODE)
	{
		free(tab);
		return (NO_CHANGE);
	}
	res = tab[0] == DIR_CODE
		? instr_lld_case_one(th, gr) : instr_lld_case_two(th, gr);
	free(tab);
	return (res);
}

