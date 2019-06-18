/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:32:37 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/18 15:24:00 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_token(t_data *data)
{
	t_token	token;
	int		end_word;
	
	while (data->line.line[data->line.current] != '\n')
	{
		data->line.current += skip_whitespace(data->line.line + data->line.current, 0);
		end_word = get_arg(data->line.line + data->line.current, ft_end_word) + data->line.current;
		if (!(token.cut = ft_strcut(data->line.line, data->line.current, end_word)))
			break ;
		token = token_val(token, data->line.current, end_word, data->line.n_line);
		add_word(data, token);
		free(token.cut);
		data->line.current = end_word;
	}
	if (!(check_token(data)))
	{
		ft_printf("error check_token\n");
		return (0);
	}
	erase_token(&data->token);
	return (1);
}
