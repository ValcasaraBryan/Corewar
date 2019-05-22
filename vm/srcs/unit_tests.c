/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:57:10 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 16:17:40 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
** creation structure -> champion -> byte
** affichage
** free
*/

static int		ut_byte_1(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->first_champion));
	//print_byte_list(&(st->first_champion));
	free_storage(&st);
	return (1);
}

/*
** creation structure -> champion -> byte
** creation byte
** creation byte
** affichage
** free
*/

static int		ut_byte_2(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->first_champion));
	add_byte(&(st->first_champion));
	add_byte(&(st->first_champion));
	print_byte_list(&(st->first_champion));
	free_storage(&st);
	return (1);
}

/*
** creation structure -> champion
** affichage
** free
*/

static int		ut_champion_1(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	//print_champion_list(&st);
	free_storage(&st);
	return (1);
}

/*
** creation structure -> champion
** changement nom
** affichage
** free
*/

static int		ut_champion_2(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	champion_change_name(&(st->first_champion), "test 1");
	//print_champion_list(&st);
	free_storage(&st);
	return (1);
}

/*
** creation structure -> champion
** changement desc
** affichage
** free
*/

static int		ut_champion_3(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	champion_change_desc(&(st->first_champion), "test 2");
	//print_champion_list(&st);
	free_storage(&st);
	return (1);
}

/*
** creation structure -> champion
** changement number
** affichage
** free
*/

static int		ut_champion_4(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	champion_change_number(&(st->first_champion), 5);
	//print_champion_list(&st);
	free_storage(&st);
	return (1);
}

/*
** creation structure -> champion
** changement nom
** changement desc
** changement number
** affichage
** changement nom
** changement desc
** changement number
** affichage
** free
*/

static int		ut_champion_5(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	champion_change_name(&(st->first_champion), "test 3");
	champion_change_desc(&(st->first_champion), "test 4");
	champion_change_number(&(st->first_champion), 8);
	//print_champion_list(&st);
	champion_change_name(&(st->first_champion), "test 5");
	champion_change_desc(&(st->first_champion), "test 6");
	champion_change_number(&(st->first_champion), 9);
	//print_champion_list(&st);
	free_storage(&st);
	return (1);
}

/*
** creation structure
** affichage
** ecriture de valeur dans la grid
** affichage
** free
*/

static int		ut_grid_1(void)
{
	int		**grid;

	add_grid(&grid);
	//print_grid(&grid);
	write_in_grid(&grid, 255, 111);
	//print_grid(&grid);
	free_grid(&grid);
	return (1);
}

/*
** creation structure
** free
*/

static int		ut_storage_1(void)
{
	t_storage	*st;

	add_storage(&st);
	free_storage(&st);
	return (1);
}

/*
** creation structure -> thread
** affichage
** free
*/

static int		ut_thread_1(void)
{
	t_storage	*st;

	add_storage(&st);
	add_thread(&st, 1);
	//print_thread_list(&st);
	free_storage(&st);
	return (1);
}

int				ut_byte(void)
{
	printf(ut_byte_1() ? "ut_byte_1		OK\n" : "ut_byte_1		KO\n");
	printf(ut_byte_2() ? "ut_byte_2		OK\n" : "ut_byte_2		KO\n");
	return (1);
}

int				ut_champion(void)
{
	printf(ut_champion_1() ? "ut_champion_1		OK\n" : "ut_champion_1		KO\n");
	printf(ut_champion_2() ? "ut_champion_2		OK\n" : "ut_champion_2		KO\n");
	printf(ut_champion_3() ? "ut_champion_3		OK\n" : "ut_champion_3		KO\n");
	printf(ut_champion_4() ? "ut_champion_4		OK\n" : "ut_champion_4		KO\n");
	printf(ut_champion_5() ? "ut_champion_5		OK\n" : "ut_champion_5		KO\n");
	return (1);
}

int				ut_grid(void)
{
	printf(ut_grid_1() ? "ut_grid_1		OK\n" : "ut_grid_1		KO\n");
	return (1);
}

int				ut_storage(void)
{
	printf(ut_storage_1() ? "ut_storage_1		OK\n" : "ut_storage_1		KO\n");
	return (1);
}

int				ut_thread(void)
{
	printf(ut_thread_1() ? "ut_thread_1		OK\n" : "ut_thread_1		KO\n");
	return (1);
}

int				all_ut(void)
{
	ut_byte();
	ut_champion();
	ut_grid();
	ut_storage();
	ut_thread();
	return (1);
}
