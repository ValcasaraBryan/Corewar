/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:42:41 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/09 13:42:42 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	long	ft_len(long long n, long long val_base)
{
	long long		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= val_base)
	{
		n = n / val_base;
		i++;
	}
	return (i);
}

static char			*conv(long long val_base, long long nb, long long i,
					char *str)
{
	while (nb > 9)
	{
		if (nb % val_base < 10)
			str[i] = (nb % val_base) + '0';
		else if (nb % val_base < val_base - 10)
			str[i] = (nb % val_base) + 'a';
		else
			str[i] = (nb % val_base) + 'a' - 10;
		nb = nb / val_base;
		i--;
	}
	if (val_base < 10 && nb >= val_base)
	{
		str[i--] = (nb % val_base) + '0';
		if (nb - val_base > 0)
			str[i] = nb + '0' - val_base;
		else
			str[i] = nb + '0' - val_base + 1;
	}
	else
		str[i] = nb + '0';
	return (str);
}

static char			*conv_maj(long long val_base, long long nb, long long i,
					char *str)
{
	while (nb > 9)
	{
		if (nb % val_base < 10)
			str[i] = (nb % val_base) + '0';
		else if (nb % val_base < val_base - 10)
			str[i] = (nb % val_base) + 'A';
		else
			str[i] = (nb % val_base) + 'A' - 10;
		nb = nb / val_base;
		i--;
	}
	if (val_base < 10 && nb >= val_base)
	{
		str[i--] = (nb % val_base) + '0';
		if (nb - val_base > 0)
			str[i] = nb + '0' - val_base;
		else
			str[i] = nb + '0' - val_base + 1;
	}
	else
		str[i] = nb + '0';
	return (str);
}

char				*ft_lltoa_base(long long nb, const char *base)
{
	long long		val_base;
	long long		i;
	char			*str;

	val_base = ft_strlen(base);
	i = ft_len(nb, val_base);
	if (!(str = ft_memalloc(i + 2)))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (base[10] == 'A')
		conv_maj(val_base, nb, i, str);
	else
		conv(val_base, nb, i, str);
	return (str);
}
