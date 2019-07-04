/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:26:10 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/04 17:04:30 by brvalcas         ###   ########.fr       */
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
		if (len == g_op_tab[i].len
			&& ft_strncmp(str, g_op_tab[i].ins, g_op_tab[i].len) == 0)
		{
			*ins = g_op_tab + i;
			return (1);
		}
	*ins = NULL;
	return (0);
}

int		ft_is_string(char *str)
{
	int	quote;
	int	i;

	quote = (str[0] == CMD_CHAR) ? 1 : 0;
	i = (quote == 1) ? 0 : -1;
	while (str[++i])
	{
		if (str[i] == CMD_CHAR)
			quote++;
		else if ((ft_isprint(str[i]) == 0 || str[i] == LABEL_CHAR
			|| str[i] == DIRECT_CHAR) && str[i] != '\n')
			return (0);
	}
	return (quote == 2 ? 1 : 0);
}
