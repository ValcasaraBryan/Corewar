/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 20:50:27 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/10 20:50:28 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = ft_memalloc(ft_strlen(s1) + len + 1)))
		return (NULL);
	str = ft_strncat(ft_strcpy(str, s1), s2, len);
	return (str);
}
