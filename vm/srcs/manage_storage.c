/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_storage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:18:44 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/21 16:04:23 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_storage	*create_storage(void)
{
	t_storage	*storage;

	if (!(storage = malloc(sizeof(*storage))))
		return (NULL);
	storage->first_thread = NULL;
	storage->last_thread = NULL;
	return (storage);
}

int					add_storage(t_storage **st)
{
	t_storage	*storage;

	storage = create_storage();
	if (st != NULL && storage != NULL)
	{
		(*st) = storage;
		return (1);
	}
	return (0);
}

int					check_storage(t_storage **st)
{
	if (st != NULL && *st != NULL)
	{
		if ((*st)->first_thread != NULL && (*st)->last_thread != NULL)
			return (1);
		return (0);
	}
	return (-1);
}

void				free_storage(t_storage **st)
{
	int		result;

	result = check_storage(st);
	if (result == 1)
		free_thread_list(st);
	if (result >= 0)
	{
		free(*st);
		*st = NULL;
	}
}
