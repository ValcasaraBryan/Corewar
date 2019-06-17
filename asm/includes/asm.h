/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:05:08 by brvalcas          #+#    #+#             */
/*   Updated: 2019/06/17 20:00:37 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "../../op.h"
# include <stdbool.h>
#define S_ERR	2
#define READ	"read"
#define OPEN	"open"
#define NO_FILE	"Can't %s source file %s\n"
#define SUCCESS	"Writing output program to %s\n"
#define SUFF_F	".s"
#define SUFFIX	".cor"
#define COR		4

#define CMD_CHAR				'"'

#define LIVE					1
#define LD						2
#define ST						3
#define ADD						4
#define SUB						5
#define AND						6
#define OR						7
#define XOR						8
#define ZJMP					9
#define LDI						10
#define STI						11
#define FORK					12
#define LLD						13
#define LLDI					14
#define LFORK					15
#define AFF						16

#define DIRECT					1
#define INDIRECT				2
#define REGISTER				3
#define INSTRUCTION				4
#define	LABEL					5
#define DIRECT_LABEL			6
#define INDIRECT_LABEL			7
#define SEPARATOR				8
#define TOKEN					9
#define	ENDLINE					10
#define	END						11

#define TRUE					1
#define IN_TRUE					2
#define FALSE					0
#define	INDIRECT_MSG			"indirect"
#define DIRECT_MSG				"direct"
#define REGISTER_MSG			"register"
#define TOKEN_DIRECT			"DIRECT"
#define TOKEN_INDIRECT			"INDIRECT"
#define TOKEN_REGISTER			"REGISTER"
#define TOKEN_DIRECT_LABEL		"DIRECT_LABEL"
#define TOKEN_INDIRECT_LABEL	"INDIRECT_LABEL"
#define TOKEN_LABEL				"LABEL"
#define TOKEN_SEPARATOR			"SEPARATOR"
#define TOKEN_ENDLINE			"ENDLINE"
#define TOKEN_END				"END"
#define LINE					"\n"
#define ERROR_COUNT				"Invalid parameter count for instruction %s"
#define ERROR_PARAMS			"Invalid parameter %d type %s for instruction %s"
#define MSG_LABEL				"No such label %s while attempting to dereference"
#define MSG_SYN					"Syntax error at"
#define MSG_TOKEN				" token [%s][%03d:%03d] %s"
#define ARG						" \"%s\""
#define SYNTAX_ARG				MSG_SYN TOKEN ARG LINE
#define ERROR_LABEL				MSG_LABE TOKEN ARG LINE
#define SYNTAX					MSG_SYN TOKEN LINE
#define INVALID_PARAMS			ERROR_PARAMS LINE

typedef struct		s_op
{
	char			*ins;
	int				len;
	unsigned char	len_params;
	unsigned char	params[3];
	unsigned char	opcode;
	int				cycle;
	char			*description;
	unsigned char	indirect;
	unsigned char	direct;
}					t_op;

typedef struct		s_ins
{
	t_op			ins;
	unsigned char	codage[3];
	unsigned char	octet;
	int				*params;
	int				len;
	struct s_ins	*next;
}					t_ins;

typedef struct		s_token
{
	char			*cut;
	int				type;
	int				start;
	int				end;
	int				n_line;
	struct s_token	*next;
}					t_token;

typedef struct		s_label
{
	t_ins			*ins;
	t_token			token;
	char			*label;
	int				len;
	int				index_ins;
	int				index_params;
	struct s_label	*next;
}					t_label;

typedef struct		s_name_label
{
	char			*label;
	int				len;
	int				index_ins;
	struct s_name_label	*next;
}					t_name_label;

typedef struct		s_line
{
	char			*line;
	int				current;
	int				n_line;
}					t_line;

typedef struct		s_error
{
	t_token			token;
	t_ins			*instruction;
	t_label			*label;
	int				index_params;
}					t_error;

typedef struct		s_data
{
	int				fd;
	int				fd_file;
	int				ret;
	char			*name_cor;
	char			*name_s;
	bool			quote;
	bool			name_com;
	int				name_and_comment;
	header_t		header;
	int				len;
	int				index;
	t_line			line;
	t_token			*token;
	t_ins			*ins;
	t_label			*ins_label;
	t_name_label	*label;
	t_error			error;
}					t_data;

extern t_op			op_tab[REG_NUMBER + 1];

int			parsing_asm(t_data *data);
void		print_list(t_data *data);
int		check_params(t_data *data, t_token **tmp, t_ins *ins, t_op *val);
void		add_word(t_data *data, t_token word);
int		ft_end_word(char c);
int		skip_whitespace(char *str, int val);
int		get_arg(char *str, int (*fonction)(char));
/*
**			list_chain_new.c
*/
t_token			*new_token(t_token token);
t_ins			*new_instruction(t_op ins);
t_name_label	*new_n_label(char *label, int index);
t_label			*new_label(t_label cpy);
/*
**			list_chain_add.c
*/
void		add_token(t_token **old, t_token new);
t_ins		*add_instruction(t_ins **old, t_op ins);
void		add_n_label(t_name_label **old, char *label, int index);
void		add_label(t_label **old, t_label cpy);
/*
**			print_file.c
*/
void	print_octet(int fd, unsigned int val, size_t nb);
void	print_tab(int fd, t_ins *ins);
int		write_file(t_data *data, int i);
/*
**			ft_is.c
*/
int		separator(char c);
int		label_chars(char c);
int		direct(char c);
int		registre(char c);
int		label(char c);
/*
**			ft_str_is.c
*/
int		ft_is_params(char *str, int (*fonction)(char));
int		ft_is_label(char *str, bool before);
int		ft_is_instruction(char *str, t_op **ins);
/*
**			ft_str_is_number.c
*/
int			ft_str_is_number(char *str);
int			ft_number_ok(char *str);
/*
**			check_token.c
*/
int		check_token(t_data *data);
/*
**			get_token.c
*/
int		get_token(t_data *data);
/*
**			token_utility.c
*/
t_token		token_val(t_token add, int start, int end, int n_line);
void		erase_token(t_token **token);
t_token		cpy_token(t_token *token);
/*
**			add_type.c
*/
int			add_type(char *str, t_op **val);
/*
**			add_word.c
*/
void		add_word(t_data *data, t_token word);
/*
**			check_params.c
*/
int		check_params(t_data *data, t_token **tmp, t_ins *ins, t_op *val);
/*
**			skip_separator.c
*/
int		skip_separator(t_token **tmp, t_op *val, int *i);
/*
**			check_word.c
*/
int		skip_whitespace(char *str, int val);
int		ft_end_word(char c);
#endif