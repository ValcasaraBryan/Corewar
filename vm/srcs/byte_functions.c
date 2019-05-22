/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:18:17 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 16:21:37 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		byte_change_value(t_byte **bt, int new_value)
{
	int		result;

	result = check_byte(bt);
	if (result == 1)
	{
		(*bt)->value = new_value;
		if ((*bt)->value >= 0)
			return (1);
	}
	return (0);
}
