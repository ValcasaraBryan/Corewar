/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:18:17 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/29 15:26:02 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		byte_change_value(t_byte **bt, int new_value)
{
	if (byte_check(bt) == 1)
	{
		if (new_value >= 0 && new_value <= 255)
		{
			(*bt)->value = new_value;
			if ((*bt)->value >= 0)
				return (1);
		}
		return (0);
	}
	return (-1);
}

int		byte_check(t_byte **bt)
{
	if (bt != NULL && *bt != NULL)
		return (1);
	return (-1);
}