/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:18:53 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:18:55 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						p_of_params(char *format)
{
	int					i;

	i = -1;
	if (!format)
		return (-1);
	while (format[++i])
		if (format[i] == '%')
			return (i);
	return (-1);
}

int						parsing_arg(char *argument, va_list ap, int len,
						t_string *list)
{
	if (len > 0)
	{
		flag_optional(argument, len - 1, list);
		list->char_of_arg = argument[len - 1];
	}
	else
	{
		flag_optional(argument, len, list);
		list->char_of_arg = argument[len];
	}
	if (argument)
		free(argument);
	if (init_list(ap, list->char_of_arg, list) == -1)
		return (-1);
	if (list->tab[LEFT - 1] == LEFT || (list->tab[POINT - 1] == POINT
		&& params(list->char_of_arg, ENT)))
		list->tab[ZERO - 1] = 0;
	if (*list->data == '-')
		list->tab[SIGN - 1] = SIGN;
	if (list->tab[SIGN - 1] == SIGN)
		list->tab[BLANK - 1] = 0;
	return (list->len);
}

int						init_list(va_list ap, char c, t_string *list)
{
	list->tab[INT_LONG - 1] = (c == 'D' || c == 'O' || c == 'U' ||
		c == 'C' || c == 'F') ? INT_LONG : list->tab[INT_LONG - 1];
	c = (c == 'D' || c == 'O' || c == 'U' || c == 'F') ? c + 32 : c;
	if (c == 's' && list->tab[INT_LONG - 1] == 0)
		return (list_add_conversion(string_s(ap), list));
	else if (c == 'S' || (c == 's' && list->tab[INT_LONG - 1] == INT_LONG))
		return (list_add_conversion(string_unix(ap, list), list));
	else if (c == 'd' || c == 'i')
		return (list_add_conversion(flag_int_sign(*list, ap), list));
	else if (c == 'f')
	{
		list->tab[POINT] = (list->tab[POINT - 1] == 0) ? 6 : list->tab[POINT];
		return (list_add_conversion(conv_float(ap, list->tab[POINT]), list));
	}
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'p')
		return (unsigned_value(ap, c, list));
	else
		return (list_add_conversion("", list));
}

int						add_arg(t_string *list, va_list ap)
{
	if (params(list->char_of_arg, NO_C))
	{
		if (params(list->char_of_arg, ENT) == 0
			|| params(list->char_of_arg, UNSIGNED_))
		{
			list->tab[BLANK - 1] = 0;
			list->tab[SIGN - 1] = 0;
		}
		return (change_string(list));
	}
	if ((list->char_of_arg == 'c' && list->tab[INT_LONG - 1] == INT_LONG)
		|| list->char_of_arg == 'C')
		return (option_char(list, conv_long_c(ap)));
	else if (list->char_of_arg == 'c')
		return (option_char(list, (unsigned char)conv_c(ap)));
	else if (ft_isprint(list->char_of_arg))
		return (option_char(list, list->char_of_arg));
	return (0);
}

int						inter_flag(const char *format, int *len_write,
						t_string *list, int *len_arg)
{
	int				i;
	int				j;

	i = *len_arg;
	j = *len_write;
	i = p_of_params((char *)format);
	j += ft_putstr_len(format, i, list->fd);
	*len_arg = i;
	*len_write = j;
	return (i);
}
