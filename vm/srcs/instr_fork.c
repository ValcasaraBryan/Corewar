/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:08:19 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/31 15:05:13 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_fork(t_thread **th, int ***gr)
{
	(void)th;
	(void)gr;
	if (UT_PRINT >= 1)
		ft_putstr("instr_fork\n");
	return (0);
}
