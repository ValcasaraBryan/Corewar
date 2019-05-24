/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/24 19:33:48 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op				op_tab[REG_NUMBER] =
{
	{"live", LIVE, 4},
	{"ld", LD, 2},
	{"st", ST, 2},
	{"add", ADD, 3},
	{"sub", SUB, 3},
	{"and", AND, 3},
	{"or", OR, 2},
	{"xor", XOR, 3},
	{"zjmp", ZJMP, 4},
	{"ldi", LDI, 3},
	{"sti", STI, 3},
	{"fork", FORK, 4},
	{"lld", LLD, 3},
	{"lldi", LLDI, 4},
	{"lfork", LFORK, 5},
	{"aff", AFF, 3},
};

t_token		*new_token(t_token token)
{
	t_token	*new;

	if (!(new = malloc(sizeof(t_token))))
		return (NULL);
	new->n_line = token.n_line;
	new->cut = token.cut;
	new->start = token.start;
	new->end = token.end;
	new->next = token.next;
	return (new);
}

void		add_token(t_token **old, t_token token)
{
	t_token	*tmp;

	if (!*old)
		*old = new_token(token);
	else
	{
		tmp = *old;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_token(token);
	}
}

t_ins		*new_instruction(unsigned char token)
{
	t_ins	*new;

	if (!(new = malloc(sizeof(t_ins))))
		return (NULL);
	new->token = token;
	new->params = 0;
	new->direct = 0;
	new->indirect = 0;
	new->registre = 0;
	new->len_octet = 0;
	new->next = NULL;
	return (new);
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
		ft_printf("%s[%03d:%03d]%03d|\n", data->token->cut, data->token->n_line, data->token->start, data->token->end);
		data->token = data->token->next;
	}
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

t_error		get_error(char *token)
{
	t_error	error;

	(void)token;
	error.type = NULL;
	error.instruction = NULL;
	return (error);
}

t_token		token_val(t_token add, int start, int end, int n_line)
{
	add.n_line = n_line;
	add.start = start;
	add.end = end;
	add.next = NULL;
	return (add);
}

void	get_token(t_data *data)
{
	t_token	token;
	int	end_word;
	
	while (data->line.line[data->line.current])
	{
		data->line.current += skip_whitespace(data->line.line + data->line.current, 0);
		end_word = skip_whitespace(data->line.line + data->line.current, 1) + data->line.current;
		if (end_word == data->len)
			break ;
		token.cut = ft_strcut(data->line.line, data->line.current, end_word);
		token = token_val(token, data->line.current, end_word, data->line.n_line);
		add_token(&data->token, token);
		data->line.current = end_word;
	}
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

int		step(t_data *data, char **tmp)
{
	if (!data->line.line && data->ret == -1)
		return (1);
	if (!data->line.line && !data->ret)
		return (0);
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
	if (data->name_com == true)
	{
		if (!(into_quote(data, *tmp))) // name et comment get
		{
			// max len depassee name || comment
			return (0);
		}
	}
	if (data->name_com == false && data->line.line[data->line.current]) // other
	{
		data->line.current += skip_whitespace(data->line.line + data->line.current, 0);
		get_token(data);
		// ft_printf("%s\n", data->line.line + data->line.current);
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
