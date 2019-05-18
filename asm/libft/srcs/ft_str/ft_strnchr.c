/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 03:07:31 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/18 02:49:52 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnchr(const char *s, char c)
{
	int		i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}
