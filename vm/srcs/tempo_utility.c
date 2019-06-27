/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tempo_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:58:19 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/20 15:41:55 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

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
	if (tab == NULL)
		return (BAD_PARAM);
	free(*tab);
	(*tab) = NULL;
	return (SUCCESS);
}

int		tab_char_create(char ***tab, char ***argc, int **args)
{
	if (tab == NULL
		|| argc == NULL || *argc == NULL
		|| args == NULL || *args == NULL)
		return (BAD_PARAM);
	if (!((*tab) = malloc(sizeof(**tab) * 5)))
		return (MALLOC_FAILED);
	(*tab)[0] = (*args)[3] != -1 ? ft_strdup((*argc)[(*args)[3]]) : NULL;
	(*tab)[1] = (*args)[5] != -1 ? ft_strdup((*argc)[(*args)[5]]) : NULL;
	(*tab)[2] = (*args)[7] != -1 ? ft_strdup((*argc)[(*args)[7]]) : NULL;
	(*tab)[3] = (*args)[9] != -1 ? ft_strdup((*argc)[(*args)[9]]) : NULL;
	(*tab)[4] = NULL;
	return (SUCCESS);
}

int		tab_int_create(int **tab, int **args)
{
	if (tab == NULL
		|| args == NULL || *args == NULL)
		return (BAD_PARAM);
	if (!((*tab) = malloc(sizeof(**tab) * 5)))
		return (MALLOC_FAILED);
	(*tab)[0] = (*args)[2] != -1 ? (*args)[2] : -1;
	(*tab)[1] = (*args)[4] != -1 ? (*args)[4] : -2;
	(*tab)[2] = (*args)[6] != -1 ? (*args)[6] : -3;
	(*tab)[3] = (*args)[8] != -1 ? (*args)[8] : -4;
	return (SUCCESS);
}
