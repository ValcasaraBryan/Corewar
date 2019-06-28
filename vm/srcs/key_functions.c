/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/28 12:31:34 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				process_battle(t_storage **st, int nb_cycles)
{
	t_champion	*current_champ;
	t_thread	*current_thread;
	t_thread	*next;
	int			i;
	int			j;
	int			var_cycle_to_die;

	print_function_state("process_battle", "START");
	i = 1;
	j = 0;
	var_cycle_to_die = CYCLE_TO_DIE;
	while (i != -1 && i != nb_cycles && var_cycle_to_die > 0)
	{
		(*st)->cycle += 1;
		if (i % var_cycle_to_die == 0)
		{
			current_thread = (*st)->first_thread;
			while (current_thread != NULL)
			{
				if (current_thread->live == 1)
				{
					current_thread->live = 0;
					current_thread = current_thread->next;
				}
				else
				{
					next = current_thread->next;
					if (delete_thread(st, &current_thread) != SUCCESS)
						return (CALL_FAILED);
					current_thread = next;
				}
			}
			current_champ = (*st)->first_champion;
			while (current_champ != NULL)
			{
				current_champ->current_lives = 0;
				current_champ = current_champ->next;
			}
			nb_cycles = nb_cycles - var_cycle_to_die;
			i = 0;
			if ((*st)->nb_live_current >= NBR_LIVE || j >= MAX_CHECKS)
			{
				j = 0;
				var_cycle_to_die = var_cycle_to_die - CYCLE_DELTA;
			}
			else
				j++;
		}
		current_thread = (*st)->first_thread;
		if (current_thread == NULL)
			i = -1;
		else
		{
			while (current_thread != NULL)
			{
				if (thread_change_cycle(&current_thread, st, 1) != SUCCESS)
					return (CALL_FAILED);
				current_thread = current_thread->next;
			}
			i++;
		}
	}
	if (i != -1 && (*st)->args[0] != -1)
		print_dump(st);
	else
		announce_winner(st);
	print_function_state("process_battle", "END");
	return (SUCCESS);
}

int				intro_champions(t_storage **st)
{
	t_champion	*current;
	int			i;

	print_function_state("intro_champions", "START");
	if (storage_check(st, 0) != VALID_FULL)
		return (BAD_PARAM);
	current = (*st)->first_champion;
	ft_putstr("Introducing contestants...\n");
	i = 1;
	while (current != NULL)
	{
		ft_putstr("* Player ");
		ft_putnbr(i);
		ft_putstr(", weighing ");
		ft_putnbr(current->size);
		ft_putstr(" bytes, \"");
		ft_putstr(current->name);
		ft_putstr("\" (\"");
		ft_putstr(current->desc);
		ft_putstr("\") !\n");
		current = current->next;
		i++;
	}
	print_function_state("intro_champions", "END");
	return (SUCCESS);
}

int				announce_winner(t_storage **st)
{
	t_champion	*current;
	int			i;

	print_function_state("announce_winner", "START");
	if (storage_check(st, 0) != VALID_FULL)
		return (BAD_PARAM);
	current = (*st)->first_champion;
	i = 1;
	while (current != NULL)
	{
		if (current->number == (*st)->nb_champ_last_live)
		{
			ft_putstr("Contestant ");
			ft_putnbr(i);
			ft_putstr(", \"");
			ft_putstr(current->name);
			ft_putstr("\", has won !\n");
		}
		current = current->next;
		i++;
	}
	print_function_state("announce_winner", "END");
	return (SUCCESS);
}

int				get_args(t_storage **st, int nb_lines, char ***tab)
{
	int			i;
	int			result;

	print_function_state("get_args", "START");
	if (nb_lines < 2 || tab == NULL || *tab == NULL
		|| storage_check(st, 0) != VALID_EMPTY)
		return (print_error());
	i = 0;
	while (++i < nb_lines)
	{
		if ((result = get_args_inner(nb_lines, tab,
			&(*st)->args, i)) == SUCCESS_INC)
			i++;
		else if (result != SUCCESS)
			return (print_error());
	}
	if ((*st)->args[10] == 0 || (*st)->args[3] == -1
		|| ((*st)->args[4] != -1 && (*st)->args[5] == -1)
		|| ((*st)->args[6] != -1 && (*st)->args[7] == -1)
		|| ((*st)->args[8] != -1 && (*st)->args[9] == -1))
		return (print_error());
	print_function_state("get_args", "END");
	return (SUCCESS);
}

int				read_in_grid(int ***gr, int where, int nb)
{
	int			col;
	int			i;
	int			line;
	int			res;

	print_function_state("read_in_grid", "START");
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
	print_function_state("read_in_grid", "END");
	return (res);
}

int				write_in_grid(int ***gr, long value, int where, int nb)
{
	int			col;
	int			i;
	int			line;
	long		res;

	print_function_state("write_in_grid", "START");
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
		res = res / 256;
	}
	print_function_state("write_in_grid", "END");
	return (SUCCESS);
}
