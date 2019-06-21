/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_storage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:18:44 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/21 15:39:24 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_storage	*create_storage(void)
{
	t_storage	*storage;
	int			i;

	if (!(storage = malloc(sizeof(*storage))))
		return (NULL);
	if (!((storage->args) = malloc(sizeof(*(storage->args)) * (11 + 1))))
	{
		free(storage);
		return (NULL);
	}
	i = -1;
	while (++i < 10)
		storage->args[i] = -1;
	storage->args[10] = 0;
	storage->args[11] = 0;
	storage->cycle = 0;
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

	if (st == NULL)
		return (BAD_PARAM);
	if ((storage = create_storage()) == NULL)
		return (CALL_FAILED);
	(*st) = storage;
	return (SUCCESS);
}

int					free_storage(t_storage **st)
{
	if (storage_check(st, 0) < VALID_EMPTY)
		return (BAD_PARAM);
	if (storage_check(st, 0) == VALID_FULL)
		free_champion_list(st);
	if (storage_check(st, 1) == VALID_FULL)
		free_grid(st);
	if (storage_check(st, 2) == VALID_FULL)
		free_thread_list(st);
	free((*st)->args);
	free(*st);
	*st = NULL;
	return (SUCCESS);
}
