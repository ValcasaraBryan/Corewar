/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:07:15 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/16 23:07:26 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		separator(char c)
{
	if (c == SEPARATOR_CHAR)
		return (1);
	return (0);
}

int		label_chars(char c)
{
	if (params(c, LABEL_CHARS))
		return (1);
	return (0);
}

int		direct(char c)
{
	if (c == DIRECT_CHAR)
		return (1);
	return (0);
}

int		registre(char c)
{
	if (c == 'r')
		return (1);
	return (0);
}

int		label(char c)
{
	if (c == LABEL_CHAR)
		return (1);
	return (0);
}
