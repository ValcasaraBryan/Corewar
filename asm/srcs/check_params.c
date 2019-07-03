/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:41:54 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/03 20:15:24 by brvalcas         ###   ########.fr       */
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

int		check_params(t_data *data, t_token **tmp, t_ins *ins, t_op *val)
{
	int	i;
	int	bin;
	t_label cpy;

	i = 0;
	bin = 2;
	while ((*tmp))
	{
		(*tmp)->type = add_type((*tmp)->cut, &val);
		if ((*tmp)->type == DIRECT || (*tmp)->type == DIRECT_LABEL || (*tmp)->type == REGISTER)
		{
			if (((*tmp)->type == DIRECT || (*tmp)->type == DIRECT_LABEL) && T_DIR == (T_DIR & (val->params[i])))
			{
				ins->octet += DIR_CODE;
				ins->codage[i] = DIR_CODE;
				ins->len += ins->ins.direct == 1 ? 2 : 4;
				if ((*tmp)->type == DIRECT)
					ins->params[i] = ft_atoi((*tmp)->cut + 1);
				else if ((*tmp)->type == DIRECT_LABEL)
				{
					cpy.ins = ins;
					cpy.token = cpy_token(*tmp);
					cpy.label = ft_strdup((*tmp)->cut + 2);
					cpy.len = (cpy.label) ? ft_strlen(cpy.label) : 0;
					cpy.index_ins = data->header.prog_size;
					cpy.index_params = i;
					add_label(&data->ins_label, cpy);
				}
			}
			else if ((*tmp)->type == REGISTER && T_REG == (T_REG & (val->params[i])))
			{
				if (ft_strlen((*tmp)->cut) > 3)
					return (0);
				ins->octet += REG_CODE;
				ins->codage[i] = REG_CODE;
				ins->len += 1;
				ins->params[i] = ft_atoi((*tmp)->cut + 1);
			}
			else
				return (error_params(i, (*tmp)->type, val->ins));
		}
		else if ((*tmp)->type == INDIRECT || (*tmp)->type == INDIRECT_LABEL)
		{
			if (((*tmp)->type == INDIRECT || (*tmp)->type == INDIRECT_LABEL) && T_IND == (T_IND & (val->params[i])))
			{
				ins->octet += IND_CODE;
				ins->codage[i] = IND_CODE;
				ins->len += ins->ins.indirect == 1 ? 2 : 4;
				if ((*tmp)->type == INDIRECT)
					ins->params[i] = ft_atoi((*tmp)->cut);
				else
				{
					cpy.ins = ins;
					cpy.token = cpy_token(*tmp);
					cpy.label = ft_strdup((*tmp)->cut + 1);
					cpy.len = (cpy.label) ? ft_strlen(cpy.label) : 0;
					cpy.index_ins = data->header.prog_size;
					cpy.index_params = i;
					add_label(&data->ins_label, cpy);
				}
			}
			else
				return (error_params(i, (*tmp)->type, val->ins));
		}
		else
		{
			ft_fprintf(MSG_SYN, S_ERR, (*tmp)->cut);
			return (0);
		}
		if ((*tmp)->next)
			(*tmp) = (*tmp)->next;
		else
			break ;
		if (i >= val->len_params)
			return (error_params(i, (*tmp)->type, val->ins));
		if (!(skip_separator(tmp, val, &i)))
			return (0);
		ins->octet = ins->octet << bin;
	}
	if (i < val->len_params - 1)
	{
		ft_fprintf(ERROR_COUNT, S_ERR, val->ins);
		return (0);
	}
	while (++i < 4)
		ins->octet = ins->octet << bin;
	return (1);
}
