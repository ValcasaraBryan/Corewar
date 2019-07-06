/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:40:47 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:40:50 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*conv_long_long(va_list ap)
{
	long long			c;

	c = va_arg(ap, long long);
	return (ft_lltoa(c));
}

char					*conv_char(va_list ap)
{
	int					c;

	c = va_arg(ap, int);
	return (ft_lltoa((char)c));
}

char					*conv_uchar(va_list ap, char *hexa)
{
	int					c;

	c = va_arg(ap, int);
	return (ft_ulltoa_base((unsigned char)c, hexa));
}

char					*conv_intmax(va_list ap)
{
	intmax_t			c;

	c = va_arg(ap, intmax_t);
	return (ft_lltoa(c));
}

char					*conv_uintmax(va_list ap, char *hexa)
{
	uintmax_t			c;

	c = va_arg(ap, uintmax_t);
	return (ft_ulltoa_base(c, hexa));
}
