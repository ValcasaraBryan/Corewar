/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:24:00 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:24:01 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (destination > source)
		while (len--)
			*(destination + len) = *(source + len);
	else
		while (len--)
			*destination++ = *source++;
	return (dst);
}
