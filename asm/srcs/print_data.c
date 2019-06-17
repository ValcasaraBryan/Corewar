/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:05:57 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/17 15:05:58 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_list(t_data *data)
{
	// while (data->token)
	// {
		// ft_printf("[%s][%03d:%03d]%03d|\n", data->token->cut, data->token->n_line,
				// data->token->start, data->token->end);
		// data->token = data->token->next;
	// }
	int	i;
	while (data->ins)
	{
		ft_printf("\033[31m%02x\033[0m\t", data->ins->ins.opcode);
		i = -1;
		if (data->ins->ins.opcode != LIVE && data->ins->ins.opcode != FORK
			&& data->ins->ins.opcode != ZJMP && data->ins->ins.opcode != LFORK)
		{
			ft_printf("\033[35m%02x\033[0m\t", data->ins->octet);
		}
		else
			ft_printf("\t");
		while (++i < data->ins->ins.len_params)
		{
			if ((data->ins->ins.indirect == 0 && data->ins->codage[i] == IND_CODE)
				|| (data->ins->ins.direct == 0 && data->ins->codage[i] == DIR_CODE))
				ft_printf("\033[32m%08x\033[0m ", data->ins->params[i]);
			else if (data->ins->codage[i] == REG_CODE)
				ft_printf("\033[32m%02x\033[0m ", data->ins->params[i]);
			else
				ft_printf("\033[32m%04x\033[0m ", (unsigned short)data->ins->params[i]);
		}
		ft_printf("\n");
		data->ins = data->ins->next;
	}
	while (data->label)
	{
		ft_printf("%s | %d\n", data->label->label, data->label->index_ins);
		data->label = data->label->next;
	}
	while (data->ins_label)
	{
		ft_printf("%p\n", data->ins_label->ins);
		ft_printf("%s\n", data->ins_label->label);
		ft_printf("%d\n", data->ins_label->index_ins);
		ft_printf("%d\n", data->ins_label->index_params);
		data->ins_label = data->ins_label->next;
	}
	ft_printf("len instruction : %08x\n", data->header.prog_size);
}
