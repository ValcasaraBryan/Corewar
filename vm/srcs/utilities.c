/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:56:14 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/21 15:56:45 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	print_nb_hexa(int nb)
{
	char		res[3];
	int			mod;
	int			size_max;
	int			i;

	mod = 0;
	i = -1;
	size_max = 2;
	res[2] = '\0';
	res[1] = '0';
	res[0] = '0';
	while (nb != 0 && size_max > 0)
	{
		mod = nb % 16;
		res[--size_max] = mod > 9 ? mod + 55 : mod + 48;
		nb /= 16;
	}
	while (res[++i])
		ft_putchar(res[i]);
}