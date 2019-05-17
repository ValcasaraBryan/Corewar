/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:57:40 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/17 18:39:58 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COREWAR_H

# define _COREWAR_H

# define LIVE		"live"
# define LD			"ld"
# define ST			"st"
# define ADD		"add"
# define SUB		"sub"
# define AND		"and"
# define OR			"or"
# define XOR		"xor"
# define ZJMP		"zjmp"
# define LDI		"ldi"
# define STI		"sti"
# define FORK		"fork"
# define LLD		"lld"
# define LLDI		"lldi"
# define LFORK		"lfork"
# define AFF		"aff"
# define T_REG		1
# define T_DIR		2
# define T_IND		4
# define T_LAB		8

typedef struct		s_instruction
{
	int				op_code;
	char			*name;
	int				param_nb;
	int				param_list[3];
	char			*binary;
	char			*hexa;
	int				cycles_nb;
	int				carry_needed;
	int				carry_after;
	int				octal_codage;
	int				dir_size;
	int				(*fct_ptr)(int param_one, int param_two, int param_three);
}					t_instruction;

/*
** ------------------------- instr_add                -------------------------
*/
int					instr_add(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_aff                -------------------------
*/
int					instr_aff(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_and                -------------------------
*/
int					instr_and(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_fork               -------------------------
*/
int					instr_fork(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_ld                 -------------------------
*/
int					instr_ld(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_ldi                -------------------------
*/
int					instr_ldi(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_lfork              -------------------------
*/
int					instr_lfork(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_live               -------------------------
*/
int					instr_live(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_lld                -------------------------
*/
int					instr_lld(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_lldi               -------------------------
*/
int					instr_lldi(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_or                 -------------------------
*/
int					instr_or(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_st                 -------------------------
*/
int					instr_st(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_sti                -------------------------
*/
int					instr_sti(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_sub                -------------------------
*/
int					instr_sub(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_xor                -------------------------
*/
int					instr_xor(int param_one, int param_two, int param_three);

/*
** ------------------------- instr_zjmp               -------------------------
*/
int					instr_zjmp(int param_one, int param_two, int param_three);

#endif
