/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_xor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:09:57 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/24 19:28:05 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		instr_xor(int a, int b, int c)
{
	if (UT_PRINT == 1)
		ft_putstr("instr_xor\n");
	if (a > -1 && b > -1 && c > -1)
		return (1);
	return (0);
}