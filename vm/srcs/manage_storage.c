/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_storage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:18:44 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/23 18:11:00 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_storage	*create_storage(void)
{
	t_storage	*storage;

	if (!(storage = malloc(sizeof(*storage))))
		return (NULL);
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

void				free_storage(t_storage **st)
{
	int		result;

	result = storage_check_champion(st);
	if (result == 1)
		free_champion_list(st);
	result = storage_check_thread(st);
	if (result == 1)
		free_thread_list(st);
	if (result >= 0)
	{
		free(*st);
		*st = NULL;
	}
}

void				print_storage(t_storage **st)
{
	printf("-------------\n");
	printf("STORAGE\n");
	print_champion_list(st);
	print_thread_list(st);
	printf("-------------\n");
}
