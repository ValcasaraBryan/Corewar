/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_champion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:18:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/08 21:42:38 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		champion_change_desc(t_champion **ch, char *new_desc)
{
	if (champion_check(ch) < 0 || new_desc == NULL)
		return (BAD_VALUE);
	if ((*ch)->desc != NULL)
	{
		free((*ch)->desc);
		(*ch)->desc = NULL;
	}
	(*ch)->desc = ft_strdup(new_desc);
	if ((*ch)->desc == NULL)
		return (CALL_FAILED);
	return (SUCCESS);
}

int		champion_change_magic_nb(t_champion **ch, int index, int new_value)
{
	if (champion_check(ch) < 0 || index < 0 || index > 3)
		return (BAD_VALUE);
	(*ch)->magic_nb[index] = new_value;
	return (SUCCESS);
}

int		champion_change_name(t_champion **ch, char *new_name)
{
	if (champion_check(ch) < 0 || new_name == NULL)
		return (BAD_VALUE);
	if ((*ch)->name != NULL)
	{
		free((*ch)->name);
		(*ch)->name = NULL;
	}
	(*ch)->name = ft_strdup(new_name);
	if ((*ch)->name == NULL)
		return (CALL_FAILED);
	return (SUCCESS);
}

int		champion_change_number(t_champion **ch, int new_nb)
{
	if (champion_check(ch) < 0 || new_nb <= 0 || new_nb > 4)
		return (BAD_VALUE);
	(*ch)->number = new_nb;
	return (SUCCESS);
}
