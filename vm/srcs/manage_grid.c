/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:21:48 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/20 17:43:15 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void		print_value_hexa(int value)
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
	while (value != 0 && size_max > 0)
	{
		mod = value % 16;
		res[--size_max] = mod > 9 ? mod + 55 : mod + 48;
		value /= 16;
	}
	while (res[++i])
		ft_putchar(res[i]);
}

int				**init_grid(void)
{
	int			**new_grid;
	int			*new_line;
	int 		size_grid;
	int			i;
	int			j;

	size_grid = 64;
	i = 0;
	if (!(new_grid = (int **)malloc(sizeof(int *) * (size_grid + 1))))
		return (NULL);
	while (i < size_grid)
	{
		if (!(new_line = (int *)malloc(sizeof(int) * (size_grid + 1))))
			return (NULL);
		j = 0;
		while (j < size_grid)
		{
			new_line[j] = 0;
			j++;
		}
		new_line[j] = -1;
		new_grid[i] = new_line;
		i++;
	}
	new_grid[i] = 0;
	return (new_grid);
}

void			print_grid(int ***grid)
{
	int			i;
	int			j;

	i = -1;
	while ((*grid)[++i] != 0)
	{
		j = -1;
		while ((*grid)[i][++j] != -1)
		{
			//ft_putnbr((*grid)[i][j]);
			print_value_hexa((*grid)[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
