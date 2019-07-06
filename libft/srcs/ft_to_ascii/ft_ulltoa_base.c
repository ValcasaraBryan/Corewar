/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:42:41 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/09 13:42:42 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_len(unsigned long long n,
				unsigned long long val_base)
{
	unsigned long long		i;

	i = 0;
	while (n >= val_base)
	{
		n = n / val_base;
		i++;
	}
	return (i);
}

static char					*conv(unsigned long long val_base,
				unsigned long long nb, long long i, char *str)
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
	else if (i == 0)
		str[i] = nb + '0';
	return (str);
}

static char					*conv_maj(unsigned long long val_base,
				unsigned long long nb, unsigned long long i, char *str)
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
	else if (i == 0)
		str[i] = nb + '0';
	return (str);
}

char						*ft_ulltoa_base(unsigned long long nb,
				const char *base)
{
	unsigned long long		i;
	int						val_base;
	char					*str;

	val_base = (base) ? ft_strlen(base) : 0;
	i = ft_len(nb, (unsigned long long)val_base);
	if (!(str = ft_memalloc(i + 2)))
		return (NULL);
	if (val_base > 10 && val_base > 0 && base[10] == 'A')
		conv_maj(val_base, nb, i, str);
	else
		conv(val_base, nb, i, str);
	return (str);
}
