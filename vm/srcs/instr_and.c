/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_and.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:08:08 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/15 18:43:28 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_and(t_thread **th, int ***gr)
{
	int		*tab;
	int		size1;
	int		size2;
	int		arg1;
	int		arg2;

	if (UT_PRINT >= 1)
		ft_putstr("instr_and\n");
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
	arg1 = read_in_grid(gr, (*th)->where + 1 + 1, size1);
	arg1 = size1 == 1 ? thread_get_value_reg(th, arg1) : arg1;
	arg1 = size1 == 2 ? read_in_grid(gr, (*th)->where + arg1, 4) : arg1;
	arg2 = read_in_grid(gr, (*th)->where + 1 + 1 + size1, size2);
	arg2 = size2 == 1 ? thread_get_value_reg(th, arg2) : arg2;
	arg2 = size2 == 2 ? read_in_grid(gr, (*th)->where + arg2, 4) : arg2;
	if (thread_change_value_reg(th, read_in_grid(gr, (*th)->where
		+ 1 + 1 + size1 + size2, 1), (arg1 & arg2)) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
