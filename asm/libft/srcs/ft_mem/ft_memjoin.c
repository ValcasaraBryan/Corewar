/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 22:14:55 by brvalcas          #+#    #+#             */
/*   Updated: 2018/09/25 22:14:56 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memjoin(void *dst, size_t len_dst, void *src, size_t len_src)
{
	int		i;
	int		j;
	char	*dest;
	char	*sour;
	char	*str;

	i = 0;
	j = 0;
	dest = (char *)dst;
	sour = (char *)src;
	if (!len_src)
		return (dst);
	if (!(str = ft_memalloc(len_dst + len_src + 1)))
		return (NULL);
	while (j < (int)len_src)
	{
		while (i < (int)len_dst)
		{
			str[i] = dest[i];
			i++;
		}
		str[i++] = sour[j++];
	}
	return (str);
}
