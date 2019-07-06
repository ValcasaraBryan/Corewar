/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:33:14 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/05 22:19:28 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		not_instruction(t_data *data, t_token **tmp, t_ins *ins_tmp,
				t_op *val)
{
	t_params	params;

	if (!val)
	{
		data->error.error = true;
		return (error_params_two((*tmp)->type, (*tmp)->cut));
	}
	params.i = 0;
	params.start_cut = 0;
	params.data = data;
	params.tmp = tmp;
	params.ins = ins_tmp;
	params.val = val;
	if (!(check_params(params)))
	{
		data->error.error = true;
		return (0);
	}
	data->header.prog_size += ins_tmp->len;
	return (1);
}

static int		is_instruction(t_data *data, t_token *tmp, t_ins **ins_tmp,
				t_op *val)
{
	int		type;

	type = tmp->type;
	if (type == INSTRUCTION && val)
	{
		*ins_tmp = add_instruction(&data->ins, *val);
		(*ins_tmp)->len += ((*ins_tmp)->ins.opcode == LIVE
			|| (*ins_tmp)->ins.opcode == FORK || (*ins_tmp)->ins.opcode == ZJMP
				|| (*ins_tmp)->ins.opcode == LFORK) ? 1 : 2;
	}
	else if (type == LABEL)
		add_n_label(&data->label, ft_strcut(tmp->cut, 0, tmp->end - 1),
			data->header.prog_size);
	return (1);
}

static int		token(t_data *data, t_token **tmp, t_ins **ins_tmp, t_op *val)
{
	if (((*tmp)->type == NAME && !data->name) || ((*tmp)->type == COMMENT && !data->comment))
	{
		if (!(add_quote(data, tmp)))
		{
			data->error.error = true;
			return (0);
		}
	}
	else if (data->name && data->comment && (*tmp)->type > 0)
	{
		if ((*tmp)->type == INSTRUCTION || ((*tmp)->type == LABEL && !val))
			return (is_instruction(data, (*tmp), ins_tmp, val));
		else
		{
			if (!(not_instruction(data, tmp, (*ins_tmp), val)))
				return (0);
		}
	}
	else
	{
		if ((*tmp)->type)
			error_params_two((*tmp)->type, (*tmp)->cut);
		else
			ft_fprintf(MSG_SYN, S_ERR, (*tmp)->cut);
		data->error.error = true;
		return (0);
	}
	return (1);
}

int				check_token(t_data *data)
{
	t_op	*val;
	t_ins	*ins_tmp;
	t_token	*tmp;

	if (!data->token)
		return (1);
	tmp = data->token;
	val = NULL;
	ins_tmp = NULL;
	while (tmp)
	{
		tmp->type = add_type(tmp->cut, &val);
		if (!(token(data, &tmp, &ins_tmp, val)))
			return (0);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	if (!(error_no_ins(data, ins_tmp)))
		return (0);
	return (1);
}
