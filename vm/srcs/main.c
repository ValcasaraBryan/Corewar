/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:02:09 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/17 18:46:44 by jdurand-         ###   ########.fr       */
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

int		cycle_to_die(t_storage **st, int nb_cycles)
{
	t_thread	*current;
	int			i;

	i = -1;
	while (++i < nb_cycles)
	{
		current = (*st)->first_thread;
		while (current != NULL)
		{
			if (thread_change_cycle(&current, &((*st)->grid), 1) < SUCCESS)
				return (CALL_FAILED);
			current = current->next;
		}
	}
	print_dump(st);
	return (SUCCESS);
}

int		intro_champions(t_storage **st)
{
	t_champion	*current;

	if (storage_check(st, 0) != VALID_FULL)
		return (BAD_PARAM);
	current = (*st)->first_champion;
	ft_putstr("Introducing contestants...\n");
	while (current != NULL)
	{
		ft_putstr("* Player ");
		ft_putnbr(current->number);
		ft_putstr(", weighing ");
		ft_putnbr(150);
		ft_putstr(" bytes, \"");
		ft_putstr(current->name);
		ft_putstr("\" (\"");
		ft_putstr(current->desc);
		ft_putstr("\") !\n");
		current = current->next;
	}
	return (SUCCESS);
}

int			main(int argv, char **argc)
{
	t_storage	*st;

	(void)argv;
	(void)argc;
	(void)st;
	
	all_ut_instr();
	/*
	all_ut();
	while (1);
	if (setup_all(&st) != SUCCESS
		|| intro_champions(&st) != SUCCESS
		|| cycle_to_die(&st, atoi(argc[1])) != SUCCESS)
	{
		free_storage(&st);
		return (CALL_FAILED);
	}
	free_storage(&st);
	*/
	return (0);
}
