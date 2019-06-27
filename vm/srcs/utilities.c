/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:56:14 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/25 17:45:28 by jdurand-         ###   ########.fr       */
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

int		convert_to_binary(char **res, int nb)
{
	int		i;

	if (res == NULL || nb < 0 || nb > 255)
		return (BAD_PARAM);
	*res = NULL;
	if (!((*res) = malloc(sizeof(**res) * 9)))
		return (MALLOC_FAILED);
	(*res)[8] = '\0';
	i = -1;
	while (++i < 8)
		(*res)[i] = '0';
	while (nb > 0 && i >= 0)
	{
		(*res)[--i] = nb % 2 + 48;
		nb = nb / 2;
	}
	return (SUCCESS);
}

int		decrypt_op_code(int **tab, int nb)
{
	char	*res;
	int		i;

	if (tab == NULL || nb < 0 || nb > 255)
		return (BAD_PARAM);
	*tab = NULL;
	if (!((*tab) = malloc(sizeof(**tab) * 5)))
		return (MALLOC_FAILED);
	if (convert_to_binary(&res, nb) != SUCCESS)
		return (CALL_FAILED);
	i = -1;
	while (i <= 3)
	{
		(*tab)[++i] = 0;
		(*tab)[i] = res[2 * i] == '0' && res[2 * i + 1] == '1'
			? REG_CODE : (*tab)[i];
		(*tab)[i] = res[2 * i] == '1' && res[2 * i + 1] == '0'
			? DIR_CODE : (*tab)[i];
		(*tab)[i] = res[2 * i] == '1' && res[2 * i + 1] == '1'
			? IND_CODE : (*tab)[i];
	}
	free(res);
	return (SUCCESS);
}

void	print_nb_hexa(int nb)
{
	char		res[3];
	int			mod;
	int			size_max;
	int			i;

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
		nb /= 16;
	}
	while (res[++i])
		ft_putchar(res[i]);
}

int		print_dump(t_storage **st)
{
	int			i;
	int			j;

	i = -1;
	if (storage_check(st, 1) < VALID_FULL)
		return (BAD_PARAM);
	while (((*st)->grid)[++i] != 0)
	{
		j = -1;
		ft_putstr(g_tab_dump[i]);
		while (((*st)->grid)[i][++j] != -1)
		{
			print_nb_hexa(((*st)->grid)[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	return (SUCCESS);
}

int		get_size_int(int code, int size_dir)
{
	int		res;

	res = 0;
	res = code == DIR_CODE ? size_dir : res;
	res = code == IND_CODE ? 2 : res;
	res = code == REG_CODE ? 1 : res;
	return (res);
}

int		failed_action_move(t_storage **st, t_thread **th, int nb_move)
{
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL
		|| (nb_move != 1 && nb_move != 2))
		return (BAD_PARAM);
	if (thread_change_where(th, &(*st)->grid, (*th)->where + nb_move) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}