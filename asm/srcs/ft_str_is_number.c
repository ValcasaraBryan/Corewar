/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:27:31 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/17 15:27:33 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_str_is_number(char *str)
{
	int		neg;

	if (!str)
		return (0);
	neg = 0;
	if (str[neg] == '-' || str[neg] == '+')
		neg++;
	if (ft_str_is_digit(str + neg))
		return (1);
	else
		return (0);
}

int			ft_number_ok(char *str)
{
	if (ft_str_is_number(str) && ft_str_is_int(str))
		return (1);
	else
		return (0);
}