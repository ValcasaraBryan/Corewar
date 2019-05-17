/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:27:33 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:27:34 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = (size_t)ft_strlen((char *)s);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		str[i] = f((char)s[i]);
	str[i] = '\0';
	return (str);
}
