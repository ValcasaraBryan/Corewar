/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:38:35 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/03 16:11:51 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	puissance(long nb)
{
	long	i;
	long	val;

	i = 1;
	val = 1;
	while (i <= nb)
	{
		val *= 10;
		i++;
	}
	return (val);
}

int			ft_str_is_int(char *str)
{
	long	val;
	int		len;
	int		neg;
	int		i;

	if (!str)
		return (0);
	i = -1;
	neg = 0;
	val = 0;
	if (str[0] == '-' || str[0] == '+')
		neg++;
	if ((len = ft_strlen(str + neg)) > 10)
		return (0);
	while (++i + neg < len)
		val += (str[len - (i - neg) - 1] - 48) * puissance(i);
	val = (neg) ? val * -1 : val;
	return ((val >= INT_MIN && val <= INT_MAX) ? 1 : 0);
}
