/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:55:33 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 18:18:17 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		fill_grid_with_champ(int ***grid, t_champion **ch)
{
	t_byte		*current;
	int			mod;

	if (check_champion_byte(ch) == 1)
	{
		mod = ((*ch)->number - 1) * GRID_SIZE;
		current = (*ch)->first_byte;
		while (current != NULL)
		{
			write_in_grid(grid, current->value, mod);
			mod++;
			current = current->next;
		}
		return (1);
	}
	return (0);
}
