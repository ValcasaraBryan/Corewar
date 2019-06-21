/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:20:17 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/21 15:44:19 by jdurand-         ###   ########.fr       */
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
			|| ((*st)->last_champion->number = (*t_n)[i]) == 0
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

int		setup_all(t_storage **st, int argv, char ***argc)
{
	char		**array_1;
	int			*array_2;

	if (argc == NULL || *argc == NULL || argv <= 0)
		return (BAD_PARAM);
	array_1 = NULL;
	array_2 = NULL;
	if (add_storage(st) != SUCCESS
		|| get_args(st, argv, argc) != SUCCESS)
		return (CALL_FAILED);
	if (tab_char_create(&array_1, argc, &((*st)->args)) != SUCCESS
		|| tab_int_create(&array_2, &((*st)->args)) != SUCCESS)
	{
		free_tab_char(&array_1);
		free_tab_int(&array_2);
		return (CALL_FAILED);
	}
	if (setup_champions(st, &array_1, &array_2) != SUCCESS
		|| setup_grid(st) != SUCCESS)
	{
		free_tab_char(&array_1);
		free_tab_int(&array_2);
		return (CALL_FAILED);
	}
	free_tab_char(&array_1);
	free_tab_int(&array_2);
	return (SUCCESS);
}
