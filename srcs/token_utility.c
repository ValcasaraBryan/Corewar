/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:29:24 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/04 16:11:18 by brvalcas         ###   ########.fr       */
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

t_token		cpy_token(t_token *token)
{
	t_token	new;

	new.cut = ft_strdup(token->cut);
	new.type = token->type;
	new.start = token->start;
	new.end = token->end;
	new.next = NULL;
	return (new);
}
