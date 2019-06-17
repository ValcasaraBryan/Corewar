/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/06/17 15:04:17 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		print_list(t_data *data)
{
	// while (data->token)
	// {
		// ft_printf("[%s][%03d:%03d]%03d|\n", data->token->cut, data->token->n_line,
				// data->token->start, data->token->end);
		// data->token = data->token->next;
	// }
	int	i;
	while (data->ins)
	{
		ft_printf("\033[31m%02x\033[0m\t", data->ins->ins.opcode);
		i = -1;
		if (data->ins->ins.opcode != LIVE && data->ins->ins.opcode != FORK
			&& data->ins->ins.opcode != ZJMP && data->ins->ins.opcode != LFORK)
		{
			ft_printf("\033[35m%02x\033[0m\t", data->ins->octet);
		}
		else
			ft_printf("\t");
		while (++i < data->ins->ins.len_params)
		{
			if ((data->ins->ins.indirect == 0 && data->ins->codage[i] == IND_CODE)
				|| (data->ins->ins.direct == 0 && data->ins->codage[i] == DIR_CODE))
				ft_printf("\033[32m%08x\033[0m ", data->ins->params[i]);
			else if (data->ins->codage[i] == REG_CODE)
				ft_printf("\033[32m%02x\033[0m ", data->ins->params[i]);
			else
				ft_printf("\033[32m%04x\033[0m ", (unsigned short)data->ins->params[i]);
		}
		ft_printf("\n");
		data->ins = data->ins->next;
	}
	while (data->label)
	{
		ft_printf("%s | %d\n", data->label->label, data->label->index_ins);
		data->label = data->label->next;
	}
	while (data->ins_label)
	{
		ft_printf("%p\n", data->ins_label->ins);
		ft_printf("%s\n", data->ins_label->label);
		ft_printf("%d\n", data->ins_label->index_ins);
		ft_printf("%d\n", data->ins_label->index_params);
		data->ins_label = data->ins_label->next;
	}
	ft_printf("len instruction : %08x\n", data->header.prog_size);
}

t_token		token_val(t_token add, int start, int end, int n_line)
{
	add.type = -1;
	add.start = start;
	add.end = end;
	add.n_line = n_line;
	return (add);
}

int		ft_is_instruction(char *str, t_op **ins)
{
	int		i;
	int		len;

	i = -1;
	if (!str)
		return (0);
	len = ft_strlen(str);
	while (++i < REG_NUMBER)
		if (len == op_tab[i].len
			&& ft_strncmp(str, op_tab[i].ins, op_tab[i].len) == 0)
		{
			*ins = op_tab + i;
			return (1);
		}
	*ins = NULL;
	return (0);
}

int			ft_str_is_number(char *str)
{
	int		neg;

	if (!str)
		return (0);
	neg = 0;
	if (str[neg] == '-' || str[neg] == '+')
		neg++;
	if (ft_str_is_digit(str + neg))
		return (1);
	else
		return (0);
}

int			ft_number_ok(char *str)
{
	if (ft_str_is_number(str) && ft_str_is_int(str))
		return (1);
	else
		return (0);
}

int		ft_is_label(char *str, bool before)
{
	int		i;
	bool	already;
	bool	ret;

	i = 0;
	if (!str)
		return (-1);
	ret = false;
	already = false;
	while (str[i])
	{
		if (label_chars(str[i]) && before == false)
			ret = true;
		else if (label(str[i]) && already == false)
		{
			already = true;
			before = false;
		}
		else
			return (-1);
		i++;
	}
	return (ret == true && already == true && before == false ? 1 : 0);
}

int		ft_is_params(char *str, int (*fonction)(char))
{
	int		i;
	bool	ret;

	i = 0;
	if (!str)
		return (-1);
	ret = false;
	while (str[i])
	{
		if (fonction(str[i]))
			ret = true;
		else if (ft_is_label(str + i, true) == 1 || ft_number_ok(str + i))
			return (ret == true ? 1 : 0);
		else
			break ;
		i++;
	}
	return (-1);
}

int		skip_whitespace(char *str, int val)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (ft_is_whitespace(str[i]) == val)
			break ;
	return (i);
}

int		ft_end_word(char c)
{
	if (ft_is_whitespace(c) || c == '#')
		return (1);
	return (0);
}

int		get_arg(char *str, int (*fonction)(char))
{
	int	i;

	i = -1;
	while (str[++i])
		if (fonction(str[i]))
			break ;
	return (i);
}

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

void	erase_token(t_token **token)
{
	t_token *tmp;

	while (*token)
	{
		tmp = (*token)->next;
		free((*token)->cut);
		(*token)->cut = NULL;
		free(*token);
		*token = NULL;
		*token = tmp;
	}
}

int		add_type(char *str, t_op **val)
{
	if (ft_is_label(str, false) == 1 && ft_is_params(str, direct) == -1)
		return (LABEL);
	else if (ft_is_label(str, true) == 1 && ft_is_params(str, direct) == 0)
		return (INDIRECT_LABEL);
	else if (ft_is_label(str + 1, true) == 1 && ft_is_params(str, direct) == 1)
		return (DIRECT_LABEL);
	else if (ft_is_params(str, registre) == 1)
		return (REGISTER);
	else if (ft_is_params(str, direct) == 0)
		return (INDIRECT);
	else if (ft_is_params(str, direct) == 1)
		return (DIRECT);
	else if (str && separator(*str) == 1)
		return (SEPARATOR);
	else if (ft_is_instruction(str, val) == 1)
		return (INSTRUCTION);
	else if (ft_is_label(str, false) == -1)
		return (0);
	else
		return (INSTRUCTION);
}

int		skip_separator(t_token **tmp, t_op *val, int *i)
{
	if (!(*tmp))
		return (1);
	(*tmp)->type = add_type((*tmp)->cut, &val);
	if ((*tmp)->type == SEPARATOR)
	{
		(*i)++;
		if ((*tmp)->next)
			(*tmp) = (*tmp)->next;
		else
		{
			ft_printf("ENDLINE\n");
			return (0);
		}
	}
	else
	{
		ft_printf("syntax error %s\n", (*tmp)->cut);
		return (0);
	}
	return (1);
}

t_token	cpy_token(t_token *token)
{
	t_token	new;

	new.cut = ft_strdup(token->cut);
	new.type = token->type;
	new.start = token->start;
	new.end = token->end;
	new.n_line = token->n_line;
	new.next = NULL;
	return (new);
}

int		check_params(t_data *data, t_token **tmp, t_ins *ins, t_op *val)
{
	int	i;
	int	bin;
	t_label cpy;

	i = 0;
	bin = 2;
	while ((*tmp))
	{
		(*tmp)->type = add_type((*tmp)->cut, &val);
		if ((*tmp)->type == DIRECT || (*tmp)->type == DIRECT_LABEL || (*tmp)->type == REGISTER)
		{
			if (T_DIR == (T_DIR & (val->params[i])))
			{
				ins->octet += DIR_CODE;
				ins->codage[i] = DIR_CODE;
				ins->len += ins->ins.direct == 1 ? 2 : 4;
				if ((*tmp)->type == DIRECT)
					ins->params[i] = ft_atoi((*tmp)->cut + 1);
				else if ((*tmp)->type == DIRECT_LABEL)
				{
					cpy.ins = ins;
					cpy.token = cpy_token(*tmp);
					cpy.label = ft_strdup((*tmp)->cut + 2);
					cpy.len = (cpy.label) ? ft_strlen(cpy.label) : 0;
					cpy.index_ins = data->header.prog_size;
					cpy.index_params = i;
					add_label(&data->ins_label, cpy);
				}
			}
			else if (T_REG == (T_REG & (val->params[i])))
			{
				if (ft_strlen((*tmp)->cut) > 3)
					return (0);
				ins->octet += REG_CODE;
				ins->codage[i] = REG_CODE;
				ins->len += 1;
				ins->params[i] = ft_atoi((*tmp)->cut + 1);
			}
			else
			{
				// ft_printf("Invalid parameter %d type direct for instruction %s\n", i, val->ins);
				return (0); // type d'argument non valide
			}
		}
		else if ((*tmp)->type == INDIRECT || (*tmp)->type == INDIRECT_LABEL)
		{
			// ft_printf("%d - %d - %d | i = %d\n", T_IND, (val->params[i]), (T_IND & (val->params[i])), i);
			if (T_IND == (T_IND & (val->params[i])))
			{
				ins->octet += IND_CODE;
				ins->codage[i] = IND_CODE;
				ins->len += ins->ins.indirect == 1 ? 2 : 4;
				if ((*tmp)->type == INDIRECT)
					ins->params[i] = ft_atoi((*tmp)->cut);
				else
				{
					cpy.ins = ins;
					cpy.token = cpy_token(*tmp);
					cpy.label = ft_strdup((*tmp)->cut + 1);
					cpy.len = (cpy.label) ? ft_strlen(cpy.label) : 0;
					cpy.index_ins = data->header.prog_size;
					cpy.index_params = i;
					add_label(&data->ins_label, cpy);
				}
			}
			else
			{
				// ft_printf("Invalid parameter %d type indirect for instruction %s\n", i, val->ins);
				return (0); // type d'argument non valide
			}
		}
		else
		{
			ft_printf("%s | ERROR\n", (*tmp)->cut);
			return (0);
		}
		if ((*tmp)->next)
			(*tmp) = (*tmp)->next;
		else
			break ;
		if (!(skip_separator(tmp, val, &i)))
			return (0);
		ins->octet = ins->octet << bin;
	}
	// ft_printf("%d < %d\n", i, val->len_params);
	if (i < val->len_params - 1)
	{
		ft_printf("Invalid parameter count for instruction %s\n", val->ins);
		return (0);
	}
	while (++i < 4)
		ins->octet = ins->octet << bin;
	return (1);
}

int		check_token(t_data *data)
{
	t_op	*val;
	int		type;
	t_ins	*ins_tmp;
	t_token	*tmp;

	tmp = data->token;
	val = NULL;
	while (tmp)
	{
		tmp->type = add_type(tmp->cut, &val);
		if (tmp->type == INSTRUCTION || (tmp->type == LABEL && !val))
		{
			type = tmp->type;
			if (type == INSTRUCTION && val)
			{
				// ft_printf("%-10s | %d\n", tmp->cut, tmp->type);
				ins_tmp = add_instruction(&data->ins, *val);
				ins_tmp->len += (ins_tmp->ins.opcode == LIVE || ins_tmp->ins.opcode == FORK
				|| ins_tmp->ins.opcode == ZJMP || ins_tmp->ins.opcode == LFORK) ? 1 : 2;
				// ft_printf("%d\n", val->opcode);
			}
			else if (type == LABEL)
				add_n_label(&data->label, ft_strcut(tmp->cut, 0, tmp->end - 1), data->header.prog_size);
		}
		else
		{
			if (!val || !(check_params(data, &tmp, ins_tmp, val)))
				return (0);
			data->header.prog_size += ins_tmp->len;
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	if (tmp->type == INSTRUCTION)
		return (0);
	return (1);
}

int		get_token(t_data *data)
{
	t_token	token;
	int		end_word;
	
	while (data->line.line[data->line.current])
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
		erase_token(&data->token);
		return (0);
	}
	erase_token(&data->token);
	return (1);
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

int		parsing_asm(t_data *data)
{
	char *tmp;

	tmp = NULL;
	if ((data->fd = open(data->name_s, O_RDONLY)) == -1)
	{
		ft_fprintf(NO_FILE, S_ERR, data->name_s);
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
	if (data->name_and_comment != 2 || data->index > data->len)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	if (!(suffix_name(data, SUFFIX)))
		return (0);
	return (1);
}
