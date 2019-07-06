/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:32:37 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/05 18:22:07 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_token(t_data *data)
{
	t_token	token;
	int		end_word;

	while (data->line.line[data->line.current] != '\n')
	{
		data->line.current += skip_whitespace(data->line.line
			+ data->line.current, 0);
		end_word = get_arg(data->line.line + data->line.current, ft_end_word)
			+ data->line.current;
		if (!(token.cut = ft_strcut(data->line.line, data->line.current,
			end_word)))
			break ;
		token = token_val(token, data->index, end_word);
		add_word(data, token);
		data->line.current = end_word;
	}
	return (check_token(data));
}
