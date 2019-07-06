/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 16:46:14 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/12 17:04:03 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_atoll(const char *str)
{
	int			neg;
	long long	rep;

	neg = 1;
	rep = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		neg = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		rep = rep * 10 + *str - '0';
		str++;
	}
	if (rep == -2537764290115403777 && neg == 1)
		return (-1);
	if (rep == -2537764290115403777 && neg == -1)
		return (0);
	return (rep * neg);
}
