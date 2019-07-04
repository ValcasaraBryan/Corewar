/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_storage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:33:51 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 10:50:47 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			storage_get_total_champions(t_storage **st)
{
	t_champion	*current;
	int			total;

	if (storage_check(st, 0) < VALID_EMPTY)
		return (BAD_PARAM);
	total = 0;
	current = (*st)->first_champion;
	while (current != NULL)
	{
		total += 1;
		current = current->next;
	}
	return (total);
}

int			storage_get_total_threads(t_storage **st)
{
	t_thread	*current;
	int			total;

	if (storage_check(st, 2) < VALID_EMPTY)
		return (BAD_PARAM);
	total = 0;
	current = (*st)->first_thread;
	while (current != NULL)
	{
		total += 1;
		current = current->next;
	}
	return (total);
}
