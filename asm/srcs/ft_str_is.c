/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:26:10 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/17 15:26:29 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_is_params(char *str, int (*fonction)(char))
{
	int		i;
	bool	ret;

	i = 0;
	if (!str)
		return (-1);
	ret = false;
	while (str[i])
	{
		if (fonction(str[i]))
			ret = true;
		else if (ft_is_label(str + i, true) == 1 || ft_number_ok(str + i))
			return (ret == true ? 1 : 0);
		else
			break ;
		i++;
	}
	return (-1);
}

int		ft_is_label(char *str, bool before)
{
	int		i;
	bool	already;
	bool	ret;

	i = 0;
	if (!str)
		return (-1);
	ret = false;
	already = false;
	while (str[i])
	{
		if (label_chars(str[i]) && before == false)
			ret = true;
		else if (label(str[i]) && already == false)
		{
			already = true;
			before = false;
		}
		else
			return (-1);
		i++;
	}
	return (ret == true && already == true && before == false ? 1 : 0);
}

int		ft_is_instruction(char *str, t_op **ins)
{
	int		i;
	int		len;

	i = -1;
	if (!str)
		return (0);
	len = ft_strlen(str);
	while (++i < REG_NUMBER)
		if (len == op_tab[i].len
			&& ft_strncmp(str, op_tab[i].ins, op_tab[i].len) == 0)
		{
			*ins = op_tab + i;
			return (1);
		}
	*ins = NULL;
	return (0);
}
