/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:23:12 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/28 12:25:28 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_thread		*create_thread(t_storage **st)
{
	t_thread	*thread;
	int			i;

	print_function_state("create_thread", "START");
	if (storage_check(st, 2) < VALID_EMPTY)
		return (NULL);
	if (!(thread = malloc(sizeof(*thread))))
		return (NULL);
	thread->action = 0;
	thread->cycle = 0;
	thread->carry = 0;
	thread->live = 0;
	i = -1;
	while (++i < REG_NUMBER)
		thread->reg[i] = 0;
	thread->where = 0;
	thread->prec = (*st)->last_thread;
	thread->next = NULL;
	print_function_state("create_thread", "END");
	return (thread);
}

static int			free_thread(t_thread **th)
{
	print_function_state("free_thread", "START");
	if (thread_check(th) < VALID_EMPTY)
		return (BAD_PARAM);
	free((*th));
	(*th) = NULL;
	print_function_state("free_thread", "END");
	return (SUCCESS);
}

int					add_thread(t_storage **st)
{
	t_thread	*thread;
	int			result;

	print_function_state("add_thread", "START");
	if ((result = storage_check(st, 2)) < VALID_EMPTY)
		return (BAD_PARAM);
	if ((thread = create_thread(st)) == NULL)
		return (CALL_FAILED);
	if (result == VALID_FULL)
		(*st)->last_thread->next = thread;
	else
		(*st)->first_thread = thread;
	(*st)->last_thread = thread;
	print_function_state("add_thread", "END");
	return (SUCCESS);
}

int					free_thread_list(t_storage **st)
{
	t_thread	*current;
	t_thread	*next;

	print_function_state("free_thread_list", "START");
	if (storage_check(st, 2) < VALID_EMPTY)
		return (BAD_PARAM);
	current = (*st)->first_thread;
	while (current != NULL)
	{
		next = current->next;
		if (free_thread(&current) != SUCCESS)
			return (CALL_FAILED);
		current = next;
	}
	free(current);
	(*st)->first_thread = NULL;
	(*st)->last_thread = NULL;
	print_function_state("free_thread_list", "END");
	return (SUCCESS);
}

int					delete_thread(t_storage **st, t_thread **th)
{
	t_thread	*current;
	t_thread	*next;
	t_thread	*prec;

	print_function_state("delete_thread", "START");
	if (storage_check(st, 2) < VALID_EMPTY || thread_check(th) < VALID_EMPTY)
		return (BAD_PARAM);
	current = *th;
	next = current->next;
	prec = current->prec;
	if (next != NULL)
		next->prec = prec;
	else
		(*st)->last_thread = prec;
	if (prec != NULL)
		prec->next = next;
	else
		(*st)->first_thread = next;
	if (free_thread(&current) != SUCCESS)
		return (CALL_FAILED);
	print_function_state("delete_thread", "END");
	return (SUCCESS);
}
