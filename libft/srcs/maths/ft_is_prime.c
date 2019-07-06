/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:18:34 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/12 18:24:07 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(int nb)
{
	int index;

	index = 2;
	if (nb <= 1)
		return (0);
	while (index < nb)
	{
		if (0 == nb % index)
			return (0);
		index++;
	}
	return (1);
}
