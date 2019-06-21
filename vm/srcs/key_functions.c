/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/21 15:49:05 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				cycle_to_die(t_storage **st, int nb_cycles)
{
	t_thread	*current;
	int			i;

	i = -1;
	printf("%d\n", nb_cycles);
	while (++i < nb_cycles)
	{
		current = (*st)->first_thread;
		while (current != NULL)
		{
			if (thread_change_cycle(&current, st, 1) < SUCCESS)
				return (CALL_FAILED);
			current = current->next;
		}
	}
	print_dump(st);
	return (SUCCESS);
}

int				intro_champions(t_storage **st)
{
	t_champion	*current;

	if (storage_check(st, 0) != VALID_FULL)
		return (BAD_PARAM);
	current = (*st)->first_champion;
	ft_putstr("Introducing contestants...\n");
	while (current != NULL)
	{
		ft_putstr("* Player ");
		ft_putnbr(current->number);
		ft_putstr(", weighing ");
		ft_putnbr(current->size);
		ft_putstr(" bytes, \"");
		ft_putstr(current->name);
		ft_putstr("\" (\"");
		ft_putstr(current->desc);
		ft_putstr("\") !\n");
		current = current->next;
	}
	return (SUCCESS);
}

int				get_args(t_storage **st, int nb_lines, char ***tab)
{
	int			i;
	int			result;

	if (nb_lines < 2 || tab == NULL || *tab == NULL || storage_check(st, 0) != VALID_EMPTY)
		return (print_error());
	i = 0;
	while (++i < nb_lines)
	{
		if ((result = get_args_inner(nb_lines, tab, &(*st)->args, i)) == SUCCESS_INC)
			i++;
		else if (result != SUCCESS)
			return (print_error());
	}
	if ((*st)->args[10] == 0 || (*st)->args[3] == -1
		|| ((*st)->args[4] != -1 && (*st)->args[5] == -1)
		|| ((*st)->args[6] != -1 && (*st)->args[7] == -1)
		|| ((*st)->args[8] != -1 && (*st)->args[9] == -1))
		return (print_error());
	return (SUCCESS);
}

int				read_in_grid(int ***gr, int where, int nb)
{
	int			col;
	int			i;
	int			line;
	int			res;

	if (grid_check(gr) != VALID_FULL || (nb != 1 && nb != 2 && nb != 4))
		return (BAD_PARAM);
	where = where < 0 ? GRID_SIZE * GRID_SIZE + where : where;
	i = -1;
	res = 0;
	while (++i < nb)
	{
		res = i != 0 ? res << 8 : res;
		where = where % (GRID_SIZE * GRID_SIZE);
		col = where % GRID_SIZE;
		line = where / GRID_SIZE;
		res += (*gr)[line][col];
		where += 1;
	}
	return (res);
}

int				write_in_grid(int ***gr, long value, int where, int nb)
{
	int			col;
	int			i;
	int			line;
	long		res;

	if (grid_check(gr) != VALID_FULL || (nb != 1 && nb != 2 && nb != 4))
		return (BAD_PARAM);
	where = where < 0 ? GRID_SIZE * GRID_SIZE + where : where;
	i = -1;
	where += nb;
	res = value;
	res = nb == 4 && value < 0 ? 9223372036854775807 - (-1 * value) + 1 : res;
	res = nb == 2 && value < 0 ? 65536 - (-1 * value) : res;
	res = nb == 1 && value < 0 ? 256 - (-1 * value) : res;
	while (++i < nb)
	{
		where = (where - 1) % (GRID_SIZE * GRID_SIZE);
		col = where % GRID_SIZE;
		line = where / GRID_SIZE;
		(*gr)[line][col] = res % 256;
		res /= 256;
	}
	return (SUCCESS);
}
