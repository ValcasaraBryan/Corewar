/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:23:12 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/05 19:35:45 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_thread		*create_thread(t_storage **st)
{
	t_thread	*thread;
	int			i;

	if (storage_check(st, 2) >= 0)
	{
		if (!(thread = malloc(sizeof(*thread))))
			return (NULL);
		thread->action = 0;
		thread->cycle = 0;
		i = -1;
		while (++i < 16)
			thread->reg[i] = 0;
		thread->where = 0;
		thread->prec = (*st)->last_thread;
		thread->next = NULL;
		return (thread);
	}
	return (NULL);
}

static int			free_thread(t_thread **th)
{
	if (thread_check(th) >= 0)
	{
		free((*th));
		(*th) = NULL;
		return (1);
	}
	return (0);
}

int					add_thread(t_storage **st)
{
	t_thread	*thread;
	int			result;

	thread = create_thread(st);
	if (thread != NULL)
	{
		result = storage_check(st, 2);
		if (result >= 0)
		{
			if (result == 1)
				(*st)->last_thread->next = thread;
			else
				(*st)->first_thread = thread;
			(*st)->last_thread = thread;
			return (1);
		}
		free_thread(&thread);
		return (0);
	}
	return (-1);
}

int					free_thread_list(t_storage **st)
{
	t_thread	*current;
	t_thread	*next;

	if (storage_check(st, 2) >= 0)
	{
		current = (*st)->first_thread;
		while (current != NULL)
		{
			next = current->next;
			free_thread(&current);
			current = next;
		}
		free(current);
		(*st)->first_thread = NULL;
		(*st)->last_thread = NULL;
		return (1);
	}
	return (0);
}
