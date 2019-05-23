/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_storage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 18:07:17 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/23 18:08:42 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		storage_check_champion(t_storage **st)
{
	if (st != NULL && *st != NULL)
	{
		if ((*st)->first_champion != NULL && (*st)->last_champion != NULL)
			return (1);
		return (0);
	}
	return (-1);
}

int		storage_check_grid(t_storage **st)
{
	if (st != NULL && *st != NULL)
	{
		if ((*st)->grid != NULL)
			return (1);
		return (0);
	}
	return (-1);
}

int		storage_check_thread(t_storage **st)
{
	if (st != NULL && *st != NULL)
	{
		if ((*st)->first_thread != NULL && (*st)->last_thread != NULL)
			return (1);
		return (0);
	}
	return (-1);
}