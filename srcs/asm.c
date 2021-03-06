/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/06 13:08:01 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		step(t_data *data)
{
	if (!data->line.line && data->ret == -1)
		return (1);
	if (!data->line.line && !data->ret)
		return (0);
	data->line.current += skip_whitespace(data->line.line
		+ data->line.current, 0);
	if (!(get_token(data)))
	{
		erase_token(&data->token);
		return (0);
	}
	erase_token(&data->token);
	free_line(&data->line.line);
	return (1);
}

static char		*ft_str_biggest(char **s1, int more)
{
	char	*tmp;
	int		len;

	if (!*s1)
		return (ft_strnew((size_t)more));
	len = (int)ft_strlen(*s1);
	if (!(tmp = malloc(sizeof(char) * (unsigned long)(len + more + 1))))
		return (NULL);
	ft_strcpy(tmp, *s1);
	free(*s1);
	*s1 = NULL;
	return (tmp);
}

static int		read_line(t_data *data, int *i, bool quote)
{
	char	buf[1 + 1];

	while ((data->ret = (int)read(data->fd, buf, 1)) > 0)
	{
		buf[data->ret] = 0;
		if (!data->line.line)
			if (!(data->line.line = ft_strnew(BUFF_SIZE)))
				return (0);
		(*i) += data->ret;
		if ((*i) == BUFF_SIZE)
		{
			if (!(data->line.line = ft_str_biggest(&data->line.line,
				BUFF_SIZE)))
				return (0);
			(*i) = 0;
		}
		ft_strcat(data->line.line, buf);
		if (buf[0] == CMD_CHAR)
			quote = (quote == false) ? true : false;
		if (buf[0] == 10 && quote == false)
			return (1);
	}
	if (ft_str_is(data->line.line, ft_is_whitespace))
		free_line(&data->line.line);
	return (data->line.line && quote == false ? -1 : 0);
}

static int		paring_asm_two(t_data *data)
{
	if (data->error.error)
		return (0);
	if (!data->ins)
	{
		ft_fprintf(MSG_SYN, S_ERR, TOKEN_ENDLINE);
		return (0);
	}
	if (!data->name || !data->comment)
	{
		ft_fprintf(COMMAND_MISS, S_ERR);
		return (0);
	}
	if (!(check_label(data)))
		return (0);
	if (!(suffix_name(data, SUFFIX)))
		return (0);
	return (1);
}

int				parsing_asm(t_data *data)
{
	int	i;

	i = 0;
	while (step(data))
	{
		if ((data->ret = read_line(data, &i, false)) == -1)
		{
			free_line(&data->line.line);
			ft_fprintf(NO_NEWLINE, S_ERR);
			return (0);
		}
		data->line.current = 0;
	}
	free_line(&data->line.line);
	if (!(paring_asm_two(data)))
		return (0);
	return (1);
}
