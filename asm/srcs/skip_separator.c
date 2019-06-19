/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_separator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:43:46 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/17 15:43:49 by bryanvalcas      ###   ########.fr       */
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
			ft_printf("ENDLINE\n");
			return (0);
		}
	}
	else
	{
		ft_printf("syntax error %s\n", (*tmp)->cut);
		return (0);
	}
	return (1);
}