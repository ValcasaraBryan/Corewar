/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:22:21 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/24 19:18:25 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	if (ft_strlen((char *)dst) == 0 && ft_strlen((char *)src) > 0)
		return (-1);
	while (i < n)
	{
		if (dst[i] != src[i])
			return (dst[i] - src[i]);
		else if (src[i] == '\0')
			return (dst[i]);
		i++;
	}
	return (0);
}
