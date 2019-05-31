/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:56:09 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/31 16:06:33 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_byte	*create_byte(t_champion **ch)
{
	t_byte		*byte;
	int			result;

	result = champion_check(ch);
	if (result >= 0)
	{
		if (!(byte = malloc(sizeof(*byte))))
			return (NULL);
		byte->value = 0;
		byte->prec = (*ch)->last_byte;
		byte->next = NULL;
		return (byte);
	}
	return (NULL);
}

static int		free_byte(t_byte **bt)
{
	if (byte_check(bt) >= 0)
	{
		free((*bt));
		(*bt) = NULL;
		return (1);
	}
	return (0);
}

int				add_byte(t_champion **ch)
{
	t_byte		*byte;
	int			result;

	byte = create_byte(ch);
	if (byte != NULL)
	{
		result = champion_check(ch);
		if (result >= 0)
		{
			if (result == 1)
				(*ch)->last_byte->next = byte;
			else
				(*ch)->first_byte = byte;
			(*ch)->last_byte = byte;
			return (1);
		}
		free_byte(&byte);
		return (0);
	}
	return (-1);
}

int				free_byte_list(t_champion **ch)
{
	t_byte		*current;
	t_byte		*next;

	if (champion_check(ch) >= 0)
	{
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
		return (1);
	}
	return (0);
}
