/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_storage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:18:44 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/31 16:08:59 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_storage	*create_storage(void)
{
	t_storage	*storage;

	if (!(storage = malloc(sizeof(*storage))))
		return (NULL);
	storage->grid = NULL;
	storage->first_champion = NULL;
	storage->last_champion = NULL;
	storage->first_thread = NULL;
	storage->last_thread = NULL;
	return (storage);
}

int					add_storage(t_storage **st)
{
	t_storage	*storage;

	if (st != NULL)
	{
		storage = create_storage();
		if (storage != NULL)
		{
			(*st) = storage;
			return (1);
		}
		return (0);
	}
	return (-1);
}

int					free_storage(t_storage **st)
{
	int		result;

	result = storage_check(st, 0);
	if (result == 1)
		free_champion_list(st);
	result = storage_check(st, 1);
	if (result == 1)
		free_grid(st);
	result = storage_check(st, 2);
	if (result == 1)
		free_thread_list(st);
	if (result >= 0)
	{
		free(*st);
		*st = NULL;
		return (1);
	}
	return (0);
}
