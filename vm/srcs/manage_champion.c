/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_champion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:29:57 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/04 19:45:23 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_champion	*create_champion(t_storage **st)
{
	t_champion	*champion;
	int			result;
	int			i;

	i = -1;
	result = storage_check(st, 0);
	if (result >= 0)
	{
		if (!(champion = malloc(sizeof(*champion))))
			return (NULL);
		champion->number = 1;
		champion->name = NULL;
		champion->desc = NULL;
		while (++i < 4)
			champion->magic_nb[i] = 0;
		i = 0;
		while (++i < 16)
			champion->reg[i] = 0;
		champion->first_byte = NULL;
		champion->last_byte = NULL;
		champion->prec = (*st)->last_champion;
		champion->next = NULL;
		return (champion);
	}
	return (NULL);
}

static int			free_champion(t_champion **ch)
{
	int			result;

	result = champion_check(ch);
	if (result >= 0)
	{
		if (result == 1)
			free_byte_list(ch);
		if ((*ch)->name != NULL)
			free((*ch)->name);
		(*ch)->name = NULL;
		if ((*ch)->desc != NULL)
			free((*ch)->desc);
		(*ch)->desc = NULL;
		free((*ch));
		return (1);
	}
	return (0);
}

int					add_champion(t_storage **st)
{
	t_champion	*champion;
	int			result;

	champion = create_champion(st);
	if (champion != NULL)
	{
		result = storage_check(st, 0);
		if (result >= 0)
		{
			if (result == 1)
				(*st)->last_champion->next = champion;
			else
				(*st)->first_champion = champion;
			(*st)->last_champion = champion;
			return (1);
		}
		free_champion(&champion);
		return (0);
	}
	return (-1);
}

int					free_champion_list(t_storage **st)
{
	t_champion	*current;
	t_champion	*next;

	if (storage_check(st, 0) >= 0)
	{
		current = (*st)->first_champion;
		while (current != NULL)
		{
			next = current->next;
			free_champion(&current);
			current = next;
		}
		free(current);
		(*st)->first_champion = NULL;
		(*st)->last_champion = NULL;
		return (1);
	}
	return (0);
}
