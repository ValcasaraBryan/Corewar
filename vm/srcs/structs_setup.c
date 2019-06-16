/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:20:17 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/16 19:08:01 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		setup_champions(t_storage **st, char ***t_p, int **t_n)
{
	int		i;

	if (storage_check(st, 0) != VALID_EMPTY
		|| t_p == NULL || t_n == NULL
		|| (*t_p) == NULL || (*t_n) == NULL)
		return (BAD_PARAM);
	i = -1;
	while ((*t_p)[++i] != NULL)
	{
		if (add_champion(st) != SUCCESS
			|| bin_extractor(&(*st)->last_champion, (*t_p)[i]) != SUCCESS
			|| champion_change_number(&(*st)->last_champion,
				(*t_n)[i]) != SUCCESS
			|| add_thread(st) != SUCCESS
			|| thread_change_value_reg(&(*st)->last_thread, 0,
				(*t_n)[i]) != SUCCESS)
			return (CALL_FAILED);
	}
	return (SUCCESS);
}

int		setup_grid(t_storage **st)
{
	t_champion	*curr;
	int			nb;
	int			total;

	if (storage_check(st, 0) != VALID_FULL
		|| storage_check(st, 1) != VALID_EMPTY)
		return (BAD_PARAM);
	total = 0;
	curr = (*st)->first_champion;
	while (curr != NULL && ++total != -1)
	{
		curr = curr->next;
	}
	if (add_grid(st) != SUCCESS)
		return (CALL_FAILED);
	nb = 0;
	curr = (*st)->first_champion;
	while (curr != NULL && ++nb != -1)
	{
		if (grid_fill_with_champ(&((*st)->grid), &curr, nb, total) != SUCCESS)
			return (CALL_FAILED);
		curr = curr->next;
	}
	return (SUCCESS);
}

int		setup_all(t_storage **st)
{
	char		**array_1;
	int			*array_2;

	if (tab_char_create(&array_1) != SUCCESS
		|| tab_int_create(&array_2, 4) != SUCCESS)
		return (CALL_FAILED);
	if (add_storage(st) != SUCCESS
		|| setup_champions(st, &array_1, &array_2) != SUCCESS
		|| setup_grid(st) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
