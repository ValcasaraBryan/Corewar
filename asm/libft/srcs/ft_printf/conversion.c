/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:18:14 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/06 20:18:15 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*string_s(va_list ap)
{
	char				*str;

	str = NULL;
	str = va_arg(ap, char *);
	if (str)
		return (ft_strdup(str));
	else
		return (NULL);
}

char					conv_c(va_list ap)
{
	int					c;

	c = va_arg(ap, int);
	return ((unsigned char)c);
}

wchar_t					conv_long_c(va_list ap)
{
	wchar_t				c;

	c = va_arg(ap, wchar_t);
	return (c);
}

char					*conv_int(va_list ap)
{
	int					c;

	c = va_arg(ap, int);
	return (ft_lltoa(c));
}

char					*conv_long(va_list ap)
{
	long				c;

	c = va_arg(ap, long);
	return (ft_lltoa(c));
}
