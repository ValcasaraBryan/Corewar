/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:19:59 by brvalcas          #+#    #+#             */
/*   Updated: 2018/09/24 16:20:02 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int select_to_free)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	if (!(str = ft_memalloc(i + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcpy(str + i, s2);
	if (select_to_free == 1)
		free(s1);
	else if (select_to_free == 2)
		free(s2);
	else if (select_to_free == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
