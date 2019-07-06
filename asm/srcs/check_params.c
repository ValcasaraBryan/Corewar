/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:41:54 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/06 11:57:29 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		params_token(t_params p, int code, int type)
{
	p.ins->octet += code;
	p.ins->codage[p.i] = code;
	if ((*p.tmp)->type == type)
		p.ins->params[p.i] = ft_atoi((*p.tmp)->cut + p.start_cut);
	else
	{
		p.cpy.ins = p.ins;
		p.cpy.token = cpy_token(*p.tmp);
		if (!(p.cpy.label = ft_strdup((*p.tmp)->cut + 1 + p.start_cut)))
			return (0);
		p.cpy.len = (p.cpy.label) ? ft_strlen(p.cpy.label) : 0;
		p.cpy.index_ins = p.data->header.prog_size;
		p.cpy.index_params = p.i;
		add_label(&p.data->ins_label, p.cpy);
	}
	return (1);
}

static int		params_direct_register(t_params p)
{
	if (((*p.tmp)->type == DIRECT || (*p.tmp)->type == DIRECT_LABEL)
		&& T_DIR == (T_DIR & (p.val->params[p.i])))
	{
		p.start_cut = 1;
		p.ins->len += p.ins->ins.direct == 1 ? 2 : 4;
		if (!(params_token(p, DIR_CODE, DIRECT)))
			return (error_malloc());
	}
	else if ((*p.tmp)->type == REGISTER
		&& T_REG == (T_REG & (p.val->params[p.i])))
	{
		if (ft_strlen((*p.tmp)->cut) > 3)
		{
			ft_fprintf(MSG_SYN, S_ERR, (*p.tmp)->cut);
			return (0);
		}
		p.ins->octet += REG_CODE;
		p.ins->codage[p.i] = REG_CODE;
		p.ins->len += 1;
		p.ins->params[p.i] = ft_atoi((*p.tmp)->cut + 1);
	}
	else
		return (error_params(p.i, (*p.tmp)->type, p.val->ins));
	return (1);
}

static int		params_indirect(t_params p)
{
	if (((*p.tmp)->type == INDIRECT || (*p.tmp)->type == INDIRECT_LABEL)
		&& T_IND == (T_IND & (p.val->params[p.i])))
	{
		p.start_cut = 0;
		p.ins->len += p.ins->ins.indirect == 1 ? 2 : 4;
		if (!(params_token(p, IND_CODE, INDIRECT)))
			return (error_malloc());
	}
	else
		return (error_params(p.i, (*p.tmp)->type, p.val->ins));
	return (1);
}

static int		check_params_direct_indirect_register(t_params p)
{
	if ((*p.tmp)->type == DIRECT || (*p.tmp)->type == DIRECT_LABEL
		|| (*p.tmp)->type == REGISTER)
		return (params_direct_register(p));
	else if ((*p.tmp)->type == INDIRECT || (*p.tmp)->type == INDIRECT_LABEL)
		return (params_indirect(p));
	else
	{
		ft_fprintf(MSG_SYN, S_ERR, (*p.tmp)->cut);
		return (0);
	}
}

int				check_params(t_params p)
{
	int	bin;

	bin = 2;
	while ((*p.tmp))
	{
		(*p.tmp)->type = add_type((*p.tmp)->cut, &p.val);
		if (!(check_params_direct_indirect_register(p)))
			return (0);
		if (p.i >= p.val->len_params)
			return (error_params(p.i, (*p.tmp)->type, p.val->ins));
		if ((*p.tmp)->next)
			(*p.tmp) = (*p.tmp)->next;
		else
			break ;
		if (!(skip_separator(p.tmp, p.val, &p.i)))
			return (0);
		p.ins->octet = p.ins->octet << bin;
	}
	if (!(error_count(p)))
		return (0);
	while (++p.i < 4)
		p.ins->octet = p.ins->octet << bin;
	return (1);
}
