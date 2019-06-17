/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:33:14 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/17 20:14:33 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_token(t_data *data)
{
	t_op	*val;
	int		type;
	t_ins	*ins_tmp;
	t_token	*tmp;

	if (!data->token)
		return (1);
	tmp = data->token;
	val = NULL;
	while (tmp)
	{
		tmp->type = add_type(tmp->cut, &val);
		if (tmp->type == INSTRUCTION || (tmp->type == LABEL && !val))
		{
			type = tmp->type;
			if (type == INSTRUCTION && val)
			{
				ins_tmp = add_instruction(&data->ins, *val);
				ins_tmp->len += (ins_tmp->ins.opcode == LIVE || ins_tmp->ins.opcode == FORK
				|| ins_tmp->ins.opcode == ZJMP || ins_tmp->ins.opcode == LFORK) ? 1 : 2;
			}
			else if (type == LABEL)
				add_n_label(&data->label, ft_strcut(tmp->cut, 0, tmp->end - 1), data->header.prog_size);
		}
		else
		{
			if (!val || !(check_params(data, &tmp, ins_tmp, val)))
				return (0);
			data->header.prog_size += ins_tmp->len;
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	if (tmp->type == INSTRUCTION)
		return (0);
	return (1);
}
