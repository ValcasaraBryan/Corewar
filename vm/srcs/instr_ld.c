/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_ld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:08:31 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/21 13:17:40 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			instr_ld_inner(t_storage **st, t_thread **th, int size)
{
	int		reg;
	int		value;

	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	value = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1, size);
	value = size == 2 ? read_in_grid(&(*st)->grid, (*th)->where + value, 4) : value;
	value = value % 512;
	reg = read_in_grid(&(*st)->grid, (*th)->where + 1 + 1 + size, 1);
	if (thread_change_value_reg(th, reg, value) != SUCCESS)
		return (CALL_FAILED);
	if (thread_change_where(th, &(*st)->grid, (*th)->where + 1 + size + 1 + 1) != SUCCESS)
		return (CALL_FAILED);
	(*th)->carry = value == 0 ? 1 : 0;
	return (SUCCESS);
}

int			instr_ld(t_storage **st, t_thread **th)
{
	int		*tab;
	int		size;

	if (UT_PRINT >= 1)
		ft_putstr("instr_ld\n");
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(&(*st)->grid, (*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if ((tab[0] != DIR_CODE && tab[0] != IND_CODE)
		|| tab[1] != REG_CODE || tab[2] != NO_CODE)
	{
		free(tab);
		return (NO_CHANGE);
	}
	size = get_size_int(tab[0], 4);
	free(tab);
	return (instr_ld_inner(st, th, size));
}
