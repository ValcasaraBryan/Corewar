/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:05:33 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/04 20:55:32 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		print_byte_list(t_champion **ch)
{
	t_byte		*current;

	if (champion_check(ch) >= 0)
	{
		printf("		-------------\n		BYTE LIST\n");
		current = (*ch)->first_byte;
		while (current != NULL)
		{
			printf("		-------------\n		value : %d\n", current->value);
			current = current->next;
		}
		printf("		-------------\n");
		return (1);
	}
	return (0);
}

int		print_champion_list(t_storage **st)
{
	t_champion	*current;
	int			i;

	if (storage_check(st, 0) >= 0)
	{
		printf("	-------------\n	CHAMPION LIST\n");
		current = (*st)->first_champion;
		while (current != NULL)
		{
			printf("	-------------\n	number      : %d\n", current->number);
			printf("	-------------\n	name        : %s\n",
				current->name != NULL ? current->name : "");
			printf("	-------------\n	desc        : %s\n",
				current->desc != NULL ? current->desc : "");
			i = -1;
			while(++i < 4)
				printf("	-------------\n	magic_nb[%d] : %d\n", i,
					current->magic_nb[i]);
			i = -1;
			while(++i < 16)
				printf("	-------------\n	reg[%d]      : %d\n", i,
					current->reg[i]);
			print_byte_list(&current);
			current = current->next;
		}
		printf("	-------------\n");
		return (1);
	}
	return (0);
}

int		print_grid(t_storage **st)
{
	int			i;
	int			j;

	i = -1;
	if (storage_check(st, 1) == 1)
	{
		while (((*st)->grid)[++i] != 0)
		{
			j = -1;
			while (((*st)->grid)[i][++j] != -1)
			{
				print_nb_hexa(((*st)->grid)[i][j]);
				ft_putchar(' ');
			}
			ft_putchar('\n');
		}
		return (1);
	}
	return (0);
}

int		print_storage(t_storage **st)
{
	if (storage_check(st, 0) >= 0)
	{
		printf("-------------\nSTORAGE\n");
		print_champion_list(st);
		print_thread_list(st);
		print_grid(st);
		printf("-------------\n");
		return (1);
	}
	return (0);
}

int		print_thread_list(t_storage **st)
{
	t_thread	*current;

	if (storage_check(st, 2) >= 0)
	{
		printf("	-------------\n	THREAD LIST\n");
		current = (*st)->first_thread;
		while (current != NULL)
		{
			printf("	-------------\n	action : %d\n", current->action);
			printf("	-------------\n	cycle  : %d\n", current->cycle);
			printf("	-------------\n	where  : %d\n", current->where);
			current = current->next;
		}
		printf("	-------------\n");
		return (1);
	}
	return (0);
}

int		print_thread_list_compact(t_storage **st)
{
	t_thread	*current;

	if (storage_check(st, 2) >= 0)
	{
		current = (*st)->first_thread;
		while (current != NULL)
		{
			printf("	%d | %d | %d\n",
				current->action, current->cycle, current->where);
			current = current->next;
		}
		printf("	---\n");
		return (1);
	}
	return (0);
}
