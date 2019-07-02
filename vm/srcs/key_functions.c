/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 17:57:25 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				process_battle(t_storage **st, int nb_cycles)
{
	t_thread	*current;
	SDL_Event	eventtest;
	t_thread	*next;
	int			i;
	int			j;
	int			var_cycle_to_die;

	print_function_state("process_battle", "START");
	i = 1;
	j = 0;
	var_cycle_to_die = CYCLE_TO_DIE;
	unsigned int checkTime = SDL_GetTicks();
	const unsigned int fps = 60;
	while (SDL_PollEvent(&eventtest) > -1)
	{
		if (!(i > -1 && i != nb_cycles && var_cycle_to_die > 0))
			break ;
		if ((*st)->win->pause != 1 && SDL_GetTicks() > (checkTime + 1000 / fps))
		{
			if (i % var_cycle_to_die == 0)
			{
				current = (*st)->first_thread;
				while (current != NULL)
				{
					if (current->live == 1)
					{
						current->live = 0;
						current = current->next;
					}
					else
					{
						next = current->next;
						if (delete_thread(st, &current) != SUCCESS)
							return (CALL_FAILED);
						current = next;
					}
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
			current = (*st)->first_thread;
			if (current == NULL)
				i = -1;
			else
			{
				while (current != NULL)
				{
					if (thread_change_cycle(&current, st, 1) != SUCCESS)
						return (CALL_FAILED);
					current = current->next;
				}
			}
			printf("ft_print_game debut\n");
			if (ft_print_game(st) != SUCCESS)
				return (FAILURE);
			printf("ft_print_game fin\n");
			//sleep(1);
			(*st)->cycle++;
			i++;
	   		checkTime = SDL_GetTicks();
		}
		printf("debut bug ici ??\n");
		printf("mid bug ici ??\n");
    	if (eventtest.type == SDL_QUIT)
    		i = -2;
    	if (eventtest.key.keysym.sym == SDLK_ESCAPE)
    		i = -2;
    	/*printf("c\n");
        	 || (*st)->win->event->key.keysym.sym == SDLK_ESCAPE))
    		    i = -2;
			printf("test5\n");
        	if (((*st)->win->event->type == SDL_KEYDOWN && (*st)->win->event->key.keysym.sym == SDLK_SPACE))
    	    	(*st)->win->pause = ((*st)->win->pause == 1)? 0 : 1;*/

		/*if (SDL_PollEvent(((*st)->win->event)) == 1)
		{
			// SDL_PumpEvents();
			// printf("%s\n", SDL_GetError());
        	if (((*st)->win->event->type == SDL_QUIT || (*st)->win->event->key.keysym.sym == SDLK_ESCAPE))
    		    i = -2;
			printf("test5\n");
        	if (((*st)->win->event->type == SDL_KEYDOWN && (*st)->win->event->key.keysym.sym == SDLK_SPACE))
    	    	(*st)->win->pause = ((*st)->win->pause == 1)? 0 : 1;
    	}*/
		printf("fin bug ici ??\n");
		printf("test6\n");
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
