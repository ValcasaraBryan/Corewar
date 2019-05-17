/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:38:35 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/13 17:00:22 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_str_is_digit(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (!(ft_isdigit(str[i])))
			return (0);
	return (i > 0 ? 1 : 0);
}
