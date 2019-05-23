/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:57:10 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/23 18:05:15 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		ut_byte_01(void)
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

static int		ut_byte_02(void)
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

static int		ut_byte_03(void)
{
	/*
	** creation byte avec param null
	*/
	int			result;

	result = add_byte(NULL);
	return (result == -1);
}

static int		ut_byte_04(void)
{
	/*
	** creation byte avec champion vide
	*/
	t_champion	*ch;
	int			result;

	result = add_byte(&ch);
	return (result == -1);
}

static int		ut_byte_05(void)
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

static int		ut_byte_06(void)
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

static int		ut_champion_01(void)
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

static int		ut_champion_02(void)
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

static int		ut_champion_03(void)
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

static int		ut_champion_04(void)
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

static int		ut_champion_05(void)
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
		? champion_change_number(&(st->last_champion), 4) : 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 8);
}

static int		ut_champion_06(void)
{
	/*
	** creation champion avec param null
	*/
	int			result;

	result = add_champion(NULL);
	return (result == -1);
}

static int		ut_champion_07(void)
{
	/*
	** creation champion avec storage vide
	*/
	t_storage	*st;
	int			result;

	result = add_champion(&st);
	return (result == -1);
}

static int		ut_champion_08(void)
{
	/*
	** creation storage -> champion
	** changement number champion valeur impossible (0)
	** affichage liste champion
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2
		? champion_change_number(&(st->last_champion), 0) + 1: 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 3);
}

static int		ut_champion_09(void)
{
	/*
	** creation storage -> champion
	** changement number champion valeur impossible (5)
	** affichage liste champion
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2
		? champion_change_number(&(st->last_champion), 5) + 1: 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 3);
}

static int		ut_champion_10(void)
{
	/*
	** creation storage -> champion
	** changement nom champion valeur impossible (NULL)
	** affichage liste champion
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2
		? champion_change_name(&(st->last_champion), NULL) + 1: 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 3);
}

static int		ut_champion_11(void)
{
	/*
	** creation storage -> champion
	** changement desc champion valeur impossible (NULL)
	** affichage liste champion
	** free storage
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	result += result == 1 ? add_champion(&st) : 0;
	result += result == 2
		? champion_change_desc(&(st->last_champion), NULL) + 1: 0;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 3);
}

static int		ut_grid_01(void)
{
	/*
	** creation grid
	** affichage grid
	** free grid
	*/
	t_storage	*st;

	add_storage(&st);
	add_grid(&st);
	if (UT_PRINT == 1)
		print_grid(&(st->grid));
	free_grid(&(st->grid));
	free_storage(&st);
	return (1);
}

static int		ut_grid_02(void)
{
	/*
	** creation grid
	** ecriture de valeur dans la grid
	** affichage grid
	** free grid
	*/
	t_storage	*st;

	add_storage(&st);
	add_grid(&st);
	write_in_grid(&(st->grid), 255, 111);
	if (UT_PRINT == 1)
		print_grid(&(st->grid));
	free_grid(&(st->grid));
	free_storage(&st);
	return (1);
}

static int		ut_grid_03(void)
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
	** affichage grid
	** free grid
	** affichage storage
	** free storage
	*/
	t_storage	*st;

	add_storage(&st);
	add_grid(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 1);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 2);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 3);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 4);
	grid_fill_with_champ(&(st->grid), &(st->last_champion));
	if (UT_PRINT == 1)
		print_grid(&(st->grid));
	free_grid(&(st->grid));
	if (UT_PRINT == 1)
		print_storage(&st);
	free_storage(&st);
	return (1);
}

static int		ut_storage_01(void)
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

static int		ut_thread_01(void)
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
	printf(ut_byte_01() ? "ut_byte_01		OK\n" : "ut_byte_01		KO\n");
	printf(ut_byte_02() ? "ut_byte_02		OK\n" : "ut_byte_02		KO\n");
	printf(ut_byte_03() ? "ut_byte_03		OK\n" : "ut_byte_03		KO\n");
	printf(ut_byte_04() ? "ut_byte_04		OK\n" : "ut_byte_04		KO\n");
	printf(ut_byte_05() ? "ut_byte_05		OK\n" : "ut_byte_05		KO\n");
	printf(ut_byte_06() ? "ut_byte_06		OK\n" : "ut_byte_06		KO\n");
	return (1);
}

int				ut_champion(void)
{
	printf(ut_champion_01() ? "ut_champion_01		OK\n" : "ut_champion_01		KO\n");
	printf(ut_champion_02() ? "ut_champion_02		OK\n" : "ut_champion_02		KO\n");
	printf(ut_champion_03() ? "ut_champion_03		OK\n" : "ut_champion_03		KO\n");
	printf(ut_champion_04() ? "ut_champion_04		OK\n" : "ut_champion_04		KO\n");
	printf(ut_champion_05() ? "ut_champion_05		OK\n" : "ut_champion_05		KO\n");
	printf(ut_champion_06() ? "ut_champion_06		OK\n" : "ut_champion_06		KO\n");
	printf(ut_champion_07() ? "ut_champion_07		OK\n" : "ut_champion_07		KO\n");
	printf(ut_champion_08() ? "ut_champion_08		OK\n" : "ut_champion_08		KO\n");
	printf(ut_champion_09() ? "ut_champion_09		OK\n" : "ut_champion_09		KO\n");
	printf(ut_champion_10() ? "ut_champion_10		OK\n" : "ut_champion_10		KO\n");
	printf(ut_champion_11() ? "ut_champion_11		OK\n" : "ut_champion_11		KO\n");
	return (1);
}

int				ut_grid(void)
{
	printf(ut_grid_01() ? "ut_grid_01		OK\n" : "ut_grid_01		KO\n");
	printf(ut_grid_02() ? "ut_grid_02		OK\n" : "ut_grid_02		KO\n");
	printf(ut_grid_03() ? "ut_grid_03		OK\n" : "ut_grid_03		KO\n");
	return (1);
}

int				ut_storage(void)
{
	printf(ut_storage_01() ? "ut_storage_01		OK\n" : "ut_storage_01		KO\n");
	return (1);
}

int				ut_thread(void)
{
	printf(ut_thread_01() ? "ut_thread_01		OK\n" : "ut_thread_01		KO\n");
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
