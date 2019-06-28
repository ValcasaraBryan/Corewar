/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests_instr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:32:22 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/28 10:40:28 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		ut_add_01(void)
{
	/*
	** instr_add avec params null
	*/
	int			result;

	result = instr_add(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_add_02(void)
{
	/*
	** instr_add avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_add(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_add_03(void)
{
	/*
	** instr_add avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_add(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_add_04(void)
{
	/*
	** instr_add avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_add(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_add_05(void)
{
	/*
	** instr_add avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_add(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_add_06(void)
{
	/*
	** instr_add avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_add(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_add_07(void)
{
	/*
	** instr_add avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_add(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_add_08(void)
{
	/*
	** instr_add avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 84, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 3, 1);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	thread_change_value_reg(&(st->last_thread), 1, 5);
	thread_change_value_reg(&(st->last_thread), 2, 7);
	thread_change_value_reg(&(st->last_thread), 3, 9);
	result = thread_get_value_reg(&(st->last_thread), 3) == 9 ? 1 : 0;
	result += instr_add(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 12 ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_aff_01(void)
{
	/*
	** instr_aff avec params null
	*/
	int			result;

	result = instr_aff(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_aff_02(void)
{
	/*
	** instr_aff avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_aff(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_aff_03(void)
{
	/*
	** instr_aff avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_aff(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_aff_04(void)
{
	/*
	** instr_aff avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_aff(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_aff_05(void)
{
	/*
	** instr_aff avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_aff(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_aff_06(void)
{
	/*
	** instr_aff avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_aff(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_aff_07(void)
{
	/*
	** instr_aff avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_aff(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_aff_08(void)
{
	/*
	** instr_aff avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 64, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	thread_change_value_reg(&(st->last_thread), 1, 9);
	result = thread_get_value_reg(&(st->last_thread), 1) == 9 ? 1 : 0;
	result += instr_aff(&st, &(st->last_thread));
	free_storage(&st);
	return (result == 1 + SUCCESS);
}

static int		ut_and_01(void)
{
	/*
	** instr_and avec params null
	*/
	int			result;

	result = instr_and(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_and_02(void)
{
	/*
	** instr_and avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_and(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_and_03(void)
{
	/*
	** instr_and avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_and(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_and_04(void)
{
	/*
	** instr_and avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_and(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_and_05(void)
{
	/*
	** instr_and avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_and(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_and_06(void)
{
	/*
	** instr_and avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_and(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_and_07(void)
{
	/*
	** instr_and avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_and(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_and_08(void)
{
	/*
	** instr_and avec params valides
	** registres seulement
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 84, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 3, 1);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	thread_change_value_reg(&(st->last_thread), 1, 5);
	thread_change_value_reg(&(st->last_thread), 2, 9);
	thread_change_value_reg(&(st->last_thread), 3, 15);
	result = thread_get_value_reg(&(st->last_thread), 3) == 15 ? 1 : 0;
	result += instr_and(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == (5 & 9) ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_and_09(void)
{
	/*
	** instr_and avec params valides
	** directs seulement
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 164, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 2, 4);
	write_in_grid(&(st->grid), 23, st->last_thread->where + 6, 4);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 10, 1);
	thread_change_value_reg(&(st->last_thread), 3, 15);
	result = thread_get_value_reg(&(st->last_thread), 3) == 15 ? 1 : 0;
	result += instr_and(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3)
		== (read_in_grid(&(st->grid), st->last_thread->where - 9, 4)
		& read_in_grid(&(st->grid), st->last_thread->where - 5, 4)) ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_and_10(void)
{
	/*
	** instr_and avec params valides
	** indirects seulement
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 244, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 69, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 444, st->last_thread->where + 4, 2);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 6, 1);
	write_in_grid(&(st->grid), 5946, st->last_thread->where + 69, 4);
	write_in_grid(&(st->grid), 231, st->last_thread->where + 444, 4);
	thread_change_value_reg(&(st->last_thread), 3, 15);
	result = thread_get_value_reg(&(st->last_thread), 3) == 15 ? 1 : 0;
	result += instr_and(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3)
		== (read_in_grid(&(st->grid), st->last_thread->where + 69 - 7, 4)
		& read_in_grid(&(st->grid), st->last_thread->where + 444 - 7, 4)) ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_fork_01(void)
{
	/*
	** instr_fork avec params null
	*/
	int			result;

	result = instr_fork(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_fork_02(void)
{
	/*
	** instr_fork avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_fork(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_fork_03(void)
{
	/*
	** instr_fork avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_fork(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_fork_04(void)
{
	/*
	** instr_fork avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_fork(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_fork_05(void)
{
	/*
	** instr_fork avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_fork(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_fork_06(void)
{
	/*
	** instr_fork avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_fork(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_fork_07(void)
{
	/*
	** instr_fork avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_fork(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_fork_08(void)
{
	/*
	** instr_fork avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 256, st->last_thread->where + 1, 2);
	result = instr_fork(&st, &(st->last_thread));
	result += st->last_thread->where == 256 ? 1 : 0;
	result += st->last_thread->prec->where == 3 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + 1);
}

static int		ut_ld_01(void)
{
	/*
	** instr_ld avec params null
	*/
	int			result;

	result = instr_ld(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_ld_02(void)
{
	/*
	** instr_ld avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_ld(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ld_03(void)
{
	/*
	** instr_ld avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_ld(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ld_04(void)
{
	/*
	** instr_ld avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_ld(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_ld_05(void)
{
	/*
	** instr_ld avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_ld(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ld_06(void)
{
	/*
	** instr_ld avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_ld(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ld_07(void)
{
	/*
	** instr_ld avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_ld(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ld_08(void)
{
	/*
	** instr_ld avec params valides
	** direct
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 144, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 2, 4);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 6, 1);
	thread_change_value_reg(&(st->last_thread), 1, 1);
	result = thread_get_value_reg(&(st->last_thread), 1) == 1 ? 1 : 0;
	result += instr_ld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 1) == -1 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 2147483647, st->last_thread->where + 2, 4);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 6, 1);
	thread_change_value_reg(&(st->last_thread), 2, 1);
	result += thread_get_value_reg(&(st->last_thread), 2) == 1 ? 1 : 0;
	result += instr_ld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 2) == 2147483647 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), -2147483648, st->last_thread->where + 2, 4);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 6, 1);
	thread_change_value_reg(&(st->last_thread), 3, 1);
	result += thread_get_value_reg(&(st->last_thread), 3) == 1 ? 1 : 0;
	result += instr_ld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == -2147483648 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_ld_09(void)
{
	/*
	** instr_ld avec params valides
	** indirect
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 208, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 40, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 4, 1);
	write_in_grid(&(st->grid), 65535, st->last_thread->where + 40, 4);
	thread_change_value_reg(&(st->last_thread), 1, 1);
	result = thread_get_value_reg(&(st->last_thread), 1) == 1 ? 1 : 0;
	result += instr_ld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 1) == 65535 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 95, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 4, 1);
	write_in_grid(&(st->grid), 3333, st->last_thread->where + 95, 4);
	thread_change_value_reg(&(st->last_thread), 2, 1);
	result += thread_get_value_reg(&(st->last_thread), 2) == 1 ? 1 : 0;
	result += instr_ld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 2) == 3333 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 5984, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	write_in_grid(&(st->grid), 23, st->last_thread->where + 5984 % IDX_MOD, 4);
	thread_change_value_reg(&(st->last_thread), 3, 1);
	result += thread_get_value_reg(&(st->last_thread), 3) == 1 ? 1 : 0;
	result += instr_ld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 23 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_ldi_01(void)
{
	/*
	** instr_ldi avec params null
	*/
	int			result;

	result = instr_ldi(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_ldi_02(void)
{
	/*
	** instr_ldi avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_ldi(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ldi_03(void)
{
	/*
	** instr_ldi avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_ldi(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ldi_04(void)
{
	/*
	** instr_ldi avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_ldi(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_ldi_05(void)
{
	/*
	** instr_ldi avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_ldi(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ldi_06(void)
{
	/*
	** instr_ldi avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_ldi(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ldi_07(void)
{
	/*
	** instr_ldi avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_ldi(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_ldi_08(void)
{
	/*
	** instr_ldi avec params valides
	** registres
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 84, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 3, 1);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	write_in_grid(&(st->grid), 64, st->last_thread->where + 5, 4);
	thread_change_value_reg(&(st->last_thread), 1, 1);
	thread_change_value_reg(&(st->last_thread), 2, 4);
	thread_change_value_reg(&(st->last_thread), 3, -1);
	result = thread_get_value_reg(&(st->last_thread), 1) == 1 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 2) == 4 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 3) == -1 ? 1 : 0;
	result += instr_ldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 64 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	thread_change_value_reg(&(st->last_thread), 1, 0);
	thread_change_value_reg(&(st->last_thread), 2, 1);
	result += thread_get_value_reg(&(st->last_thread), 1) == 0 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 2) == 1 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 3) == 64 ? 1 : 0;
	result += instr_ldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 1409352195 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + 1 + 1 + SUCCESS + 1 + 1 + 1 + 1 + SUCCESS + 1);
}

static int		ut_ldi_09(void)
{
	/*
	** instr_ldi avec params valides
	** directs
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 164, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 4, 2);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 6, 1);
	thread_change_value_reg(&(st->last_thread), 3, -1);
	result = thread_get_value_reg(&(st->last_thread), 3) == -1 ? 1 : 0;
	result += instr_ldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 164 ? 1 : 0;
	printf("result = %d\n", result);
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 4, 2);
	result += thread_get_value_reg(&(st->last_thread), 3) == 164 ? 1 : 0;
	result += instr_ldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 65537 ? 1 : 0;
	printf("result = %d\n", result);
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_ldi_10(void)
{
	/*
	** instr_ldi avec params valides
	** indirect + direct
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 228, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 10, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 4, 2);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 6, 1);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 10, 4);
	thread_change_value_reg(&(st->last_thread), 3, -1);
	result = thread_get_value_reg(&(st->last_thread), 3) == -1 ? 1 : 0;
	result += instr_ldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 228 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 20, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 4, 2);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 20, 4);
	result += thread_get_value_reg(&(st->last_thread), 3) == 228 ? 1 : 0;
	result += instr_ldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 14942228 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_lfork_01(void)
{
	/*
	** instr_lfork avec params null
	*/
	int			result;

	result = instr_lfork(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_lfork_02(void)
{
	/*
	** instr_lfork avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_lfork(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lfork_03(void)
{
	/*
	** instr_lfork avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_lfork(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lfork_04(void)
{
	/*
	** instr_lfork avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_lfork(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_lfork_05(void)
{
	/*
	** instr_lfork avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_lfork(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lfork_06(void)
{
	/*
	** instr_lfork avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_lfork(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lfork_07(void)
{
	/*
	** instr_lfork avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_lfork(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lfork_08(void)
{
	/*
	** instr_lfork avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 256, st->last_thread->where + 1, 2);
	result = instr_lfork(&st, &(st->last_thread));
	result += st->last_thread->where == 256 ? 1 : 0;
	result += st->last_thread->prec->where == 3 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + 1);
}

static int		ut_live_01(void)
{
	/*
	** instr_live avec params null
	*/
	int			result;

	result = instr_live(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_live_02(void)
{
	/*
	** instr_live avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_live(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_live_03(void)
{
	/*
	** instr_live avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_live(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_live_04(void)
{
	/*
	** instr_live avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_live(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_live_05(void)
{
	/*
	** instr_live avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_live(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_live_06(void)
{
	/*
	** instr_live avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_live(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_live_07(void)
{
	/*
	** instr_live avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_live(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_live_08(void)
{
	/*
	** instr_live sans champion
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	result = instr_live(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_live_09(void)
{
	/*
	** instr_live avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_champion(&st);
	add_thread(&st);
	result = instr_live(&st, &(st->last_thread));
	free_storage(&st);
	return (result == SUCCESS);
}

static int		ut_lld_01(void)
{
	/*
	** instr_lld avec params null
	*/
	int			result;

	result = instr_lld(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_lld_02(void)
{
	/*
	** instr_lld avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_lld(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lld_03(void)
{
	/*
	** instr_lld avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_lld(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lld_04(void)
{
	/*
	** instr_lld avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_lld(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_lld_05(void)
{
	/*
	** instr_lld avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_lld(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lld_06(void)
{
	/*
	** instr_lld avec grid vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_lld(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lld_07(void)
{
	/*
	** instr_lld avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_lld(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lld_08(void)
{
	/*
	** instr_lld avec params valides
	** direct
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 144, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 2, 4);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 6, 1);
	thread_change_value_reg(&(st->last_thread), 1, 1);
	result = thread_get_value_reg(&(st->last_thread), 1) == 1 ? 1 : 0;
	result += instr_lld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 1) == -1 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 2147483647, st->last_thread->where + 2, 4);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 6, 1);
	thread_change_value_reg(&(st->last_thread), 2, 1);
	result += thread_get_value_reg(&(st->last_thread), 2) == 1 ? 1 : 0;
	result += instr_lld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 2) == 2147483647 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), -2147483648, st->last_thread->where + 2, 4);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 6, 1);
	thread_change_value_reg(&(st->last_thread), 3, 1);
	result += thread_get_value_reg(&(st->last_thread), 3) == 1 ? 1 : 0;
	result += instr_lld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == -2147483648 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_lld_09(void)
{
	/*
	** instr_lld avec params valides
	** indirect
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 208, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 40, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 4, 1);
	write_in_grid(&(st->grid), 65535, st->last_thread->where + 40, 4);
	thread_change_value_reg(&(st->last_thread), 1, 1);
	result = thread_get_value_reg(&(st->last_thread), 1) == 1 ? 1 : 0;
	result += instr_lld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 1) == 65535 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 95, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 4, 1);
	write_in_grid(&(st->grid), 3333, st->last_thread->where + 95, 4);
	thread_change_value_reg(&(st->last_thread), 2, 1);
	result += thread_get_value_reg(&(st->last_thread), 2) == 1 ? 1 : 0;
	result += instr_lld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 2) == 3333 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 5984, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	write_in_grid(&(st->grid), 23, st->last_thread->where + 5984, 4);
	thread_change_value_reg(&(st->last_thread), 3, 1);
	result += thread_get_value_reg(&(st->last_thread), 3) == 1 ? 1 : 0;
	result += instr_lld(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 23 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_lldi_01(void)
{
	/*
	** instr_lldi avec params null
	*/
	int			result;

	result = instr_lldi(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_lldi_02(void)
{
	/*
	** instr_lldi avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_lldi(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lldi_03(void)
{
	/*
	** instr_lldi avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_lldi(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lldi_04(void)
{
	/*
	** instr_lldi avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_lldi(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_lldi_05(void)
{
	/*
	** instr_lldi avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_lldi(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lldi_06(void)
{
	/*
	** instr_lldi avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_lldi(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lldi_07(void)
{
	/*
	** instr_lldi avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_lldi(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_lldi_08(void)
{
	/*
	** instr_lldi avec params valides
	** registres
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 84, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 3, 1);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	write_in_grid(&(st->grid), 64, st->last_thread->where + 5, 4);
	thread_change_value_reg(&(st->last_thread), 1, 1);
	thread_change_value_reg(&(st->last_thread), 2, 4);
	thread_change_value_reg(&(st->last_thread), 3, -1);
	result = thread_get_value_reg(&(st->last_thread), 1) == 1 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 2) == 4 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 3) == -1 ? 1 : 0;
	result += instr_lldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 64 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	thread_change_value_reg(&(st->last_thread), 1, 0);
	thread_change_value_reg(&(st->last_thread), 2, 1);
	result += thread_get_value_reg(&(st->last_thread), 1) == 0 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 2) == 1 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 3) == 64 ? 1 : 0;
	result += instr_lldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 1409352195 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + 1 + 1 + SUCCESS + 1 + 1 + 1 + 1 + SUCCESS + 1);
}

static int		ut_lldi_09(void)
{
	/*
	** instr_lldi avec params valides
	** directs
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 164, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 4, 2);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 6, 1);
	thread_change_value_reg(&(st->last_thread), 3, -1);
	result = thread_get_value_reg(&(st->last_thread), 3) == -1 ? 1 : 0;
	result += instr_lldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 164 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 4, 2);
	result += thread_get_value_reg(&(st->last_thread), 3) == 164 ? 1 : 0;
	result += instr_lldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 65537 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_lldi_10(void)
{
	/*
	** instr_lldi avec params valides
	** indirect + direct
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 228, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 10, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 4, 2);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 6, 1);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 10, 4);
	thread_change_value_reg(&(st->last_thread), 3, -1);
	result = thread_get_value_reg(&(st->last_thread), 3) == -1 ? 1 : 0;
	result += instr_lldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 228 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 20, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 4, 2);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 20, 4);
	result += thread_get_value_reg(&(st->last_thread), 3) == 228 ? 1 : 0;
	result += instr_lldi(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 14942228 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_move_01(void)
{
	/*
	** instr_move avec params null
	*/
	int			result;

	result = instr_move(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_move_02(void)
{
	/*
	** instr_move avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_move(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_move_03(void)
{
	/*
	** instr_move avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_move(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_move_04(void)
{
	/*
	** instr_move avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_move(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_move_05(void)
{
	/*
	** instr_move avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_move(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_move_06(void)
{
	/*
	** instr_move avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_move(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_move_07(void)
{
	/*
	** instr_move avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_move(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_move_08(void)
{
	/*
	** instr_move avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	result = instr_move(&st, &(st->last_thread));
	free_storage(&st);
	return (result == SUCCESS);
}

static int		ut_or_01(void)
{
	/*
	** instr_or avec params null
	*/
	int			result;

	result = instr_or(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_or_02(void)
{
	/*
	** instr_or avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_or(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_or_03(void)
{
	/*
	** instr_or avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_or(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_or_04(void)
{
	/*
	** instr_or avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_or(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_or_05(void)
{
	/*
	** instr_or avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_or(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_or_06(void)
{
	/*
	** instr_or avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_or(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_or_07(void)
{
	/*
	** instr_or avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_or(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_or_08(void)
{
	/*
	** instr_or avec params valides
	** registres seulement
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 84, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 3, 1);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	thread_change_value_reg(&(st->last_thread), 1, 5);
	thread_change_value_reg(&(st->last_thread), 2, 9);
	thread_change_value_reg(&(st->last_thread), 3, 15);
	result = thread_get_value_reg(&(st->last_thread), 3) == 15 ? 1 : 0;
	result += instr_or(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == (5 | 9) ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_or_09(void)
{
	/*
	** instr_or avec params valides
	** directs seulement
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 164, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 2, 4);
	write_in_grid(&(st->grid), 23, st->last_thread->where + 6, 4);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 10, 1);
	thread_change_value_reg(&(st->last_thread), 3, 15);
	result = thread_get_value_reg(&(st->last_thread), 3) == 15 ? 1 : 0;
	result += instr_or(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3)
		== (read_in_grid(&(st->grid), st->last_thread->where - 9 , 4)
		| read_in_grid(&(st->grid), st->last_thread->where - 5 , 4)) ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_or_10(void)
{
	/*
	** instr_or avec params valides
	** indirects seulement
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 244, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 69, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 444, st->last_thread->where + 4, 2);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 6, 1);
	write_in_grid(&(st->grid), 5946, st->last_thread->where + 69, 4);
	write_in_grid(&(st->grid), 231, st->last_thread->where + 444, 4);
	thread_change_value_reg(&(st->last_thread), 3, 15);
	result = thread_get_value_reg(&(st->last_thread), 3) == 15 ? 1 : 0;
	result += instr_or(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3)
		== (read_in_grid(&(st->grid), st->last_thread->where + 69 - 7, 4)
		| read_in_grid(&(st->grid), st->last_thread->where + 444 - 7, 4)) ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_st_01(void)
{
	/*
	** instr_st avec params null
	*/
	int			result;

	result = instr_st(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_st_02(void)
{
	/*
	** instr_st avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_st(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_st_03(void)
{
	/*
	** instr_st avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_st(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_st_04(void)
{
	/*
	** instr_st avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_st(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_st_05(void)
{
	/*
	** instr_st avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_st(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_st_06(void)
{
	/*
	** instr_st avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_st(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_st_07(void)
{
	/*
	** instr_st avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_st(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_st_08(void)
{
	/*
	** instr_st avec params valides
	** registre
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 80, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 3, 1);
	thread_change_value_reg(&(st->last_thread), 1, 15);
	thread_change_value_reg(&(st->last_thread), 2, 44);
	result = thread_get_value_reg(&(st->last_thread), 1) == 15 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 2) == 44 ? 1 : 0;
	result += instr_st(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 2) == 15 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 4, st->last_thread->where + 3, 1);
	thread_change_value_reg(&(st->last_thread), 3, 268);
	thread_change_value_reg(&(st->last_thread), 4, 699);
	result += thread_get_value_reg(&(st->last_thread), 3) == 268 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 4) == 699 ? 1 : 0;
	result += instr_st(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 4) == 268 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + 1 + SUCCESS + 1 + 1 + 1 + SUCCESS + 1);
}

static int		ut_st_09(void)
{
	/*
	** instr_st avec params valides
	** indirect
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 112, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 40, st->last_thread->where + 3, 2);
	thread_change_value_reg(&(st->last_thread), 1, 15);
	result = thread_get_value_reg(&(st->last_thread), 1) == 15 ? 1 : 0;
	result += instr_st(&st, &(st->last_thread));
	result += read_in_grid(&(st->grid), st->last_thread->where + 40 - 5, 4) == 15 % IDX_MOD ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 64, st->last_thread->where + 3, 2);
	thread_change_value_reg(&(st->last_thread), 3, 5555);
	result += thread_get_value_reg(&(st->last_thread), 3) == 5555 ? 1 : 0;
	result += instr_st(&st, &(st->last_thread));
	result += read_in_grid(&(st->grid), st->last_thread->where + 64 - 5, 4) == 5555 % IDX_MOD ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_sti_01(void)
{
	/*
	** instr_sti avec params null
	*/
	int			result;

	result = instr_sti(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_sti_02(void)
{
	/*
	** instr_sti avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_sti(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sti_03(void)
{
	/*
	** instr_sti avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_sti(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sti_04(void)
{
	/*
	** instr_sti avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_sti(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_sti_05(void)
{
	/*
	** instr_sti avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_sti(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sti_06(void)
{
	/*
	** instr_sti avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_sti(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sti_07(void)
{
	/*
	** instr_sti avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_sti(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sti_08(void)
{
	/*
	** instr_sti avec params valides
	** registres
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 84, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 3, 1);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	thread_change_value_reg(&(st->last_thread), 1, 15);
	thread_change_value_reg(&(st->last_thread), 2, 44);
	thread_change_value_reg(&(st->last_thread), 3, 78);
	result = thread_get_value_reg(&(st->last_thread), 1) == 15 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 2) == 44 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 3) == 78 ? 1 : 0;
	result += instr_sti(&st, &(st->last_thread));
	result += read_in_grid(&(st->grid), st->last_thread->where + 44 + 78 - 5, 4) == 15 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 4, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 5, st->last_thread->where + 3, 1);
	write_in_grid(&(st->grid), 6, st->last_thread->where + 4, 1);
	thread_change_value_reg(&(st->last_thread), 4, 268);
	thread_change_value_reg(&(st->last_thread), 5, 699);
	thread_change_value_reg(&(st->last_thread), 6, 5689);
	result += thread_get_value_reg(&(st->last_thread), 4) == 268 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 5) == 699 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 6) == 5689 ? 1 : 0;
	result += instr_sti(&st, &(st->last_thread));
	result += read_in_grid(&(st->grid), st->last_thread->where + 699 + 5689 - 5, 4) == 268 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + 1 + 1 + SUCCESS + 1 + 1 + 1 + 1 + SUCCESS + 1);
}

static int		ut_sti_09(void)
{
	/*
	** instr_sti avec params valides
	** directs
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 104, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 15, st->last_thread->where + 3, 2);
	write_in_grid(&(st->grid), 30, st->last_thread->where + 5, 2);
	thread_change_value_reg(&(st->last_thread), 1, 100);
	result = thread_get_value_reg(&(st->last_thread), 1) == 100 ? 1 : 0;
	result += instr_sti(&st, &(st->last_thread));
	result += read_in_grid(&(st->grid), st->last_thread->where + 15 + 30 - 7, 4) == 100 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 4, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 666, st->last_thread->where + 3, 2);
	write_in_grid(&(st->grid), 999, st->last_thread->where + 5, 2);
	thread_change_value_reg(&(st->last_thread), 4, 268);
	result += thread_get_value_reg(&(st->last_thread), 4) == 268 ? 1 : 0;
	result += instr_sti(&st, &(st->last_thread));
	result += read_in_grid(&(st->grid), st->last_thread->where + 666 + 999 - 7, 4) == 268 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_sti_10(void)
{
	/*
	** instr_sti avec params valides
	** indirect + direct
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 120, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 10, st->last_thread->where + 3, 2);
	write_in_grid(&(st->grid), 89, st->last_thread->where + 10 + 2, 2);
	write_in_grid(&(st->grid), 30, st->last_thread->where + 5, 2);
	thread_change_value_reg(&(st->last_thread), 1, 100);
	result = thread_get_value_reg(&(st->last_thread), 1) == 100 ? 1 : 0;
	result += instr_sti(&st, &(st->last_thread));
	result += read_in_grid(&(st->grid), st->last_thread->where + 89 + 30 - 7, 4) == 100 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	write_in_grid(&(st->grid), 4, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 10, st->last_thread->where + 3, 2);
	write_in_grid(&(st->grid), 46, st->last_thread->where + 10 + 2, 2);
	write_in_grid(&(st->grid), 999, st->last_thread->where + 5, 2);
	thread_change_value_reg(&(st->last_thread), 4, 268);
	result += thread_get_value_reg(&(st->last_thread), 4) == 268 ? 1 : 0;
	result += instr_sti(&st, &(st->last_thread));
	result += read_in_grid(&(st->grid), st->last_thread->where + 46 + 999 - 7, 4) == 268 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	free_storage(&st);
	return (result == 1 + SUCCESS + 1 + 1 + SUCCESS + 1);
}

static int		ut_sub_01(void)
{
	/*
	** instr_sub avec params null
	*/
	int			result;

	result = instr_sub(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_sub_02(void)
{
	/*
	** instr_sub avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_sub(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sub_03(void)
{
	/*
	** instr_sub avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_sub(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sub_04(void)
{
	/*
	** instr_sub avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_sub(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_sub_05(void)
{
	/*
	** instr_sub avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_sub(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sub_06(void)
{
	/*
	** instr_sub avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_sub(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sub_07(void)
{
	/*
	** instr_sub avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_sub(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_sub_08(void)
{
	/*
	** instr_sub avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 84, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 3, 1);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	thread_change_value_reg(&(st->last_thread), 1, 9);
	thread_change_value_reg(&(st->last_thread), 2, 5);
	thread_change_value_reg(&(st->last_thread), 3, 7);
	result = thread_get_value_reg(&(st->last_thread), 3) == 7 ? 1 : 0;
	result += instr_sub(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == 4 ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_xor_01(void)
{
	/*
	** instr_xor avec params null
	*/
	int			result;

	result = instr_xor(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_xor_02(void)
{
	/*
	** instr_xor avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_xor(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_xor_03(void)
{
	/*
	** instr_xor avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_xor(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_xor_04(void)
{
	/*
	** instr_xor avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_xor(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_xor_05(void)
{
	/*
	** instr_xor avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_xor(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_xor_06(void)
{
	/*
	** instr_xor avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_xor(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_xor_07(void)
{
	/*
	** instr_xor avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_xor(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_xor_08(void)
{
	/*
	** instr_xor avec params valides
	** registres seulement
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 84, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 1, st->last_thread->where + 2, 1);
	write_in_grid(&(st->grid), 2, st->last_thread->where + 3, 1);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 4, 1);
	thread_change_value_reg(&(st->last_thread), 1, 5);
	thread_change_value_reg(&(st->last_thread), 2, 9);
	thread_change_value_reg(&(st->last_thread), 3, 15);
	result = thread_get_value_reg(&(st->last_thread), 3) == 15 ? 1 : 0;
	result += instr_xor(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3) == (5 ^ 9) ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_xor_09(void)
{
	/*
	** instr_xor avec params valides
	** directs seulement
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 164, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), -1, st->last_thread->where + 2, 4);
	write_in_grid(&(st->grid), 23, st->last_thread->where + 6, 4);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 10, 1);
	thread_change_value_reg(&(st->last_thread), 3, 15);
	result = thread_get_value_reg(&(st->last_thread), 3) == 15 ? 1 : 0;
	result += instr_xor(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3)
		== (read_in_grid(&(st->grid), st->last_thread->where - 9, 4)
		^ read_in_grid(&(st->grid), st->last_thread->where - 5, 4)) ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_xor_10(void)
{
	/*
	** instr_xor avec params valides
	** indirects seulement
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	write_in_grid(&(st->grid), 244, st->last_thread->where + 1, 1);
	write_in_grid(&(st->grid), 69, st->last_thread->where + 2, 2);
	write_in_grid(&(st->grid), 444, st->last_thread->where + 4, 2);
	write_in_grid(&(st->grid), 3, st->last_thread->where + 6, 1);
	write_in_grid(&(st->grid), 5946, st->last_thread->where + 69, 4);
	write_in_grid(&(st->grid), 231, st->last_thread->where + 444, 4);
	thread_change_value_reg(&(st->last_thread), 3, 15);
	result = thread_get_value_reg(&(st->last_thread), 3) == 15 ? 1 : 0;
	result += instr_xor(&st, &(st->last_thread));
	result += thread_get_value_reg(&(st->last_thread), 3)
		== (read_in_grid(&(st->grid), st->last_thread->where + 69 - 7, 4)
		^ read_in_grid(&(st->grid), st->last_thread->where + 444 - 7, 4)) ? 1 : 0;
	free_storage(&st);
	return (result == 1 + SUCCESS + 1);
}

static int		ut_zjmp_01(void)
{
	/*
	** instr_zjmp avec params null
	*/
	int			result;

	result = instr_zjmp(NULL, NULL);
	return (result == BAD_PARAM);
}

static int		ut_zjmp_02(void)
{
	/*
	** instr_zjmp avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = instr_zjmp(&st, NULL);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_zjmp_03(void)
{
	/*
	** instr_zjmp avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_zjmp(NULL, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_zjmp_04(void)
{
	/*
	** instr_zjmp avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = instr_zjmp(&st, &th);
	return (result == BAD_PARAM);
}

static int		ut_zjmp_05(void)
{
	/*
	** instr_zjmp avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = instr_zjmp(&st, &th);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_zjmp_06(void)
{
	/*
	** instr_zjmp avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = instr_zjmp(&st2, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_zjmp_07(void)
{
	/*
	** instr_zjmp avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = instr_zjmp(&st, &(st->last_thread));
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_zjmp_08(void)
{
	/*
	** instr_zjmp avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	st->last_thread->carry = 1;
	write_in_grid(&(st->grid), 500, st->last_thread->where + 1, 2);
	result = instr_zjmp(&st, &(st->last_thread));
	result += st->last_thread->where == 500 ? 1 : 0;
	thread_change_where(&(st->last_thread), &(st->grid), 0);
	st->last_thread->carry = 0;
	write_in_grid(&(st->grid), 500, st->last_thread->where + 1, 2);
	result += instr_zjmp(&st, &(st->last_thread));
	result += st->last_thread->where == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + NO_CHANGE + 1);
}

void			ut_add(void)
{
	ft_putstr(ut_add_01() ? "ut_add_01	OK\n" : "ut_add_01	ERROR\n");
	ft_putstr(ut_add_02() ? "ut_add_02	OK\n" : "ut_add_02	ERROR\n");
	ft_putstr(ut_add_03() ? "ut_add_03	OK\n" : "ut_add_03	ERROR\n");
	ft_putstr(ut_add_04() ? "ut_add_04	OK\n" : "ut_add_04	ERROR\n");
	ft_putstr(ut_add_05() ? "ut_add_05	OK\n" : "ut_add_05	ERROR\n");
	ft_putstr(ut_add_06() ? "ut_add_06	OK\n" : "ut_add_06	ERROR\n");
	ft_putstr(ut_add_07() ? "ut_add_07	OK\n" : "ut_add_07	ERROR\n");
	ft_putstr(ut_add_08() ? "ut_add_08	OK\n" : "ut_add_08	ERROR\n");
	/*
	ft_putstr(ut_add_09() ? "ut_add_09	OK\n" : "ut_add_09	ERROR\n");
	ft_putstr(ut_add_10() ? "ut_add_10	OK\n" : "ut_add_10	ERROR\n");
	ft_putstr(ut_add_11() ? "ut_add_11	OK\n" : "ut_add_11	ERROR\n");
	ft_putstr(ut_add_12() ? "ut_add_12	OK\n" : "ut_add_12	ERROR\n");
	ft_putstr(ut_add_13() ? "ut_add_13	OK\n" : "ut_add_13	ERROR\n");
	ft_putstr(ut_add_14() ? "ut_add_14	OK\n" : "ut_add_14	ERROR\n");
	ft_putstr(ut_add_15() ? "ut_add_15	OK\n" : "ut_add_15	ERROR\n");
	*/
}

void			ut_aff(void)
{
	ft_putstr(ut_aff_01() ? "ut_aff_01	OK\n" : "ut_aff_01	ERROR\n");
	ft_putstr(ut_aff_02() ? "ut_aff_02	OK\n" : "ut_aff_02	ERROR\n");
	ft_putstr(ut_aff_03() ? "ut_aff_03	OK\n" : "ut_aff_03	ERROR\n");
	ft_putstr(ut_aff_04() ? "ut_aff_04	OK\n" : "ut_aff_04	ERROR\n");
	ft_putstr(ut_aff_05() ? "ut_aff_05	OK\n" : "ut_aff_05	ERROR\n");
	ft_putstr(ut_aff_06() ? "ut_aff_06	OK\n" : "ut_aff_06	ERROR\n");
	ft_putstr(ut_aff_07() ? "ut_aff_07	OK\n" : "ut_aff_07	ERROR\n");
	ft_putstr(ut_aff_08() ? "ut_aff_08	OK\n" : "ut_aff_08	ERROR\n");
	/*
	ft_putstr(ut_aff_09() ? "ut_aff_09	OK\n" : "ut_aff_09	ERROR\n");
	ft_putstr(ut_aff_10() ? "ut_aff_10	OK\n" : "ut_aff_10	ERROR\n");
	ft_putstr(ut_aff_11() ? "ut_aff_11	OK\n" : "ut_aff_11	ERROR\n");
	ft_putstr(ut_aff_12() ? "ut_aff_12	OK\n" : "ut_aff_12	ERROR\n");
	ft_putstr(ut_aff_13() ? "ut_aff_13	OK\n" : "ut_aff_13	ERROR\n");
	ft_putstr(ut_aff_14() ? "ut_aff_14	OK\n" : "ut_aff_14	ERROR\n");
	ft_putstr(ut_aff_15() ? "ut_aff_15	OK\n" : "ut_aff_15	ERROR\n");
	*/
}

void			ut_and(void)
{
	ft_putstr(ut_and_01() ? "ut_and_01	OK\n" : "ut_and_01	ERROR\n");
	ft_putstr(ut_and_02() ? "ut_and_02	OK\n" : "ut_and_02	ERROR\n");
	ft_putstr(ut_and_03() ? "ut_and_03	OK\n" : "ut_and_03	ERROR\n");
	ft_putstr(ut_and_04() ? "ut_and_04	OK\n" : "ut_and_04	ERROR\n");
	ft_putstr(ut_and_05() ? "ut_and_05	OK\n" : "ut_and_05	ERROR\n");
	ft_putstr(ut_and_06() ? "ut_and_06	OK\n" : "ut_and_06	ERROR\n");
	ft_putstr(ut_and_07() ? "ut_and_07	OK\n" : "ut_and_07	ERROR\n");
	ft_putstr(ut_and_08() ? "ut_and_08	OK\n" : "ut_and_08	ERROR\n");
	ft_putstr(ut_and_09() ? "ut_and_09	OK\n" : "ut_and_09	ERROR\n");
	ft_putstr(ut_and_10() ? "ut_and_10	OK\n" : "ut_and_10	ERROR\n");
	/*
	ft_putstr(ut_and_11() ? "ut_and_11	OK\n" : "ut_and_11	ERROR\n");
	ft_putstr(ut_and_12() ? "ut_and_12	OK\n" : "ut_and_12	ERROR\n");
	ft_putstr(ut_and_13() ? "ut_and_13	OK\n" : "ut_and_13	ERROR\n");
	ft_putstr(ut_and_14() ? "ut_and_14	OK\n" : "ut_and_14	ERROR\n");
	ft_putstr(ut_and_15() ? "ut_and_15	OK\n" : "ut_and_15	ERROR\n");
	*/
}

void			ut_fork(void)
{
	ft_putstr(ut_fork_01() ? "ut_fork_01	OK\n" : "ut_fork_01	ERROR\n");
	ft_putstr(ut_fork_02() ? "ut_fork_02	OK\n" : "ut_fork_02	ERROR\n");
	ft_putstr(ut_fork_03() ? "ut_fork_03	OK\n" : "ut_fork_03	ERROR\n");
	ft_putstr(ut_fork_04() ? "ut_fork_04	OK\n" : "ut_fork_04	ERROR\n");
	ft_putstr(ut_fork_05() ? "ut_fork_05	OK\n" : "ut_fork_05	ERROR\n");
	ft_putstr(ut_fork_06() ? "ut_fork_06	OK\n" : "ut_fork_06	ERROR\n");
	ft_putstr(ut_fork_07() ? "ut_fork_07	OK\n" : "ut_fork_07	ERROR\n");
	ft_putstr(ut_fork_08() ? "ut_fork_08	OK\n" : "ut_fork_08	ERROR\n");
	/*
	ft_putstr(ut_fork_09() ? "ut_fork_09	OK\n" : "ut_fork_09	ERROR\n");
	ft_putstr(ut_fork_10() ? "ut_fork_10	OK\n" : "ut_fork_10	ERROR\n");
	ft_putstr(ut_fork_11() ? "ut_fork_11	OK\n" : "ut_fork_11	ERROR\n");
	ft_putstr(ut_fork_12() ? "ut_fork_12	OK\n" : "ut_fork_12	ERROR\n");
	ft_putstr(ut_fork_13() ? "ut_fork_13	OK\n" : "ut_fork_13	ERROR\n");
	ft_putstr(ut_fork_14() ? "ut_fork_14	OK\n" : "ut_fork_14	ERROR\n");
	ft_putstr(ut_fork_15() ? "ut_fork_15	OK\n" : "ut_fork_15	ERROR\n");
	*/
}

void			ut_ld(void)
{
	ft_putstr(ut_ld_01() ? "ut_ld_01	OK\n" : "ut_ld_01	ERROR\n");
	ft_putstr(ut_ld_02() ? "ut_ld_02	OK\n" : "ut_ld_02	ERROR\n");
	ft_putstr(ut_ld_03() ? "ut_ld_03	OK\n" : "ut_ld_03	ERROR\n");
	ft_putstr(ut_ld_04() ? "ut_ld_04	OK\n" : "ut_ld_04	ERROR\n");
	ft_putstr(ut_ld_05() ? "ut_ld_05	OK\n" : "ut_ld_05	ERROR\n");
	ft_putstr(ut_ld_06() ? "ut_ld_06	OK\n" : "ut_ld_06	ERROR\n");
	ft_putstr(ut_ld_07() ? "ut_ld_07	OK\n" : "ut_ld_07	ERROR\n");
	ft_putstr(ut_ld_08() ? "ut_ld_08	OK\n" : "ut_ld_08	ERROR\n");
	ft_putstr(ut_ld_09() ? "ut_ld_09	OK\n" : "ut_ld_09	ERROR\n");
	/*
	ft_putstr(ut_ld_10() ? "ut_ld_10	OK\n" : "ut_ld_10	ERROR\n");
	ft_putstr(ut_ld_11() ? "ut_ld_11	OK\n" : "ut_ld_11	ERROR\n");
	ft_putstr(ut_ld_12() ? "ut_ld_12	OK\n" : "ut_ld_12	ERROR\n");
	ft_putstr(ut_ld_13() ? "ut_ld_13	OK\n" : "ut_ld_13	ERROR\n");
	ft_putstr(ut_ld_14() ? "ut_ld_14	OK\n" : "ut_ld_14	ERROR\n");
	ft_putstr(ut_ld_15() ? "ut_ld_15	OK\n" : "ut_ld_15	ERROR\n");
	*/
}

void			ut_ldi(void)
{
	ft_putstr(ut_ldi_01() ? "ut_ldi_01	OK\n" : "ut_ldi_01	ERROR\n");
	ft_putstr(ut_ldi_02() ? "ut_ldi_02	OK\n" : "ut_ldi_02	ERROR\n");
	ft_putstr(ut_ldi_03() ? "ut_ldi_03	OK\n" : "ut_ldi_03	ERROR\n");
	ft_putstr(ut_ldi_04() ? "ut_ldi_04	OK\n" : "ut_ldi_04	ERROR\n");
	ft_putstr(ut_ldi_05() ? "ut_ldi_05	OK\n" : "ut_ldi_05	ERROR\n");
	ft_putstr(ut_ldi_06() ? "ut_ldi_06	OK\n" : "ut_ldi_06	ERROR\n");
	ft_putstr(ut_ldi_07() ? "ut_ldi_07	OK\n" : "ut_ldi_07	ERROR\n");
	ft_putstr(ut_ldi_08() ? "ut_ldi_08	OK\n" : "ut_ldi_08	ERROR\n");
	ft_putstr(ut_ldi_09() ? "ut_ldi_09	OK\n" : "ut_ldi_09	ERROR\n");
	ft_putstr(ut_ldi_10() ? "ut_ldi_10	OK\n" : "ut_ldi_10	ERROR\n");
	/*
	ft_putstr(ut_ldi_11() ? "ut_ldi_11	OK\n" : "ut_ldi_11	ERROR\n");
	ft_putstr(ut_ldi_12() ? "ut_ldi_12	OK\n" : "ut_ldi_12	ERROR\n");
	ft_putstr(ut_ldi_13() ? "ut_ldi_13	OK\n" : "ut_ldi_13	ERROR\n");
	ft_putstr(ut_ldi_14() ? "ut_ldi_14	OK\n" : "ut_ldi_14	ERROR\n");
	ft_putstr(ut_ldi_15() ? "ut_ldi_15	OK\n" : "ut_ldi_15	ERROR\n");
	*/
}

void			ut_lfork(void)
{
	ft_putstr(ut_lfork_01() ? "ut_lfork_01	OK\n" : "ut_lfork_01	ERROR\n");
	ft_putstr(ut_lfork_02() ? "ut_lfork_02	OK\n" : "ut_lfork_02	ERROR\n");
	ft_putstr(ut_lfork_03() ? "ut_lfork_03	OK\n" : "ut_lfork_03	ERROR\n");
	ft_putstr(ut_lfork_04() ? "ut_lfork_04	OK\n" : "ut_lfork_04	ERROR\n");
	ft_putstr(ut_lfork_05() ? "ut_lfork_05	OK\n" : "ut_lfork_05	ERROR\n");
	ft_putstr(ut_lfork_06() ? "ut_lfork_06	OK\n" : "ut_lfork_06	ERROR\n");
	ft_putstr(ut_lfork_07() ? "ut_lfork_07	OK\n" : "ut_lfork_07	ERROR\n");
	ft_putstr(ut_lfork_08() ? "ut_lfork_08	OK\n" : "ut_lfork_08	ERROR\n");
	/*
	ft_putstr(ut_lfork_09() ? "ut_lfork_09	OK\n" : "ut_lfork_09	ERROR\n");
	ft_putstr(ut_lfork_10() ? "ut_lfork_10	OK\n" : "ut_lfork_10	ERROR\n");
	ft_putstr(ut_lfork_11() ? "ut_lfork_11	OK\n" : "ut_lfork_11	ERROR\n");
	ft_putstr(ut_lfork_12() ? "ut_lfork_12	OK\n" : "ut_lfork_12	ERROR\n");
	ft_putstr(ut_lfork_13() ? "ut_lfork_13	OK\n" : "ut_lfork_13	ERROR\n");
	ft_putstr(ut_lfork_14() ? "ut_lfork_14	OK\n" : "ut_lfork_14	ERROR\n");
	ft_putstr(ut_lfork_15() ? "ut_lfork_15	OK\n" : "ut_lfork_15	ERROR\n");
	*/
}

void			ut_live(void)
{
	ft_putstr(ut_live_01() ? "ut_live_01	OK\n" : "ut_live_01	ERROR\n");
	ft_putstr(ut_live_02() ? "ut_live_02	OK\n" : "ut_live_02	ERROR\n");
	ft_putstr(ut_live_03() ? "ut_live_03	OK\n" : "ut_live_03	ERROR\n");
	ft_putstr(ut_live_04() ? "ut_live_04	OK\n" : "ut_live_04	ERROR\n");
	ft_putstr(ut_live_05() ? "ut_live_05	OK\n" : "ut_live_05	ERROR\n");
	ft_putstr(ut_live_06() ? "ut_live_06	OK\n" : "ut_live_06	ERROR\n");
	ft_putstr(ut_live_07() ? "ut_live_07	OK\n" : "ut_live_07	ERROR\n");
	ft_putstr(ut_live_08() ? "ut_live_08	OK\n" : "ut_live_08	ERROR\n");
	ft_putstr(ut_live_09() ? "ut_live_09	OK\n" : "ut_live_09	ERROR\n");
	/*
	ft_putstr(ut_live_10() ? "ut_live_10	OK\n" : "ut_live_10	ERROR\n");
	ft_putstr(ut_live_11() ? "ut_live_11	OK\n" : "ut_live_11	ERROR\n");
	ft_putstr(ut_live_12() ? "ut_live_12	OK\n" : "ut_live_12	ERROR\n");
	ft_putstr(ut_live_13() ? "ut_live_13	OK\n" : "ut_live_13	ERROR\n");
	ft_putstr(ut_live_14() ? "ut_live_14	OK\n" : "ut_live_14	ERROR\n");
	ft_putstr(ut_live_15() ? "ut_live_15	OK\n" : "ut_live_15	ERROR\n");
	*/
}

void			ut_lld(void)
{
	ft_putstr(ut_lld_01() ? "ut_lld_01	OK\n" : "ut_lld_01	ERROR\n");
	ft_putstr(ut_lld_02() ? "ut_lld_02	OK\n" : "ut_lld_02	ERROR\n");
	ft_putstr(ut_lld_03() ? "ut_lld_03	OK\n" : "ut_lld_03	ERROR\n");
	ft_putstr(ut_lld_04() ? "ut_lld_04	OK\n" : "ut_lld_04	ERROR\n");
	ft_putstr(ut_lld_05() ? "ut_lld_05	OK\n" : "ut_lld_05	ERROR\n");
	ft_putstr(ut_lld_06() ? "ut_lld_06	OK\n" : "ut_lld_06	ERROR\n");
	ft_putstr(ut_lld_07() ? "ut_lld_07	OK\n" : "ut_lld_07	ERROR\n");
	ft_putstr(ut_lld_08() ? "ut_lld_08	OK\n" : "ut_lld_08	ERROR\n");
	ft_putstr(ut_lld_09() ? "ut_lld_09	OK\n" : "ut_lld_09	ERROR\n");
	/*
	ft_putstr(ut_lld_10() ? "ut_lld_10	OK\n" : "ut_lld_10	ERROR\n");
	ft_putstr(ut_lld_11() ? "ut_lld_11	OK\n" : "ut_lld_11	ERROR\n");
	ft_putstr(ut_lld_12() ? "ut_lld_12	OK\n" : "ut_lld_12	ERROR\n");
	ft_putstr(ut_lld_13() ? "ut_lld_13	OK\n" : "ut_lld_13	ERROR\n");
	ft_putstr(ut_lld_14() ? "ut_lld_14	OK\n" : "ut_lld_14	ERROR\n");
	ft_putstr(ut_lld_15() ? "ut_lld_15	OK\n" : "ut_lld_15	ERROR\n");
	*/
}

void			ut_lldi(void)
{
	ft_putstr(ut_lldi_01() ? "ut_lldi_01	OK\n" : "ut_lldi_01	ERROR\n");
	ft_putstr(ut_lldi_02() ? "ut_lldi_02	OK\n" : "ut_lldi_02	ERROR\n");
	ft_putstr(ut_lldi_03() ? "ut_lldi_03	OK\n" : "ut_lldi_03	ERROR\n");
	ft_putstr(ut_lldi_04() ? "ut_lldi_04	OK\n" : "ut_lldi_04	ERROR\n");
	ft_putstr(ut_lldi_05() ? "ut_lldi_05	OK\n" : "ut_lldi_05	ERROR\n");
	ft_putstr(ut_lldi_06() ? "ut_lldi_06	OK\n" : "ut_lldi_06	ERROR\n");
	ft_putstr(ut_lldi_07() ? "ut_lldi_07	OK\n" : "ut_lldi_07	ERROR\n");
	ft_putstr(ut_lldi_08() ? "ut_lldi_08	OK\n" : "ut_lldi_08	ERROR\n");
	ft_putstr(ut_lldi_09() ? "ut_lldi_09	OK\n" : "ut_lldi_09	ERROR\n");
	ft_putstr(ut_lldi_10() ? "ut_lldi_10	OK\n" : "ut_lldi_10	ERROR\n");
	/*
	ft_putstr(ut_lldi_11() ? "ut_lldi_11	OK\n" : "ut_lldi_11	ERROR\n");
	ft_putstr(ut_lldi_12() ? "ut_lldi_12	OK\n" : "ut_lldi_12	ERROR\n");
	ft_putstr(ut_lldi_13() ? "ut_lldi_13	OK\n" : "ut_lldi_13	ERROR\n");
	ft_putstr(ut_lldi_14() ? "ut_lldi_14	OK\n" : "ut_lldi_14	ERROR\n");
	ft_putstr(ut_lldi_15() ? "ut_lldi_15	OK\n" : "ut_lldi_15	ERROR\n");
	*/
}

void			ut_move(void)
{
	ft_putstr(ut_move_01() ? "ut_move_01	OK\n" : "ut_move_01	ERROR\n");
	ft_putstr(ut_move_02() ? "ut_move_02	OK\n" : "ut_move_02	ERROR\n");
	ft_putstr(ut_move_03() ? "ut_move_03	OK\n" : "ut_move_03	ERROR\n");
	ft_putstr(ut_move_04() ? "ut_move_04	OK\n" : "ut_move_04	ERROR\n");
	ft_putstr(ut_move_05() ? "ut_move_05	OK\n" : "ut_move_05	ERROR\n");
	ft_putstr(ut_move_06() ? "ut_move_06	OK\n" : "ut_move_06	ERROR\n");
	ft_putstr(ut_move_07() ? "ut_move_07	OK\n" : "ut_move_07	ERROR\n");
	ft_putstr(ut_move_08() ? "ut_move_08	OK\n" : "ut_move_08	ERROR\n");
	/*
	ft_putstr(ut_move_09() ? "ut_move_09	OK\n" : "ut_move_09	ERROR\n");
	ft_putstr(ut_move_10() ? "ut_move_10	OK\n" : "ut_move_10	ERROR\n");
	ft_putstr(ut_move_11() ? "ut_move_11	OK\n" : "ut_move_11	ERROR\n");
	ft_putstr(ut_move_12() ? "ut_move_12	OK\n" : "ut_move_12	ERROR\n");
	ft_putstr(ut_move_13() ? "ut_move_13	OK\n" : "ut_move_13	ERROR\n");
	ft_putstr(ut_move_14() ? "ut_move_14	OK\n" : "ut_move_14	ERROR\n");
	ft_putstr(ut_move_15() ? "ut_move_15	OK\n" : "ut_move_15	ERROR\n");
	*/
}

void			ut_or(void)
{
	ft_putstr(ut_or_01() ? "ut_or_01	OK\n" : "ut_or_01	ERROR\n");
	ft_putstr(ut_or_02() ? "ut_or_02	OK\n" : "ut_or_02	ERROR\n");
	ft_putstr(ut_or_03() ? "ut_or_03	OK\n" : "ut_or_03	ERROR\n");
	ft_putstr(ut_or_04() ? "ut_or_04	OK\n" : "ut_or_04	ERROR\n");
	ft_putstr(ut_or_05() ? "ut_or_05	OK\n" : "ut_or_05	ERROR\n");
	ft_putstr(ut_or_06() ? "ut_or_06	OK\n" : "ut_or_06	ERROR\n");
	ft_putstr(ut_or_07() ? "ut_or_07	OK\n" : "ut_or_07	ERROR\n");
	ft_putstr(ut_or_08() ? "ut_or_08	OK\n" : "ut_or_08	ERROR\n");
	ft_putstr(ut_or_09() ? "ut_or_09	OK\n" : "ut_or_09	ERROR\n");
	ft_putstr(ut_or_10() ? "ut_or_10	OK\n" : "ut_or_10	ERROR\n");
	/*
	ft_putstr(ut_or_11() ? "ut_or_11	OK\n" : "ut_or_11	ERROR\n");
	ft_putstr(ut_or_12() ? "ut_or_12	OK\n" : "ut_or_12	ERROR\n");
	ft_putstr(ut_or_13() ? "ut_or_13	OK\n" : "ut_or_13	ERROR\n");
	ft_putstr(ut_or_14() ? "ut_or_14	OK\n" : "ut_or_14	ERROR\n");
	ft_putstr(ut_or_15() ? "ut_or_15	OK\n" : "ut_or_15	ERROR\n");
	*/
}

void			ut_st(void)
{
	ft_putstr(ut_st_01() ? "ut_st_01	OK\n" : "ut_st_01	ERROR\n");
	ft_putstr(ut_st_02() ? "ut_st_02	OK\n" : "ut_st_02	ERROR\n");
	ft_putstr(ut_st_03() ? "ut_st_03	OK\n" : "ut_st_03	ERROR\n");
	ft_putstr(ut_st_04() ? "ut_st_04	OK\n" : "ut_st_04	ERROR\n");
	ft_putstr(ut_st_05() ? "ut_st_05	OK\n" : "ut_st_05	ERROR\n");
	ft_putstr(ut_st_06() ? "ut_st_06	OK\n" : "ut_st_06	ERROR\n");
	ft_putstr(ut_st_07() ? "ut_st_07	OK\n" : "ut_st_07	ERROR\n");
	ft_putstr(ut_st_08() ? "ut_st_08	OK\n" : "ut_st_08	ERROR\n");
	ft_putstr(ut_st_09() ? "ut_st_09	OK\n" : "ut_st_09	ERROR\n");
	/*
	ft_putstr(ut_st_10() ? "ut_st_10	OK\n" : "ut_st_10	ERROR\n");
	ft_putstr(ut_st_11() ? "ut_st_11	OK\n" : "ut_st_11	ERROR\n");
	ft_putstr(ut_st_12() ? "ut_st_12	OK\n" : "ut_st_12	ERROR\n");
	ft_putstr(ut_st_13() ? "ut_st_13	OK\n" : "ut_st_13	ERROR\n");
	ft_putstr(ut_st_14() ? "ut_st_14	OK\n" : "ut_st_14	ERROR\n");
	ft_putstr(ut_st_15() ? "ut_st_15	OK\n" : "ut_st_15	ERROR\n");
	*/
}

void			ut_sti(void)
{
	ft_putstr(ut_sti_01() ? "ut_sti_01	OK\n" : "ut_sti_01	ERROR\n");
	ft_putstr(ut_sti_02() ? "ut_sti_02	OK\n" : "ut_sti_02	ERROR\n");
	ft_putstr(ut_sti_03() ? "ut_sti_03	OK\n" : "ut_sti_03	ERROR\n");
	ft_putstr(ut_sti_04() ? "ut_sti_04	OK\n" : "ut_sti_04	ERROR\n");
	ft_putstr(ut_sti_05() ? "ut_sti_05	OK\n" : "ut_sti_05	ERROR\n");
	ft_putstr(ut_sti_06() ? "ut_sti_06	OK\n" : "ut_sti_06	ERROR\n");
	ft_putstr(ut_sti_07() ? "ut_sti_07	OK\n" : "ut_sti_07	ERROR\n");
	ft_putstr(ut_sti_08() ? "ut_sti_08	OK\n" : "ut_sti_08	ERROR\n");
	ft_putstr(ut_sti_09() ? "ut_sti_09	OK\n" : "ut_sti_09	ERROR\n");
	ft_putstr(ut_sti_10() ? "ut_sti_10	OK\n" : "ut_sti_10	ERROR\n");
	/*
	ft_putstr(ut_sti_11() ? "ut_sti_11	OK\n" : "ut_sti_11	ERROR\n");
	ft_putstr(ut_sti_12() ? "ut_sti_12	OK\n" : "ut_sti_12	ERROR\n");
	ft_putstr(ut_sti_13() ? "ut_sti_13	OK\n" : "ut_sti_13	ERROR\n");
	ft_putstr(ut_sti_14() ? "ut_sti_14	OK\n" : "ut_sti_14	ERROR\n");
	ft_putstr(ut_sti_15() ? "ut_sti_15	OK\n" : "ut_sti_15	ERROR\n");
	*/
}

void			ut_sub(void)
{
	ft_putstr(ut_sub_01() ? "ut_sub_01	OK\n" : "ut_sub_01	ERROR\n");
	ft_putstr(ut_sub_02() ? "ut_sub_02	OK\n" : "ut_sub_02	ERROR\n");
	ft_putstr(ut_sub_03() ? "ut_sub_03	OK\n" : "ut_sub_03	ERROR\n");
	ft_putstr(ut_sub_04() ? "ut_sub_04	OK\n" : "ut_sub_04	ERROR\n");
	ft_putstr(ut_sub_05() ? "ut_sub_05	OK\n" : "ut_sub_05	ERROR\n");
	ft_putstr(ut_sub_06() ? "ut_sub_06	OK\n" : "ut_sub_06	ERROR\n");
	ft_putstr(ut_sub_07() ? "ut_sub_07	OK\n" : "ut_sub_07	ERROR\n");
	ft_putstr(ut_sub_08() ? "ut_sub_08	OK\n" : "ut_sub_08	ERROR\n");
	/*
	ft_putstr(ut_sub_09() ? "ut_sub_09	OK\n" : "ut_sub_09	ERROR\n");
	ft_putstr(ut_sub_10() ? "ut_sub_10	OK\n" : "ut_sub_10	ERROR\n");
	ft_putstr(ut_sub_11() ? "ut_sub_11	OK\n" : "ut_sub_11	ERROR\n");
	ft_putstr(ut_sub_12() ? "ut_sub_12	OK\n" : "ut_sub_12	ERROR\n");
	ft_putstr(ut_sub_13() ? "ut_sub_13	OK\n" : "ut_sub_13	ERROR\n");
	ft_putstr(ut_sub_14() ? "ut_sub_14	OK\n" : "ut_sub_14	ERROR\n");
	ft_putstr(ut_sub_15() ? "ut_sub_15	OK\n" : "ut_sub_15	ERROR\n");
	*/
}

void			ut_xor(void)
{
	ft_putstr(ut_xor_01() ? "ut_xor_01	OK\n" : "ut_xor_01	ERROR\n");
	ft_putstr(ut_xor_02() ? "ut_xor_02	OK\n" : "ut_xor_02	ERROR\n");
	ft_putstr(ut_xor_03() ? "ut_xor_03	OK\n" : "ut_xor_03	ERROR\n");
	ft_putstr(ut_xor_04() ? "ut_xor_04	OK\n" : "ut_xor_04	ERROR\n");
	ft_putstr(ut_xor_05() ? "ut_xor_05	OK\n" : "ut_xor_05	ERROR\n");
	ft_putstr(ut_xor_06() ? "ut_xor_06	OK\n" : "ut_xor_06	ERROR\n");
	ft_putstr(ut_xor_07() ? "ut_xor_07	OK\n" : "ut_xor_07	ERROR\n");
	ft_putstr(ut_xor_08() ? "ut_xor_08	OK\n" : "ut_xor_08	ERROR\n");
	ft_putstr(ut_xor_09() ? "ut_xor_09	OK\n" : "ut_xor_09	ERROR\n");
	ft_putstr(ut_xor_10() ? "ut_xor_10	OK\n" : "ut_xor_10	ERROR\n");
	/*
	ft_putstr(ut_xor_11() ? "ut_xor_11	OK\n" : "ut_xor_11	ERROR\n");
	ft_putstr(ut_xor_12() ? "ut_xor_12	OK\n" : "ut_xor_12	ERROR\n");
	ft_putstr(ut_xor_13() ? "ut_xor_13	OK\n" : "ut_xor_13	ERROR\n");
	ft_putstr(ut_xor_14() ? "ut_xor_14	OK\n" : "ut_xor_14	ERROR\n");
	ft_putstr(ut_xor_15() ? "ut_xor_15	OK\n" : "ut_xor_15	ERROR\n");
	*/
}

void			ut_zjmp(void)
{
	ft_putstr(ut_zjmp_01() ? "ut_zjmp_01	OK\n" : "ut_zjmp_01	ERROR\n");
	ft_putstr(ut_zjmp_02() ? "ut_zjmp_02	OK\n" : "ut_zjmp_02	ERROR\n");
	ft_putstr(ut_zjmp_03() ? "ut_zjmp_03	OK\n" : "ut_zjmp_03	ERROR\n");
	ft_putstr(ut_zjmp_04() ? "ut_zjmp_04	OK\n" : "ut_zjmp_04	ERROR\n");
	ft_putstr(ut_zjmp_05() ? "ut_zjmp_05	OK\n" : "ut_zjmp_05	ERROR\n");
	ft_putstr(ut_zjmp_06() ? "ut_zjmp_06	OK\n" : "ut_zjmp_06	ERROR\n");
	ft_putstr(ut_zjmp_07() ? "ut_zjmp_07	OK\n" : "ut_zjmp_07	ERROR\n");
	ft_putstr(ut_zjmp_08() ? "ut_zjmp_08	OK\n" : "ut_zjmp_08	ERROR\n");
	/*
	ft_putstr(ut_zjmp_09() ? "ut_zjmp_09	OK\n" : "ut_zjmp_09	ERROR\n");
	ft_putstr(ut_zjmp_10() ? "ut_zjmp_10	OK\n" : "ut_zjmp_10	ERROR\n");
	ft_putstr(ut_zjmp_11() ? "ut_zjmp_11	OK\n" : "ut_zjmp_11	ERROR\n");
	ft_putstr(ut_zjmp_12() ? "ut_zjmp_12	OK\n" : "ut_zjmp_12	ERROR\n");
	ft_putstr(ut_zjmp_13() ? "ut_zjmp_13	OK\n" : "ut_zjmp_13	ERROR\n");
	ft_putstr(ut_zjmp_14() ? "ut_zjmp_14	OK\n" : "ut_zjmp_14	ERROR\n");
	ft_putstr(ut_zjmp_15() ? "ut_zjmp_15	OK\n" : "ut_zjmp_15	ERROR\n");
	*/
}

void			all_ut_instr(void)
{
	ut_add();
	ut_aff();
	ut_and();
	ut_fork();
	ut_ld();
	ut_ldi();
	ut_lfork();
	ut_live();
	ut_lld();
	ut_lldi();
	ut_move();
	ut_or();
	ut_st();
	ut_sti();
	ut_sub();
	ut_xor();
	ut_zjmp();
}
