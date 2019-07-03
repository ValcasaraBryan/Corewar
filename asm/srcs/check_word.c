/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:46:16 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/03 13:34:31 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		skip_whitespace(char *str, int val)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] != '\n')
		if (ft_is_whitespace(str[i]) == val)
			break ;
	return (i);
}

int		ft_end_word(char c)
{
	if (ft_is_whitespace(c) || c == '#')
		return (1);
	return (0);
}

int		get_arg(char *str, int (*fonction)(char))
{
	int	i;

	if (str[0] != CMD_CHAR)
	{
		i = -1;
		while (str[++i] != '\n')
			if (fonction(str[i]))
				break ;

		// ft_printf("%s - %d\n", str, i);
	}
	else
	{
		i = 0;
		while (str[++i])
		{
			if (str[i] == CMD_CHAR)
				return (i + 1);
		}
	}
	return (i);
}