/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_battle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:04:12 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 16:40:42 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		update_live_threads(t_storage **st)
{
	t_thread	*current;
	t_thread	*next;

	current = (*st)->first_thread;
	while (current != NULL)
	{
		next = current->next;
		if (current->live == 1)
			current->live = 0;
		else
		{
			if (delete_thread(st, &current) != SUCCESS)
				return (CALL_FAILED);
		}
		current = next;
	}
	return (SUCCESS);
}

static int		update_cycle_threads(t_storage **st)
{
	t_thread	*current;

	current = (*st)->first_thread;
	while (current != NULL)
	{
		if (thread_change_cycle(&current, st, 1) != SUCCESS)
			return (CALL_FAILED);
		current = current->next;
	}
	return (SUCCESS);
}

static int		update_champions(t_storage **st)
{
	t_champion	*current;

	current = (*st)->first_champion;
	while (current != NULL)
	{
		current->current_lives = 0;
		current = current->next;
	}
	(*st)->nb_live_current = 0;
	return (SUCCESS);
}

static int		update_threads(t_storage **st, int *i, int *j,
	int *var_cycle_to_die)
{
	if ((*i) % (*var_cycle_to_die) == 0)
	{
		(*i) = 0;
		if (update_live_threads(st) != SUCCESS)
			return (CALL_FAILED);
		if ((*st)->nb_live_current >= NBR_LIVE || (*j) >= MAX_CHECKS)
			(*var_cycle_to_die) = (*var_cycle_to_die) - CYCLE_DELTA;
		(*j) = ((*st)->nb_live_current >= NBR_LIVE
			|| (*j) >= MAX_CHECKS) ? 0 : (*j) + 1;
		if (update_champions(st) != SUCCESS)
			return (FAILURE);
	}
	if (update_cycle_threads(st) != SUCCESS)
		return (CALL_FAILED);
	(*i) = (*st)->first_thread == NULL ? -1 : (*i) + 1;
	(*st)->cycle += 1;
	return (SUCCESS);
}

int				process_battle(t_storage **st, int nb_cycles)
{
	int				i;
	int				j;
	int				var_cycle_to_die;
	unsigned int	check_time;

	i = 1;
	j = 0;
	var_cycle_to_die = CYCLE_TO_DIE;
	check_time = SDL_GetTicks();
	while (i > -1 && (*st)->cycle != nb_cycles && var_cycle_to_die > 0)
	{
		if ((*st)->args[1] != 1
			|| ((*st)->args[1] == 1 && (*st)->win->pause != 1
			&& SDL_GetTicks() > (check_time + 1000 / FPS)))
		{
			if (update_threads(st, &i, &j, &var_cycle_to_die) != SUCCESS
				|| ((*st)->args[1] == 1
				&& ft_print_game(st, &var_cycle_to_die) != SUCCESS))
				return (FAILURE);
			check_time = SDL_GetTicks();
		}
	}
	return ((i != -1 && (*st)->args[0] != -1)
		? print_dump(st) : announce_winner(st));
}
