/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:41:58 by brvalcas          #+#    #+#             */
/*   Updated: 2018/08/08 19:41:59 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(const char *format, ...)
{
	va_list				ap;
	t_string			*list;
	int					ret;
	int					i;
	unsigned int		percent;

	i = -1;
	percent = nb_percent((char *)format);
	if (percent)
	{
		va_start(ap, format);
		if (!(list = (t_string *)malloc(sizeof(t_string) * percent)))
			return (-1);
		while (++i < (int)percent)
			list[i].fd = 1;
		if ((ret = parsing(format, list, ap, percent)) == -1)
			return (ret);
		free_data(list, percent, 0, ap);
	}
	else
		return (ft_putstr_len(format, ft_strlen(format), 1));
	return (ret);
}

unsigned int			nb_percent(const char *format)
{
	int					i;
	int					j;
	int					nb_percent;

	i = -1;
	nb_percent = 0;
	if (!format)
		return (-1);
	while (format[++i])
		if (format[i] == '%')
		{
			if ((j = parsing_params((char *)format + i))
				&& format[i + j] == '%')
				i += j;
			++nb_percent;
		}
	return (nb_percent);
}

int						parsing_params(char *arg)
{
	int					i;
	int					j;
	int					x;
	int					err;

	j = 0;
	x = 0;
	err = 0;
	if (!arg)
		return (-1);
	i = p_of_params(arg);
	while (arg[i + (++j)])
	{
		if (params(arg[i + j], CONV) > 0)
			return (j);
		if (params(arg[i + j], ALL) == 0)
			return (x + 1);
		err = (params(arg[i + j], FLAG) > 0) ? err + 1 : err;
		x++;
	}
	return (err = (err > 0) ? err : 0);
}

int						params(char comp, const char *list)
{
	int					i;

	i = -1;
	while (list[++i])
		if (list[i] == comp)
			return (i + 1);
	return (0);
}

int						parsing(const char *format, t_string *list,
						va_list ap, unsigned int nb_percent)
{
	int					i_of_format;
	int					len_arg;
	char				*arg;
	int					len_write;
	int					i;

	i = 0;
	i_of_format = p_of_params((char *)format);
	len_write = (i_of_format > 0) ? ft_putstr_len(format, i_of_format,
		list->fd) : 0;
	while (nb_percent--)
	{
		reset_tab_int(list + i, LENGHT_TAB);
		len_arg = parsing_params((char *)format + i_of_format++);
		arg = ft_strndup(format + i_of_format, len_arg);
		if ((parsing_arg(arg, ap, len_arg, list + i)) == -1)
			return (free_data(list, i, -1, ap));
		i_of_format += len_arg;
		if ((retour_err(&len_write, add_arg(list + i++, ap))) == -1)
			return (free_data(list, i - 1, -1, ap));
		i_of_format = (nb_percent) ? i_of_format + inter_flag(format +
			i_of_format, &len_write, list, &len_arg) : i_of_format;
	}
	return ((format + i_of_format) ? len_write + ft_putstr_len(format +
		i_of_format, ft_strlen(format + i_of_format), list->fd) : len_write);
}
