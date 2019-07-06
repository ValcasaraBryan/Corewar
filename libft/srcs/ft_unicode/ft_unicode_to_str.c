/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:32:49 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/19 18:32:50 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			*tab_unix(int octet, int len, wchar_t str)
{
	int		*tab;
	long	mask;
	long	mask_byte;

	if (octet == 1)
		return (tab = ft_putval_tab(str, octet));
	if (!(mask = ft_set_octet(octet)))
		return (0);
	if (!(mask_byte = ft_set_unichar(mask, len + 1, str)))
		return (0);
	if (!(tab = ft_putval_tab(mask_byte, octet)))
		return (0);
	return (tab);
}

static char	*tampon(int octet, int *tab, wchar_t *str)
{
	char	*tmp;

	tmp = ft_strnew(octet);
	if (octet > 1)
	{
		while (octet-- > 0)
			*(tmp + octet) = *(tab + octet);
		free(tab);
		return (tmp);
	}
	else
	{
		free(tab);
		*tmp = *str;
		return (tmp);
	}
}

int			ft_unicode_to_str(char **data, wchar_t *str, unsigned int precision)
{
	int		total;
	int		len;
	int		octet;

	if (!str)
		return (0);
	total = 0;
	while (*str)
	{
		len = ft_wchar_len(*str);
		total += (octet = ft_wset_plage_byte(len));
		if (octet == -1)
			return (-1);
		if (total > (int)precision && precision > 0)
			return (total);
		*data = ft_strjoin_free(*data, tampon(octet,
				tab_unix(octet, len, *str), str), 3);
		str++;
	}
	return (total);
}
