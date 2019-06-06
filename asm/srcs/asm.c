/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/06/06 19:39:29 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op				op_tab[REG_NUMBER] =
{
//	name		opcode		len_name	params
	{"live",	LIVE,		4,			1},
	{"ld",		LD,			2,			2},
	{"st",		ST,			2,			2},
	{"add",		ADD,		3,			3},
	{"sub",		SUB,		3,			3},
	{"and",		AND,		3,			3},
	{"or",		OR,			2,			3},
	{"xor",		XOR,		3,			3},
	{"zjmp",	ZJMP,		4,			1},
	{"ldi",		LDI,		3,			3},
	{"sti",		STI,		3,			3},
	{"fork",	FORK,		4,			1},
	{"lld",		LLD,		3,			2},
	{"lldi",	LLDI,		4,			3},
	{"lfork",	LFORK,		5,			1},
	{"aff",		AFF,		3,			1},
};

t_token		*new_token(t_token token)
{
	t_token	*new;

	if (!(new = malloc(sizeof(t_token))))
		return (NULL);
	new->cut = token.cut;
	new->type = token.type;
	new->start = token.start;
	new->end = token.end;
	new->n_line = token.n_line;
	new->next = NULL;
	return (new);
}

t_ins		*new_instruction(unsigned char token)
{
	t_ins	*new;

	if (!(new = malloc(sizeof(t_ins))))
		return (NULL);
	new->token = token;
	new->params = 0;
	new->params_one = 0;
	new->params_two = 0;
	new->params_three = 0;
	new->next = NULL;
	return (new);
}

void		add_token(t_token **old, t_token new)
{
	t_token	*tmp;

	if (!*old)
		*old = new_token(new);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token(new);
	}
}

void		add_instruction(t_ins **old, unsigned char token)
{
	t_ins	*tmp;

	if (!*old)
		*old = new_instruction(token);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_instruction(token);
	}
}

void		print_list(t_data *data)
{
	while (data->token)
	{
		ft_printf("[%s][%03d:%03d]%03d|\n", data->token->cut, data->token->n_line,
				data->token->start, data->token->end);
		data->token = data->token->next;
	}
	// while (data->instruction)
	// {
		// ft_printf("instruction = [%02x][%02x][%02x][%02x][%02x]\n",
			// data->instruction->token, data->instruction->params, data->instruction->params_one,
				// data->instruction->params_two, data->instruction->params_three);
		// data->instruction = data->instruction->next;
	// }
}

void	init_data(t_data *data, char *av)
{
	data->fd = -1;
	data->ret = -1;
	data->name_s = av;
	data->name_cor = NULL;
	data->quote = false;
	data->name_com = false;
	data->name_and_comment = 0;
	data->line.line = NULL;
	data->line.current = 0;
	data->line.n_line = 0;
	data->token = NULL;
	data->instruction = NULL;
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

unsigned char		add_params(char *str, int *bin)
{
	if (!str)
		return (0);
	if (str[0] == '%')
		return (DIR_CODE << (*bin -= 2));
	else if (str[0] == 'r')
		return (REG_CODE << (*bin -= 2));
	else
		return (IND_CODE << (*bin -= 2));
}

int		ft_is_virgule(char c)
{
	int	i;

	i = -1;
	if (c == ',')
		return (1);
	else
		return (0);
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

int		separator(char c)
{
	if (c == SEPARATOR_CHAR)
		return (1);
	return (0);
}

int		skip_separator(char *str, int val)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (separator(str[i]) == val)
			break ;
	return (i);
}

int			ft_str_is(char *str, const char *cmp)
{
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (!params(str[i], cmp))
			return (0);
	return (1);
}

int			ft_skip_word(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (!params(str[i], LABEL_CHARS) && str[i] != COMMENT_CHAR
			&& str[i] != LABEL_CHAR && str[i] != DIRECT_CHAR)
			break ;
	}
	return (i);
}

t_token		token_val(t_token add, int start, int end, int n_line)
{
	add.type = -1;
	add.start = start;
	add.end = end;
	add.n_line = n_line;
	return (add);
}

int		ft_is_instruction(char *str, t_op *ins)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (++i < REG_NUMBER)
		if (ft_strncmp(str, op_tab[i].op, op_tab[i].len) == 0)
		{
			*ins = op_tab[i];
			return (1);
		}
	return (0);
}

int		label_chars(char c)
{
	if (params(c, LABEL_CHARS))
		return (1);
	return (0);
}

int		direct(char c)
{
	if (c == DIRECT_CHAR)
		return (1);
	return (0);
}

int		registre(char c)
{
	if (c == 'r')
		return (1);
	return (0);
}

int		label(char c)
{
	if (c == LABEL_CHAR)
		return (1);
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

int		add_type(char *str, t_op *val)
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

int		check_token(t_data *data)
{
	t_op	val;
	t_token	*tmp;

	tmp = data->token;
	while (tmp)
	{
		tmp->type = add_type(tmp->cut, &val);
		tmp = tmp->next;
	}
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
			*tmp = (char *)data->name;
			data->len = PROG_NAME_LENGTH;
			data->line.current += check_alpha(data->line.line + data->line.current);
		}
		else if (ft_strncmp(data->line.line + data->line.current, COMMENT_CMD_STRING, check_alpha(data->line.line + data->line.current)) == 0) // verifier que apres ce ne soit pas de mauvaise lettres good si whites spaces ou ""
		{
			*tmp = (char *)data->comment;
			data->len = COMMENT_LENGTH;
			data->line.current += check_alpha(data->line.line + data->line.current);
		}
		data->name_com = (*tmp) ? true : false;
	}
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
	if (data->name_and_comment != 2 || data->index > data->len)
	{
		ft_printf("ERROR\n");
		return (0);
	}
	if (!(suffix_name(data, SUFFIX)))
		return (0);
	return (1);
}
