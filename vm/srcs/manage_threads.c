/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:23:12 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/20 18:35:24 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int			storage_not_null(t_storage **st)
{
	if (st != NULL && *st != NULL)
	{
		if ((*st)->first_thread != NULL && (*st)->last_thread != NULL)
			return (1);
		return (0);
	}
	return (-1);
}

static t_thread		*create_thread(t_storage **st, int place)
{
	t_thread	*thread;
	int			result;

	result = storage_not_null(st);
	if (result >= 0)
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
		result = storage_not_null(st);
		if (result == 1)
			(*st)->last_thread->next = thread;
		else
			(*st)->first_thread = thread;
		(*st)->last_thread = thread;
		return (1);
	}
	return (0);
}

void				print_thread_list(t_storage **st)
{
	t_thread	*current;
	int			result;

	result = storage_not_null(st);
	if (result >= 0)
	{
		current = (*st)->first_thread;
		while (current != NULL)
		{
			ft_putstr("-----------\n");
			ft_putstr("current_action : ");
			ft_putnbr(current->current_action);
			ft_putstr("\ncurrent_cycle  : ");
			ft_putnbr(current->current_cycle);
			ft_putstr("\ncurrent_place  : ");
			ft_putnbr(current->current_place);
			ft_putstr("\n-----------\n");
			current = current->next;
		}
	}
}