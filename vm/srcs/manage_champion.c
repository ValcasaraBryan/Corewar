/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_champion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:29:57 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 14:08:14 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_champion	*create_champion(t_storage **st)
{
	t_champion	*champion;
	int			result;
	int			i;

	print_function_state("create_champion", "START");
	i = -1;
	if ((result = storage_check(st, 0)) < VALID_EMPTY)
		return (NULL);
	if (!(champion = malloc(sizeof(*champion))))
		return (NULL);
	champion->number = 1;
	champion->name = NULL;
	champion->size = 24;
	champion->desc = NULL;
	champion->first_byte = NULL;
	champion->last_byte = NULL;
	champion->prec = (*st)->last_champion;
	champion->next = NULL;
	print_function_state("create_champion", "END");
	return (champion);
}

static int			free_champion(t_champion **ch)
{
	int			result;

	print_function_state("free_champion", "START");
	if ((result = champion_check(ch)) < VALID_EMPTY)
		return (BAD_PARAM);
	if (result == VALID_FULL)
		free_byte_list(ch);
	if ((*ch)->name != NULL)
		free((*ch)->name);
	(*ch)->name = NULL;
	if ((*ch)->desc != NULL)
		free((*ch)->desc);
	(*ch)->desc = NULL;
	free((*ch));
	print_function_state("free_champion", "END");
	return (SUCCESS);
}

int					add_champion(t_storage **st)
{
	t_champion	*champion;
	int			result;

	print_function_state("add_champion", "START");
	if ((result = storage_check(st, 0)) < VALID_EMPTY)
		return (BAD_PARAM);
	if ((champion = create_champion(st)) == NULL)
		return (CALL_FAILED);
	if (result == VALID_FULL)
		(*st)->last_champion->next = champion;
	else
		(*st)->first_champion = champion;
	(*st)->last_champion = champion;
	print_function_state("add_champion", "END");
	return (SUCCESS);
}

int					free_champion_list(t_storage **st)
{
	t_champion	*current;
	t_champion	*next;

	print_function_state("free_champion_list", "START");
	if (storage_check(st, 0) < VALID_EMPTY)
		return (BAD_PARAM);
	current = (*st)->first_champion;
	while (current != NULL)
	{
		next = current->next;
		free_champion(&current);
		current = next;
	}
	free(current);
	(*st)->first_champion = NULL;
	(*st)->last_champion = NULL;
	print_function_state("free_champion_list", "END");
	return (SUCCESS);
}
