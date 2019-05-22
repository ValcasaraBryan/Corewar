/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:57:40 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 18:18:45 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COREWAR_H

# define _COREWAR_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

# include <stdio.h>

# define GRID_SIZE		10

# define LIVE			"live"
# define LD				"ld"
# define ST				"st"
# define ADD			"add"
# define SUB			"sub"
# define AND			"and"
# define OR				"or"
# define XOR			"xor"
# define ZJMP			"zjmp"
# define LDI			"ldi"
# define STI			"sti"
# define FORK			"fork"
# define LLD			"lld"
# define LLDI			"lldi"
# define LFORK			"lfork"
# define AFF			"aff"
# define T_REG			1
# define T_DIR			2
# define T_IND			4
# define T_LAB			8

typedef struct			s_thread
{
	int					current_action;
	int					current_cycle;
	int					current_place;
	struct s_thread		*prec;
	struct s_thread		*next;
}						t_thread;

typedef struct			s_byte
{
	int					value;
	struct s_byte		*prec;
	struct s_byte		*next;
}						t_byte;

typedef struct			s_champion
{
	int					number;
	char				*name;
	char				*desc;
	struct s_byte		*first_byte;
	struct s_byte		*last_byte;
	struct s_champion	*prec;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_storage
{
	struct s_thread		*first_thread;
	struct s_thread		*last_thread;
	struct s_champion	*first_champion;
	struct s_champion	*last_champion;
}						t_storage;

typedef struct			s_instruction
{
	int					op_code;
	char				*name;
	int					param_nb;
	int					param_list[3];
	char				*binary;
	char				*hexa;
	int					cycles_nb;
	int					carry_needed;
	int					carry_after;
	int					octal_codage;
	int					dir_size;
	int					(*fct_ptr)(int a, int b, int c);
}						t_instruction;

extern t_instruction	g_tab_instructions[17];

/*
** ------------------------- byte_functions           -------------------------
*/
int						byte_change_value(t_byte **bt, int new_value);

/*
** ------------------------- champion_functions       -------------------------
*/
int						champion_change_desc(t_champion **ch, char *new_desc);
int						champion_change_name(t_champion **ch, char *new_name);
int						champion_change_number(t_champion **ch, int new_nb);

/*
** ------------------------- champion_functions       -------------------------
*/
int						fill_grid_with_champ(int ***grid, t_champion **ch);

/*
** ------------------------- instr_add                -------------------------
*/
int						instr_add(int a, int b, int c);

/*
** ------------------------- instr_aff                -------------------------
*/
int						instr_aff(int a, int b, int c);

/*
** ------------------------- instr_and                -------------------------
*/
int						instr_and(int a, int b, int c);

/*
** ------------------------- instr_fork               -------------------------
*/
int						instr_fork(int a, int b, int c);

/*
** ------------------------- instr_ld                 -------------------------
*/
int						instr_ld(int a, int b, int c);

/*
** ------------------------- instr_ldi                -------------------------
*/
int						instr_ldi(int a, int b, int c);

/*
** ------------------------- instr_lfork              -------------------------
*/
int						instr_lfork(int a, int b, int c);

/*
** ------------------------- instr_live               -------------------------
*/
int						instr_live(int a, int b, int c);

/*
** ------------------------- instr_lld                -------------------------
*/
int						instr_lld(int a, int b, int c);

/*
** ------------------------- instr_lldi               -------------------------
*/
int						instr_lldi(int a, int b, int c);

/*
** ------------------------- instr_or                 -------------------------
*/
int						instr_or(int a, int b, int c);

/*
** ------------------------- instr_st                 -------------------------
*/
int						instr_st(int a, int b, int c);

/*
** ------------------------- instr_sti                -------------------------
*/
int						instr_sti(int a, int b, int c);

/*
** ------------------------- instr_sub                -------------------------
*/
int						instr_sub(int a, int b, int c);

/*
** ------------------------- instr_xor                -------------------------
*/
int						instr_xor(int a, int b, int c);

/*
** ------------------------- instr_zjmp               -------------------------
*/
int						instr_zjmp(int a, int b, int c);

/*
** ------------------------- key_functions             -------------------------
*/
int						write_in_grid(int ***grid, int value, int where);

/*
** ------------------------- manage_byte               -------------------------
*/
int						add_byte(t_champion **ch);
int						check_byte(t_byte **bt);
void					free_byte_list(t_champion **ch);
void					print_byte_list(t_champion **ch);

/*
** ------------------------- manage_champion          -------------------------
*/
int						add_champion(t_storage **st);
int						check_champion_byte(t_champion **ch);
void					free_champion_list(t_storage **st);
void					print_champion_list(t_storage **st);

/*
** ------------------------- manage_grid              -------------------------
*/
int						add_grid(int ***grid);
void					free_grid(int ***grid);
void					print_grid(int ***grid);

/*
** ------------------------- manage_storage           -------------------------
*/
int						add_storage(t_storage **st);
int						check_storage_champion(t_storage **st);
int						check_storage_thread(t_storage **st);
void					free_storage(t_storage **st);
void					print_storage(t_storage **st);

/*
** ------------------------- manage_thread            -------------------------
*/
int						add_thread(t_storage **st, int place);
void					free_thread_list(t_storage **st);
void					print_thread_list(t_storage **st);

/*
** ------------------------- unit_tests               -------------------------
*/
int						ut_byte(void);
int						ut_champion(void);
int						ut_grid(void);
int						ut_storage(void);
int						ut_thread(void);
int						all_ut(void);

/*
** ------------------------- utilities                -------------------------
*/
void					print_nb_hexa(int nb);

#endif
