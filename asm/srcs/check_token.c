/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:33:14 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/03 20:20:36 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*into_quote(char *str)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] == CMD_CHAR)
		{
			i++;
			break ;
		}
	}
	while (str[i + ++j])
	{
		if (str[i + j] == CMD_CHAR)
		{
			j++;
			break ;
		}
	}
	if (i == j)
		return (ft_strdup(""));
	else if (i < j)
		return (ft_strcut(str, i, j));
	else
		return (NULL);
}

int			add_quote(t_data *data, t_token **token)
{
	char	*tmp;
	char	*string;

	if ((*token)->type == NAME)
	{
		data->len = PROG_NAME_LENGTH;
		tmp = (char *)data->header.prog_name;
	}
	else if ((*token)->type == COMMENT)
	{
		data->len = COMMENT_LENGTH;
		tmp = (char *)data->header.comment;
	}
	if ((*token)->next)
	{
		data->name = ((*token)->type == NAME) ? true : data->name;
		data->comment = ((*token)->type == COMMENT) ? true : data->comment;
		(*token) = (*token)->next;
	}
	else
		return (0);
	if (!(string = into_quote((*token)->cut)))
		return (0);
	ft_strcpy(tmp, string);
	free(string);
	string = NULL;
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
		if (tmp->type == NAME || tmp->type == COMMENT)
		{
			if (!(add_quote(data, &tmp)))
			{
				data->error.error = true;
				return (0);
			}
		}
		else if (data->name && data->comment && tmp->type > 0)
		{
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
				if (!val)
				{
					data->error.error = true;
					return (error_params_two(tmp->type, tmp->cut));
				}
				if (!(check_params(data, &tmp, ins_tmp, val)))
				{
					data->error.error = true;
					return (0);
				}
				data->header.prog_size += ins_tmp->len;
			}
		}
		else
		{
			ft_fprintf(MSG_SYN, S_ERR, tmp->cut);
			data->error.error = true;
			return (0);
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	return (1);
}
