/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:22:19 by jdurand-          #+#    #+#             */
/*   Updated: 2018/04/09 10:36:11 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (!(res = ft_strnew(len)))
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	return (res);
}
