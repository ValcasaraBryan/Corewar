/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:23:45 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:23:46 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*destination;
	char	*source;

	destination = (char *)dst;
	source = (char *)src;
	i = 0;
	if (n == 0)
		return (destination);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
