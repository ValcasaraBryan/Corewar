/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:58:00 by brvalcas          #+#    #+#             */
/*   Updated: 2019/01/29 14:58:02 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			free_tab_str(char ***str)
{
	char	**tab;
	int		i;

	i = -1;
	tab = *str;
	if (!tab)
		return (0);
	else
	{
		while (tab[++i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		free(tab);
		tab = NULL;
		*str = tab;
	}
	return (i);
}
