/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 12:49:44 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 08:28:48 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		set_value(t_thread **th, int ***grid, int size, int where)
{
	int		value;

	if (size == 4)
	{
		return (read_in_grid(grid, where, 4));
	}
	else if (size == 1)
	{
		value = read_in_grid(grid, where, size);
		return (thread_get_value_reg(th, value));
	}
	else
	{
		value = read_in_grid(grid, where, size);
		return (read_in_grid(grid, (*th)->pc + value, 4));
	}
}

int		set_value_spe(t_thread **th, int ***grid, int size, int where)
{
	int		value;

	if (size == 4)
	{
		return (read_in_grid(grid, where, 2));
	}
	else if (size == 1)
	{
		value = read_in_grid(grid, where, size);
		return (thread_get_value_reg(th, value));
	}
	else
	{
		value = read_in_grid(grid, where, size);
		return (read_in_grid(grid, (*th)->pc + value, 4));
	}
}

int		set_value_mod(t_thread **th, int ***grid, int size, int where)
{
	int		value;

	if (size == 4)
	{
		return (read_in_grid(grid, where, 4));
	}
	else if (size == 1)
	{
		value = read_in_grid(grid, where, size);
		return (thread_get_value_reg(th, value));
	}
	else
	{
		value = read_in_grid(grid, where, size);
		return (read_in_grid(grid, (*th)->pc + (short)value % IDX_MOD, 4));
	}
}

int		set_value_mod_spe(t_thread **th, int ***grid, int size, int where)
{
	int		value;

	if (size == 4)
	{
		return (read_in_grid(grid, where, 2));
	}
	else if (size == 1)
	{
		value = read_in_grid(grid, where, size);
		return (thread_get_value_reg(th, value));
	}
	else
	{
		value = read_in_grid(grid, where, size);
		return (read_in_grid(grid, (*th)->pc + (short)value % IDX_MOD, 4));
	}
}
