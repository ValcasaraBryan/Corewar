/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:25:31 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/04 14:25:52 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*retour_into_quote(int i, int j, char *str)
{
	if (i == j)
		return (ft_strdup(""));
	else if (i < j)
		return (ft_strcut(str, i, j));
	else
		return (NULL);
}

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
	return (retour_into_quote(i, j, str));
}

int			retour_add_quote(t_data *data, t_token **token, char *tmp, char *string)
{
	if (!(string = into_quote((*token)->cut)))
		return (0);
	if ((int)ft_strlen(string) > data->len)
	{
		ft_fprintf(MSG_TOO_LONG, S_ERR, tmp == data->header.comment ? MSG_COMMENT : MSG_NAME, data->len);
		free_line(&string);
		return (0);
	}
	ft_strcpy(tmp, string);
	free_line(&string);
	return (1);
}

int			add_quote(t_data *data, t_token **token)
{
	char	*tmp;

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
	{
		ft_fprintf(MSG_SYN, S_ERR, TOKEN_ENDLINE);
		return (0);
	}
	return (retour_add_quote(data, token, tmp, NULL));
}
