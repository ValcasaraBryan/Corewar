/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:05:33 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 14:58:00 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

char	*g_tab_dump[64] =
{
	"0x0000 : ", "0x0040 : ", "0x0080 : ", "0x00c0 : ", "0x0100 : ",
	"0x0140 : ", "0x0180 : ", "0x01c0 : ", "0x0200 : ", "0x0240 : ",
	"0x0280 : ", "0x02c0 : ", "0x0300 : ", "0x0340 : ", "0x0380 : ",
	"0x03c0 : ", "0x0400 : ", "0x0440 : ", "0x0480 : ", "0x04c0 : ",
	"0x0500 : ", "0x0540 : ", "0x0580 : ", "0x05c0 : ", "0x0600 : ",
	"0x0640 : ", "0x0680 : ", "0x06c0 : ", "0x0700 : ", "0x0740 : ",
	"0x0780 : ", "0x07c0 : ", "0x0800 : ", "0x0840 : ", "0x0880 : ",
	"0x08c0 : ", "0x0900 : ", "0x0940 : ", "0x0980 : ", "0x09c0 : ",
	"0x0a00 : ", "0x0a40 : ", "0x0a80 : ", "0x0ac0 : ", "0x0b00 : ",
	"0x0b40 : ", "0x0b80 : ", "0x0bc0 : ", "0x0c00 : ", "0x0c40 : ",
	"0x0c80 : ", "0x0cc0 : ", "0x0d00 : ", "0x0d40 : ", "0x0d80 : ",
	"0x0dc0 : ", "0x0e00 : ", "0x0e40 : ", "0x0e80 : ", "0x0ec0 : ",
	"0x0f00 : ", "0x0f40 : ", "0x0f80 : ", "0x0fc0 : "
};

int		print_dump(t_storage **st)
{
	int		i;
	int		j;

	print_function_state("print_dump", "START");
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
	print_function_state("print_dump", "END");
	return (SUCCESS);
}

void	print_function_state(char *name, char *msg)
{
	if (UT_PRINT >= 2)
	{
		ft_putstr(name);
		ft_putchar(' ');
		ft_putstr(msg);
		ft_putchar('\n');
	}
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
		res[--size_max] = mod > 9 ? mod + 87 : mod + 48;
		nb = nb / 16;
	}
	while (res[++i])
		ft_putchar(res[i]);
}

int			print_usage(void)
{
	ft_putstr_fd("usage : ./corewar [-v | -dump N] [-n N] <file.cor> ...\n", 2);
	return (FAILURE);
}
