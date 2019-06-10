/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:05:33 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/10 19:05:36 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		print_byte_list(t_champion **ch)
{
	t_byte		*current;

	if (champion_check(ch) < VALID_EMPTY)
		return (BAD_PARAM);
	printf("		-------------\n		BYTE LIST\n");
	ft_putstr("		");
	current = (*ch)->first_byte;
	while (current != NULL)
	{
		ft_putnbr(current->value);
		ft_putchar(' ');
		current = current->next;
	}
	printf("\n		-------------\n");
	return (SUCCESS);
}

int		print_champion_list(t_storage **st)
{
	t_champion	*current;
	int			i;

	if (storage_check(st, 0) < VALID_EMPTY)
		return (BAD_PARAM);
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
		print_byte_list(&current);
		current = current->next;
	}
	printf("	-------------\n");
	return (SUCCESS);
}

int		print_grid(t_storage **st)
{
	int			i;
	int			j;

	i = -1;
	if (storage_check(st, 1) < VALID_FULL)
		return (BAD_PARAM);
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
	return (SUCCESS);
}

int		print_storage(t_storage **st)
{
	if (storage_check(st, 0) < VALID_EMPTY)
		return (BAD_PARAM);
	printf("-------------\nSTORAGE\n");
	print_champion_list(st);
	print_thread_list(st);
	print_grid(st);
	printf("-------------\n");
	return (SUCCESS);
}

int		print_thread_list(t_storage **st)
{
	t_thread	*c;

	if (storage_check(st, 2) < VALID_EMPTY)
		return (BAD_PARAM);
	printf("	-------------\n	THREAD LIST\n");
	c = (*st)->first_thread;
	while (c != NULL)
	{
		printf("	%d | %d | %d", c->action, c->cycle, c->where);
		printf("	%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
			c->reg[0], c->reg[1], c->reg[2], c->reg[3], c->reg[4],
			c->reg[5], c->reg[6], c->reg[7], c->reg[8], c->reg[9],
			c->reg[10], c->reg[11], c->reg[12], c->reg[13], c->reg[14],
			c->reg[15]);
		c = c->next;
	}
	printf("	-------------\n");
	return (SUCCESS);
}
