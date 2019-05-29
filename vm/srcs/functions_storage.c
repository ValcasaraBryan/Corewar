/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_storage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:07:17 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/29 16:17:14 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		storage_check(t_storage **st, int type)
{
	if (st != NULL && *st != NULL)
	{
		if (type == 0)
		{
			if ((*st)->first_champion != NULL && (*st)->last_champion != NULL)
				return (1);
			return (0);
		}
		else if (type == 1)
		{
			if ((*st)->grid != NULL)
				return (1);
			return (0);
		}
		else if (type == 2)
		{
			if ((*st)->first_thread != NULL && (*st)->last_thread != NULL)
				return (1);
			return (0);
		}
		return (-2);
	}
	return (-1);
}
