/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 12:27:05 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/06 12:27:06 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(const char *s, size_t start, size_t end)
{
	char	*str;
	int		i;
	int		len;

	str = NULL;
	if (!s || end <= start)
		return (NULL);
	len = end - start;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = 0;
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	return (str);
}
