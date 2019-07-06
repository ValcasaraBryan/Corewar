/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:05:08 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/05 22:13:28 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "../../op.h"
# include <stdbool.h>
# define S_ERR					2
# define READ					"read"
# define OPEN					"open"
# define CREAT					"create"
# define NO_FILE				"Can't %s source file %s\n"
# define SUCCESS				"Writing output program to %s\n"
# define SUFF_F					".s"
# define SUFFIX					".cor"
# define COR					4

# define CMD_CHAR				'"'

# define LIVE					1
# define LD						2
# define ST						3
# define ADD					4
# define SUB					5
# define AND					6
# define OR						7
# define XOR					8
# define ZJMP					9
# define LDI					10
# define STI					11
# define FORK					12
# define LLD					13
# define LLDI					14
# define LFORK					15
# define AFF					16

# define DIRECT					1
# define INDIRECT				2
# define REGISTER				3
# define INSTRUCTION			4
# define LABEL					5
# define DIRECT_LABEL			6
# define INDIRECT_LABEL			7
# define SEPARATOR				8
# define TOKEN					9
# define ENDLINE				10
# define NAME					12
# define COMMENT				13
# define STRING					14

# define TRUE					1
# define IN_TRUE				2
# define FALSE					0
# define DIRECT_MSG				"direct"
# define INDIRECT_MSG			"indirect"
# define REGISTER_MSG			"register"
# define INSTRUCTION_MSG		"instruction"
# define TOKEN_ENDLINE			"ENDLINE"
# define MSG_DIRECT				"DIRECT"
# define MSG_DIRECT_LABEL		"DIRECT_LABEL"
# define MSG_INDIRECT			"INDIRECT"
# define MSG_INDIRECT_LABEL		"INDIRECT_LABEL"
# define MSG_REGISTER			"REGISTER"
# define MSG_INSTRUCTION		"INSTRUCTION"
# define MSG_SEPARATEUR			"SEPARATOR"
# define MSG_CMD_COMMENT		"COMMAND_COMMENT"
# define MSG_CMD_NAME			"COMMAND_NAME"

# define MSG_COMMENT			"comment"
# define MSG_NAME				"name"
# define NO_NEW_LINE_3			"(Perhaps you forgot to end with a newline ?)\n"
# define NO_NEW_LINE_2			"Syntax error - unexpected end of input "
# define NO_NEWLINE				NO_NEW_LINE_2 NO_NEW_LINE_3
# define COMMAND_MISS			"It misses .name and .comment on the first lines\n"
# define INVALID_PARAMS			"Invalid parameter %d "
# define ERROR_MSG				"for instruction %s \"%s\"\n"
# define BAD_MSG				"type %s for instruction %s\n"
# define ERROR_PARAMS			INVALID_PARAMS ERROR_MSG
# define BAD_PARAMS				INVALID_PARAMS BAD_MSG
# define ERROR_COUNT			"Invalid parameter count for instruction %s\n"
# define MSG_LABEL_2			"No such label \"%s\" while "
# define MSG_LABEL_3			"attempting to dereference token \n"
# define MSG_LABEL				MSG_LABEL_2 MSG_LABEL_3
# define MSG_SYN				"Syntax error at token \"%s\"\n"
# define MSG_SYN_TYPE			"Syntax error at token %s \"%s\"\n"
# define MSG_TOO_LONG			"Champion %s too long (Max length %d)\n"
# define ERROR_MALLOC			"Error malloc\n"
# define ERROR_SUFFIX			"There is no suffix \".s\" at the end of \"%s\"\n"

typedef struct					s_op
{
	char						*ins;
	int							len;
	unsigned char				len_params;
	unsigned char				params[3];
	unsigned char				opcode;
	int							cycle;
	char						*description;
	unsigned char				indirect;
	unsigned char				direct;
}								t_op;

typedef struct					s_ins
{
	t_op						ins;
	unsigned char				codage[3];
	unsigned char				octet;
	int							*params;
	int							len;
	struct s_ins				*next;
}								t_ins;

typedef struct					s_token
{
	char						*cut;
	int							type;
	int							start;
	int							end;
	int							n_line;
	struct s_token				*next;
}								t_token;

typedef struct					s_label
{
	t_ins						*ins;
	t_token						token;
	char						*label;
	int							len;
	int							index_ins;
	int							index_params;
	struct s_label				*next;
}								t_label;

typedef struct					s_name_label
{
	char						*label;
	int							len;
	int							index_ins;
	struct s_name_label			*next;
}								t_name_label;

typedef struct					s_line
{
	char						*line;
	int							current;
}								t_line;

typedef struct					s_error
{
	bool						error;
}								t_error;

typedef struct					s_data
{
	int							fd;
	int							fd_file;
	int							ret;
	char						*name_cor;
	char						*name_s;
	bool						quote;
	bool						name;
	bool						comment;
	header_t					header;
	int							len;
	int							n_line;
	int							index;
	t_line						line;
	t_token						*token;
	t_ins						*ins;
	t_label						*ins_label;
	t_name_label				*label;
	t_error						error;
}								t_data;

typedef struct					s_params
{
	int							i;
	int							start_cut;
	t_data						*data;
	t_token						**tmp;
	t_ins						*ins;
	t_op						*val;
	t_label						cpy;
}								t_params;

extern t_op						g_op_tab[REG_NUMBER + 1];
/*
**			asm.c
*/
int								parsing_asm(t_data *data);
/*
**			list_chain_new.c
*/
t_token							*new_token(t_token token);
t_ins							*new_instruction(t_op ins);
t_name_label					*new_n_label(char *label, int index);
t_label							*new_label(t_label cpy);
/*
**			list_chain_add.c
*/
void							add_token(t_token **old, t_token new);
t_ins							*add_instruction(t_ins **old, t_op ins);
void							add_n_label(t_name_label **old,
								char *label, int index);
void							add_label(t_label **old, t_label cpy);
/*
**			print_file.c
*/
void							write_file(t_data *data, int i);
/*
**			ft_is.c
*/
int								separator(char c);
int								label_chars(char c);
int								direct(char c);
int								registre(char c);
int								label(char c);
/*
**			ft_str_is.c
*/
int								ft_is_params(char *str, int (*fonction)(char));
int								ft_is_label(char *str, bool before);
int								ft_is_instruction(char *str, t_op **ins);
int								ft_is_string(char *str);
/*
**			ft_str_is_number.c
*/
int								ft_str_is_number(char *str);
int								ft_number_ok(char *str);
/*
**			check_token.c
*/
int								check_token(t_data *data);
/*
**			get_token.c
*/
int								get_token(t_data *data);
/*
**			token_utility.c
*/
t_token							token_val(t_token add, int start, int end);
t_token							cpy_token(t_token *token);
/*
**			add_type.c
*/
int								add_type(char *str, t_op **val);
/*
**			add_word.c
*/
void							add_word(t_data *data, t_token word);
/*
**			check_params.c
*/
int								check_params(t_params p);
/*
**			skip_separator.c
*/
int								skip_separator(t_token **tmp, t_op *val,
								int *i);
/*
**			check_word.c
*/
int								skip_whitespace(char *str, int val);
int								ft_end_word(char c);
int								get_arg(char *str, int (*fonction)(char));
/*
**			liberation.c
*/
void							erase_token(t_token **token);
void							erase_ins(t_ins **ins);
void							erase_label(t_label **label);
void							erase_name_label(t_name_label **label);
/*
**			quote.c
*/
int								add_quote(t_data *data, t_token **token);
/*
**			error_msg.c
*/
int								error_params(int index, int type, char *ins);
int								error_params_two(int type, char *ins);
int								error_count(t_params p);
int								error_no_ins(t_data *data, t_ins *ins);
int								error_malloc(void);
/*
**			check_label.c
*/
int								check_label(t_data *data);
/*
**			suffix_name.c
*/
int								suffix_name(t_data *data, const char *s);
#endif
