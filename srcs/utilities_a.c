/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 15:56:14 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 09:16:02 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			convert_to_binary(char **res, int nb)
{
	int		i;

	if (res == NULL || nb < 0 || nb > 255)
		return (BAD_PARAM);
	*res = NULL;
	if (!((*res) = malloc(sizeof(**res) * 9)))
		return (MALLOC_FAILED);
	ft_bzero((*res), sizeof(**res) * 9);
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

int			decrypt_op_code(int **tab, int nb)
{
	char	*res;
	int		i;

	if (tab == NULL || nb < 0 || nb > 255)
		return (BAD_PARAM);
	*tab = NULL;
	if (!((*tab) = malloc(sizeof(**tab) * 5)))
		return (MALLOC_FAILED);
	ft_bzero((*tab), sizeof(**tab) * 5);
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

int			get_size_int(int code, int size_dir)
{
	int		res;

	res = 0;
	res = code == DIR_CODE ? size_dir : res;
	res = code == IND_CODE ? 2 : res;
	res = code == REG_CODE ? 1 : res;
	return (res);
}

int			failed_action_move(t_storage **st, t_thread **th, int nb_move)
{
	if (thread_check(th) < VALID_EMPTY || storage_check(st, 1) != VALID_FULL
		|| (nb_move < 1 || nb_move > 3))
		return (BAD_PARAM);
	if (thread_change_where(th, &(*st)->grid,
		(*th)->pc + nb_move) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}

int			check_reg(int reg)
{
	if (reg <= 0 || reg > REG_NUMBER)
		return (BAD_PARAM);
	return (SUCCESS);
}
