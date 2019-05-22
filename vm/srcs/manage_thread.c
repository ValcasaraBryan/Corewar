/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:23:12 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 18:08:20 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_thread		*create_thread(t_storage **st, int place)
{
	t_thread	*thread;

	if (check_storage_thread(st) >= 0)
	{
		if (!(thread = malloc(sizeof(*thread))))
			return (NULL);
		thread->current_action = 0;
		thread->current_cycle = 0;
		thread->current_place = place;
		thread->prec = (*st)->last_thread;
		thread->next = NULL;
		return (thread);
	}
	return (NULL);
}

int					add_thread(t_storage **st, int place)
{
	t_thread	*thread;
	int			result;

	thread = create_thread(st, place);
	if (thread != NULL)
	{
		result = check_storage_thread(st);
		if (result >= 0)
		{
			if (result == 1)
				(*st)->last_thread->next = thread;
			else
				(*st)->first_thread = thread;
			(*st)->last_thread = thread;
			return (1);
		}
		return (0);
	}
	return (-1);
}

void				free_thread_list(t_storage **st)
{
	t_thread	*current;
	t_thread	*next;

	current = (*st)->first_thread;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
	(*st)->first_thread = NULL;
	(*st)->last_thread = NULL;
}

void				print_thread_list(t_storage **st)
{
	t_thread	*current;

	if (check_storage_thread(st) >= 0)
	{
		current = (*st)->first_thread;
		printf("	-------------\n");
		printf("	THREAD LIST\n");
		while (current != NULL)
		{
			printf("	-------------\n");
			printf("	current_action : %d\n", current->current_action);
			printf("	current_cycle  : %d\n", current->current_cycle);
			printf("	current_place  : %d\n", current->current_place);
			current = current->next;
		}
		printf("	-------------\n");
	}
}
