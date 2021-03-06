/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_separator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:43:46 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/04 18:21:37 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
