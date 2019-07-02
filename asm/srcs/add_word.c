/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:39:32 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/02 15:46:57 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_word(t_data *data, t_token word)
{
	int		i;
	int		j;
	t_token	new;

	i = -1;
	new = word;
	while (word.cut[++i])
	{
		j = i;
		if (word.cut[i] != CMD_CHAR)
		{
			if (separator(word.cut[i]) == 1)
				j++;
			else
				while (word.cut[j])
					if (separator(word.cut[++j]) == 1)
						break ;
		}
		else
		{
			while (word.cut[++j])
				if (word.cut[j] == CMD_CHAR)
				{
					j++;
					break ;
				}
		}
		if (!(new.cut = ft_strcut(word.cut, i, j)))
			return ;
		add_token(&data->token, new);
		i = (j - 1 >= 0) ? j - 1 : j;
	}
}
