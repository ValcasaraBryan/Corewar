/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_champion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:18:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 13:52:20 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		champion_change_desc(t_champion **ch, char *new_desc)
{
	print_function_state("champion_change_desc", "START");
	if (champion_check(ch) < VALID_EMPTY || new_desc == NULL)
		return (BAD_PARAM);
	if ((*ch)->desc != NULL)
	{
		free((*ch)->desc);
		(*ch)->desc = NULL;
	}
	(*ch)->desc = ft_strdup(new_desc);
	if ((*ch)->desc == NULL)
		return (CALL_FAILED);
	print_function_state("champion_change_desc", "END");
	return (SUCCESS);
}

int		champion_change_name(t_champion **ch, char *new_name)
{
	print_function_state("champion_change_name", "START");
	if (champion_check(ch) < VALID_EMPTY || new_name == NULL)
		return (BAD_PARAM);
	if ((*ch)->name != NULL)
	{
		free((*ch)->name);
		(*ch)->name = NULL;
	}
	(*ch)->name = ft_strdup(new_name);
	if ((*ch)->name == NULL)
		return (CALL_FAILED);
	print_function_state("champion_change_name", "END");
	return (SUCCESS);
}

int		champion_change_size(t_champion **ch, int new_size)
{
	print_function_state("champion_change_size", "START");
	if (champion_check(ch) < VALID_EMPTY || new_size <= 0)
		return (BAD_PARAM);
	(*ch)->size = new_size;
	print_function_state("champion_change_size", "END");
	return (SUCCESS);
}
