/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:42 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/24 19:27:54 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_sti(int a, int b, int c)
{
	if (UT_PRINT == 1)
		ft_putstr("instr_sti\n");
	if (a > -1 && b > -1 && c > -1)
		return (1);
	return (0);
}