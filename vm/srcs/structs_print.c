/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:05:33 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 18:09:18 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		print_byte_list(t_champion **ch)
{
	t_byte		*current;

	print_function_state("print_byte_list", "START");
	if (champion_check(ch) < VALID_EMPTY)
		return (BAD_PARAM);
	ft_putstr("		-------------\n		BYTE LIST\n		");
	current = (*ch)->first_byte;
	while (current != NULL)
	{
		ft_putnbr(current->value);
		ft_putchar(' ');
		current = current->next;
	}
	ft_putstr("\n		-------------\n");
	print_function_state("print_byte_list", "END");
	return (SUCCESS);
}

int		print_champion_list(t_storage **st)
{
	t_champion	*current;

	print_function_state("print_champion_list", "START");
	if (storage_check(st, 0) < VALID_EMPTY)
		return (BAD_PARAM);
	ft_putstr("	-------------\n	CHAMPION LIST\n");
	current = (*st)->first_champion;
	while (current != NULL)
	{
		ft_putstr("	-------------\n	number      : ");
		ft_putnbr(current->number);
		ft_putstr("\n	-------------\n	size        : ");
		ft_putnbr(current->size);
		ft_putstr("\n	-------------\n	name        : ");
		ft_putstr(current->name != NULL ? current->name : "");
		ft_putstr("\n	-------------\n	desc        : ");
		ft_putstr(current->desc != NULL ? current->desc : "");
		ft_putchar('\n');
		print_byte_list(&current);
		current = current->next;
	}
	ft_putstr("	-------------\n");
	print_function_state("print_champion_list", "END");
	return (SUCCESS);
}

int		print_grid(t_storage **st)
{
	int			i;
	int			j;

	print_function_state("print_grid", "START");
	i = -1;
	if (storage_check(st, 1) != VALID_FULL)
		return (BAD_PARAM);
	while (++i < GRID_SIZE)
	{
		j = -1;
		while (++j < GRID_SIZE)
		{
			print_nb_hexa(((*st)->grid)[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	print_function_state("print_grid", "END");
	return (SUCCESS);
}

int		print_storage(t_storage **st)
{
	print_function_state("print_storage", "START");
	if (storage_check(st, 0) < VALID_EMPTY)
		return (BAD_PARAM);
	ft_putstr("-------------\nSTORAGE\n");
	print_champion_list(st);
	print_thread_list(st);
	print_grid(st);
	ft_putstr("-------------\n");
	print_function_state("print_storage", "END");
	return (SUCCESS);
}

int		print_thread_list(t_storage **st)
{
	t_thread	*c;

	print_function_state("print_thread_list", "START");
	if (storage_check(st, 2) < VALID_EMPTY)
		return (BAD_PARAM);
	ft_putstr("	-------------\n	THREAD LIST\n");
	c = (*st)->first_thread;
	while (c != NULL)
	{
		ft_putstr("	");
		ft_putnbr(c->action);
		ft_putstr(" | ");
		ft_putnbr(c->cycle);
		ft_putstr(" | ");
		ft_putnbr(c->where);
		ft_putstr("	");
		ft_putnbr(c->reg[0]);
		ft_putchar(' ');
		ft_putnbr(c->reg[1]);
		ft_putchar(' ');
		ft_putnbr(c->reg[2]);
		ft_putchar(' ');
		ft_putnbr(c->reg[3]);
		ft_putchar(' ');
		ft_putnbr(c->reg[4]);
		ft_putchar(' ');
		ft_putnbr(c->reg[5]);
		ft_putchar(' ');
		ft_putnbr(c->reg[6]);
		ft_putchar(' ');
		ft_putnbr(c->reg[7]);
		ft_putchar(' ');
		ft_putnbr(c->reg[8]);
		ft_putchar(' ');
		ft_putnbr(c->reg[9]);
		ft_putchar(' ');
		ft_putnbr(c->reg[10]);
		ft_putchar(' ');
		ft_putnbr(c->reg[11]);
		ft_putchar(' ');
		ft_putnbr(c->reg[12]);
		ft_putchar(' ');
		ft_putnbr(c->reg[13]);
		ft_putchar(' ');
		ft_putnbr(c->reg[14]);
		ft_putchar(' ');
		ft_putnbr(c->reg[15]);
		ft_putchar(' ');
		ft_putchar('\n');
		c = c->next;
	}
	ft_putstr("	-------------\n");
	print_function_state("print_thread_list", "END");
	return (SUCCESS);
}

void	print_function_state(char *name, char *msg)
{
	if (UT_PRINT >= 1)
	{
		ft_putstr(name);
		ft_putchar(' ');
		ft_putstr(msg);
		ft_putchar('\n');
	}
}