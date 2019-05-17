/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 09:48:19 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/12 11:17:31 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int res;
	int comt;
	int imp;

	res = 0;
	comt = 0;
	imp = 1;
	while (nb >= comt * comt + imp)
	{
		res += imp;
		comt++;
		imp += 2;
	}
	if (nb == comt * comt)
		return (comt);
	else
		return (0);
}
