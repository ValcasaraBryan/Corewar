/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:17:58 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:17:59 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					flag_optional(char *arg, int len, t_string *list)
{
	int				i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '-')
			list->tab[LEFT - 1] = LEFT;
		if (arg[i] == '0'
			&& ((i - 1 >= 0) ? arg[i - 1] != '.' : 1))
			list->tab[ZERO - 1] = ZERO;
		if (arg[i] == ' ')
			list->tab[BLANK - 1] = BLANK;
		if (arg[i] == '+')
			list->tab[SIGN - 1] = SIGN;
		if (arg[i] == '#' && params(arg[len], UNSIGNED_))
			list->tab[HASHTAG - 1] = HASHTAG;
		if (arg[i] == 'j')
			list->tab[J_FLAG - 1] = J_FLAG;
		i = largeur_of_camp(arg, list, i);
		i = flag_optional_suit(arg, list, i);
	}
}

int						largeur_of_camp(char *arg, t_string *list, int i)
{
	char	*str;

	str = NULL;
	if (list->tab[LARGEUR] == 0)
	{
		if (arg[i] >= '1' && arg[i] <= '9'
			&& ((i - 1 >= 0) ? arg[i - 1] != '.' : 1))
		{
			list->tab[LARGEUR] = ft_atoll(arg + i);
			str = ft_lltoa(list->tab[LARGEUR]);
			i += ft_strlen(str) - 1;
			free(str);
		}
	}
	if (list->tab[POINT - 1] == 0)
		if (arg[i] == '.')
		{
			list->tab[POINT - 1] = POINT;
			list->tab[POINT] = ft_atoll(arg + i + 1);
			str = ft_lltoa(list->tab[POINT]);
			i += ft_strlen(str);
			free(str);
		}
	return (i);
}

int						flag_optional_suit(char *arg, t_string *list, int i)
{
	if (arg[i] == 'z')
		list->tab[Z_FLAG - 1] = Z_FLAG;
	if (arg[i] == 'l' && list->tab[INT_LONG - 1] == 0
		&& list->tab[INT_LONG_LONG - 1] == 0)
	{
		if (arg[i] == 'l' && arg[i + 1] == 'l')
		{
			list->tab[INT_LONG_LONG - 1] = INT_LONG_LONG;
			i++;
		}
		else
			list->tab[INT_LONG - 1] = INT_LONG;
	}
	if (arg[i] == 'h' && list->tab[INT_SHORT - 1] == 0
		&& list->tab[INT_SHORT_SHORT - 1] == 0)
	{
		if (arg[i] == 'h' && arg[i + 1] == 'h')
		{
			list->tab[INT_SHORT_SHORT - 1] = INT_SHORT_SHORT;
			i++;
		}
		else
			list->tab[INT_SHORT - 1] = INT_SHORT;
	}
	return (i);
}

int						list_add_conversion(char *string, t_string *list)
{
	if (!list && list->len == -1)
		return (-1);
	if (string)
	{
		list->data = string;
		list->len = ft_strlen(string);
	}
	else
	{
		list->data = ft_strdup("(null)");
		list->len = 6;
	}
	return (list->len);
}

int						binary_flag(int *tab, int len)
{
	int					i;
	int					j;

	i = -1;
	j = 0;
	if (!tab)
		return (0);
	while (++i < len)
		if (tab[i] > 0)
			++j;
	return (j);
}
