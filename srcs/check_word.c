/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:46:16 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/06 12:47:50 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				skip_whitespace(char *str, int val)
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

int				ft_end_word(char c)
{
	if (ft_is_whitespace(c) || c == '#' || c == CMD_CHAR)
		return (1);
	return (0);
}

static int		get_arg_two(char *str, int i, char *tmp,
				int (*fonction)(char))
{
	while (str[++i] != '\n')
	{
		if (fonction(str[i]))
			break ;
		else
		{
			tmp = ft_strndup(str, i);
			if (ft_is_label(tmp, false) == 1 && ft_is_params(tmp, direct) == -1)
				break ;
			free_line(&tmp);
		}
	}
	free_line(&tmp);
	return (i);
}

int				get_arg(char *str, int (*fonction)(char))
{
	char	*tmp;
	int		i;

	tmp = NULL;
	if (str[0] != CMD_CHAR)
	{
		i = -1;
		i = get_arg_two(str, i, tmp, fonction);
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
