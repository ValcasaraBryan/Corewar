/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:42 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/19 17:49:25 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	instr_sti_inner(t_thread **th, int ***gr, int size1, int size2)
{
	int		reg;
	int		value;
	int		where1;
	int		where2;

	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	reg = read_in_grid(gr, (*th)->where + 1 + 1, 1);
	value = thread_get_value_reg(th, reg);
	where1 = size1 == 4 ? read_in_grid(gr, (*th)->where + 1 + 1 + 1, 2)
		: read_in_grid(gr, (*th)->where + 1 + 1 + 1, size1);
	where1 = size1 == 1 ? thread_get_value_reg(th, where1) : where1;
	where1 = size1 == 2 ? read_in_grid(gr, (*th)->where + where1, 4) : where1;
	size1 = size1 == 4 ? 2 : size1;
	where2 = read_in_grid(gr, (*th)->where + 1 + 1 + 1 + size1, size2);
	where2 = size2 == 1 ? thread_get_value_reg(th, where2) : where2;
	if (write_in_grid(gr, value, (*th)->where + where1 + where2, 4) != SUCCESS)
		return (CALL_FAILED);
	if (thread_change_where(th, gr,
		(*th)->where + 1 + 1 + 1 + size1 + size2) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

int			instr_sti(t_thread **th, int ***gr)
{
	int		*tab;
	int		size1;
	int		size2;

	if (UT_PRINT >= 1)
		ft_putstr("instr_sti\n");
	if (thread_check(th) < VALID_EMPTY || grid_check(gr) != VALID_FULL)
		return (BAD_PARAM);
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1, 1)) != SUCCESS)
		return (CALL_FAILED);
	if (tab[0] != REG_CODE
		|| (tab[1] != REG_CODE && tab[1] != DIR_CODE && tab[1] != IND_CODE)
		|| (tab[2] != DIR_CODE && tab[2] != REG_CODE))
	{
		free(tab);
		return (NO_CHANGE);
	}
	size1 = get_size_int(tab[1], 4);
	size2 = get_size_int(tab[2], 2);
	free(tab);
	return (instr_sti_inner(th, gr, size1, size2));
}
