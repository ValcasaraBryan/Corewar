/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:57:10 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/29 17:09:28 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

char	*desc = " module de defense";
char 	*name = " maxidef ";
char	*path_all_ok = "../vm_champs/champs/test_3.cor";
char	*path_fake = "lol.cor";
char	*path_folder = "../vm_champs/champs/";
char	*path_no_rights = "../vm_champs/champs/maxidef_bis.cor";
char	*path_dev_zero = "/dev/zero";
char	*path_dev_random = "/dev/random";
char	*path_dev_null = "/dev/null";

static int		ut_byte_01(void)
{
	/*
	** creation byte
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = add_byte(&(st->last_champion));
	if (UT_PRINT == 1)
		print_byte_list(&(st->first_champion));
	free_storage(&st);
	return (result == 1);
}

static int		ut_byte_02(void)
{
	/*
	** changement valeur byte valeurs charnieres
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = byte_change_value(&(st->last_champion->last_byte), 0);
	result += byte_change_value(&(st->last_champion->last_byte), 255);
	if (UT_PRINT == 1)
		print_byte_list(&(st->last_champion));
	free_storage(&st);
	return (result == 2);
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

	ch = NULL;
	result = add_byte(&ch);
	return (result == -1);
}

static int		ut_byte_05(void)
{
	/*
	** changement valeur byte avec valeurs impossibles (negative / superieure a 255)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 5);
	result = byte_change_value(&(st->last_champion->last_byte), -1) + 1;
	result += byte_change_value(&(st->last_champion->last_byte), 256) + 1;
	if (UT_PRINT == 1)
		print_byte_list(&(st->last_champion));
	free_storage(&st);
	return (result == 2);
}

static int		ut_byte_09(void)
{
	/*
	** free byte list avec param null
	*/
	int			result;

	result = free_byte_list(NULL);
	return (result == 0);
}

static int		ut_byte_10(void)
{
	/*
	** free byte list avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = free_byte_list(&ch);
	return (result == 0);
}

static int		ut_byte_11(void)
{
	/*
	** print byte list avec param null
	*/
	int			result;

	result = print_byte_list(NULL);
	return (result == 0);
}

static int		ut_byte_12(void)
{
	/*
	** print byte list avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = print_byte_list(&ch);
	return (result == 0);
}

static int		ut_byte_13(void)
{
	/*
	** print byte list
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = print_byte_list(&(st->first_champion));
	free_storage(&st);
	return (result == 1);
}

static int		ut_byte_14(void)
{
	/*
	** free byte list
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = free_byte_list(&(st->first_champion));
	free_storage(&st);
	return (result == 1);
}

static int		ut_byte_15(void)
{
	/*
	** byte_check avec param null
	*/
	int			result;

	result = byte_check(NULL);
	return (result == -1);
}

static int		ut_byte_16(void)
{
	/*
	** byte_check avec byte vide
	*/
	t_byte		*bt;
	int			result;

	bt = NULL;
	result = byte_check(&bt);
	return (result == -1);
}

static int		ut_byte_17(void)
{
	/*
	** byte_check
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = byte_check(&(st->last_champion->last_byte));
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_01(void)
{
	/*
	** creation champion
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = add_champion(&st);
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_02(void)
{
	/*
	** changement nom champion
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_name(&(st->last_champion), "test 1");
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_03(void)
{
	/*
	** changement desc champion
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_desc(&(st->last_champion), "test 2");
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_04(void)
{
	/*
	** changement number champion valeurs charnieres (1 / 4)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_number(&(st->last_champion), 1);
	result += champion_change_number(&(st->last_champion), 4);
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 2);
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

	st = NULL;
	result = add_champion(&st);
	return (result == -1);
}

static int		ut_champion_08(void)
{
	/*
	** changement number champion valeurs impossibles (0 / 5)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_number(&(st->last_champion), 0) + 1;
	result += champion_change_number(&(st->last_champion), 5) + 1;
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 2);
}

static int		ut_champion_10(void)
{
	/*
	** changement nom champion valeur impossible (NULL)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_name(&(st->last_champion), NULL);
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 0);
}

static int		ut_champion_11(void)
{
	/*
	** changement desc champion valeur impossible (NULL)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_desc(&(st->last_champion), NULL);
	if (UT_PRINT == 1)
		print_champion_list(&st);
	free_storage(&st);
	return (result == 0);
}

static int		ut_champion_14(void)
{
	/*
	** free champion list avec param null
	*/
	int			result;

	result = free_champion_list(NULL);
	return (result == 0);
}

static int		ut_champion_15(void)
{
	/*
	** free champion list avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = free_champion_list(&st);
	return (result == 0);
}

static int		ut_champion_16(void)
{
	/*
	** print champion list avec param null
	*/
	int			result;

	result = print_champion_list(NULL);
	return (result == 0);
}

static int		ut_champion_17(void)
{
	/*
	** print champion list avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_champion_list(&st);
	return (result == 0);
}

static int		ut_champion_18(void)
{
	/*
	** print champion list
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = print_champion_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_19(void)
{
	/*
	** free champion list
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = free_champion_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_20(void)
{
	/*
	** champion_check avec param null
	*/
	int			result;

	result = champion_check(NULL);
	return (result == -1);
}

static int		ut_champion_21(void)
{
	/*
	** champion_check avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = champion_check(&ch);
	return (result == -1);
}

static int		ut_champion_22(void)
{
	/*
	** champion_check sans bytes
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_check(&(st->last_champion));
	free_storage(&st);
	return (result == 0);
}

static int		ut_champion_23(void)
{
	/*
	** champion_check avec bytes
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = champion_check(&(st->last_champion));
	free_storage(&st);
	return (result == 1);
}

static int		ut_grid_01(void)
{
	/*
	** creation grid
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = add_grid(&st);
	if (UT_PRINT == 1)
		print_storage(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_grid_02(void)
{
	/*
	** ecriture de valeur dans la grid
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = write_in_grid(&(st->grid), 255, 111);
	if (UT_PRINT == 1)
		print_storage(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_grid_03(void)
{
	/*
	** ecriture des bytes d'un champion dans la grid
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	add_champion(&st);
	champion_change_number(&(st->last_champion), 4);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 1);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 2);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 3);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 4);
	result = grid_fill_with_champ(&(st->grid), &(st->last_champion));
	if (UT_PRINT == 1)
		print_storage(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_grid_04(void)
{
	/*
	** creation grid avec param null
	*/
	int			result;

	result = add_grid(NULL);
	return (result == -1);
}

static int		ut_grid_05(void)
{
	/*
	** creation grid avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = add_grid(&st);
	return (result == -1);
}

static int		ut_grid_06(void)
{
	/*
	** free grid avec param null
	*/
	int			result;

	result = free_grid(NULL);
	return (result == 0);
}

static int		ut_grid_07(void)
{
	/*
	** free grid avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = free_grid(&st);
	free_storage(&st);
	return (result == 0);
}

static int		ut_grid_08(void)
{
	/*
	** print grid avec param null
	*/
	int			result;

	result = print_grid(NULL);
	return (result == 0);
}

static int		ut_grid_09(void)
{
	/*
	** print grid avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = print_grid(&st);
	free_storage(&st);
	return (result == 0);
}

//grid_fill_with_champ non fonctionnel a faire
//write_in_grid non fonctionnel a faire

static int		ut_storage_01(void)
{
	/*
	** creation storage
	*/
	t_storage	*st;

	add_storage(&st);
	if (UT_PRINT == 1)
		print_storage(&st);
	free_storage(&st);
	return (1);
}

static int		ut_storage_02(void)
{
	/*
	** free storage avec param null
	*/
	int			result;

	result = free_storage(NULL);
	return (result == 0);
}

static int		ut_storage_03(void)
{
	/*
	** free storage avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = free_storage(&st);
	return (result == 0);
}

static int		ut_storage_04(void)
{
	/*
	** print storage avec param null
	*/
	int			result;

	result = print_storage(NULL);
	return (result == 0);
}

static int		ut_storage_05(void)
{
	/*
	** print storage avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_storage(&st);
	return (result == 0);
}

static int		ut_storage_06(void)
{
	/*
	** storage_check avec param null
	*/
	int			result;

	result = storage_check(NULL, 0);
	return (result == -1);
}

static int		ut_storage_07(void)
{
	/*
	** storage_check avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = storage_check(&st, 0);
	return (result == -1);
}

static int		ut_storage_08(void)
{
	/*
	** storage_check sans champion
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = storage_check(&st, 0);
	free_storage(&st);
	return (result == 0);
}

static int		ut_storage_09(void)
{
	/*
	** storage_check avec champion
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = storage_check(&st, 0);
	free_storage(&st);
	return (result == 1);
}

static int		ut_storage_10(void)
{
	/*
	** storage_check sans grid
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = storage_check(&st, 1);
	free_storage(&st);
	return (result == 0);
}

static int		ut_storage_11(void)
{
	/*
	** storage_check avec grid
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = storage_check(&st, 1);
	free_storage(&st);
	return (result == 1);
}

static int		ut_storage_12(void)
{
	/*
	** storage_check sans thread
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = storage_check(&st, 2);
	free_storage(&st);
	return (result == 0);
}

static int		ut_storage_13(void)
{
	/*
	** storage_check avec thread
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = storage_check(&st, 2);
	free_storage(&st);
	return (result == 1);
}

static int		ut_storage_14(void)
{
	/*
	** storage_check mauvais type
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = storage_check(&st, 3);
	free_storage(&st);
	return (result == -2);
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
	add_thread(&st);
	if (UT_PRINT == 1)
		print_thread_list(&st);
	free_storage(&st);
	return (1);
}

static int		ut_thread_04(void)
{
	/*
	** free thread list avec param null
	*/
	int			result;

	result = free_thread_list(NULL);
	return (result == 0);
}

static int		ut_thread_05(void)
{
	/*
	** free thread list avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = free_thread_list(&st);
	return (result == 0);
}

static int		ut_thread_06(void)
{
	/*
	** print thread list avec param null
	*/
	int			result;

	result = print_thread_list(NULL);
	return (result == 0);
}

static int		ut_thread_07(void)
{
	/*
	** print thread list avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_thread_list(&st);
	return (result == 0);
}

static int		ut_thread_08(void)
{
	/*
	** print thread list
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = print_thread_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_thread_09(void)
{
	/*
	** free thread list
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = free_thread_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_thread_10(void)
{
	/*
	** thread_check avec param null
	*/
	int			result;

	result = thread_check(NULL);
	return (result == -1);
}

static int		ut_thread_11(void)
{
	/*
	** thread_check avec thread vide
	*/
	t_thread	*th;
	int			result;

	th = NULL;
	result = thread_check(&th);
	return (result == -1);
}

static int		ut_thread_12(void)
{
	/*
	** thread_check
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_check(&(st->last_thread));
	free_storage(&st);
	return (result == 1);
}

static int		ut_thread_13(void)
{
	/*
	** thread_change_action avec param null
	*/
	int			result;

	result = thread_change_action(NULL, 0);
	return (result == -1);
}

static int		ut_thread_14(void)
{
	/*
	** thread_change_action avec thread vide
	*/
	t_thread	*th;
	int			result;

	th = NULL;
	result = thread_change_action(&th, 0);
	return (result == -1);
}

static int		ut_thread_15(void)
{
	/*
	** thread_change_action avec valeurs charnieres (0 / 16)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_action(&(st->last_thread), 0);
	result += thread_change_action(&(st->last_thread), 16);
	free_storage(&st);
	return (result == 2);
}

static int		ut_thread_16(void)
{
	/*
	** thread_change_action avec valeurs impossibles (-1 / 17)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_action(&(st->last_thread), -1) + 1;
	result += thread_change_action(&(st->last_thread), 17) + 1;
	free_storage(&st);
	return (result == 2);
}

static int		ut_thread_17(void)
{
	/*
	** thread_change_where avec param null
	*/
	int			result;

	result = thread_change_where(NULL, 0);
	return (result == -1);
}

static int		ut_thread_18(void)
{
	/*
	** thread_change_where avec thread vide
	*/
	t_thread	*th;
	int			result;

	th = NULL;
	result = thread_change_where(&th, 0);
	return (result == -1);
}

static int		ut_thread_19(void)
{
	/*
	** thread_change_where avec valeurs charnieres (0 / GRID_SIZE * GRID_SIZE)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_where(&(st->last_thread), 0);
	result += thread_change_where(&(st->last_thread), GRID_SIZE * GRID_SIZE);
	free_storage(&st);
	return (result == 2);
}

static int		ut_thread_20(void)
{
	/*
	** thread_change_where avec valeurs impossibles (-1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_where(&(st->last_thread), -1) + 1;
	free_storage(&st);
	return (result == 1);
}

static int		ut_thread_21(void)
{
	/*
	** thread_change_cycle avec param null
	*/
	int			result;

	result = thread_change_cycle(NULL, 0);
	return (result == -1);
}

static int		ut_thread_22(void)
{
	/*
	** thread_change_cycle avec thread vide
	*/
	t_thread	*th;
	int			result;

	th = NULL;
	result = thread_change_cycle(&th, 0);
	return (result == -1);
}

static int		ut_thread_23(void)
{
	/*
	** thread_change_cycle avec valeurs charnieres (0 / 1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	thread_change_action(&(st->last_thread), 2);
	result = thread_change_cycle(&(st->last_thread), 0);
	result += thread_change_cycle(&(st->last_thread), 1);
	free_storage(&st);
	return (result == 2);
}

static int		ut_thread_24(void)
{
	/*
	** thread_change_cycle avec valeurs impossibles (-1 / 2)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_cycle(&(st->last_thread), -1) + 1;
	result += thread_change_cycle(&(st->last_thread), 2) + 1;
	free_storage(&st);
	return (result == 2);
}

static int		ut_thread_25(void)
{
	/*
	** thread_change_cycle jusqu'a activation de la fonction
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	thread_change_action(&(st->last_thread), 2);
	result = thread_change_cycle(&(st->last_thread), 0);
	result += thread_change_cycle(&(st->last_thread), 1);
	result += thread_change_cycle(&(st->last_thread), 1);
	result += thread_change_cycle(&(st->last_thread), 1);
	result += thread_change_cycle(&(st->last_thread), 1);
	result += thread_change_cycle(&(st->last_thread), 1);
	free_storage(&st);
	return (result == 6);
}

static int		ut_thread_26(void)
{
	/*
	** thread_change_nb_champion avec param null
	*/
	int			result;

	result = thread_change_nb_champion(NULL, 0);
	return (result == -1);
}

static int		ut_thread_27(void)
{
	/*
	** thread_change_nb_champion avec thread vide
	*/
	t_thread	*th;
	int			result;

	th = NULL;
	result = thread_change_nb_champion(&th, 0);
	return (result == -1);
}

static int		ut_thread_28(void)
{
	/*
	** thread_change_nb_champion avec valeurs charnieres (1 / 4)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_nb_champion(&(st->last_thread), 1);
	result += thread_change_nb_champion(&(st->last_thread), 4);
	free_storage(&st);
	return (result == 2);
}

static int		ut_thread_29(void)
{
	/*
	** thread_change_nb_champion avec valeurs impossibles (0 / 5)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_nb_champion(&(st->last_thread), 0) + 1;
	result += thread_change_nb_champion(&(st->last_thread), 5) + 1;
	free_storage(&st);
	return (result == 2);
}

static int		ut_key_functions_01(void)
{
	int		*tab;
	decrypt_op_code(&tab, 144);
	free(tab);
	return (1);
}

static int		ut_utilities_01(void)
{
	return (1);
}

//tests a faire

static int		ut_bin_extractor_01(void)
{
	/*
	** appel avec param NULL
	*/
	int		result;

	result = bin_extractor(NULL, path_all_ok);
	return (result == 0);
}

static int		ut_bin_extractor_02(void)
{
	/*
	** appel avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = bin_extractor(&ch, path_all_ok);
	return (result == 0);
}

static int		ut_bin_extractor_03(void)
{
	/*
	** appel avec champion valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_all_ok);
	free_storage(&st);
	ft_putnbr(result);
	return (result == 1);
}

static int		ut_bin_extractor_04(void)
{
	/*
	** appel avec chemin invalide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_fake);
	free_storage(&st);
	return (result == -1);
}

static int		ut_bin_extractor_05(void)
{
	/*
	** verification name
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_all_ok);
	result += strcmp(st->last_champion->name, name);
	free_storage(&st);
	return (result == 1);
}

static int		ut_bin_extractor_06(void)
{
	/*
	** verification commentaire
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_all_ok);
	result += strcmp(st->last_champion->desc, desc);
	print_storage(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_bin_extractor_07(void)
{
	/*
	** appel avec chemin dossier
	*/
	t_storage	*st;
	int			result;
	
	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_folder);
	free_storage(&st);
	return (result == -1);
}

static int		ut_bin_extractor_08(void)
{
	/*
	** appel fichier sans droits
	*/
	t_storage	*st;
	int			result;
	
	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_no_rights);
	free_storage(&st);
	return (result == -1);
}

static int		ut_bin_extractor_09(void)
{
	/*
	** appel fichier dev zero
	*/
	t_storage	*st;
	int			result;
	
	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_dev_zero);
	free_storage(&st);
	return (result == -1);
}

static int		ut_bin_extractor_10(void)
{
	/*
	** appel fichier dev random
	*/
	t_storage	*st;
	int			result;
	
	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_dev_random);
	free_storage(&st);
	return (result == -1);
}

static int		ut_bin_extractor_11(void)
{
	/*
	** appel fichier dev null
	*/
	t_storage	*st;
	int			result;
	
	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_dev_null);
	free_storage(&st);
	return (result == -1);
}

//mauvais chemin
//	dossier /dev/zero /dev/random /dev/null

//plusieurs champions

static int		ut_byte(void)
{
	ft_putstr(ut_byte_01() ? "ut_byte_01		OK\n" : "ut_byte_01		ERROR\n");
	ft_putstr(ut_byte_02() ? "ut_byte_02		OK\n" : "ut_byte_02		ERROR\n");
	ft_putstr(ut_byte_03() ? "ut_byte_03		OK\n" : "ut_byte_03		ERROR\n");
	ft_putstr(ut_byte_04() ? "ut_byte_04		OK\n" : "ut_byte_04		ERROR\n");
	ft_putstr(ut_byte_05() ? "ut_byte_05		OK\n" : "ut_byte_05		ERROR\n");
	//ft_putstr(ut_byte_06() ? "ut_byte_06		OK\n" : "ut_byte_06		ERROR\n");
	//ft_putstr(ut_byte_07() ? "ut_byte_07		OK\n" : "ut_byte_07		ERROR\n");
	//ft_putstr(ut_byte_08() ? "ut_byte_08		OK\n" : "ut_byte_08		ERROR\n");
	ft_putstr(ut_byte_09() ? "ut_byte_09		OK\n" : "ut_byte_09		ERROR\n");
	ft_putstr(ut_byte_10() ? "ut_byte_10		OK\n" : "ut_byte_10		ERROR\n");
	ft_putstr(ut_byte_11() ? "ut_byte_11		OK\n" : "ut_byte_11		ERROR\n");
	ft_putstr(ut_byte_12() ? "ut_byte_12		OK\n" : "ut_byte_12		ERROR\n");
	if (UT_PRINT == 1)
		ft_putstr(ut_byte_13() ? "ut_byte_13		OK\n" : "ut_byte_13		ERROR\n");
	ft_putstr(ut_byte_14() ? "ut_byte_14		OK\n" : "ut_byte_14		ERROR\n");
	ft_putstr(ut_byte_15() ? "ut_byte_15		OK\n" : "ut_byte_15		ERROR\n");
	ft_putstr(ut_byte_16() ? "ut_byte_16		OK\n" : "ut_byte_16		ERROR\n");
	ft_putstr(ut_byte_17() ? "ut_byte_17		OK\n" : "ut_byte_17		ERROR\n");
	return (1);
}

static int		ut_champion(void)
{
	ft_putstr(ut_champion_01() ? "ut_champion_01		OK\n" : "ut_champion_01		ERROR\n");
	ft_putstr(ut_champion_02() ? "ut_champion_02		OK\n" : "ut_champion_02		ERROR\n");
	ft_putstr(ut_champion_03() ? "ut_champion_03		OK\n" : "ut_champion_03		ERROR\n");
	ft_putstr(ut_champion_04() ? "ut_champion_04		OK\n" : "ut_champion_04		ERROR\n");
	//ft_putstr(ut_champion_05() ? "ut_champion_05		OK\n" : "ut_champion_05		ERROR\n");
	ft_putstr(ut_champion_07() ? "ut_champion_07		OK\n" : "ut_champion_07		ERROR\n");
	ft_putstr(ut_champion_06() ? "ut_champion_06		OK\n" : "ut_champion_06		ERROR\n");
	ft_putstr(ut_champion_08() ? "ut_champion_08		OK\n" : "ut_champion_08		ERROR\n");
	//ft_putstr(ut_champion_09() ? "ut_champion_09		OK\n" : "ut_champion_09		ERROR\n");
	ft_putstr(ut_champion_10() ? "ut_champion_10		OK\n" : "ut_champion_10		ERROR\n");
	ft_putstr(ut_champion_11() ? "ut_champion_11		OK\n" : "ut_champion_11		ERROR\n");
	//ft_putstr(ut_champion_12() ? "ut_champion_12		OK\n" : "ut_champion_12		ERROR\n");
	//ft_putstr(ut_champion_13() ? "ut_champion_13		OK\n" : "ut_champion_13		ERROR\n");
	ft_putstr(ut_champion_14() ? "ut_champion_14		OK\n" : "ut_champion_14		ERROR\n");
	ft_putstr(ut_champion_15() ? "ut_champion_15		OK\n" : "ut_champion_15		ERROR\n");
	ft_putstr(ut_champion_16() ? "ut_champion_16		OK\n" : "ut_champion_16		ERROR\n");
	ft_putstr(ut_champion_17() ? "ut_champion_17		OK\n" : "ut_champion_17		ERROR\n");
	if (UT_PRINT == 1)
		ft_putstr(ut_champion_18() ? "ut_champion_18		OK\n" : "ut_champion_18		ERROR\n");
	ft_putstr(ut_champion_19() ? "ut_champion_19		OK\n" : "ut_champion_19		ERROR\n");
	ft_putstr(ut_champion_20() ? "ut_champion_20		OK\n" : "ut_champion_20		ERROR\n");
	ft_putstr(ut_champion_21() ? "ut_champion_21		OK\n" : "ut_champion_21		ERROR\n");
	ft_putstr(ut_champion_22() ? "ut_champion_22		OK\n" : "ut_champion_22		ERROR\n");
	ft_putstr(ut_champion_23() ? "ut_champion_23		OK\n" : "ut_champion_23		ERROR\n");
	return (1);
}

static int		ut_grid(void)
{
	ft_putstr(ut_grid_01() ? "ut_grid_01		OK\n" : "ut_grid_01		ERROR\n");
	ft_putstr(ut_grid_02() ? "ut_grid_02		OK\n" : "ut_grid_02		ERROR\n");
	ft_putstr(ut_grid_03() ? "ut_grid_03		OK\n" : "ut_grid_03		ERROR\n");
	ft_putstr(ut_grid_04() ? "ut_grid_04		OK\n" : "ut_grid_04		ERROR\n");
	ft_putstr(ut_grid_05() ? "ut_grid_05		OK\n" : "ut_grid_05		ERROR\n");
	ft_putstr(ut_grid_06() ? "ut_grid_06		OK\n" : "ut_grid_06		ERROR\n");
	ft_putstr(ut_grid_07() ? "ut_grid_07		OK\n" : "ut_grid_07		ERROR\n");
	ft_putstr(ut_grid_08() ? "ut_grid_08		OK\n" : "ut_grid_08		ERROR\n");
	ft_putstr(ut_grid_09() ? "ut_grid_09		OK\n" : "ut_grid_09		ERROR\n");
	return (1);
}

static int		ut_storage(void)
{
	ft_putstr(ut_storage_01() ? "ut_storage_01		OK\n" : "ut_storage_01		ERROR\n");
	ft_putstr(ut_storage_02() ? "ut_storage_02		OK\n" : "ut_storage_02		ERROR\n");
	ft_putstr(ut_storage_03() ? "ut_storage_03		OK\n" : "ut_storage_03		ERROR\n");
	ft_putstr(ut_storage_04() ? "ut_storage_04		OK\n" : "ut_storage_04		ERROR\n");
	ft_putstr(ut_storage_05() ? "ut_storage_05		OK\n" : "ut_storage_05		ERROR\n");
	ft_putstr(ut_storage_06() ? "ut_storage_06		OK\n" : "ut_storage_06		ERROR\n");
	ft_putstr(ut_storage_07() ? "ut_storage_07		OK\n" : "ut_storage_07		ERROR\n");
	ft_putstr(ut_storage_08() ? "ut_storage_08		OK\n" : "ut_storage_08		ERROR\n");
	ft_putstr(ut_storage_09() ? "ut_storage_09		OK\n" : "ut_storage_09		ERROR\n");
	ft_putstr(ut_storage_10() ? "ut_storage_10		OK\n" : "ut_storage_10		ERROR\n");
	ft_putstr(ut_storage_11() ? "ut_storage_11		OK\n" : "ut_storage_11		ERROR\n");
	ft_putstr(ut_storage_12() ? "ut_storage_12		OK\n" : "ut_storage_12		ERROR\n");
	ft_putstr(ut_storage_13() ? "ut_storage_13		OK\n" : "ut_storage_13		ERROR\n");
	ft_putstr(ut_storage_14() ? "ut_storage_14		OK\n" : "ut_storage_14		ERROR\n");
	return (1);
}

static int		ut_thread(void)
{
	ft_putstr(ut_thread_01() ? "ut_thread_01		OK\n" : "ut_thread_01		ERROR\n");
	//ft_putstr(ut_thread_02() ? "ut_thread_02		OK\n" : "ut_thread_02		ERROR\n");
	//ft_putstr(ut_thread_03() ? "ut_thread_03		OK\n" : "ut_thread_03		ERROR\n");
	ft_putstr(ut_thread_04() ? "ut_thread_04		OK\n" : "ut_thread_04		ERROR\n");
	ft_putstr(ut_thread_05() ? "ut_thread_05		OK\n" : "ut_thread_05		ERROR\n");
	ft_putstr(ut_thread_06() ? "ut_thread_06		OK\n" : "ut_thread_06		ERROR\n");
	ft_putstr(ut_thread_07() ? "ut_thread_07		OK\n" : "ut_thread_07		ERROR\n");
	if (UT_PRINT == 1)
		ft_putstr(ut_thread_08() ? "ut_thread_08		OK\n" : "ut_thread_08		ERROR\n");
	ft_putstr(ut_thread_09() ? "ut_thread_09		OK\n" : "ut_thread_09		ERROR\n");
	ft_putstr(ut_thread_10() ? "ut_thread_10		OK\n" : "ut_thread_10		ERROR\n");
	ft_putstr(ut_thread_11() ? "ut_thread_11		OK\n" : "ut_thread_11		ERROR\n");
	ft_putstr(ut_thread_12() ? "ut_thread_12		OK\n" : "ut_thread_12		ERROR\n");
	ft_putstr(ut_thread_13() ? "ut_thread_13		OK\n" : "ut_thread_13		ERROR\n");
	ft_putstr(ut_thread_14() ? "ut_thread_14		OK\n" : "ut_thread_14		ERROR\n");
	ft_putstr(ut_thread_15() ? "ut_thread_15		OK\n" : "ut_thread_15		ERROR\n");
	ft_putstr(ut_thread_16() ? "ut_thread_16		OK\n" : "ut_thread_16		ERROR\n");
	ft_putstr(ut_thread_17() ? "ut_thread_17		OK\n" : "ut_thread_17		ERROR\n");
	ft_putstr(ut_thread_18() ? "ut_thread_18		OK\n" : "ut_thread_18		ERROR\n");
	ft_putstr(ut_thread_19() ? "ut_thread_19		OK\n" : "ut_thread_19		ERROR\n");
	ft_putstr(ut_thread_20() ? "ut_thread_20		OK\n" : "ut_thread_20		ERROR\n");
	ft_putstr(ut_thread_21() ? "ut_thread_21		OK\n" : "ut_thread_21		ERROR\n");
	ft_putstr(ut_thread_22() ? "ut_thread_22		OK\n" : "ut_thread_22		ERROR\n");
	ft_putstr(ut_thread_23() ? "ut_thread_23		OK\n" : "ut_thread_23		ERROR\n");
	ft_putstr(ut_thread_24() ? "ut_thread_24		OK\n" : "ut_thread_24		ERROR\n");
	ft_putstr(ut_thread_25() ? "ut_thread_25		OK\n" : "ut_thread_25		ERROR\n");
	ft_putstr(ut_thread_26() ? "ut_thread_26		OK\n" : "ut_thread_26		ERROR\n");
	ft_putstr(ut_thread_27() ? "ut_thread_27		OK\n" : "ut_thread_27		ERROR\n");
	ft_putstr(ut_thread_28() ? "ut_thread_28		OK\n" : "ut_thread_28		ERROR\n");
	ft_putstr(ut_thread_29() ? "ut_thread_29		OK\n" : "ut_thread_29		ERROR\n");
	return (1);
}

static int		ut_key_functions(void)
{
	ft_putstr(ut_key_functions_01() ? "ut_key_functions_01	OK\n" : "ut_key_functions_01	ERROR\n");
	return (1);
}

static int		ut_utilities(void)
{
	ft_putstr(ut_utilities_01() ? "ut_utilities_01		OK\n" : "ut_utilities_01		ERROR\n");
	return (1);
}

static int		ut_bin_extractor(void)
{
	ft_putstr(ut_bin_extractor_01() ? "ut_bin_extractor_01	OK\n" : "ut_bin_extractor_01	ERROR\n");
	ft_putstr(ut_bin_extractor_02() ? "ut_bin_extractor_02	OK\n" : "ut_bin_extractor_02	ERROR\n");
	ft_putstr(ut_bin_extractor_03() ? "ut_bin_extractor_03	OK\n" : "ut_bin_extractor_03	ERROR\n");
	ft_putstr(ut_bin_extractor_04() ? "ut_bin_extractor_04	OK\n" : "ut_bin_extractor_04	ERROR\n");
	ft_putstr(ut_bin_extractor_05() ? "ut_bin_extractor_05	OK\n" : "ut_bin_extractor_05	ERROR\n");
	ft_putstr(ut_bin_extractor_06() ? "ut_bin_extractor_06	OK\n" : "ut_bin_extractor_06	ERROR\n");
	if (0)
		ft_putstr(ut_bin_extractor_07() ? "ut_bin_extractor_07	OK\n" : "ut_bin_extractor_07	ERROR\n");
	ft_putstr(ut_bin_extractor_08() ? "ut_bin_extractor_08	OK\n" : "ut_bin_extractor_08	ERROR\n");
	if (0)
		ft_putstr(ut_bin_extractor_09() ? "ut_bin_extractor_09	OK\n" : "ut_bin_extractor_09	ERROR\n");
	if (0)
		ft_putstr(ut_bin_extractor_10() ? "ut_bin_extractor_10	OK\n" : "ut_bin_extractor_10	ERROR\n");
	if (0)
		ft_putstr(ut_bin_extractor_11() ? "ut_bin_extractor_11	OK\n" : "ut_bin_extractor_11	ERROR\n");
	return (1);
}

int				all_ut(void)
{
	ut_byte();
	ut_champion();
	ut_grid();
	ut_storage();
	ut_thread();
	ut_key_functions();
	ut_utilities();
	ut_bin_extractor();
	return (1);
}
