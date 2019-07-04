/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:57:40 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 15:31:55 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _COREWAR_H

# define _COREWAR_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# include "../libft/includes/libft.h"
# include "SDL_ttf.h"

# include <stdio.h>

# define GRID_SIZE		64
# define UT_PRINT		0

/*
** instructions
*/

# define MOVE			"move"
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

/*
** return values
*/

# define SUCCESS_INC	20
# define SUCCESS		10
# define NO_CHANGE		0
# define BAD_PARAM		-10
# define MALLOC_FAILED	-20
# define CALL_FAILED	-30
# define BAD_FD			-40
# define FAILURE		-50
# define VALID_FULL		15
# define VALID_EMPTY	5

/*
** op.h
*/

/*
** used
*/
# define T_REG			1
# define T_DIR			2
# define T_IND			4
# define T_LAB			8

# define NO_CODE		0
# define REG_CODE		1
# define DIR_CODE		2
# define IND_CODE		3

# define REG_NUMBER		16
# define MAGIC_NB		0x00EA83F3
# define MAX_PLAYERS	4
# define IDX_MOD		(MEM_SIZE / 8)

# define CYCLE_TO_DIE	1536
# define CYCLE_DELTA	50
# define NBR_LIVE		21
# define MAX_CHECKS		10
# define FPS			60

/*
** unused
*/

# define MAX_ARGS		4
# define MEM_SIZE		(4*1024)
# define CH_MAX_SIZE	(MEM_SIZE / 6)

# define NAME_LENGTH	(128)
# define DESC_LENGTH	(2048)
# define M_NB_LENGTH	(4)

typedef struct			s_thread
{
	int					action;
	int					cycle;
	int					where;
	int					carry;
	int					live;
	int					reg[REG_NUMBER];
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
	int					last_live;
	int					current_lives;
	int					number;
	int					size;
	char				*name;
	char				*desc;
	struct s_byte		*first_byte;
	struct s_byte		*last_byte;
	struct s_champion	*prec;
	struct s_champion	*next;
}						t_champion;

typedef union			u_color
{
	int					color;
	unsigned char		rgb[4];
}						t_color;

typedef struct			s_win
{
	int 				pause;
	int 				nb_threads;
	SDL_Event			*event;
	SDL_Rect 			*rect;
	SDL_Renderer 		*renderer;
	SDL_Surface			*surface;
	SDL_Texture 		*texture;
	SDL_Texture			**tab_b;
	SDL_Texture			**tab_g;
	SDL_Texture			**tab_o;
	SDL_Texture			**tab_v;
	SDL_Texture			**tab_w;
	SDL_Window			*window;
	TTF_Font			*ttf_text;
}						t_win;

typedef struct			s_storage
{
	int					cycle;
	int					nb_live_current;
	int					nb_champ_last_live;
	int					*args;
	int					**grid;
	int					**color_grid;
	struct s_thread		*first_thread;
	struct s_thread		*last_thread;
	struct s_champion	*first_champion;
	struct s_champion	*last_champion;
	struct s_win 		*win;
}						t_storage;

typedef struct			s_instruction
{
	int					instr_nb;
	char				*name;
	int					param_nb;
	int					param_list[3];
	char				*hexa;
	int					cycles_nb;
	int					carry_needed;
	int					carry_after;
	int					no_codage_byte;
	int					size_four_dir;
	int					(*fct_ptr)(t_storage **st, t_thread **th);
}						t_instruction;

extern t_instruction	g_tab_instructions[18];
/*
**						garance
*/
# include <math.h>
# include <unistd.h>
# include <stdbool.h>
# define WIDTH 2300
# define HEIGHT 1152
# define WHITE 0xffffff
# define GREY 0x202020
# define P1 0x33cc33
# define P2 0x0099ff
# define P3 0xff00ff
# define P4 0xff9933
# define OCT_W 28
# define OCT_H 18
# define LETTER_W 10
# include <time.h>
# include <stdlib.h>



int ft_print_game(t_storage **st);
int ft_init_sdl(t_storage **st);
int ft_init_win(t_storage **st);






SDL_Color	argb_to_sdl(Uint32 color);
char *ft_itoa_hexa(int a);
int ft_color_octet(int player);
char	*ft_ctoa(char c);






int				ft_print_infos(t_storage **st);
int			ft_print_threads(t_storage **st);
int		ft_print_grid(t_storage **st);
int		ft_free_visu(t_storage **st);




int						init_args(int **args);








/*
** ------------------------	bin_extractor				------------------------
*/
int						bin_extractor(t_champion **ch, char *path);

/*
** ------------------------	functions_announce			------------------------
*/
int				announce_champions(t_storage **st);
int				announce_winner(t_storage **st);

/*
** ------------------------	functions_byte				------------------------
*/
int						byte_change_value(t_byte **bt, int new_value);

/*
** ------------------------	functions_champion			------------------------
*/
int						champion_change_desc(t_champion **ch, char *new_desc);
int						champion_change_name(t_champion **ch, char *new_name);
int						champion_change_size(t_champion **ch, int new_size);

/*
** ------------------------	functions_get_args			------------------------
*/
int						get_args(t_storage **st, int nb_lines, char ***tab);

/*
** ------------------------	functions_grid				------------------------
*/
int						grid_fill_with_champ(int ***grid, t_champion **ch,
	int nb, int total);
int						grid_fill_with_champ_color(int ***grid, t_champion **ch,
	int nb, int total);

/*
** ------------------------	functions_read_write		------------------------
*/
int						read_in_grid(int ***grid, int where, int nb);
int						write_in_grid(int ***grid, long value, int where,
	int nb);
int						write_in_grid_color(t_storage **st, int t_where,
	int where);

/*
** ------------------------	functions_storage			------------------------
*/
int						storage_get_total_champions(t_storage **st);
int																storage_get_total_threads(t_storage **st);

/*
** ------------------------	functions_thread			------------------------
*/
int						thread_change_action(t_thread **th, int new_action);
int						thread_change_cycle(t_thread **th, t_storage **st, int type);
int						thread_change_value_reg(t_thread **th, int reg,
	int new_value);
int						thread_change_where(t_thread **th, int ***gr,
	int new_where);
int						thread_get_value_reg(t_thread **th, int reg);

/*
** ------------------------	instr_add					------------------------
*/
int						instr_add(t_storage **st, t_thread **th);

/*
** ------------------------	instr_aff					------------------------
*/
int						instr_aff(t_storage **st, t_thread **th);

/*
** ------------------------	instr_and					------------------------
*/
int						instr_and(t_storage **st, t_thread **th);

/*
** ------------------------	instr_fork					------------------------
*/
int						instr_fork(t_storage **st, t_thread **th);

/*
** ------------------------	instr_ld					------------------------
*/
int						instr_ld(t_storage **st, t_thread **th);

/*
** ------------------------	instr_ldi					------------------------
*/
int						instr_ldi(t_storage **st, t_thread **th);

/*
** ------------------------	instr_lfork					------------------------
*/
int						instr_lfork(t_storage **st, t_thread **th);

/*
** ------------------------	instr_live					------------------------
*/
int						instr_live(t_storage **st, t_thread **th);

/*
** ------------------------	instr_lld					------------------------
*/
int						instr_lld(t_storage **st, t_thread **th);

/*
** ------------------------	instr_lldi					------------------------
*/
int						instr_lldi(t_storage **st, t_thread **th);

/*
** ------------------------	instr_move					------------------------
*/
int						instr_move(t_storage **st, t_thread **th);

/*
** ------------------------	instr_or					------------------------
*/
int						instr_or(t_storage **st, t_thread **th);

/*
** ------------------------	instr_st					------------------------
*/
int						instr_st(t_storage **st, t_thread **th);

/*
** ------------------------	instr_sti					------------------------
*/
int						instr_sti(t_storage **st, t_thread **th);

/*
** ------------------------	instr_sub					------------------------
*/
int						instr_sub(t_storage **st, t_thread **th);

/*
** ------------------------	instr_xor					------------------------
*/
int						instr_xor(t_storage **st, t_thread **th);

/*
** ------------------------	instr_zjmp					------------------------
*/
int						instr_zjmp(t_storage **st, t_thread **th);

/*
** ------------------------	manage_byte					------------------------
*/
int						add_byte(t_champion **ch);
int						free_byte_list(t_champion **ch);

/*
** ------------------------	manage_champion				------------------------
*/
int						add_champion(t_storage **st);
int						free_champion_list(t_storage **st);

/*
** ------------------------	manage_grid					------------------------
*/
int						add_grid(t_storage **st, int type);
int						free_grid(t_storage **st, int type);

/*
** ------------------------	manage_print				------------------------
*/
int						print_dump(t_storage **st);
void					print_function_state(char *name, char *msg);
void					print_nb_hexa(int nb);
int						print_usage(void);

/*
** ------------------------	manage_storage				------------------------
*/
int						add_storage(t_storage **st);
int						free_storage(t_storage **st);

/*
** ------------------------	manage_thread				------------------------
*/
int						add_thread(t_storage **st);
int						free_thread_list(t_storage **st);
int						delete_thread(t_storage **st, t_thread **th);

/*
** ------------------------	process_battle				------------------------
*/
int						process_battle(t_storage **st, int nb_cycles);

/*
** ------------------------	set_values_instr			------------------------
*/
int			set_value(t_thread **th, int ***grid, int size, int where);
int			set_value_spe(t_thread **th, int ***grid, int size, int where);
int			set_value_mod(t_thread **th, int ***grid, int size, int where);
int			set_value_mod_spe(t_thread **th, int ***grid, int size, int where);

/*
** ------------------------	structs_check				------------------------
*/
int						byte_check(t_byte **bt);
int						champion_check(t_champion **ch);
int						grid_check(int ***gr);
int						storage_check(t_storage **st, int type);
int						thread_check(t_thread **th);

/*
** ------------------------	structs_setup				------------------------
*/
int						setup_all(t_storage **st, int argv, char ***argc);

/*
** ------------------------	tempo_utility				------------------------
*/
int						free_tab_char(char ***tab);
int						free_tab_int(int **tab);
int						tab_char_create(char ***tab, char ***argc, int **args);
int						tab_int_create(int **tab, int **args);

/*
** ------------------------	utilities					------------------------
*/
int						convert_to_binary(char **res, int nb);
int						decrypt_op_code(int **tab, int nb);
int						get_size_int(int code, int size_dir);
int		failed_action_move(t_storage **st, t_thread **th, int nb_move);
int			check_reg(int reg);

#endif
