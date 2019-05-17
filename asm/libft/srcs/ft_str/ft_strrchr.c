/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:28:42 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 17:07:41 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	d;

	i = ft_strlen((char *)s);
	str = (char *)s;
	d = (char)c;
	while (i >= 0)
	{
		if (str[i] == d)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
