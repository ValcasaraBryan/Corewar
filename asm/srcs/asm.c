/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/03 14:44:15 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_alpha(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_is_whitespace(str[i]) || str[i] == CMD_CHAR)
			return (i);
	}
	return (i);
}

int		suffix_name(t_data *data, const char *s)
{
	int		i;
	char	*name;

	if (!data->name_s)
		return (0);
	i = ft_strlen(data->name_s) + 1;
	while (--i >= 0)
		if (!ft_strcmp(data->name_s + i, SUFF_F))
			break ;
	name = ft_strcut(data->name_s, 0, i);
	data->name_cor = ft_strndup((const char *)name, i + COR);
	free_line(&name);
	ft_strcat(data->name_cor, (char *)s);
	return (1);	
}

int		step(t_data *data)
{
	if (!data->line.line && data->ret == -1)
		return (1);
	if (!data->line.line && !data->ret)
		return (0);
	data->line.current += skip_whitespace(data->line.line + data->line.current, 0);
	if (!(get_token(data)))
		return (0);
	return (1);
}

void	erase_label(t_label **label)
{
	t_label *tmp;

	while (*label)
	{
		tmp = (*label)->next;
		free((*label)->token.cut);
		(*label)->token.cut = NULL;
		free((*label)->label);
		(*label)->label = NULL;
		free(*label);
		*label = NULL;
		*label = tmp;
	}
}

void	erase_name_label(t_name_label **label)
{
	t_name_label *tmp;

	while (*label)
	{
		tmp = (*label)->next;
		free((*label)->label);
		(*label)->label = NULL;
		free(*label);
		*label = NULL;
		*label = tmp;
	}
}

int		check_label(t_data *data)
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
			// ft_printf("%s - %s\n", tmp->label, def->label);
			if (tmp->len == def->len)
				if (ft_strncmp(tmp->label, def->label, tmp->len) == 0)
				{
					match = true;
					break ;
				}
			def = def->next;
		}
		if (match == true)
			tmp->ins->params[tmp->index_params] = def->index_ins - tmp->index_ins;
		else
		{
			ft_fprintf(MSG_LABEL, S_ERR, tmp->token.cut);
			return (0);
		}
		tmp = tmp->next;
	}
	erase_name_label(&data->label);
	erase_label(&data->ins_label);
	return (1);
}

char	*ft_str_biggest(char **s1, int more)
{
	char	*tmp;
	int		len;

	if (!*s1)
		return (ft_strnew(more));
	len = ft_strlen(*s1);
	if (!(tmp = malloc(sizeof (char) * (len + more + 1))))
		return (NULL);
	ft_strcpy(tmp, *s1);
	free(*s1);
	*s1 = NULL;
	return (tmp);
}

int		read_line(t_data *data, int *i)
{
	bool	quote;
	char	buf[1 + 1];

	quote = false;
	while ((data->ret = read(data->fd, buf, 1)) > 0)
	{
		buf[data->ret] = 0;
		if (!data->line.line)
			data->line.line = ft_strnew(BUFF_SIZE);
		(*i) += data->ret;
		if ((*i) == BUFF_SIZE)
		{
			data->line.line = ft_str_biggest(&data->line.line, BUFF_SIZE);
			(*i) = 0;
		}
		ft_strcat(data->line.line, buf);
		if (buf[0] == CMD_CHAR)
			quote = (quote == false) ? true : false;
		if (buf[0] == 10 && quote == false)
			return (1);
	}
	data->line.line = (ft_str_is(data->line.line, ft_is_whitespace)) ? NULL : data->line.line;
	return (data->line.line ? -1 : 0);
}

int		parsing_asm(t_data *data)
{
	int	i;

	i = 0;
	if ((data->fd = open(data->name_s, O_RDONLY)) == -1)
	{
		ft_fprintf(NO_FILE, S_ERR, READ, data->name_cor);
		return (0);
	}
	while (step(data))
	{
		if (data->line.line)
		{
			free(data->line.line);
			data->line.line = NULL;
		}
		if ((data->ret = read_line(data, &i)) == -1)
		{
			ft_fprintf(NO_NEWLINE, S_ERR);
			return (0);
		}
		// ft_printf("%s\n", data->line.line);
		data->line.current = 0;
	}
	if (!data->name || !data->comment)
	{
		ft_fprintf(COMMAND_MISS, S_ERR);
		return (0);
	}
	if (data->error.error)
		return (0);
	if (!(check_label(data)))
		return (0);
	if (!(suffix_name(data, SUFFIX)))
		return (0);
	return (1);
}
