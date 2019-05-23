/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:57:10 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/23 14:42:06 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		ut_byte_1(void)
{
	/*
	** creation storage -> champion -> byte
	** affichage liste byte
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2 ? add_byte(&(st->last_champion)) : 0;
	if (UT_PRINT == 1)
		print_byte_list(&(st->first_champion));
	free_storage(&st);
	return (result == 3);
}

static int		ut_byte_2(void)
{
	/*
	** creation storage -> champion -> byte
	** changement valeur byte (0)
	** changement valeur byte (255)
	** affichage liste byte
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2 ? add_byte(&(st->last_champion)) : 0;
	result += result == 3
		? byte_change_value(&(st->last_champion->last_byte), 0) : 0;
	result += result == 4
		? byte_change_value(&(st->last_champion->last_byte), 255) : 0;
	if (UT_PRINT == 1)
		print_byte_list(&(st->last_champion));
	free_storage(&st);
	return (result == 5);
}

static int		ut_byte_3(void)
{
	/*
	** creation byte avec param null
	*/
	int			result;

	result = add_byte(NULL);
	return (result == -1);
}

static int		ut_byte_4(void)
{
	/*
	** creation byte avec champion vide
	*/
	t_champion	*ch;
	int			result;

	result = add_byte(&ch);
	return (result == -1);
}

static int		ut_byte_5(void)
{
	/*
	** creation storage -> champion -> byte
	** changement valeur byte avec valeur impossible (negative)
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2 ? add_byte(&(st->last_champion)) : 0;
	result += result == 3
		? byte_change_value(&(st->last_champion->last_byte), 5) : 0;
	result += result == 4
		? byte_change_value(&(st->last_champion->last_byte), -1) + 1 : 0;
	if (UT_PRINT == 1)
		print_byte_list(&(st->last_champion));
	free_storage(&st);
	return (result == 5);
}

static int		ut_byte_6(void)
{
	/*
	** creation storage -> champion -> byte
	** changement valeur byte avec valeur impossible (superieure a 255)
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2 ? add_byte(&(st->last_champion)) : 0;
	result += result == 3
		? byte_change_value(&(st->last_champion->last_byte), 5) : 0;
	result += result == 4
		? byte_change_value(&(st->last_champion->last_byte), 256) + 1 : 0;
	if (UT_PRINT == 1)
		print_byte_list(&(st->last_champion));
	free_storage(&st);
	return (result == 5);
}

static int		ut_champion_1(void)
{
	/*
	** creation storage -> champion
	** affichage liste champion
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 2);
}

static int		ut_champion_2(void)
{
	/*
	** creation storage -> champion
	** changement nom champion
	** affichage liste champion
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2
		? champion_change_name(&(st->last_champion), "test 1") : 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 3);
}

static int		ut_champion_3(void)
{
	/*
	** creation storage -> champion
	** changement desc champion
	** affichage liste champion
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2
		? champion_change_desc(&(st->last_champion), "test 2") : 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 3);
}

static int		ut_champion_4(void)
{
	/*
	** creation storage -> champion
	** changement number champion
	** affichage liste champion
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2
		? champion_change_number(&(st->last_champion), 1) : 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 3);
}

static int		ut_champion_5(void)
{
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
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2
		? champion_change_name(&(st->last_champion), "test 3") : 0;
	result += result == 3
		? champion_change_desc(&(st->last_champion), "test 4") : 0;
	result += result == 4
		? champion_change_number(&(st->last_champion), 1) : 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	result += result == 5
		? champion_change_name(&(st->last_champion), "test 5") : 0;
	result += result == 6
		? champion_change_desc(&(st->last_champion), "test 6") : 0;
	result += result == 7
		? champion_change_number(&(st->last_champion), 2) : 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 8);
}

static int		ut_champion_6(void)
{
	return (1);
}

static int		ut_grid_1(void)
{
	/*
	** creation grid
	** affichage grid
	** free grid
	*/
	int		**grid;

	add_grid(&grid);
	if (UT_PRINT == 1)
		print_grid(&grid);
	free_grid(&grid);
	return (1);
}

static int		ut_grid_2(void)
{
	/*
	** creation grid
	** ecriture de valeur dans la grid
	** affichage grid
	** free grid
	*/
	int		**grid;

	add_grid(&grid);
	write_in_grid(&grid, 255, 111);
	if (UT_PRINT == 1)
		print_grid(&grid);
	free_grid(&grid);
	return (1);
}

static int		ut_grid_3(void)
{
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
	if (UT_PRINT == 1)
		print_storage(&st);
	free_storage(&st);
	if (UT_PRINT == 1)
		print_grid(&grid);
	free_grid(&grid);
	return (1);
}

static int		ut_storage_1(void)
{
	/*
	** creation storage
	** affichage storage
	** free storage
	*/
	t_storage	*st;

	add_storage(&st);
	if (UT_PRINT == 1)
		print_storage(&st);
	free_storage(&st);
	return (1);
}

static int		ut_thread_1(void)
{
	/*
	** creation storage -> thread
	** affichage liste thread
	** free storage
	*/
	t_storage	*st;

	add_storage(&st);
	add_thread(&st, 1);
	if (UT_PRINT == 1)
		print_thread_list(&st);
	free_storage(&st);
	return (1);
}

int				ut_byte(void)
{
	printf(ut_byte_1() ? "ut_byte_1		OK\n" : "ut_byte_1		KO\n");
	printf(ut_byte_2() ? "ut_byte_2		OK\n" : "ut_byte_2		KO\n");
	printf(ut_byte_3() ? "ut_byte_3		OK\n" : "ut_byte_3		KO\n");
	printf(ut_byte_4() ? "ut_byte_4		OK\n" : "ut_byte_4		KO\n");
	printf(ut_byte_5() ? "ut_byte_5		OK\n" : "ut_byte_5		KO\n");
	printf(ut_byte_6() ? "ut_byte_6		OK\n" : "ut_byte_6		KO\n");
	return (1);
}

int				ut_champion(void)
{
	printf(ut_champion_1() ? "ut_champion_1		OK\n" : "ut_champion_1		KO\n");
	printf(ut_champion_2() ? "ut_champion_2		OK\n" : "ut_champion_2		KO\n");
	printf(ut_champion_3() ? "ut_champion_3		OK\n" : "ut_champion_3		KO\n");
	printf(ut_champion_4() ? "ut_champion_4		OK\n" : "ut_champion_4		KO\n");
	printf(ut_champion_5() ? "ut_champion_5		OK\n" : "ut_champion_5		KO\n");
	printf(ut_champion_6() ? "ut_champion_6		OK\n" : "ut_champion_6		KO\n");
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
	/*ut_byte();
	*/
	ut_champion();
	/*ut_grid();
	ut_storage();
	ut_thread();*/
	return (1);
}
