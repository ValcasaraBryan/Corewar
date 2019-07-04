/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:02:09 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 12:43:28 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

t_instruction	g_tab_instructions[18] =
{
	{0, MOVE, 0, { 0 }, "00", 0, 0, 0, 0, 0, *instr_move },
	{1, LIVE, 1, { T_DIR }, "01", 10, -1, -1, 1, 1, *instr_live },
	{2, LD, 2, { T_DIR | T_IND, T_REG }, "02", 5, -1, -1, 0, 1, *instr_ld },
	{3, ST, 2, { T_REG, T_IND | T_REG }, "03", 5, -1, -1, 0, 0, *instr_st },
	{4, ADD, 3, { T_REG, T_REG, T_REG }, "04", 10, -1, -1, 0, 0, *instr_add },
	{5, SUB, 3, { T_REG, T_REG, T_REG }, "05", 10, -1, -1, 0, 0, *instr_sub },
	{6, AND, 3, { T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG }, "06",
		6, -1, -1, 0, 1, *instr_and },
	{7, OR, 3, { T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG }, "07",
		6, -1, -1, 0, 1, *instr_or },
	{8, XOR, 3, { T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG }, "08",
		6, -1, -1, 0, 1, *instr_xor },
	{9, ZJMP, 1, { T_DIR }, "09", 20, -1, -1, 1, 0, *instr_zjmp },
	{10, LDI, 3, { T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG }, "0A", 25, -1,
		-1, 0, 0, *instr_ldi },
	{11, STI, 3, { T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG }, "0B", 25, -1,
		-1, 0, 0, *instr_sti },
	{12, FORK, 1, { T_DIR }, "0C", 800, -1, -1, 1, 0, *instr_fork },
	{13, LLD, 2, { T_DIR | T_IND, T_REG }, "0D", 10, -1, -1, 0, 1, *instr_lld },
	{14, LLDI, 3, { T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG }, "0E", 50, -1,
		-1, 0, 0, *instr_lldi },
	{15, LFORK, 1, { T_DIR }, "0F", 1000, -1, -1, 1, 0, *instr_lfork },
	{16, AFF, 1, { T_REG }, "10", 2, -1, -1, 0, 0, *instr_aff },
	{17, 0, 0, { 0 }, "00", 0, 0, 0, 0, 0, 0 }
};

int			main(int argv, char **argc)
{
	t_storage	*st;

	print_function_state("main", "START");
	if (setup_all(&st, argv, &argc) != SUCCESS
		|| intro_champions(&st) != SUCCESS
		|| process_battle(&st, st->args[0]) != SUCCESS)
	{
		ft_free_visu(&st);
		free_storage(&st);
		return (CALL_FAILED);
	}
	ft_free_visu(&st);
	free_storage(&st);
	print_function_state("main", "END");
	while (1 == 1)
	{
		st = NULL;
	}
	return (0);
}
