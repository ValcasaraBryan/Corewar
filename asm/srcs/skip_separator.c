/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_separator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:43:46 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/04 14:04:50 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int		skip_separator(t_token **tmp, t_op *val, int *i)
{
	if (!(*tmp))
		return (1);
	(*tmp)->type = add_type((*tmp)->cut, &val);
	if ((*tmp)->type == SEPARATOR)
	{
		(*i)++;
		if ((*tmp)->next)
			(*tmp) = (*tmp)->next;
		else
		{
			ft_fprintf(MSG_SYN, S_ERR, TOKEN_ENDLINE);
			return (0);
		}
	}
	else
		return (error_params_two((*tmp)->type, (*tmp)->cut));
	return (1);
}
