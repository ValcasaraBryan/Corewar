/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:56:14 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/12 10:57:36 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

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
	if (!((*tab) = malloc(sizeof(**tab) * 4)))
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
