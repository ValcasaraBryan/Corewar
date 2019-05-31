/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:02:09 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/31 16:11:47 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

t_instruction	g_tab_instructions[18] =
{
	{0,		0,		0,	{	0																		},	"00000000",	"00",	0,		0,	0,	0,	0,	*instr_move		},
	{1,		LIVE,	1,	{	T_DIR																	},	"00000001",	"01",	10,		-1,	-1,	-1,	-1,	*instr_live		},
	{2,		LD,		2,	{	T_DIR | T_IND,				T_REG										},	"00000010",	"02",	5,		-1,	-1,	-1,	-1,	*instr_ld		},
	{3,		ST,		2,	{	T_REG,						T_IND | T_REG								},	"00000011",	"03",	5,		-1,	-1,	-1,	-1,	*instr_st		},
	{4,		ADD,	3,	{	T_REG,						T_REG,						T_REG			},	"00000100",	"04",	10,		-1,	-1,	-1,	-1,	*instr_add		},
	{5,		SUB,	3,	{	T_REG,						T_REG,						T_REG			},	"00000101",	"05",	10,		-1,	-1,	-1,	-1,	*instr_sub		},
	{6,		AND,	3,	{	T_REG | T_DIR | T_IND,		T_REG | T_IND | T_DIR,		T_REG			},	"00000110",	"06",	6,		-1,	-1,	-1,	-1,	*instr_and		},
	{7,		OR,		3,	{	T_REG | T_IND | T_DIR,		T_REG | T_IND | T_DIR,		T_REG			},	"00000111",	"07",	6,		-1,	-1,	-1,	-1,	*instr_or		},
	{8,		XOR,	3,	{	T_REG | T_IND | T_DIR,		T_REG | T_IND | T_DIR,		T_REG			},	"00001000",	"08",	6,		-1,	-1,	-1,	-1,	*instr_xor		},
	{9,		ZJMP,	1,	{	T_DIR																	},	"00001001",	"09",	20,		-1,	-1,	-1,	-1,	*instr_zjmp		},
	{10,	LDI,	3,	{	T_REG | T_DIR | T_IND,		T_DIR | T_REG,				T_REG			},	"00001010",	"0A",	25,		-1,	-1,	-1,	-1,	*instr_ldi		},
	{11,	STI,	3,	{	T_REG,						T_REG | T_DIR | T_IND,		T_DIR | T_REG	},	"00001011",	"0B",	25,		-1,	-1,	-1,	-1,	*instr_sti		},
	{12,	FORK,	1,	{	T_DIR																	},	"00001100",	"0C",	800,	-1,	-1,	-1,	-1,	*instr_fork		},
	{13,	LLD,	2,	{	T_DIR | T_IND,				T_REG										},	"00001101",	"0D",	10,		-1,	-1,	-1,	-1,	*instr_lld		},
	{14,	LLDI,	3,	{	T_REG | T_DIR | T_IND,		T_DIR | T_REG,				T_REG			},	"00001110",	"0E",	50,		-1,	-1,	-1,	-1,	*instr_lldi		},
	{15,	LFORK,	1,	{	T_DIR																	},	"00001111",	"0F",	1000,	-1,	-1,	-1,	-1,	*instr_lfork	},
	{16,	AFF,	1,	{	T_REG																	},	"00010000",	"10",	2,		-1,	-1,	-1,	-1,	*instr_aff		},
	{17,	0,		0,	{	0																		},	"00000000",	"00",	0,		0,	0,	0,	0,	0				}
};

int			main(int argv, char **argc)
{
	int		show_usage;

	show_usage = 0;
	(void)g_tab_instructions;
	(void)argc;
	(void)argv;
	//usage
	all_ut();
	while (1);
	return (0);
}
