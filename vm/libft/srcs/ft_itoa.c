/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:04:41 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 16:53:55 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		size;
	char	*s;

	size = ft_nbrlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(s = (char *)malloc(sizeof(char) * (size_t)(size + 1))))
		return (NULL);
	ft_bzero(s, (size_t)(size + 1));
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[size] = '\0';
	while (n > 0)
	{
		s[size - 1] = n % 10 + 48;
		n = n / 10;
		--size;
	}
	return (s);
}
