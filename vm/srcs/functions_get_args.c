/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_get_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:37:21 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/20 14:31:21 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			get_args_inner(int nb_lines, char ***tab, int **args, int i)
{
	if (ft_strcmp((*tab)[i], "-v") == 0)
		return (get_flag_with_nb(&((*tab)[i]), args, 3));
	else if (ft_strcmp((*tab)[i], "-dump") == 0)
	{
		i++;
		if (nb_lines > i)
			return (get_flag_with_nb(&((*tab)[i]), args, 1));
	}
	else if (ft_strcmp((*tab)[i], "-n") == 0)
	{
		i++;
		if (nb_lines > i)
			return (get_flag_with_nb(&((*tab)[i]), args, 2));
	}
	else
		return (get_champion(args, &((*tab)[i]), i));
	return (FAILURE);
}

int			get_champion(int **args, char **str, int i)
{
	int		j;
	int		num_arg;

	if ((*args)[10] > 3)
		return (BAD_PARAM);
	j = ft_strlen(*str);
	if (j <= 4)
		return (FAILURE);
	num_arg = (*args)[10] * 2 + 3;
	j -= 4;
	if (ft_strcmp(&((*str)[j]), ".cor") == 0)
	{
		(*args)[num_arg] = i;
		(*args)[10] += 1;
	}
	return (SUCCESS);
}

int			get_flag_with_nb(char **str, int **args, int type)
{
	int		result;
	int		num_arg;

	if (args == NULL || *args == NULL || str == NULL || *str == NULL
		|| type < 1 || type > 3)
		return (BAD_PARAM);
	if ((type == 1 || type == 2) && (result = atoi(*str)) <= 0)
		return (BAD_PARAM);
	if (type == 2)
	{
		if ((*args)[10] > 3)
			return (BAD_PARAM);
		num_arg = (*args)[10] * 2 + 2;
		(*args)[num_arg] = result;
	}
	else
	{
		if ((*args)[0] != -1 || (*args)[1] != -1 || (*args)[10] != 0)
			return (BAD_PARAM);
		if (type == 1)
			(*args)[0] = result;
		else
			(*args)[1] = 1;
	}
	return (type == 1 || type == 2 ? SUCCESS_INC : SUCCESS);
}

int			init_args(int **args)
{
	int		i;

	if (!((*args) = malloc(sizeof(int) * (11 + 1))))
		return (MALLOC_FAILED);
	i = -1;
	while (++i < 10)
		(*args)[i] = -1;
	(*args)[10] = 0;
	(*args)[11] = 0;
	return (SUCCESS);
}

int			print_error(void)
{
	ft_putstr_fd("usage : ./corewar [-v | -dump N] [-n N] <file.cor> ...\n", 2);
	return (FAILURE);
}
