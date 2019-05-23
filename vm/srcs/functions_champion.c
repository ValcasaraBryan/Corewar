/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:18:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 15:39:20 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		champion_change_desc(t_champion **ch, char *new_desc)
{
	int		result;

	result = check_champion_byte(ch);
	if (result >= 0)
	{
		if ((*ch)->desc != NULL)
		{
			free((*ch)->desc);
			(*ch)->desc = NULL;
		}
		(*ch)->desc = ft_strdup(new_desc);
		if ((*ch)->desc != NULL)
			return (1);
	}
	return (0);
}

int		champion_change_name(t_champion **ch, char *new_name)
{
	int		result;

	result = check_champion_byte(ch);
	if (result >= 0)
	{
		if ((*ch)->name != NULL)
		{
			free((*ch)->name);
			(*ch)->name = NULL;
		}
		(*ch)->name = ft_strdup(new_name);
		if ((*ch)->name != NULL)
			return (1);
	}
	return (0);
}

int		champion_change_number(t_champion **ch, int new_nb)
{
	int		result;

	result = check_champion_byte(ch);
	if (result >= 0)
	{
		(*ch)->number = new_nb;
		if ((*ch)->number > 0 && (*ch)->number <= 4)
			return (1);
	}
	return (0);
}
