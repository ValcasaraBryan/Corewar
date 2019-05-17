/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:46:16 by jdurand-          #+#    #+#             */
/*   Updated: 2018/06/12 17:10:38 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		multiple;

	i = 0;
	res = 0;
	multiple = str[i] == '-' ? -1 : 1;
	i = str[i] == '-' || str[i] == '+' ? i + 1 : i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = -48 + res * 10 + str[i];
		if (res < 0)
		{
			return (res == -2147483648 && multiple == -1 && (str[i + 1] == '\0'
			|| str[i + 1] == ' ') ? -2147483648 : 0);
		}
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0' && str[i] != ' ')
		return (0);
	return (multiple * res);
}
