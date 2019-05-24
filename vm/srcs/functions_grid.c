/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:55:33 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/24 18:12:21 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		grid_fill_with_champ(int ***grid, t_champion **ch)
{
	t_byte		*current;
	int			mod;

	if (champion_check(ch) == 1)
	{
		mod = ((*ch)->number - 1) * GRID_SIZE * (GRID_SIZE / 4);
		current = (*ch)->first_byte;
		while (current != NULL)
		{
			write_in_grid(grid, current->value, mod);
			mod++;
			current = current->next;
		}
		return (1);
	}
	return (-1);
}
