/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:37:32 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/17 15:37:35 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		add_type(char *str, t_op **val)
{
	if (ft_is_label(str, false) == 1 && ft_is_params(str, direct) == -1)
		return (LABEL);
	else if (ft_is_label(str, true) == 1 && ft_is_params(str, direct) == 0)
		return (INDIRECT_LABEL);
	else if (ft_is_label(str + 1, true) == 1 && ft_is_params(str, direct) == 1)
		return (DIRECT_LABEL);
	else if (ft_is_params(str, registre) == 1)
		return (REGISTER);
	else if (ft_is_params(str, direct) == 0)
		return (INDIRECT);
	else if (ft_is_params(str, direct) == 1)
		return (DIRECT);
	else if (str && separator(*str) == 1)
		return (SEPARATOR);
	else if (ft_is_instruction(str, val) == 1)
		return (INSTRUCTION);
	else if (ft_is_label(str, false) == -1)
		return (0);
	else
		return (INSTRUCTION);
}