/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:39:32 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/17 15:39:35 by bryanvalcas      ###   ########.fr       */
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
		if (separator(word.cut[i]) == 1)
			j++;
		else
			while (word.cut[j])
				if (separator(word.cut[++j]) == 1)
					break ;
		new.cut = ft_strcut(word.cut, i, j);
		add_token(&data->token, new);
		i = (j - 1 >= 0) ? j - 1 : j;
	}
}
