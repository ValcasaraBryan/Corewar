/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:57:10 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/22 18:20:38 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/*
** creation storage -> champion -> byte
** affichage liste byte
** free storage
*/

static int		ut_byte_1(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	//print_byte_list(&(st->first_champion));
	free_storage(&st);
	return (1);
}

/*
** creation storage -> champion -> byte
** changement valeur byte
** affichage liste byte
** free storage
*/

static int		ut_byte_2(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 5);
	//print_byte_list(&(st->last_champion));
	free_storage(&st);
	return (1);
}

/*
** creation storage -> champion
** affichage liste champion
** free storage
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
** creation storage -> champion
** changement nom champion
** affichage liste champion
** free storage
*/

static int		ut_champion_2(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	champion_change_name(&(st->last_champion), "test 1");
	//print_champion_list(&st);
	free_storage(&st);
	return (1);
}

/*
** creation storage -> champion
** changement desc champion
** affichage liste champion
** free storage
*/

static int		ut_champion_3(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	champion_change_desc(&(st->last_champion), "test 2");
	//print_champion_list(&st);
	free_storage(&st);
	return (1);
}

/*
** creation storage -> champion
** changement number champion
** affichage liste champion
** free storage
*/

static int		ut_champion_4(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	champion_change_number(&(st->last_champion), 5);
	//print_champion_list(&st);
	free_storage(&st);
	return (1);
}

/*
** creation storage -> champion
** changement nom champion
** changement desc champion
** changement number champion
** affichage liste champion
** changement nom champion
** changement desc champion
** changement number champion
** affichage liste champion
** free storage
*/

static int		ut_champion_5(void)
{
	t_storage	*st;

	add_storage(&st);
	add_champion(&st);
	champion_change_name(&(st->last_champion), "test 3");
	champion_change_desc(&(st->last_champion), "test 4");
	champion_change_number(&(st->last_champion), 8);
	//print_champion_list(&st);
	champion_change_name(&(st->last_champion), "test 5");
	champion_change_desc(&(st->last_champion), "test 6");
	champion_change_number(&(st->last_champion), 9);
	//print_champion_list(&st);
	free_storage(&st);
	return (1);
}

/*
** creation grid
** affichage grid
** free grid
*/

static int		ut_grid_1(void)
{
	int		**grid;

	add_grid(&grid);
	//print_grid(&grid);
	free_grid(&grid);
	return (1);
}

/*
** creation grid
** ecriture de valeur dans la grid
** affichage grid
** free grid
*/

static int		ut_grid_2(void)
{
	int		**grid;

	add_grid(&grid);
	write_in_grid(&grid, 255, 111);
	//print_grid(&grid);
	free_grid(&grid);
	return (1);
}

/*
** creation grid
** creation storage -> champion -> byte
** changement valeur byte
** creation storage -> champion -> byte
** changement valeur byte
** creation storage -> champion -> byte
** changement valeur byte
** creation storage -> champion -> byte
** changement valeur byte
** affichage storage
** free storage
** affichage grid
** free grid
*/

static int		ut_grid_3(void)
{
	int		**grid;
	t_storage	*st;

	add_grid(&grid);
	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 1);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 2);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 3);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 4);
	fill_grid_with_champ(&grid, &(st->last_champion));
	print_storage(&st);
	free_storage(&st);
	print_grid(&grid);
	free_grid(&grid);
	return (1);
}

/*
** creation storage
** affichage storage
** free storage
*/

static int		ut_storage_1(void)
{
	t_storage	*st;

	add_storage(&st);
	//print_storage(&st);
	free_storage(&st);
	return (1);
}

/*
** creation storage -> thread
** affichage liste thread
** free storage
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
	printf(ut_grid_2() ? "ut_grid_2		OK\n" : "ut_grid_2		KO\n");
	printf(ut_grid_3() ? "ut_grid_3		OK\n" : "ut_grid_3		KO\n");
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
