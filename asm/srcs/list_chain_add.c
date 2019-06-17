/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_chain_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:57:41 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/16 22:57:49 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_token(t_token **old, t_token new)
{
	t_token	*tmp;

	if (!*old)
		*old = new_token(new);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token(new);
	}
}

t_ins		*add_instruction(t_ins **old, t_op ins)
{
	t_ins	*tmp;

	if (!*old)
	{
		*old = new_instruction(ins);
		return (*old);
	}
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_instruction(ins);
		return (tmp->next);
	}
}

void		add_n_label(t_name_label **old, char *label, int index)
{
	t_name_label	*tmp;

	if (!*old)
		*old = new_n_label(label, index);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_n_label(label, index);
	}
}

void		add_label(t_label **old, t_label cpy)
{
	t_label	*tmp;

	if (!*old)
		*old = new_label(cpy);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_label(cpy);
	}
}
