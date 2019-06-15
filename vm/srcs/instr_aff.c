/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:07:59 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/15 14:29:42 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_aff(t_thread **th, int ***gr)
{
	int		*tab;
	int		reg;
	int		res;

	if (UT_PRINT >= 1)
		ft_putstr("instr_aff\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != REG_CODE || tab[1] != NO_CODE || tab[2] != NO_CODE)
	{
		free(tab);
		return (NO_CHANGE);
	}
	free(tab);
	reg = read_in_grid(gr, (*th)->where + 1 + 1, 1);
	if ((res = thread_get_value_reg(th, reg)) == BAD_PARAM)
		return (CALL_FAILED);
	ft_putnbr(res);
	return (SUCCESS);
}
