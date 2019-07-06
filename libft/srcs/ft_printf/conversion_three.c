/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:41:31 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:41:33 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*conv_size_t(va_list ap, char *hexa)
{
	size_t				c;

	c = va_arg(ap, size_t);
	return (ft_ulltoa_base(c, hexa));
}

char					*conv_ssize_t(va_list ap)
{
	ssize_t				c;

	c = va_arg(ap, ssize_t);
	return (ft_lltoa(c));
}

char					*conv_float(va_list ap, unsigned int precision)
{
	double				c;

	c = va_arg(ap, double);
	return (ft_dotoa(c, precision));
}

char					*conv_uint(va_list ap, char *hexa)
{
	unsigned int		c;

	c = va_arg(ap, unsigned int);
	return (ft_ulltoa_base(c, hexa));
}

char					*conv_ulong(va_list ap, char *hexa)
{
	unsigned long		c;

	c = va_arg(ap, unsigned long);
	return (ft_ulltoa_base(c, hexa));
}
