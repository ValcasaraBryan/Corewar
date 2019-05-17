/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 20:38:45 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/18 18:19:08 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	if (len >= 1)
	{
		while (src[i] && i < len && len > 0)
		{
			dst[i] = src[i];
			i++;
		}
		while (i < len)
			dst[i++] = '\0';
	}
	return (dst);
}
