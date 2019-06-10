/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:56:09 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/10 17:40:06 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_byte	*create_byte(t_champion **ch)
{
	t_byte		*byte;
	int			result;

	if ((result = champion_check(ch)) < VALID_EMPTY)
		return (NULL);
	if (!(byte = malloc(sizeof(*byte))))
		return (NULL);
	byte->value = 0;
	byte->prec = (*ch)->last_byte;
	byte->next = NULL;
	return (byte);
}

static int		free_byte(t_byte **bt)
{
	if (byte_check(bt) < VALID_EMPTY)
		return (BAD_PARAM);
	free((*bt));
	(*bt) = NULL;
	return (SUCCESS);
}

int				add_byte(t_champion **ch)
{
	t_byte		*byte;
	int			result;

	if ((result = champion_check(ch)) < VALID_EMPTY)
		return (BAD_PARAM);
	if ((byte = create_byte(ch)) == NULL)
		return (CALL_FAILED);
	if (result == VALID_FULL)
		(*ch)->last_byte->next = byte;
	else
		(*ch)->first_byte = byte;
	(*ch)->last_byte = byte;
	return (SUCCESS);
}

int				free_byte_list(t_champion **ch)
{
	t_byte		*current;
	t_byte		*next;

	if (champion_check(ch) < VALID_EMPTY)
		return (BAD_PARAM);
	current = (*ch)->first_byte;
	while (current != NULL)
	{
		next = current->next;
		free_byte(&current);
		current = next;
	}
	free(current);
	(*ch)->first_byte = NULL;
	(*ch)->last_byte = NULL;
	return (SUCCESS);
}
