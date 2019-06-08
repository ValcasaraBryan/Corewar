/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/08 21:15:39 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		cycle_threads(t_storage **st)
{
	t_thread	*current;
	int			result;
	int			i;

	if (storage_check(st, 2) != 1)
		return (0);
	i = -1;
	//a changer par "tant qu'il ne reste pas qu'un seul champion" et autres
	while (++i < 50)
	{
		current = (*st)->first_thread;
		while (current != NULL)
		{
			result = thread_change_cycle(&current, &((*st)->grid), 1);
			if (result < 1)
				return (-1);
			current = current->next;
		}
	}
	return (1);
}

int		decrypt_op_code(int **tab, int nb)
{
	char	*r;
	int		i;

	if (tab == NULL || nb < 0 || nb > 255)
		return (0);
	*tab = NULL;
	if (!((*tab) = malloc(sizeof(**tab) * 4)))
		return (-1);
	if (convert_to_binary(&r, nb) == -1)
		return (-1);
	i = -1;
	while (i <= 3)
	{
		(*tab)[++i] = 0;
		(*tab)[i] = r[2 * i] == '0' && r[2 * i + 1] == '1' ? 1 : (*tab)[i];
		(*tab)[i] = r[2 * i] == '1' && r[2 * i + 1] == '0' ? 2 : (*tab)[i];
		(*tab)[i] = r[2 * i] == '1' && r[2 * i + 1] == '1' ? 3 : (*tab)[i];
	}
	free(r);
	return (1);
}

int		read_in_grid(int ***gr, int where)
{
	int		col;
	int		line;

	if (grid_check(gr) != 1)
		return (0);
	if (where < 0)
		return (-1);
	where = where % (GRID_SIZE * GRID_SIZE);
	col = where % GRID_SIZE;
	line = where / GRID_SIZE;
	return ((*gr)[line][col]);
}

int		setup_champions(t_storage **st, char ***t_p, int **t_n)
{
	int		i;

	if (storage_check(st, 0) != 0
		|| t_p == NULL || t_n == NULL
		|| (*t_p) == NULL || (*t_n) == NULL)
	return (0);
	i = -1;
	while ((*t_p)[++i] != NULL)
	{
		if (add_champion(st) != 1
			|| bin_extractor(&(*st)->last_champion, (*t_p)[i]) != 1
			|| champion_change_number(&(*st)->last_champion, (*t_n)[i]) != 1
			|| add_thread(st) != 1
			|| thread_change_value_reg(&(*st)->last_thread, 0, (*t_n)[i]) != 1)
		return (-1);
	}
	return (1);
}

int		setup_grid(t_storage **st)
{
	t_champion	*current;
	int			nb;
	int			total;

	if (storage_check(st, 0) != 1 || storage_check(st, 1) != 0)
		return (0);
	total = 0;
	current = (*st)->first_champion;
	while (current != NULL)
	{
		total += 1;
		current = current->next;
	}
	if (add_grid(st) != 1)
		return (-1);
	nb = 0;
	current = (*st)->first_champion;
	while (current != NULL)
	{
		nb += 1;
		if (grid_fill_with_champ(&((*st)->grid), &current, nb, total) != 1)
			return (-1);
		current = current->next;
	}
	return (1);
}

int		write_in_grid(int ***gr, int value, int where)
{
	int		col;
	int		line;

	if (grid_check(gr) != 1)
		return (0);
	if (where < 0)
		return (-1);
	if (value < 0 || value > 255)
		return (-2);
	where = where % (GRID_SIZE * GRID_SIZE);
	col = where % GRID_SIZE;
	line = where / GRID_SIZE;
	(*gr)[line][col] = value;
	return (1);
}
