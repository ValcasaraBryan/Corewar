/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:02:09 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 10:50:53 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

char	*g_tab_dump[64] =
{
	"0x0000 : ", "0x0040 : ", "0x0080 : ", "0x00c0 : ", "0x0100 : ",
	"0x0140 : ", "0x0180 : ", "0x01c0 : ", "0x0200 : ", "0x0240 : ",
	"0x0280 : ", "0x02c0 : ", "0x0300 : ", "0x0340 : ", "0x0380 : ",
	"0x03c0 : ", "0x0400 : ", "0x0440 : ", "0x0480 : ", "0x04c0 : ",
	"0x0500 : ", "0x0540 : ", "0x0580 : ", "0x05c0 : ", "0x0600 : ",
	"0x0640 : ", "0x0680 : ", "0x06c0 : ", "0x0700 : ", "0x0740 : ",
	"0x0780 : ", "0x07c0 : ", "0x0800 : ", "0x0840 : ", "0x0880 : ",
	"0x08c0 : ", "0x0900 : ", "0x0940 : ", "0x0980 : ", "0x09c0 : ",
	"0x0a00 : ", "0x0a40 : ", "0x0a80 : ", "0x0ac0 : ", "0x0b00 : ",
	"0x0b40 : ", "0x0b80 : ", "0x0bc0 : ", "0x0c00 : ", "0x0c40 : ",
	"0x0c80 : ", "0x0cc0 : ", "0x0d00 : ", "0x0d40 : ", "0x0d80 : ",
	"0x0dc0 : ", "0x0e00 : ", "0x0e40 : ", "0x0e80 : ", "0x0ec0 : ",
	"0x0f00 : ", "0x0f40 : ", "0x0f80 : ", "0x0fc0 : "
};

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

	if (setup_all(&st, argv, &argc) != SUCCESS
		|| announce_champions(&st) != SUCCESS
		|| process_battle(&st, st->args[0]) != SUCCESS)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_visu(&st);
		free_storage(&st);
		return (CALL_FAILED);
	}
	ft_free_visu(&st);
	free_storage(&st);
	return (0);
}
