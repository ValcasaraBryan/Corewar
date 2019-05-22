/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_champion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:29:57 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 16:08:56 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static t_champion	*create_champion(t_storage **st)
{
	t_champion	*champion;
	int			result;

	result = check_storage_champion(st);
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
		result = check_storage_champion(st);
		if (result == 1)
			(*st)->last_champion->next = champion;
		else
			(*st)->first_champion = champion;
		(*st)->last_champion = champion;
		return (1);
	}
	return (0);
}

int					check_champion_byte(t_champion **ch)
{
	if (ch != NULL && *ch != NULL)
	{
		if ((*ch)->first_byte != NULL && (*ch)->last_byte != NULL)
			return (1);
		return (0);
	}
	return (-1);
}

void				free_champion_list(t_storage **st)
{
	t_champion	*current;
	t_champion	*next;

	current = (*st)->first_champion;
	while (current != NULL)
	{
		next = current->next;
		if (check_champion_byte(&current) == 1)
			free_byte_list(&current);
		if (current->name != NULL)
			free(current->name);
		current->name = NULL;
		if (current->desc != NULL)
			free(current->desc);
		current->desc = NULL;
		free(current);
		current = next;
	}
	free(current);
	(*st)->first_champion = NULL;
	(*st)->last_champion = NULL;
}

void				print_champion_list(t_storage **st)
{
	t_champion	*current;
	int			result;

	result = check_storage_champion(st);
	if (result >= 0)
	{
		ft_putstr("-----------\n");
		ft_putstr("CHAMPION LIST\n");
		current = (*st)->first_champion;
		while (current != NULL)
		{
			printf("-------------\n");
			printf("number : %d\n", current->number);
			printf("name   : %s\n", current->name != NULL ? current->name : "");
			printf("desc   : %s\n", current->desc != NULL ? current->desc : "");
			printf("-------------\n");
			current = current->next;
		}
	}
}
