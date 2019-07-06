/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:48:48 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 17:10:59 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = ft_strlen((char *)s) - 1;
	j = 0;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (i / 2) > j)
		j++;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= j)
		i--;
	if (!(str = ft_memalloc(i - j + 2)))
		return (NULL);
	str = ft_strncpy(str, (char *)(s + j), i - j + 1);
	return (str);
}
