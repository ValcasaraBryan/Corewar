/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:57:40 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/31 16:11:20 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COREWAR_H

# define _COREWAR_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define GRID_SIZE		64

# define UT_PRINT		1

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
	int					action;
	int					cycle;
	int					nb_champion;
	int					where;
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
	int					reg[16];
	char				*name;
	char				*desc;
	struct s_byte		*first_byte;
	struct s_byte		*last_byte;
	struct s_champion	*prec;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_storage
{
	int					**grid;
	struct s_thread		*first_thread;
	struct s_thread		*last_thread;
	struct s_champion	*first_champion;
	struct s_champion	*last_champion;
}						t_storage;

typedef struct			s_instruction
{
	int					instr_nb;
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
	int					(*fct_ptr)(t_thread **th, int ***gr);
}						t_instruction;

extern t_instruction	g_tab_instructions[18];

/*
** ------------------------- bin_extractor           -------------------------
*/
int						bin_extractor(t_champion **ch, char *path);

/*
** ------------------------- functions_byte           -------------------------
*/
int						byte_change_value(t_byte **bt, int new_value);
int						byte_check(t_byte **bt);

/*
** ------------------------- functions_champion       -------------------------
*/
int						champion_change_desc(t_champion **ch, char *new_desc);
int						champion_change_name(t_champion **ch, char *new_name);
int						champion_change_number(t_champion **ch, int new_nb);
int						champion_check(t_champion **ch);

/*
** ------------------------- functions_grid           -------------------------
*/
int						grid_check(int ***gr);
int						grid_fill_with_champ(int ***grid, t_champion **ch);

/*
** ------------------------- functions_storage        -------------------------
*/
int						storage_check(t_storage **st, int type);

/*
** ------------------------- functions_thread         -------------------------
*/
int						thread_change_action(t_thread **th, int new_action);
int						thread_change_cycle(t_thread **th, int ***gr, int type);
int						thread_change_nb_champion(t_thread **th, int new_nb);
int						thread_change_where(t_thread **th, int ***gr,
	int new_where);
int						thread_check(t_thread **th);

/*
** ------------------------- instr_add                -------------------------
*/
int						instr_add(t_thread **th, int ***gr);

/*
** ------------------------- instr_aff                -------------------------
*/
int						instr_aff(t_thread **th, int ***gr);

/*
** ------------------------- instr_and                -------------------------
*/
int						instr_and(t_thread **th, int ***gr);

/*
** ------------------------- instr_fork               -------------------------
*/
int						instr_fork(t_thread **th, int ***gr);

/*
** ------------------------- instr_ld                 -------------------------
*/
int						instr_ld(t_thread **th, int ***gr);

/*
** ------------------------- instr_ldi                -------------------------
*/
int						instr_ldi(t_thread **th, int ***gr);

/*
** ------------------------- instr_lfork              -------------------------
*/
int						instr_lfork(t_thread **th, int ***gr);

/*
** ------------------------- instr_live               -------------------------
*/
int						instr_live(t_thread **th, int ***gr);

/*
** ------------------------- instr_lld                -------------------------
*/
int						instr_lld(t_thread **th, int ***gr);

/*
** ------------------------- instr_lldi               -------------------------
*/
int						instr_lldi(t_thread **th, int ***gr);

/*
** ------------------------- instr_move               -------------------------
*/
int						instr_move(t_thread **th, int ***gr);

/*
** ------------------------- instr_or                 -------------------------
*/
int						instr_or(t_thread **th, int ***gr);

/*
** ------------------------- instr_st                 -------------------------
*/
int						instr_st(t_thread **th, int ***gr);

/*
** ------------------------- instr_sti                -------------------------
*/
int						instr_sti(t_thread **th, int ***gr);

/*
** ------------------------- instr_sub                -------------------------
*/
int						instr_sub(t_thread **th, int ***gr);

/*
** ------------------------- instr_xor                -------------------------
*/
int						instr_xor(t_thread **th, int ***gr);

/*
** ------------------------- instr_zjmp               -------------------------
*/
int						instr_zjmp(t_thread **th, int ***gr);

/*
** ------------------------- key_functions             -------------------------
*/
int						cycle_threads(t_storage **st);
int						decrypt_op_code(int **tab, int nb);
int						read_in_grid(int ***grid, int where);
int						write_in_grid(int ***grid, int value, int where);

/*
** ------------------------- manage_byte               -------------------------
*/
int						add_byte(t_champion **ch);
int						free_byte_list(t_champion **ch);

/*
** ------------------------- manage_champion          -------------------------
*/
int						add_champion(t_storage **st);
int						free_champion_list(t_storage **st);

/*
** ------------------------- manage_grid              -------------------------
*/
int						add_grid(t_storage **st);
int						free_grid(t_storage **st);

/*
** ------------------------- manage_storage           -------------------------
*/
int						add_storage(t_storage **st);
int						free_storage(t_storage **st);

/*
** ------------------------- manage_thread            -------------------------
*/
int						add_thread(t_storage **st);
int						free_thread_list(t_storage **st);

/*
** ------------------------- print_structs            -------------------------
*/
int						print_byte_list(t_champion **ch);
int						print_champion_list(t_storage **st);
int						print_grid(t_storage **st);
int						print_storage(t_storage **st);
int						print_thread_list(t_storage **st);
int						print_thread_list_compact(t_storage **st);

/*
** ------------------------- unit_tests               -------------------------
*/
int						all_ut(void);

/*
** ------------------------- utilities                -------------------------
*/
int						convert_to_binary(char **res, int nb);
void					print_nb_hexa(int nb);

#endif
