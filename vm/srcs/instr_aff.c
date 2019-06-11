/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:07:59 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/10 22:14:40 by jdurand-         ###   ########.fr       */
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
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != 1 || tab[1] != 0 || tab[2] != 0)
	{
		free(tab);
		return (NO_CHANGE);
	}
	free(tab);
	if ((reg = read_in_grid(gr, (*th)->where + 2)) < NO_CHANGE)
		return (CALL_FAILED);
	if ((res = thread_get_value_reg(th, reg)) == BAD_PARAM)
		return (CALL_FAILED);
	ft_putnbr(res);
	return (SUCCESS);
}
