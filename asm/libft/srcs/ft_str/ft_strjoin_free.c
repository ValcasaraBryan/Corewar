/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:19:59 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/18 03:38:08 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void free_str(char **str)
{
	free(*str);
	*str = NULL;
}

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
		free_str(&s1);
	else if (select_to_free == 2)
		free_str(&s2);
	else if (select_to_free == 3)
	{
		free_str(&s1);
		free_str(&s2);
	}
	return (str);
}
