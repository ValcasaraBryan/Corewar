/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:23:27 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:23:28 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	size_t			i;

	i = 0;
	source = (unsigned char *)s;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
			return (&source[i]);
		i++;
	}
	return (NULL);
}
