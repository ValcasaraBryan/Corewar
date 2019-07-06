/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:39:32 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/06 13:12:56 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		check_char(t_token word, int *i, int *j)
{
	if (word.cut[(*i)] != CMD_CHAR)
	{
		if (separator(word.cut[(*i)]) == 1)
			(*j)++;
		else
			while (word.cut[(*j)])
				if (separator(word.cut[++(*j)]))
					break ;
	}
	else
	{
		while (word.cut[++(*j)])
			if (word.cut[(*j)] == CMD_CHAR)
			{
				(*j)++;
				break ;
			}
	}
}

void			add_word(t_data *data, t_token word)
{
	int		i;
	int		j;
	t_token	new;

	i = -1;
	new = word;
	while (word.cut[++i])
	{
		j = i;
		check_char(word, &i, &j);
		if (!(new.cut = ft_strcut(word.cut, (size_t)i, (size_t)j)))
			return ;
		add_token(&data->token, new);
		i = (j - 1 >= 0) ? j - 1 : j;
	}
	free(word.cut);
	word.cut = NULL;
}
