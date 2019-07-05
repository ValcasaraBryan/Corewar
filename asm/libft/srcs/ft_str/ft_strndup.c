/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:06:51 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/05 15:58:38 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char	*str;
	size_t	i;

	if (!src)
		return (NULL);
	i = ft_strlen(src);
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	if (len <= i)
		return (ft_strncpy(str, src, len));
	else
		return (ft_strcpy(str, src));
}
