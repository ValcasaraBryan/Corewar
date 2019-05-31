/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:05:33 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/31 16:13:04 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		print_byte_list(t_champion **ch)
{
	t_byte		*current;

	if (champion_check(ch) >= 0)
	{
		ft_putstr("		-------------\n		BYTE LIST\n");
		current = (*ch)->first_byte;
		while (current != NULL)
		{
			ft_putstr("		-------------\n		value : ");
			ft_putnbr(current->value);
			ft_putchar('\n');
			current = current->next;
		}
		ft_putstr("		-------------\n");
		return (1);
	}
	return (0);
}

int		print_champion_list(t_storage **st)
{
	t_champion	*current;

	if (storage_check(st, 0) >= 0)
	{
		ft_putstr("	-------------\n	CHAMPION LIST\n");
		current = (*st)->first_champion;
		while (current != NULL)
		{
			ft_putstr("	-------------\n	number : ");
			ft_putnbr(current->number);
			ft_putstr("\n	-------------\n	name   : ");
			ft_putstr(current->name != NULL ? current->name : "");
			ft_putstr("\n	-------------\n	desc   : ");
			ft_putstr(current->desc != NULL ? current->desc : "");
			ft_putchar('\n');
			print_byte_list(&current);
			current = current->next;
		}
		ft_putstr("	-------------\n");
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
		ft_putstr("-------------\nSTORAGE\n");
		print_champion_list(st);
		print_thread_list(st);
		print_grid(st);
		ft_putstr("-------------\n");
		return (1);
	}
	return (0);
}

int		print_thread_list(t_storage **st)
{
	t_thread	*current;

	if (storage_check(st, 2) >= 0)
	{
		ft_putstr("	-------------\n	THREAD LIST\n");
		current = (*st)->first_thread;
		while (current != NULL)
		{
			ft_putstr("	-------------\n	action : ");
			ft_putnbr(current->action);
			ft_putstr("\n	-------------\n	cycle  : ");
			ft_putnbr(current->cycle);
			ft_putstr("\n	-------------\n	where  : ");
			ft_putnbr(current->where);
			ft_putchar('\n');
			current = current->next;
		}
		ft_putstr("	-------------\n");
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
