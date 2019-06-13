/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:05:08 by brvalcas          #+#    #+#             */
/*   Updated: 2019/06/13 18:07:51 by bryanvalcas      ###   ########.fr       */
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
#define NO_FILE	"Can't read source file %s\n"
#define SUCCESS	"Writing output program to %s\n"
#define SUFF_F	".s"
#define SUFFIX	".cor"
#define COR		4

// #define IND_SIZE				2
// #define REG_SIZE				4
// #define DIR_SIZE				REG_SIZE

// #define REG_CODE				1
// #define DIR_CODE				2
// #define IND_CODE				3
// 
// #define COMMENT_CHAR			'#'
// #define LABEL_CHAR				':'
// #define DIRECT_CHAR				'%'
// #define SEPARATOR_CHAR			','
#define CMD_CHAR				'"'
// 
// #define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
// 
// #define NAME_CMD_STRING			".name"
// #define COMMENT_CMD_STRING		".comment"
// 
// #define PROG_NAME_LENGTH		(128)
// #define COMMENT_LENGTH			(2048)

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
	unsigned char	octet;
	int				*params;
	struct s_ins	*next;
}					t_ins;

typedef struct		s_label
{
	t_ins			**ins;
	int				index_params;
	struct s_label	*next;
}					t_label;

typedef struct		s_token
{
	char			*cut;
	int				type;
	int				start;
	int				end;
	int				n_line;
	struct s_token	*next;
}					t_token;

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
	header_t		header;
	int				len;
	int				index;
	t_line			line;
	t_token			*token;
	t_ins			*ins;
}					t_data;

extern t_op			op_tab[REG_NUMBER + 1];

void	init_data(t_data *data, char *av);
int		parsing_asm(t_data *data);
void		print_list(t_data *data);

#endif