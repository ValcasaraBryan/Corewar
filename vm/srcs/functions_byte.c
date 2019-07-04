/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:18:17 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 14:27:34 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		byte_change_value(t_byte **bt, int new_value)
{
	if (byte_check(bt) != VALID_FULL || new_value < 0 || new_value > 255)
		return (BAD_PARAM);
	(*bt)->value = new_value;
	return (SUCCESS);
}
