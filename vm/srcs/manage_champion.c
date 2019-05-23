/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_champion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:29:57 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/23 18:10:19 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_champion	*create_champion(t_storage **st)
{
	t_champion	*champion;
	int			result;

	result = storage_check_champion(st);
	if (result >= 0)
	{
		if (!(champion = malloc(sizeof(*champion))))
			return (NULL);
		champion->number = 1;
		champion->name = NULL;
		champion->desc = NULL;
		champion->first_byte = NULL;
		champion->last_byte = NULL;
		champion->prec = (*st)->last_champion;
		champion->next = NULL;
		return (champion);
	}
	return (NULL);
}

int					add_champion(t_storage **st)
{
	t_champion	*champion;
	int			result;

	champion = create_champion(st);
	if (champion != NULL)
	{
		result = storage_check_champion(st);
		if (result >= 0)
		{
			if (result == 1)
				(*st)->last_champion->next = champion;
			else
				(*st)->first_champion = champion;
			(*st)->last_champion = champion;
			return (1);
		}
		free(champion);
		return (0);
	}
	return (-1);
}

void				free_champion(t_champion **ch)
{
	int			result;

	result = champion_check(ch);
	if (result >= 0)
	{
		if (result == 1)
			free_byte_list(ch);
		if ((*ch)->name != NULL)
			free((*ch)->name);
		(*ch)->name = NULL;
		if ((*ch)->desc != NULL)
			free((*ch)->desc);
		(*ch)->desc = NULL;
		free((*ch));
	}
}

void				free_champion_list(t_storage **st)
{
	t_champion	*current;
	t_champion	*next;

	if (storage_check_champion(st) >= 0)
	{
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
	}
}

void				print_champion_list(t_storage **st)
{
	t_champion	*current;

	if (storage_check_champion(st) >= 0)
	{
		ft_putstr("	-------------\n");
		ft_putstr("	CHAMPION LIST\n");
		current = (*st)->first_champion;
		while (current != NULL)
		{
			printf("	-------------\n");
			printf("	number : %d\n", current->number);
			printf("	name   : %s\n", current->name != NULL
				? current->name : "");
			printf("	desc   : %s\n", current->desc != NULL
				? current->desc : "");
			print_byte_list(&current);
			current = current->next;
		}
		printf("	-------------\n");
	}
}
