/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:23:36 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:23:38 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string_1;
	unsigned char	*string_2;

	string_1 = (unsigned char *)s1;
	string_2 = (unsigned char *)s2;
	while (n--)
	{
		if (*string_1 != *string_2)
			return (*string_1 - *string_2);
		string_1++;
		string_2++;
	}
	return (0);
}
