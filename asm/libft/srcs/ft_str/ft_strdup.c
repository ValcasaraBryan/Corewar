/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 22:17:38 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/22 16:33:39 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;

	if (!(str = ft_memalloc(ft_strlen(src) + 1)))
		return (NULL);
	return (ft_strcpy(str, src));
}
