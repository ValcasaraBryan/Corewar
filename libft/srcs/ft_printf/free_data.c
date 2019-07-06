/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:24:01 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/19 14:24:06 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						free_data(t_string *list, unsigned int nb_percent,
						int ret, va_list ap)
{
	while (nb_percent--)
		if (params(list[nb_percent].char_of_arg, NO_C))
			free(list[nb_percent].data);
	if (list)
		free(list);
	va_end(ap);
	return (ret);
}

int						print_zero_space_char(t_string *list, int octet)
{
	if (list->tab[LARGEUR] > 0 && list->tab[ZERO - 1] == ZERO)
		return (ft_putchar_len('0', list->tab[LARGEUR] - octet, list->fd));
	else if (list->tab[LARGEUR] > 0 && list->tab[ZERO - 1] == 0)
		return (ft_putchar_len(' ', list->tab[LARGEUR] - octet, list->fd));
	else
		return (0);
}

int						retour_err(int *len_write, int f)
{
	int					read;

	read = *len_write;
	if (f == -1)
		return (-1);
	read += f;
	*len_write = read;
	return (f);
}

char					add_sign(t_string *list)
{
	char				c;

	c = 0;
	if (list->tab[SIGN - 1] == SIGN)
	{
		if (*list->data == '-')
			c = '-';
		else
			c = '+';
	}
	else if (list->tab[BLANK - 1] == BLANK)
		c = ' ';
	return (c);
}

int						ft_fprintf(const char *format, int fd, ...)
{
	va_list				ap;
	t_string			*list;
	int					ret;
	int					i;
	unsigned int		percent;

	i = 0;
	percent = nb_percent((char *)format);
	if (percent)
	{
		va_start(ap, fd);
		if (!(list = (t_string *)malloc(sizeof(t_string) * percent)))
			return (-1);
		while (i < (int)percent)
			list[i++].fd = fd;
		if ((ret = parsing(format, list, ap, percent)) == -1)
			return (ret);
		free_data(list, percent, 0, ap);
	}
	else
		return (ft_putstr_len(format, ft_strlen(format), fd));
	return (ret);
}
