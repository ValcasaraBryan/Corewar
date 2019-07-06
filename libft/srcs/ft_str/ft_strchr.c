/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:25:48 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:25:49 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	d;

	i = 0;
	str = (char *)s;
	d = (char)c;
	if (s)
		j = ft_strlen((char *)s);
	else
		j = 0;
	while (i <= j)
	{
		if (str[i] == d)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
