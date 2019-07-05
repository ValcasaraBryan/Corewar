/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_chain_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:57:45 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/05 15:48:49 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token			*new_token(t_token token)
{
	t_token	*new;

	if (!(new = malloc(sizeof(t_token))))
		return (NULL);
	new->cut = token.cut;
	new->type = token.type;
	new->start = token.start;
	new->end = token.end;
	new->n_line = token.n_line;
	new->next = NULL;
	return (new);
}

t_ins			*new_instruction(t_op ins)
{
	t_ins	*new;
	int		i;

	if (!(new = malloc(sizeof(t_ins))))
		return (NULL);
	new->ins = ins;
	new->octet = 0;
	if (!(new->params = malloc(sizeof(int) * ins.len_params)))
		return (NULL);
	i = -1;
	while (++i < ins.len_params)
		new->params[i] = 0;
	new->len = 0;
	new->next = NULL;
	return (new);
}

t_name_label	*new_n_label(char *label, int index)
{
	t_name_label *new;

	if (!(new = malloc(sizeof(t_ins))))
		return (NULL);
	new->label = (label) ? label : NULL;
	new->len = (label) ? ft_strlen(label) : 0;
	new->index_ins = index;
	new->next = NULL;
	return (new);
}

t_label			*new_label(t_label cpy)
{
	t_label *new;

	if (!(new = malloc(sizeof(t_ins))))
		return (NULL);
	new->ins = cpy.ins;
	new->token = cpy.token;
	new->label = cpy.label;
	new->len = cpy.len;
	new->index_ins = cpy.index_ins;
	new->index_params = cpy.index_params;
	new->next = NULL;
	return (new);
}
