/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:07:31 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/11 03:07:33 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnchr(const char *s, int c, size_t len)
{
	size_t	i;
	char	*str;
	char	d;

	i = 0;
	str = (char *)s;
	d = (char)c;
	while (i <= len)
	{
		if (str[i] == d)
			return (i);
		i++;
	}
	return (-1);
}
