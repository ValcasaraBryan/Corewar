/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:42:13 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/06 12:26:19 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*conv_ulong_long(va_list ap, char *hexa)
{
	unsigned long long	c;

	c = va_arg(ap, unsigned long long);
	return (ft_ulltoa_base(c, hexa));
}

char					*conv_short(va_list ap)
{
	int					c;

	c = va_arg(ap, int);
	return (ft_lltoa((short)c));
}

char					*conv_ushort(va_list ap, char *hexa)
{
	int					c;

	c = va_arg(ap, int);
	return (ft_ulltoa_base((unsigned short)c, hexa));
}

char					*conv_void(va_list ap, char *hexa)
{
	void				*c;

	c = va_arg(ap, void *);
	return (ft_ulltoa_base((long long)c, hexa));
}

char					*string_unix(va_list ap, t_string *list)
{
	wchar_t				*str;
	char				*data;

	str = va_arg(ap, wchar_t *);
	if (!str)
		return (ft_strdup("(null)"));
	data = ft_strdup("");
	if (ft_unicode_to_str(&data, str, (unsigned int)list->tab[POINT]) == -1)
	{
		list->len = -1;
		free(data);
		return (0);
	}
	return (data);
}
