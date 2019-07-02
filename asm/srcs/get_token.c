/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:32:37 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/02 15:51:44 by brvalcas         ###   ########.fr       */
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
		end_word = get_arg(data, data->line.line + data->line.current, ft_end_word) + data->line.current;
		if (!(token.cut = ft_strcut(data->line.line, data->line.current, end_word)))
			break ;

		// ft_printf("%s\n", token.cut);
		token = token_val(token, data->index, end_word); // trouver le moyen de mettre le curseur a 0 lorsque je trouve un '\n'
																			// dans une string pour calculer l'index de la newline
		add_word(data, token);
		free(token.cut);
		data->line.current = end_word;
	}
	if (!(check_token(data)))
		return (0);
	erase_token(&data->token);
	return (1);
}
