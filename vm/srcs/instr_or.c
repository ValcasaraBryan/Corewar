/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_or.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:27 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/19 17:49:16 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_or_inner(t_thread **th, int ***gr, int size1, int size2)
{
	int		value1;
	int		value2;

	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	value1 = read_in_grid(gr, (*th)->where + 1 + 1, size1);
	value1 = size1 == 1 ? thread_get_value_reg(th, value1) : value1;
	value1 = size1 == 2 ? read_in_grid(gr, (*th)->where + value1, 4) : value1;
	value2 = read_in_grid(gr, (*th)->where + 1 + 1 + size1, size2);
	value2 = size2 == 1 ? thread_get_value_reg(th, value2) : value2;
	value2 = size2 == 2 ? read_in_grid(gr, (*th)->where + value2, 4) : value2;
	if (thread_change_value_reg(th, read_in_grid(gr, (*th)->where
		+ 1 + 1 + size1 + size2, 1), (value1 | value2)) != SUCCESS)
		return (CALL_FAILED);
	if (thread_change_where(th, gr,
		(*th)->where + 1 + size1 + size2 + 1 + 1) != SUCCESS)
		return (CALL_FAILED);
	(*th)->carry = (value1 | value2) == 0 ? 1 : 0;
	return (SUCCESS);
}

int			instr_or(t_thread **th, int ***gr)
{
	int		*tab;
	int		size1;
	int		size2;

	if (UT_PRINT >= 1)
		ft_putstr("instr_or\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if ((tab[0] != DIR_CODE && tab[0] != IND_CODE && tab[0] != REG_CODE)
		|| (tab[1] != DIR_CODE && tab[1] != IND_CODE && tab[1] != REG_CODE)
		|| tab[2] != REG_CODE)
	{
		free(tab);
		return (NO_CHANGE);
	}
	size1 = get_size_int(tab[0], 4);
	size2 = get_size_int(tab[1], 4);
	free(tab);
	return (instr_or_inner(th, gr, size1, size2));
}
