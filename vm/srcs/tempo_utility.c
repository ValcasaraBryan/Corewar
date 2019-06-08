/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempo_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:58:19 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/08 20:12:00 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		free_tab_char(char ***tab)
{
	int		i;

	if (tab == NULL)
		return (0);
	i = -1;
	while ((*tab)[++i] != NULL)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
	}
	free(*tab);
	(*tab) = NULL;
	return (1);
}

int		free_tab_int(int **tab)
{
	int		i;

	if (tab == NULL)
		return (0);
	i = -1;
	free(*tab);
	(*tab) = NULL;
	return (1);
}

int		tab_char_create(char ***tab)
{
	char	*array_1[] = {
		"../vm_champs/champs/test_1.cor",
		"../vm_champs/champs/test_2.cor",
		"../vm_champs/champs/test_3.cor",
		"../vm_champs/champs/test_4.cor"
	};
	int		i;

	if (tab == NULL)
		return (0);
	if (!((*tab) = malloc(sizeof(**tab) * 5)))
		return(-1);
	i = -1;
	(*tab)[4] = NULL;
	while (++i < 4)
		(*tab)[i] = ft_strdup(array_1[i]);
	return (1);
}

int		tab_int_create(int **tab, int range)
{
	int		i;

	if (tab == NULL || range < 1)
		return (0);
	if (!((*tab) = malloc(sizeof(**tab) * range)))
		return(-1);
	i = -1;
	while (++i < range)
		(*tab)[i] = i + 1;
	return (1);
}