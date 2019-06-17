/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/06/17 20:15:14 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_arg(char *str, int (*fonction)(char))
{
	int	i;

	i = -1;
	while (str[++i])
		if (fonction(str[i]))
			break ;
	return (i);
}

int		into_quote(t_data *data, char *tmp)
{
	// ft_printf("|%s|\n", data->line.line + data->line.current);
	while (data->line.line[data->line.current])
	{
		if (data->index > data->len)
		{
			// error max len name_prog || comment
			return (0);
		}
		if (data->quote == true && data->line.line[data->line.current] != CMD_CHAR)
		{
			// ft_printf("sortie |%s|\n", data->line.line + data->line.current);
			tmp[data->index++] = data->line.line[data->line.current];
			// into quote
		}
		else if (data->quote == false && data->line.line[data->line.current] == CMD_CHAR)
		{
			data->quote = true;
			// debut de la quote
		}
		else if (data->quote == true && data->line.line[data->line.current] == CMD_CHAR)
		{
			data->quote = false;
			data->name_com = false;
			data->line.current++;
			data->name_and_comment++;
			// ft_printf("%s|\n", tmp);
			tmp[data->index] = 0;
			// ft_printf("%s|\n", tmp);
			// fin de la quote
			break ;
		}
		// else if (data->quote == false && ft_is_whitespace(data->line.line[data->line.current]))
			// data->line.current++;
		data->line.current++;
		if (!data->line.line[data->line.current] && data->quote == true)
		{
			tmp[data->index++] = '\n';
			// endline into quote
		}
	}
	return (1);
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

void	name_and_comment(t_data *data, char **tmp)
{
	if (data->name_com == false && data->name_and_comment != 2) // name et comment activation
	{
		*tmp = NULL;
		data->index = 0;
		data->line.current += skip_whitespace(data->line.line + data->line.current, 0);
		if (ft_strncmp(data->line.line + data->line.current, NAME_CMD_STRING, check_alpha(data->line.line + data->line.current)) == 0) // verifier que apres ce ne soit pas de mauvaise lettres good si whites spaces ou ""
		{
			*tmp = (char *)data->header.prog_name;
			data->len = PROG_NAME_LENGTH;
			data->line.current += check_alpha(data->line.line + data->line.current);
		}
		else if (ft_strncmp(data->line.line + data->line.current, COMMENT_CMD_STRING, check_alpha(data->line.line + data->line.current)) == 0) // verifier que apres ce ne soit pas de mauvaise lettres good si whites spaces ou ""
		{
			*tmp = (char *)data->header.comment;
			data->len = COMMENT_LENGTH;
			data->line.current += check_alpha(data->line.line + data->line.current);
		}
		data->name_com = (*tmp) ? true : false;
	}
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

int		step(t_data *data, char **tmp)
{
	if (!data->line.line && data->ret == -1)
		return (1);
	if (!data->line.line && !data->ret)
		return (0);
	name_and_comment(data, tmp);
	if (data->name_com == true)
	{
		if (!(into_quote(data, *tmp))) // name et comment get
		{
			// max len depasee name || comment
			return (0);
		}
	}
	if (data->name_com == false && data->line.line[data->line.current]) // other
	{
		data->line.current += skip_whitespace(data->line.line + data->line.current, 0);
		// ft_printf("%s\n", data->line.line + data->line.current);
		if (!(get_token(data)))
			return (0);
	}
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

int		parsing_asm(t_data *data)
{
	char	*tmp;

	tmp = NULL;
	if ((data->fd = open(data->name_s, O_RDONLY)) == -1)
	{
		ft_fprintf(NO_FILE, S_ERR, READ, data->name_cor);
		return (0);
	}
	while (step(data, &tmp))
	{
			// ft_printf("%s|%d\n", data->line.line, data->ret);
		if (data->line.line)
		{
			free(data->line.line);
			data->line.line = NULL;
		}
		if ((data->ret = get_next_line(data->fd, &data->line.line)) == -1)
		{
			ft_printf("ERROR lecture\n");
			return (0);
		}
		data->line.current = 0;
		data->line.n_line++;
	}
	if (!(check_label(data)))
		return (0);
	if (data->name_and_comment != 2 || data->index > data->len || error(data->error))
	{
		return (0);
	}
	if (!(suffix_name(data, SUFFIX)))
		return (0);
	return (1);
}
