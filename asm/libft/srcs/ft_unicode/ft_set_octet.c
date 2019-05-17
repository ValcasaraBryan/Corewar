/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_octet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:51:45 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:51:46 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long				ft_set_octet(int octet)
{
	long			multiple;
	long			multi_byte;
	long			mask;
	int				i;

	i = 0;
	if (octet <= 0)
		return (-1);
	multi_byte = 1;
	multiple = 8 * octet - 1;
	while (multiple > i++)
		multi_byte *= 2;
	mask = multi_byte;
	i = 0;
	while (i++ < octet - 1)
		mask += multi_byte >> i;
	i = 0;
	while (i++ <= octet)
		mask += multi_byte >> (8 * i);
	return (mask);
}
