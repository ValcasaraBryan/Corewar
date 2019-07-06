/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:01:32 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/25 22:01:34 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						change_string(t_string *list)
{
	if (binary_flag(list->tab, LENGHT_TAB))
	{
		priority_precision_largeur_sign_hashtag(list);
		priority_precision_largeur_sign_hashtag_(list);
		priority_precision_largeur(list);
		return (add_precision(list));
	}
	else
	{
		list->len = list->char_of_arg == 'p' && *list->data == '0' ? 0
			: list->len;
		return (ft_putstr_len(list->data, list->len, list->fd));
	}
}

void					priority_precision_largeur_sign_hashtag(t_string *list)
{
	list->len = (list->tab[SIGN - 1] == SIGN && *list->data == '-')
		? list->len - 1 : list->len;
	list->tab[HASHTAG - 1] = list->tab[HASHTAG - 1] == HASHTAG
	&& params(list->char_of_arg, "oO") && list->tab[POINT - 1] == 0
	&& *list->data == '0' ? 0 : list->tab[HASHTAG - 1];
	if (list->tab[HASHTAG - 1] == HASHTAG)
	{
		list->tab[POINT] = params(list->char_of_arg, "oO")
		&& list->tab[POINT - 1] == POINT ? list->tab[POINT] - 1
			: list->tab[POINT];
		list->tab[LARGEUR] = params(list->char_of_arg, "oO")
		&& list->tab[LARGEUR] > 0 ? list->tab[LARGEUR] - 1 : list->tab[LARGEUR];
		list->tab[HASHTAG - 1] = params(list->char_of_arg, "Xx")
			&& *list->data == '0' ? 0 : list->tab[HASHTAG - 1];
	}
}

void					priority_precision_largeur_sign_hashtag_(t_string *list)
{
	if (list->tab[POINT - 1] == POINT)
	{
		list->len = params(list->char_of_arg, ENT) && *list->data == '0'
			? 0 : list->len;
		list->len = params(list->char_of_arg, "sS") && list->len
			> list->tab[POINT] ? list->tab[POINT] : list->len;
		list->tab[POINT] = params(list->char_of_arg, "sS") && list->len
			< list->tab[POINT] ? list->len : list->tab[POINT];
		list->tab[POINT] = list->len > list->tab[POINT] ? list->len
			: list->tab[POINT];
	}
	list->tab[LARGEUR] = params(list->char_of_arg, "oO") == 0
		&& list->tab[HASHTAG - 1] == HASHTAG && list->tab[LARGEUR] > 0
			&& list->tab[LARGEUR] + 2 > list->len ? list->tab[LARGEUR] - 2
				: list->tab[LARGEUR];
	list->tab[LARGEUR] = (list->tab[LARGEUR] < 0) ? 0 : list->tab[LARGEUR];
}

void					priority_precision_largeur(t_string *list)
{
	if (list->tab[LARGEUR] > 0 && list->tab[POINT - 1] == 0)
		list->tab[LARGEUR] = list->tab[LARGEUR] > list->len
			? list->tab[LARGEUR] - list->len : 0;
	else if (list->tab[LARGEUR] > 0 && list->tab[POINT - 1] == POINT)
	{
		list->tab[LARGEUR] = list->tab[LARGEUR] > list->tab[POINT]
			? list->tab[LARGEUR] - list->tab[POINT] : 0;
		list->tab[POINT] = list->len < list->tab[POINT]
			? list->tab[POINT] - list->len : 0;
	}
	else if (list->tab[LARGEUR] == 0 && list->tab[POINT - 1] == POINT)
		list->tab[POINT] = list->len < list->tab[POINT]
			? list->tab[POINT] - list->len : 0;
}

int						add_precision(t_string *list)
{
	int					len_write;
	int					sign;

	sign = list->tab[SIGN - 1] == SIGN || list->tab[BLANK - 1] == BLANK ? 1 : 0;
	len_write = list->tab[LEFT - 1] == 0 && list->tab[LARGEUR] > 0
		&& list->tab[ZERO - 1] == 0 ? ft_putchar_len(' ', list->tab[LARGEUR]
			- sign, list->fd) : 0;
	len_write += ft_putchar_len(add_sign(list), sign, list->fd);
	if (list->tab[HASHTAG - 1] == HASHTAG && params(list->char_of_arg, "oO"))
		len_write += ft_putchar_fd('0', list->fd);
	if (list->tab[HASHTAG - 1] == HASHTAG && params(list->char_of_arg, "xp"))
		len_write += ft_putstr_len("0x", 2, list->fd);
	if (list->tab[HASHTAG - 1] == HASHTAG && params(list->char_of_arg, "X"))
		len_write += ft_putstr_len("0X", 2, list->fd);
	if (list->tab[LEFT - 1] == 0 && list->tab[LARGEUR] > 0
		&& list->tab[ZERO - 1] == ZERO)
		len_write += ft_putchar_len('0', list->tab[LARGEUR] - sign, list->fd);
	if (list->tab[POINT - 1] == POINT && params(list->char_of_arg, ENT))
		len_write += ft_putchar_len('0', list->tab[POINT], list->fd);
	len_write = *list->data == '-' ? len_write + ft_putstr_len(list->data + 1,
		list->len, list->fd) : len_write + ft_putstr_len(list->data,
			list->len, list->fd);
	if (list->tab[LEFT - 1] == LEFT && list->tab[LARGEUR] > 0)
		len_write += ft_putchar_len(' ', list->tab[LARGEUR] - sign, list->fd);
	return (len_write);
}
