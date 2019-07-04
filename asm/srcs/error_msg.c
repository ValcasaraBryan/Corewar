/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:47:46 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/04 14:48:16 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		error_params(int index, int type, char *ins)
{
	char	*type_string;

	type_string = NULL;
	if (type == DIRECT_LABEL || type == DIRECT)
		type_string = DIRECT_MSG;
	else if (type == INDIRECT_LABEL || type == INDIRECT)
		type_string = INDIRECT_MSG;
	else if (type == REGISTER)
		type_string = REGISTER_MSG;
	else if (type == INSTRUCTION)
		type_string = INSTRUCTION_MSG;
	ft_fprintf(BAD_PARAMS, S_ERR, index, type_string, ins);
	return (0);
}

int		error_params_two(int type, char *ins)
{
	char	*type_string;

	type_string = NULL;
	if (type == DIRECT)
		type_string = MSG_DIRECT;
	else if (type == DIRECT_LABEL)
		type_string = MSG_DIRECT_LABEL;
	else if (type == INDIRECT)
		type_string = MSG_INDIRECT;
	else if (type == INDIRECT_LABEL)
		type_string = MSG_INDIRECT_LABEL;
	else if (type == REGISTER)
		type_string = MSG_REGISTER;
	else if (type == INSTRUCTION)
		type_string = MSG_INSTRUCTION;
	else if (type == SEPARATOR)
		type_string = MSG_SEPARATEUR;
	ft_fprintf(MSG_SYN_TYPE, S_ERR, type_string, ins);
	return (0);
}
