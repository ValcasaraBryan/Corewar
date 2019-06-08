/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:56:14 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/08 18:58:14 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		convert_to_binary(char **res, int nb)
{
	int		i;

	if (res != NULL && nb >= 0 && nb <= 255)
	{
		*res = NULL;
		if (!((*res) = malloc(sizeof(**res) * 9)))
			return (-1);
		(*res)[8] = '\0';
		i = -1;
		while (++i < 8)
			(*res)[i] = '0';
		while (nb > 0 && i >= 0)
		{
			(*res)[--i] = nb % 2 + 48;
			nb = nb / 2;
		}
		return (1);
	}
	return (0);
}

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
