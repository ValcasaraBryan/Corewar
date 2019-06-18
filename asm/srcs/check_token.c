/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:33:14 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/18 15:46:43 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*into_quote(char *str)
{
	int		i;
	int		j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == CMD_CHAR)
			break ;
	}
}

int			add_quote(t_data *data, t_token *token)
{
	char	*tmp;

	if (token->type == NAME)
	{
		data->len = PROG_NAME_LENGTH;
		tmp = (char *)data->header.prog_name;
	}
	else if (token->type == COMMENT)
	{
		data->len = COMMENT_LENGTH;
		tmp = (char *)data->header.comment;
	}
	if (token->next)
		token = token->next;
	else
		return (0);
	if (tmp)
	{
		ft_printf("%s\n", token->cut);
	}
	return (1);
}
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
		else if (tmp->type == NAME || tmp->type == COMMENT)
		{
			// ft_printf("%s %d\n", data->line.line, tmp->type);
			if (!(add_quote(data, tmp)))
				return (0);
		}
		else
		{
			if (!val || !(check_params(data, &tmp, ins_tmp, val)))
			{
				// ft_printf("error check_params %p | %s | %d\n", val, tmp->cut, tmp->type);
				return (0);
			}
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
