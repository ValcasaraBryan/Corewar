/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:05:08 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/23 19:34:11 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdbool.h>
#define S_ERR	2
#define NO_FILE	"Can't read source file %s\n"
#define SUCCESS	"Writing output program to %s\n"
#define SUFF_F	".s"
#define SUFFIX	".cor"
#define COR		4

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE

#define REG_CODE				1
#define DIR_CODE				2
#define IND_CODE				3

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','
#define CMD_CHAR				'"'

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define PROG_NAME_LENGTH		(128)
#define COMMENT_LENGTH			(2048)

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

#define REG_NUMBER				16

#define TRUE					1
#define IN_TRUE					2
#define FALSE					0

typedef struct		s_ins
{
	unsigned char	token;
	unsigned char	params;
	int				direct;
	int				indirect;
	unsigned char	registre;
	int				len_octet;
	struct s_ins	*next;
}					t_ins;

typedef struct		s_token
{
	char			*cut;
	int				start;
	int				end;
	int				n_line;
	struct s_token	*next;
}					t_token;

typedef struct		s_error
{
	t_ins			**instruction;
	char			*type;
	int				n_line;
	int				index;
}					t_error;

typedef struct		s_line
{
	char			*line;
	int				current;
	int				n_line;
}					t_line;

typedef struct		s_data
{
	int				fd;
	int				ret;
	char			*name_cor;
	char			*name_s;
	bool			quote;
	bool			name_com;
	int				name_and_comment;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				index;
	t_line			line;
	t_token			*token;
	t_ins			*instruction;
	t_error			error;
}					t_data;

typedef struct		s_op
{
	char			*op;
	int				opcode;
	int				len;
}					t_op;

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
#endif