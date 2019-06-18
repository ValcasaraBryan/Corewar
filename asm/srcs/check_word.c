/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:46:16 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/18 14:21:58 by brvalcas         ###   ########.fr       */
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
