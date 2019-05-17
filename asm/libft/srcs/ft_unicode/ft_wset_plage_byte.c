/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wset_plage_byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:51:33 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:51:34 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_wset_plage_byte(int len)
{
	if (len == -1)
		return (-1);
	else if (len >= 0 && len < 8)
		return (1);
	else if (len >= 8 && len <= 11 && MB_CUR_MAX != 1)
		return (2);
	else if (len > 8 && MB_CUR_MAX == 1)
		return (-1);
	else if (MB_CUR_MAX == 1)
		return (1);
	else if (len >= 12 && len <= 16)
		return (3);
	else if (len >= 17 && len <= 21)
		return (4);
	else
		return (-1);
}
