/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_lfork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:08:57 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/24 19:27:10 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_lfork(int a, int b, int c)
{
	(void)b;
	(void)c;
	if (UT_PRINT == 1)
		ft_putstr("instr_lfork\n");
	if (a > -1)
		return (1);
	return (0);
}
