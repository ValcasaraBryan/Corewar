/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:56:09 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 16:20:10 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_byte	*create_byte(t_champion **ch)
{
	t_byte		*byte;
	int			result;

	result = check_champion_byte(ch);
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
		result = check_champion_byte(ch);
		if (result == 1)
			(*ch)->last_byte->next = byte;
		else
			(*ch)->first_byte = byte;
		(*ch)->last_byte = byte;
		return (1);
	}
	return (0);
}

int				check_byte(t_byte **bt)
{
	if (bt != NULL && *bt != NULL)
		return (1);
	return (-1);
}

void			free_byte_list(t_champion **ch)
{
	t_byte		*current;
	t_byte		*next;

	current = (*ch)->first_byte;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(current);
	(*ch)->first_byte = NULL;
	(*ch)->last_byte = NULL;
}

void			print_byte_list(t_champion **ch)
{
	t_byte		*current;
	int			result;

	result = check_champion_byte(ch);
	if (result >= 0)
	{
		ft_putstr("-----------\n");
		ft_putstr("BYTE LIST\n");
		current = (*ch)->first_byte;
		while (current != NULL)
		{
			printf("-------------\n");
			printf("value : %d\n", current->value);
			printf("-------------\n");
			current = current->next;
		}
	}
}
