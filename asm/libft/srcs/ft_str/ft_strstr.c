/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 22:56:33 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/19 16:16:38 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (needle[j] != haystack[i + j])
		{
			j = 0;
			i++;
		}
		else if (needle[j] == haystack[i + j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
	}
	return (NULL);
}
