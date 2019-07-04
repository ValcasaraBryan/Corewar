/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_get_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:37:21 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 14:53:59 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int	get_champion(int **args, char **str, int i)
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

static int	get_flag_with_nb(char **str, int **args, int type)
{
	int		result;
	int		num_arg;

	if (args == NULL || *args == NULL || str == NULL || *str == NULL
		|| type < 1 || type > 3)
		return (BAD_PARAM);
	if ((type == 1 || type == 2) && (result = atoi(*str)) == 0)
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
		(*args)[0] = type == 1 ? result : (*args)[0];
		(*args)[1] = type != 1 ? 1 : (*args)[1];
	}
	return (type == 1 || type == 2 ? SUCCESS_INC : SUCCESS);
}

static int	get_args_inner(int nb_lines, char ***tab, int **args, int i)
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

int				get_args(t_storage **st, int nb_lines, char ***tab)
{
	int			i;
	int			result;

	if (nb_lines < 2 || tab == NULL || *tab == NULL
		|| storage_check(st, 0) != VALID_EMPTY)
		return (print_usage());
	i = 0;
	while (++i < nb_lines)
	{
		if ((result = get_args_inner(nb_lines, tab,
			&(*st)->args, i)) == SUCCESS_INC)
			i++;
		else if (result != SUCCESS)
			return (print_usage());
	}
	if ((*st)->args[10] == 0 || (*st)->args[3] == -1
		|| ((*st)->args[4] != -1 && (*st)->args[5] == -1)
		|| ((*st)->args[6] != -1 && (*st)->args[7] == -1)
		|| ((*st)->args[8] != -1 && (*st)->args[9] == -1))
		return (print_usage());
	return (SUCCESS);
}
