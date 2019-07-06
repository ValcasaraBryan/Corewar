/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:41:07 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/04 16:41:08 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_match(t_label *tmp, t_name_label *def, bool match)
{
	if (match == true)
		tmp->ins->params[tmp->index_params] = def->index_ins - tmp->index_ins;
	else
	{
		ft_fprintf(MSG_LABEL, S_ERR, tmp->token.cut);
		return (0);
	}
	return (1);
}

int				check_label(t_data *data)
{
	t_label			*tmp;
	t_name_label	*def;
	bool			match;

	tmp = data->ins_label;
	while (tmp)
	{
		match = false;
		def = data->label;
		while (def)
		{
			if (tmp->len == def->len)
				if (ft_strncmp(tmp->label, def->label, tmp->len) == 0)
				{
					match = true;
					break ;
				}
			def = def->next;
		}
		if (!(ft_match(tmp, def, match)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
