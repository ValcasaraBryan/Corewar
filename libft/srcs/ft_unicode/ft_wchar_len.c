/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:51:23 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:51:24 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_wchar_len(wchar_t c)
{
	unsigned int	quatre_bit;
	int				i;

	quatre_bit = 2147483648;
	i = 32;
	if (c >= 0x11FFFF)
		return (-1);
	if (c <= 0xDFFF && c > 0xD7FF)
		return (-1);
	while (!(quatre_bit & c) && quatre_bit)
	{
		quatre_bit /= 2;
		i--;
	}
	return (i);
}
