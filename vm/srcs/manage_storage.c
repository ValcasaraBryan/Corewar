/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_storage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:18:44 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 18:30:25 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_storage	*create_storage(void)
{
	t_storage	*storage;
	int			i;

	print_function_state("create_storage", "START");
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
	storage->nb_live_current = 0;
	storage->nb_champ_last_live = 0;
	storage->grid = NULL;
	storage->color_grid = NULL;
	storage->first_champion = NULL;
	storage->last_champion = NULL;
	storage->first_thread = NULL;
	storage->last_thread = NULL;
	storage->win = NULL;
	print_function_state("create_storage", "END");
	return (storage);
}

int					add_storage(t_storage **st)
{
	t_storage	*storage;

	print_function_state("add_storage", "START");
	if (st == NULL)
		return (BAD_PARAM);
	if ((storage = create_storage()) == NULL)
		return (CALL_FAILED);
	(*st) = storage;
	print_function_state("add_storage", "END");
	return (SUCCESS);
}

int					free_storage(t_storage **st)
{
	print_function_state("free_storage", "START");
	if (storage_check(st, 0) < VALID_EMPTY)
		return (BAD_PARAM);
	if (storage_check(st, 0) == VALID_FULL)
		free_champion_list(st);
	if (storage_check(st, 1) == VALID_FULL)
		free_grid(st, 1);
	if (storage_check(st, 2) == VALID_FULL)
		free_thread_list(st);
	if (storage_check(st, 3) == VALID_FULL)
		free_grid(st, 3);
	free((*st)->args);
	free(*st);
	*st = NULL;
	print_function_state("free_storage", "END");
	return (SUCCESS);
}
