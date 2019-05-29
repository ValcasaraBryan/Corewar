/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_champion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:18:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/29 15:25:49 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		champion_change_desc(t_champion **ch, char *new_desc)
{
	if (champion_check(ch) >= 0)
	{
		if ((*ch)->desc != NULL)
		{
			free((*ch)->desc);
			(*ch)->desc = NULL;
		}
		if (new_desc != NULL)
		{
			(*ch)->desc = ft_strdup(new_desc);
			if ((*ch)->desc != NULL)
				return (1);
		}
		return (0);
	}
	return (-1);
}

int		champion_change_name(t_champion **ch, char *new_name)
{
	if (champion_check(ch) >= 0)
	{
		if ((*ch)->name != NULL)
		{
			free((*ch)->name);
			(*ch)->name = NULL;
		}
		if (new_name != NULL)
		{
			(*ch)->name = ft_strdup(new_name);
			if ((*ch)->name != NULL)
				return (1);
		}
		return (0);
	}
	return (-1);
}

int		champion_change_number(t_champion **ch, int new_nb)
{
	if (champion_check(ch) >= 0)
	{
		(*ch)->number = new_nb;
		if ((*ch)->number > 0 && (*ch)->number <= 4)
			return (1);
		return (0);
	}
	return (-1);
}

int		champion_check(t_champion **ch)
{
	if (ch != NULL && *ch != NULL)
	{
		if ((*ch)->first_byte != NULL && (*ch)->last_byte != NULL)
			return (1);
		return (0);
	}
	return (-1);
}
