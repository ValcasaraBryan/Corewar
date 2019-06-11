/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:08:31 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/11 16:43:48 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

// indirect
// a revoir
static int	instr_ld_case_one(t_thread **th, int ***gr)
{
	int		reg;
	int		value;

	value = read_four_in_grid(gr, (*th)->where + 2);
	if ((reg = read_in_grid(gr, (*th)->where + 6)) < NO_CHANGE)
		return (CALL_FAILED);
	if (thread_change_value_reg(th, reg, value) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

// direct
static int	instr_ld_case_two(t_thread **th, int ***gr)
{
	int		reg;
	int		value;

	value = read_four_in_grid(gr, (*th)->where + 2);
	if ((reg = read_in_grid(gr, (*th)->where + 6)) < NO_CHANGE)
		return (CALL_FAILED);
	if (thread_change_value_reg(th, reg, value) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

int			instr_ld(t_thread **th, int ***gr)
{
	int		*tab;
	int		res;

	if (UT_PRINT >= 1)
		ft_putstr("instr_ld\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1)) != SUCCESS)
		return (CALL_FAILED);
	if ((tab[0] != 2 && tab[0] != 3) || tab[1] != 1 || tab[2] != 0)
	{
		free(tab);
		return (NO_CHANGE);
	}
	res = tab[0] == 2 ? instr_ld_case_one(th, gr) : instr_ld_case_two(th, gr);
	free(tab);
	return (res);
}
