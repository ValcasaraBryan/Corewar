/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_unichar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:52:26 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:52:29 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long				ft_set_unichar(long masque_byte, int len, wchar_t c)
{
	long			soustraction;
	int				i;

	while (len-- > 0)
	{
		i = 0;
		soustraction = 1;
		while (i++ < len - 1)
			soustraction = soustraction * 2;
		if (soustraction <= c)
		{
			c -= soustraction;
			if (len > 18 && len <= 21)
				masque_byte += soustraction << 6;
			else if (len > 12)
				masque_byte += soustraction << 4;
			else if (len > 6)
				masque_byte += soustraction << 2;
			else if (len <= 6)
				masque_byte += soustraction;
		}
	}
	if (c == 1)
		masque_byte++;
	return (masque_byte);
}
