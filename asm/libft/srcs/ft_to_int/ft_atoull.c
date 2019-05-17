/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:22:53 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:22:56 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_atoull(const char *str)
{
	unsigned long long	rep;

	rep = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		rep = rep * 10 + *str - '0';
		str++;
	}
	return (rep);
}
