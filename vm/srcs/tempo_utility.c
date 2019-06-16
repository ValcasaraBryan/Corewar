/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempo_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:58:19 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/16 19:08:09 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

char	*g_tab_tempo[4] =
{
	"../vm_champs/champs/test_1.cor",
	"../vm_champs/champs/test_2.cor",
	"../vm_champs/champs/test_3.cor",
	"../vm_champs/champs/test_4.cor"
};

int		free_tab_char(char ***tab)
{
	int		i;

	if (tab == NULL)
		return (BAD_PARAM);
	i = -1;
	while ((*tab)[++i] != NULL)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
	}
	free(*tab);
	(*tab) = NULL;
	return (SUCCESS);
}

int		free_tab_int(int **tab)
{
	int		i;

	if (tab == NULL)
		return (BAD_PARAM);
	i = -1;
	free(*tab);
	(*tab) = NULL;
	return (SUCCESS);
}

int		tab_char_create(char ***tab)
{
	int		i;

	if (tab == NULL)
		return (BAD_PARAM);
	if (!((*tab) = malloc(sizeof(**tab) * 5)))
		return (MALLOC_FAILED);
	i = -1;
	(*tab)[4] = NULL;
	while (++i < 4)
		(*tab)[i] = ft_strdup(g_tab_tempo[i]);
	return (SUCCESS);
}

int		tab_int_create(int **tab, int range)
{
	int		i;

	if (tab == NULL || range < 1)
		return (BAD_PARAM);
	if (!((*tab) = malloc(sizeof(**tab) * range)))
		return (MALLOC_FAILED);
	i = -1;
	while (++i < range)
		(*tab)[i] = i + 1;
	return (SUCCESS);
}
