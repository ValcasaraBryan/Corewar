/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putval_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:52:46 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:52:47 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					*ft_putval_tab(wchar_t c, int octet)
{
	int				*tab;
	long			soustraction;
	long			mask;
	int				val_octet;
	int				i;

	if (!(tab = (int *)malloc(sizeof(int) * octet)))
		return (0);
	i = -1;
	val_octet = octet;
	mask = 4278190080;
	while (++i < 4 - octet)
		mask = mask >> 8;
	i = -1;
	while (val_octet > 0)
	{
		soustraction = c & mask;
		c -= soustraction;
		soustraction = soustraction >> (((val_octet-- - 1) * 8));
		tab[++i] = (int)soustraction;
		mask = mask >> 8;
	}
	return (tab);
}
/*
**	len = ft_wchar_len(d);
**	octet = ft_wset_plage_byte(len);
**	tab = ft_putval_tab(ft_set_unichar(ft_set_octet(octet), len + 1, d), octet);
**	ft_putwchar(tab, octet);
*/
