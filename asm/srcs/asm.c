/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/06/18 15:40:44 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_arg(char *str, int (*fonction)(char))
{
	int	i;

	i = -1;
	while (str[++i] != '\n')
		if (fonction(str[i]))
			break ;
	return (i);
}

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
		{
			ft_printf("error get_token\n");
			return (0);
		}
	// 
	return (1);
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
			ft_printf("No such label %s while attempting to dereference token \"%s\"\n", tmp->label, tmp->token.cut);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int		read_line(t_data *data)
{
	int		i;
	bool	quote;
	char	buf[1 + 1];

	i = 0;
	quote = false;
	while ((data->ret = read(data->fd, buf, 1)) > 0)
	{
		buf[data->ret] = 0;
		if (!data->line.line)
			data->line.line = ft_strnew(32);
		i += data->ret;
		if (i == 32)
		{
			data->line.line = ft_strjoin_free(data->line.line, ft_strnew(i), 3);
			i = 0;
		}
		else
			ft_strcat(data->line.line, buf);
		if (buf[0] == CMD_CHAR)
			quote = (quote == false) ? true : false;
		if (buf[0] == 10 && quote == false)
			return (1);
	}
	return (data->line.line ? -1 : 0);
}

int		parsing_asm(t_data *data)
{
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
		if ((data->ret = read_line(data)) == -1)
		{
			ft_printf("no newline\n");
			return (0);
		}
		data->line.current = 0;
		data->line.n_line++;
	}
	// ft_printf("[%s]\n", data->header.prog_name);
	// ft_printf("[%s]\n", data->header.comment);
	if (!(check_label(data)))
		return (0);
	if (data->name_and_comment != 2 || data->index > data->len || error(data->error))
	{
		// ft_printf("error name or comment\n");
		return (0);
	}
	if (!(suffix_name(data, SUFFIX)))
		return (0);
	return (1);
}

int		error(t_error error)
{
	char *type;
	if (!error.instruction || !error.label)
		return (0);
	ft_printf("%s %d [%03d:%03d]\n", error.token.cut, error.token.type, error.token.n_line, error.token.start);
	if (error.token.type == DIRECT || error.token.type == DIRECT_LABEL)
		type = DIRECT_MSG;
	else if (error.token.type == INDIRECT || error.token.type == INDIRECT_LABEL)
		type = INDIRECT_MSG;
	else if (error.token.type == REGISTER)
		type = REGISTER_MSG;
	else
		type = NULL;
	if (error.instruction->codage[error.index_params] != error.instruction->ins.params[error.index_params])
	{
		ft_fprintf(INVALID_PARAMS, S_ERR, error.index_params, type, error.instruction->ins.ins);
		return (1);
	}
	// ft_printf("%d\n", error.instruction->codage[error.index_params]);
	// ft_printf("%s %d\n", error.instruction->ins.ins, error.instruction->ins.params[error.index_params]);
	// ft_printf("%p\n", error.label);
	// ft_printf("%d\n", error.index_params);
	return (0);
}
