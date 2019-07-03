/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:29:24 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/03 14:07:50 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		token_val(t_token add, int start, int end)
{
	add.type = -1;
	add.start = start;
	add.end = end;
	return (add);
}

void	erase_token(t_token **token)
{
	t_token *tmp;

	while (*token)
	{
		tmp = (*token)->next;
		free((*token)->cut);
		(*token)->cut = NULL;
		free(*token);
		*token = NULL;
		*token = tmp;
	}
}

t_token	cpy_token(t_token *token)
{
	t_token	new;

	new.cut = ft_strdup(token->cut);
	new.type = token->type;
	new.start = token->start;
	new.end = token->end;
	new.next = NULL;
	return (new);
}
