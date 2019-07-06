/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 20:15:49 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/19 16:01:08 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	size_t			src_init;
	size_t			dst_init;
	unsigned char	*src_unsigned;

	i = 0;
	j = 0;
	src_init = ft_strlen((char *)src);
	dst_init = ft_strlen(dst);
	src_unsigned = (unsigned char *)src;
	while (dst[j] != '\0')
		j++;
	while (j < (dst_init + src_init) && i < size && j < size - 1)
	{
		dst[j] = src_unsigned[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	if (size > dst_init)
		return (src_init + dst_init);
	if (size >= 1)
		return (src_init + size);
	return (src_init);
}
