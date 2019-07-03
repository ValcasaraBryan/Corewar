/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:41:54 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/03 14:12:30 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
        // ft_printf("%s | %s | %d / %d\n", (*tmp)->cut, data->line.line, (*tmp)->type, val->params[i]);
		if ((*tmp)->type == DIRECT || (*tmp)->type == DIRECT_LABEL || (*tmp)->type == REGISTER)
		{
			if (((*tmp)->type == DIRECT || (*tmp)->type == DIRECT_LABEL) && T_DIR == (T_DIR & (val->params[i])))
			{
                // ft_printf("ceci est un direct %s | %d\n", (*tmp)->cut, (T_DIR & (val->params[i])));
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
                // ft_printf("ceci est un registre %s\n", (*tmp)->cut);
				if (ft_strlen((*tmp)->cut) > 3)
					return (0);
				ins->octet += REG_CODE;
				ins->codage[i] = REG_CODE;
				ins->len += 1;
				ins->params[i] = ft_atoi((*tmp)->cut + 1);
			}
			else
			{
				if ((*tmp)->type == DIRECT_LABEL && T_DIR == (T_DIR & (val->params[i])))
					ft_fprintf(MSG_LABEL, S_ERR, (*tmp)->cut);
				else if (T_DIR == (T_DIR & (val->params[i])))
					ft_fprintf(ERROR_PARAMS, S_ERR, i, val->ins, (*tmp)->cut);
				return (0); // type d'argument non valide
			}
		}
		else if ((*tmp)->type == INDIRECT || (*tmp)->type == INDIRECT_LABEL)
		{
			// ft_printf("%d - %d - %d | i = %d\n", T_IND, (val->params[i]), (T_IND & (val->params[i])), i);
			if (((*tmp)->type == INDIRECT || (*tmp)->type == INDIRECT_LABEL) && T_IND == (T_IND & (val->params[i])))
			{
                // ft_printf("ceci est un indirect %s\n", (*tmp)->cut);
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
			{
				if ((*tmp)->type == INDIRECT_LABEL && T_IND == (T_IND & (val->params[i])))
					ft_fprintf(MSG_LABEL, S_ERR, (*tmp)->cut);
				else if (T_IND != (T_IND & (val->params[i])))
					ft_fprintf(ERROR_PARAMS, S_ERR, i, val->ins, (*tmp)->cut);
				return (0); // type d'argument non valide
			}
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
		if (!(skip_separator(tmp, val, &i)))
			return (0);
		if (i >= val->len_params)
		{
			ft_fprintf(ERROR_PARAMS, S_ERR, i, val->ins, (*tmp)->cut);
			return (0);
		}
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
