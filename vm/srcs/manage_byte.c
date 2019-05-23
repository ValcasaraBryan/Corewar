/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:56:09 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/23 18:04:51 by jdurand-         ###   ########.fr       */
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
		free(byte);
		return (0);
	}
	return (-1);
}

void			free_byte(t_byte **bt)
{
	if (byte_check(bt) >= 0)
	{
		free((*bt));
		(*bt) = NULL;
	}
}

void			free_byte_list(t_champion **ch)
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
	}
}

void			print_byte_list(t_champion **ch)
{
	t_byte		*current;

	if (champion_check(ch) >= 0)
	{
		printf("		-------------\n");
		printf("		BYTE LIST\n");
		current = (*ch)->first_byte;
		while (current != NULL)
		{
			printf("		-------------\n");
			printf("		value : %d\n", current->value);
			current = current->next;
		}
		printf("		-------------\n");
	}
}
