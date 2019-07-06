/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:05:33 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 09:15:23 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		print_dump(t_storage **st)
{
	int		i;
	int		j;

	i = -1;
	if (storage_check(st, 1) < VALID_FULL)
		return (BAD_PARAM);
	while (++i < GRID_SIZE)
	{
		j = -1;
		ft_putstr(g_tab_dump[i]);
		while (++j < GRID_SIZE)
		{
			print_nb_hexa(((*st)->grid)[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	return (SUCCESS);
}

void	print_nb_hexa(int nb)
{
	char	res[3];
	int		mod;
	int		size_max;
	int		i;

	if (nb < 0 || nb > 255)
		return ;
	mod = 0;
	i = -1;
	size_max = 2;
	res[2] = '\0';
	res[1] = '0';
	res[0] = '0';
	while (nb != 0 && size_max > 0)
	{
		mod = nb % 16;
		res[--size_max] = mod > 9 ? (char)(mod + 87) : (char)(mod + 48);
		nb = nb / 16;
	}
	while (res[++i])
		ft_putchar(res[i]);
}

int		print_usage(void)
{
	ft_putstr_fd("usage : ./corewar [-v | -dump N] [-n N] <file.cor> ...\n", 2);
	return (FAILURE);
}
