/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:27:37 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:27:38 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = (unsigned int)ft_strlen((char *)s);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		str[i] = f(i, (char)s[i]);
	str[i] = '\0';
	return (str);
}
