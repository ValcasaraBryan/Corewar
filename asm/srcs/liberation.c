/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:41:15 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/03 17:41:25 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

void	erase_ins(t_ins **ins)
{
	t_ins *tmp;

	while (*ins)
	{
		tmp = (*ins)->next;
		free((*ins)->params);
		(*ins)->params = NULL;
		free(*ins);
		*ins = NULL;
		*ins = tmp;
	}
}

void	erase_label(t_label **label)
{
	t_label *tmp;

	while (*label)
	{
		tmp = (*label)->next;
		free((*label)->token.cut);
		(*label)->token.cut = NULL;
		free((*label)->label);
		(*label)->label = NULL;
		free(*label);
		*label = NULL;
		*label = tmp;
	}
}

void	erase_name_label(t_name_label **label)
{
	t_name_label *tmp;

	while (*label)
	{
		tmp = (*label)->next;
		free((*label)->label);
		(*label)->label = NULL;
		free(*label);
		*label = NULL;
		*label = tmp;
	}
}
