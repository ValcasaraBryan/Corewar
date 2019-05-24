/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:07 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/24 19:27:13 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_live(int a, int b, int c)
{
	(void)b;
	(void)c;
	if (UT_PRINT == 1)
		ft_putstr("instr_live\n");
	if (a > -1)
		return (1);
	return (0);
}
