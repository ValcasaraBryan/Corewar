/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_storage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:18:44 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/28 12:29:19 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void			init_storage(t_storage **st)
{
	int				i;

	i = -1;
	while (++i < 10)
		(*st)->args[i] = -1;
	(*st)->args[10] = 0;
	(*st)->args[11] = 0;
	(*st)->cycle = 0;
	(*st)->nb_live_current = 0;
	(*st)->nb_champ_last_live = 0;
	(*st)->grid = NULL;
	(*st)->color_grid = NULL;
	(*st)->first_champion = NULL;
	(*st)->last_champion = NULL;
	(*st)->first_thread = NULL;
	(*st)->last_thread = NULL;
}

static t_storage	*create_storage(void)
{
	t_storage		*storage;

	print_function_state("create_storage", "START");
	if (!(storage = malloc(sizeof(*storage))))
		return (NULL);
	if (!((storage->args) = malloc(sizeof(*(storage->args)) * (11 + 1))))
	{
		free(storage);
		return (NULL);
	}
	init_storage(&storage);
	print_function_state("create_storage", "END");
	return (storage);
}

int					add_storage(t_storage **st)
{
	t_storage		*storage;

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
