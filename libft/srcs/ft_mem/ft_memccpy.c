/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:23:18 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 17:57:17 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	str;
	size_t			i;
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	str = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		if (source[i] == str)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
