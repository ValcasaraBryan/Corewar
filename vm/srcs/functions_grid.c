/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:55:33 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 18:33:14 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		grid_fill_with_champ(int ***grid, t_champion **ch, int nb, int total)
{
	t_byte		*current;
	int			where;

	print_function_state("grid_fill_with_champ", "START");
	if (total < 1 || total > MAX_PLAYERS || nb < 1 || nb > MAX_PLAYERS
		|| champion_check(ch) != VALID_FULL || grid_check(grid) != VALID_FULL)
		return (BAD_PARAM);
	where = (GRID_SIZE * GRID_SIZE / total) * (nb - 1);
	current = (*ch)->first_byte;
	while (current != NULL)
	{
		if (write_in_grid(grid, current->value, where, 1) != SUCCESS)
			return (CALL_FAILED);
		where++;
		current = current->next;
	}
	print_function_state("grid_fill_with_champ", "END");
	return (SUCCESS);
}

int		grid_fill_with_champ_color(int ***grid, t_champion **ch, int nb, int total)
{
	t_byte		*current;
	int			where;

	print_function_state("grid_fill_with_champ_color", "START");
	if (total < 1 || total > MAX_PLAYERS || nb < 1 || nb > MAX_PLAYERS
		|| champion_check(ch) != VALID_FULL || grid_check(grid) != VALID_FULL)
		return (BAD_PARAM);
	where = (GRID_SIZE * GRID_SIZE / total) * (nb - 1);
	current = (*ch)->first_byte;
	while (current != NULL)
	{
		if (write_in_grid(grid, nb, where, 1) != SUCCESS)
			return (CALL_FAILED);
		where++;
		current = current->next;
	}
	print_function_state("grid_fill_with_champ_color", "END");
	return (SUCCESS);
}
