/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:05:49 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/05 20:21:47 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_add(t_thread **th, int ***gr)
{
	int		*tab;
	int		r1;
	int		r2;
	int		r3;

	if (UT_PRINT >= 1)
		ft_putstr("instr_add\n");
	if (decrypt_op_code(&tab, read_in_grid(gr, (*th)->where + 1)) != 1)
		return (-1);
	if (tab[0] == 1 && tab[1] == 1 && tab[2] == 1)
	{
		free(tab);
		if ((r1 = read_in_grid(gr, (*th)->where + 2)) < 0
			|| (r2 = read_in_grid(gr, (*th)->where + 3)) < 0
			|| (r3 = read_in_grid(gr, (*th)->where + 4)) < 0)
			return (-1);
		if (thread_change_reg(th, r3, thread_get_value_reg(th, r1)
			+ thread_get_value_reg(th, r2)) != 1)
			return (-2);
		return (1);
	}
	free(tab);
	return (0);
}
