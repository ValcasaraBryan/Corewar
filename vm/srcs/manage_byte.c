/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:56:09 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 09:28:02 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_byte	*create_byte(t_champion **ch)
{
	t_byte		*byte;
	int			result;

	print_function_state("create_byte", "START");
	if ((result = champion_check(ch)) < VALID_EMPTY)
		return (NULL);
	if (!(byte = malloc(sizeof(*byte))))
		return (NULL);
	ft_bzero(byte, sizeof(*byte));
	byte->value = 0;
	byte->prec = (*ch)->last_byte;
	byte->next = NULL;
	print_function_state("create_byte", "END");
	return (byte);
}

static int		free_byte(t_byte **bt)
{
	print_function_state("free_byte", "START");
	if (byte_check(bt) < VALID_EMPTY)
		return (BAD_PARAM);
	free((*bt));
	(*bt) = NULL;
	print_function_state("free_byte", "END");
	return (SUCCESS);
}

int				add_byte(t_champion **ch)
{
	t_byte		*byte;
	int			result;

	print_function_state("add_byte", "START");
	if ((result = champion_check(ch)) < VALID_EMPTY)
		return (BAD_PARAM);
	if ((byte = create_byte(ch)) == NULL)
		return (CALL_FAILED);
	if (result == VALID_FULL)
		(*ch)->last_byte->next = byte;
	else
		(*ch)->first_byte = byte;
	(*ch)->last_byte = byte;
	print_function_state("add_byte", "END");
	return (SUCCESS);
}

int				free_byte_list(t_champion **ch)
{
	t_byte		*current;
	t_byte		*next;

	print_function_state("free_byte_list", "START");
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
	print_function_state("free_byte_list", "END");
	return (SUCCESS);
}
