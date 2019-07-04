/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:37:32 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/04 16:16:58 by brvalcas         ###   ########.fr       */
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
	else if (ft_strncmp(str, NAME_CMD_STRING, 5) == 0)
		return (NAME);
	else if (ft_strncmp(str, COMMENT_CMD_STRING, 8) == 0)
		return (COMMENT);
	else if (ft_is_string(str))
		return (STRING);
	else
		return (0);
}
