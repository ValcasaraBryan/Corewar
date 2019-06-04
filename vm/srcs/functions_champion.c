/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_champion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:18:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/04 20:00:55 by jdurand-         ###   ########.fr       */
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

int		champion_change_magic_nb(t_champion **ch, int index, int new_value)
{
	if (champion_check(ch) >= 0)
	{
		if (index >= 0 && index <= 3)
		{
			(*ch)->magic_nb[index] = new_value;
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

int		champion_change_number(t_champion **ch, int new_nb, int default_nb)
{
	if (champion_check(ch) >= 0)
	{
		if (new_nb > 0 && new_nb <= 4)
		{
			(*ch)->number = new_nb;
			if (default_nb == 1)
			{
				if (champion_change_reg(ch, 0, -new_nb) == 1)
					return (2);
				return (-3);
			}
			if (champion_change_reg(ch, 0, new_nb) == 1)
				return (1);
			return (-2);
		}
		return (0);
	}
	return (-1);
}

int		champion_change_reg(t_champion **ch, int reg, int new_value)
{
	if (champion_check(ch) >= 0)
	{
		if (reg >= 0 && reg <= 15)
		{
			(*ch)->reg[reg] = new_value;
			return (1);
		}
		return (0);
	}
	return (-1);
}
