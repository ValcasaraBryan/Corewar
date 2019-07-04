/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:04:41 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 15:26:33 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*res;
	int		minus;
	int		len;

	minus = n < 0 ? 1 : 0;
	len = ft_nbrlen(n);
	if (!(res = ft_strnew(len + minus)))
		return (NULL);
	res[0] = minus == 1 ? '-' : '0';
	while (len > 0)
	{
		res[len - 1 + minus] = n > 0 ? n % 10 + 48 : -(n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (res);
}
