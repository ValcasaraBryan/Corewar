/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_aff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:07:59 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/26 13:37:53 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			instr_aff_inner(t_storage **st, t_thread **th)
{
	short	reg;
	int		value;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	reg = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1, 1);
	value = thread_get_value_reg(th, reg);
	value = value % 256;
	//ft_putnbr(value);
	if (thread_change_where(th,
		&(*st)->grid, (*th)->where + 1 + 1 + 1) != SUCCESS)
		return (failed_action_move(st, th, 2));
	return (SUCCESS);
}

int			instr_aff(t_storage **st, t_thread **th)
{
	int		*tab;

	if (UT_PRINT >= 1)
		ft_putstr("instr_aff\n");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (failed_action_move(st, th, 2));
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid,
		(*th)->where + 1, 1)) != SUCCESS)
		return (failed_action_move(st, th, 2));
	if (tab[0] != REG_CODE || tab[1] != NO_CODE || tab[2] != NO_CODE)
	{
		free(tab);
		return (failed_action_move(st, th, 2));
	}
	free(tab);
	return (instr_aff_inner(st, th));
}
