/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:57:10 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/31 16:24:19 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

char	*desc = "test comm";
char 	*name = "test";
char	*path_all_ok = "../vm_champs/champs/test_2.cor";
char	*path_fake = "lol.cor";
char	*path_folder = "../vm_champs/champs/";
char	*path_no_rights = "../vm_champs/champs/maxidef_bis.cor";
char	*path_dev_zero = "/dev/zero";
char	*path_dev_random = "/dev/random";
char	*path_dev_null = "/dev/null";

static int		ut_byte_01(void)
{
	/*
	** add_byte avec param null
	*/
	int			result;

	result = add_byte(NULL);
	return (result == -1);
}

static int		ut_byte_02(void)
{
	/*
	** add_byte avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = add_byte(&ch);
	return (result == -1);
}

static int		ut_byte_03(void)
{
	/*
	** add_byte avec champion valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = add_byte(&(st->last_champion));
	free_storage(&st);
	return (result == 1);
}

static int		ut_byte_04(void)
{
	/*
	** free_byte_list avec param null
	*/
	int			result;

	result = free_byte_list(NULL);
	return (result == 0);
}

static int		ut_byte_05(void)
{
	/*
	** free_byte_list avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = free_byte_list(&ch);
	return (result == 0);
}

static int		ut_byte_06(void)
{
	/*
	** free_byte_list avec champion valide
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

static int		ut_byte_10(void)
{
	/*
	** byte_change_value valeurs charnieres
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = byte_change_value(&(st->last_champion->last_byte), 0);
	result += byte_change_value(&(st->last_champion->last_byte), 255);
	free_storage(&st);
	return (result == 2);
}

static int		ut_byte_11(void)
{
	/*
	** byte_change_value valeurs impossibles (negative / superieure a 255)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 5);
	result = byte_change_value(&(st->last_champion->last_byte), -1) + 1;
	result += byte_change_value(&(st->last_champion->last_byte), 256) + 1;
	free_storage(&st);
	return (result == 2);
}

static int		ut_byte_12(void)
{
	/*
	** byte_check avec param null
	*/
	int			result;

	result = byte_check(NULL);
	return (result == -1);
}

static int		ut_byte_13(void)
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

static int		ut_byte_14(void)
{
	/*
	** byte_check avec byte valide
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
	** add_champion avec param null
	*/
	int			result;

	result = add_champion(NULL);
	return (result == -1);
}

static int		ut_champion_02(void)
{
	/*
	** add_champion avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = add_champion(&st);
	return (result == -1);
}

static int		ut_champion_03(void)
{
	/*
	** add_champion avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = add_champion(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_04(void)
{
	/*
	** free_champion_list avec param null
	*/
	int			result;

	result = free_champion_list(NULL);
	return (result == 0);
}

static int		ut_champion_05(void)
{
	/*
	** free_champion_list avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = free_champion_list(&st);
	return (result == 0);
}

static int		ut_champion_06(void)
{
	/*
	** free_champion_list avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = free_champion_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_10(void)
{
	/*
	** champion_change_desc avec param null
	*/
	int			result;

	result = champion_change_desc(NULL, "test");
	return (result == -1);
}

static int		ut_champion_11(void)
{
	/*
	** champion_change_desc avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = champion_change_desc(&ch, "test");
	return (result == -1);
}

static int		ut_champion_12(void)
{
	/*
	** champion_change_desc avec valeur impossible (NULL)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_desc(&(st->last_champion), NULL);
	free_storage(&st);
	return (result == 0);
}

static int		ut_champion_13(void)
{
	/*
	** champion_change_desc avec params valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_desc(&(st->last_champion), "test 2");
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_14(void)
{
	/*
	** champion_change_name avec param null
	*/
	int			result;

	result = champion_change_name(NULL, "test");
	return (result == -1);
}

static int		ut_champion_15(void)
{
	/*
	** champion_change_name avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = champion_change_name(&ch, "test");
	return (result == -1);
}

static int		ut_champion_16(void)
{
	/*
	** champion_change_name avec valeur impossible (NULL)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_name(&(st->last_champion), NULL);
	free_storage(&st);
	return (result == 0);
}

static int		ut_champion_17(void)
{
	/*
	** champion_change_name avec params valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_name(&(st->last_champion), "test 1");
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_18(void)
{
	/*
	** champion_change_name avec params valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_name(&(st->last_champion), "test 1");
	free_storage(&st);
	return (result == 1);
}

static int		ut_champion_19(void)
{
	/*
	** champion_change_number avec param null
	*/
	int			result;

	result = champion_change_number(NULL, 1);
	return (result == -1);
}

static int		ut_champion_20(void)
{
	/*
	** champion_change_number avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = champion_change_number(&ch, 1);
	return (result == -1);
}

static int		ut_champion_21(void)
{
	/*
	** champion_change_number avec valeurs charnieres (1 / 4)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_number(&(st->last_champion), 1);
	result += champion_change_number(&(st->last_champion), 4);
	free_storage(&st);
	return (result == 2);
}

static int		ut_champion_22(void)
{
	/*
	** champion_change_number avec valeurs impossibles (0 / 5)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_number(&(st->last_champion), 0) + 1;
	result += champion_change_number(&(st->last_champion), 5) + 1;
	free_storage(&st);
	return (result == 2);
}

static int		ut_champion_23(void)
{
	/*
	** champion_check avec param null
	*/
	int			result;

	result = champion_check(NULL);
	return (result == -1);
}

static int		ut_champion_24(void)
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

static int		ut_champion_25(void)
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

static int		ut_champion_26(void)
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
	** add_grid avec param null
	*/
	int			result;

	result = add_grid(NULL);
	return (result == -1);
}

static int		ut_grid_02(void)
{
	/*
	** add_grid avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = add_grid(&st);
	return (result == -1);
}

static int		ut_grid_03(void)
{
	/*
	** add_grid avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = add_grid(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_grid_04(void)
{
	/*
	** free_grid avec param null
	*/
	int			result;

	result = free_grid(NULL);
	return (result == 0);
}

static int		ut_grid_05(void)
{
	/*
	** free_grid avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = free_grid(&st);
	free_storage(&st);
	return (result == 0);
}

static int		ut_grid_06(void)
{
	/*
	** free_grid avec grid valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = free_grid(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_grid_10(void)
{
	/*
	** grid_check avec param null
	*/
	int			result;

	result = grid_check(NULL);
	return (result == 0);
}

static int		ut_grid_11(void)
{
	/*
	** grid_check avec grid vide
	*/
	int			**gr;
	int			result;

	gr = NULL;
	result = grid_check(&gr);
	return (result == 0);
}

static int		ut_grid_12(void)
{
	/*
	** grid_check avec grid valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = grid_check(&(st->grid));
	free_storage(&st);
	return (result == 1);
}

static int		ut_grid_13(void)
{
	/*
	** grid_fill_with_champ avec grid null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = grid_fill_with_champ(NULL, &(st->last_champion));
	free_storage(&st);
	return (result == 0);
}

static int		ut_grid_14(void)
{
	/*
	** grid_fill_with_champ avec grid vide
	*/
	t_storage	*st;
	int			result;
	int			**gr;

	gr = NULL;
	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = grid_fill_with_champ(&gr, &(st->last_champion));
	free_storage(&st);
	return (result == 0);
}

static int		ut_grid_15(void)
{
	/*
	** grid_fill_with_champ avec champion null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = grid_fill_with_champ(&(st->grid), NULL);
	free_storage(&st);
	return (result == -1);
}

static int		ut_grid_16(void)
{
	/*
	** grid_fill_with_champ avec champion vide
	*/
	t_champion	*ch;
	t_storage	*st;
	int			result;

	ch = NULL;
	add_storage(&st);
	add_grid(&st);
	result = grid_fill_with_champ(&(st->grid), &ch);
	free_storage(&st);
	return (result == -1);
}

static int		ut_grid_17(void)
{
	/*
	** grid_fill_with_champ avec champion sans bytes
	*/
	t_champion	*ch;
	t_storage	*st;
	int			result;

	ch = NULL;
	add_storage(&st);
	add_champion(&st);
	add_grid(&st);
	result = grid_fill_with_champ(&(st->grid), &ch);
	free_storage(&st);
	return (result == -1);
}

static int		ut_grid_18(void)
{
	/*
	** grid_fill_with_champ avec params valides
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
	free_storage(&st);
	return (result == 1);
}

static int		ut_storage_01(void)
{
	/*
	** add_storage avec param null
	*/
	int			result;

	result = add_storage(NULL);
	return (result == -1);
}

static int		ut_storage_02(void)
{
	/*
	** add_storage avec param valide
	*/
	t_storage	*st;
	int			result;

	result = add_storage(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_storage_03(void)
{
	/*
	** free_storage avec param null
	*/
	int			result;

	result = free_storage(NULL);
	return (result == 0);
}

static int		ut_storage_04(void)
{
	/*
	** free_storage avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = free_storage(&st);
	return (result == 0);
}

static int		ut_storage_05(void)
{
	/*
	** free_storage avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = free_storage(&st);
	return (result == 1);
}

static int		ut_storage_09(void)
{
	/*
	** storage_check avec param null
	*/
	int			result;

	result = storage_check(NULL, 0);
	return (result == -1);
}

static int		ut_storage_10(void)
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

static int		ut_storage_11(void)
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

static int		ut_storage_12(void)
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

static int		ut_storage_13(void)
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

static int		ut_storage_14(void)
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

static int		ut_storage_15(void)
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

static int		ut_storage_16(void)
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

static int		ut_storage_17(void)
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
	** add_thread avec param null
	*/
	int			result;

	result = add_thread(NULL);
	return (result == -1);
}

static int		ut_thread_02(void)
{
	/*
	** add_thread avec param vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = add_thread(&st);
	return (result == -1);
}

static int		ut_thread_03(void)
{
	/*
	** add_thread avec param valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = add_thread(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_thread_04(void)
{
	/*
	** free_thread_list avec param null
	*/
	int			result;

	result = free_thread_list(NULL);
	return (result == 0);
}

static int		ut_thread_05(void)
{
	/*
	** free_thread_list avec storage vide
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
	** free_thread_list avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = free_thread_list(&st);
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
	** thread_change_cycle avec params null
	*/
	int			result;

	result = thread_change_cycle(NULL, NULL, 0);
	return (result == -1);
}

static int		ut_thread_18(void)
{
	/*
	** thread_change_cycle avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = thread_change_cycle(NULL, &(st->grid), 0);
	free_storage(&st);
	return (result == -1);
}

static int		ut_thread_19(void)
{
	/*
	** thread_change_cycle avec grid null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_cycle(&(st->last_thread), NULL, 0);
	free_storage(&st);
	return (result == -1);
}

static int		ut_thread_20(void)
{
	/*
	** thread_change_cycle avec params vides
	*/
	t_thread	*th;
	int			**gr;
	int			result;

	th = NULL;
	gr = NULL;
	result = thread_change_cycle(&th, &gr, 0);
	return (result == -1);
}

static int		ut_thread_21(void)
{
	/*
	** thread_change_cycle avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st);
	result = thread_change_cycle(&th, &(st->grid), 0);
	free_storage(&st);
	return (result == -1);
}

static int		ut_thread_22(void)
{
	/*
	** thread_change_cycle avec grid vide
	*/
	t_storage	*st;
	int			**gr;
	int			result;

	gr = NULL;
	add_storage(&st);
	add_thread(&st);
	result = thread_change_cycle(&(st->last_thread), &gr, 0);
	free_storage(&st);
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
	add_grid(&st);
	thread_change_action(&(st->last_thread), 2);
	result = thread_change_cycle(&(st->last_thread), &(st->grid), 0);
	result += thread_change_cycle(&(st->last_thread), &(st->grid), 1);
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
	add_grid(&st);
	result = thread_change_cycle(&(st->last_thread), &(st->grid), -1) + 1;
	result += thread_change_cycle(&(st->last_thread), &(st->grid), 2) + 1;
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
	add_grid(&st);
	thread_change_action(&(st->last_thread), 2);
	thread_change_cycle(&(st->last_thread), &(st->grid), 0);
	thread_change_cycle(&(st->last_thread), &(st->grid), 1);
	thread_change_cycle(&(st->last_thread), &(st->grid), 1);
	thread_change_cycle(&(st->last_thread), &(st->grid), 1);
	thread_change_cycle(&(st->last_thread), &(st->grid), 1);
	result = thread_change_cycle(&(st->last_thread), &(st->grid), 1);
	free_storage(&st);
	return (result == 2);
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

static int		ut_thread_30(void)
{
	/*
	** thread_change_where avec params null
	*/
	int			result;

	result = thread_change_where(NULL, NULL, 0);
	return (result == -1);
}

static int		ut_thread_31(void)
{
	/*
	** thread_change_where avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = thread_change_where(NULL, &(st->grid), 0);
	free_storage(&st);
	return (result == -1);
}

static int		ut_thread_32(void)
{
	/*
	** thread_change_where avec grid null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_where(&(st->last_thread), NULL, 0);
	free_storage(&st);
	return (result == -1);
}

static int		ut_thread_33(void)
{
	/*
	** thread_change_where avec params vides
	*/
	t_thread	*th;
	int			**gr;
	int			result;

	th = NULL;
	gr = NULL;
	result = thread_change_where(&th, &gr, 0);
	return (result == -1);
}

static int		ut_thread_34(void)
{
	/*
	** thread_change_where avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st);
	result = thread_change_where(&th, &(st->grid), 0);
	free_storage(&st);
	return (result == -1);
}

static int		ut_thread_35(void)
{
	/*
	** thread_change_where avec grid vide
	*/
	t_storage	*st;
	int			**gr;
	int			result;

	gr = NULL;
	add_storage(&st);
	add_thread(&st);
	result = thread_change_where(&(st->last_thread), &gr, 0);
	free_storage(&st);
	return (result == -1);
}

static int		ut_thread_36(void)
{
	/*
	** thread_change_where avec valeurs charnieres (0 / GRID_SIZE * GRID_SIZE - 1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	add_thread(&st);
	result = thread_change_where(&(st->last_thread), &(st->grid), 0);
	result += thread_change_where(&(st->last_thread), &(st->grid), GRID_SIZE * GRID_SIZE - 1);
	free_storage(&st);
	return (result == 2);
}

static int		ut_thread_37(void)
{
	/*
	** thread_change_where avec valeur impossible (-1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	add_thread(&st);
	result = thread_change_where(&(st->last_thread), &(st->grid), -1);
	free_storage(&st);
	return (result == 0);
}

static int		ut_thread_38(void)
{
	/*
	** thread_check avec param null
	*/
	int			result;

	result = thread_check(NULL);
	return (result == -1);
}

static int		ut_thread_39(void)
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

static int		ut_thread_40(void)
{
	/*
	** thread_check avec thread valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_check(&(st->last_thread));
	free_storage(&st);
	return (result == 1);
}

static int		ut_key_functions_01(void)
{
	/*
	** read_in_grid avec param null
	*/
	int			result;

	result = read_in_grid(NULL, 0);
	return (result == 0);
}

static int		ut_key_functions_02(void)
{
	/*
	** read_in_grid avec grid vide
	*/
	int			result;
	int			**gr;

	gr = NULL;
	result = read_in_grid(&gr, 0);
	return (result == 0);
}

static int		ut_key_functions_03(void)
{
	/*
	** read_in_grid avec valeur invalide (-1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	write_in_grid(&(st->grid), 5, 0);
	result = read_in_grid(&(st->grid), -1);
	free_storage(&st);
	return (result == -1);
}

static int		ut_key_functions_04(void)
{
	/*
	** read_in_grid avec valeurs charnieres (0 / GRID_SIZE * GRID_SIZE - 1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	write_in_grid(&(st->grid), 3, 0);
	write_in_grid(&(st->grid), 4, GRID_SIZE * GRID_SIZE - 1);
	result = read_in_grid(&(st->grid), 0);
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE - 1);
	free_storage(&st);
	return (result == 7);
}

static int		ut_key_functions_05(void)
{
	/*
	** write_in_grid avec param null
	*/
	int			result;

	result = write_in_grid(NULL, 0, 0);
	return (result == 0);
}

static int		ut_key_functions_06(void)
{
	/*
	** write_in_grid avec grid vide
	*/
	int			result;
	int			**gr;

	gr = NULL;
	result = write_in_grid(&gr, 0, 0);
	return (result == 0);
}

static int		ut_key_functions_07(void)
{
	/*
	** write_in_grid avec where invalide (-1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = write_in_grid(&(st->grid), 0, -1);
	free_storage(&st);
	return (result == -1);
}

static int		ut_key_functions_08(void)
{
	/*
	** write_in_grid avec values invalides (-1 / 256)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = write_in_grid(&(st->grid), -1, 0);
	result += write_in_grid(&(st->grid), 256, 0);
	free_storage(&st);
	return (result == -4);
}

static int		ut_key_functions_09(void)
{
	/*
	** write_in_grid avec where charnieres (0 / GRID_SIZE * GRID_SIZE - 1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = write_in_grid(&(st->grid), 0, 0);
	result += write_in_grid(&(st->grid), 0, GRID_SIZE * GRID_SIZE - 1);
	free_storage(&st);
	return (result == 2);
}

static int		ut_key_functions_10(void)
{
	/*
	** write_in_grid avec values charnieres (0 / 255)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = write_in_grid(&(st->grid), 0, 0);
	result += write_in_grid(&(st->grid), 255, 0);
	free_storage(&st);
	return (result == 2);
}

static int		ut_key_functions_11(void)
{
	/*
	** cycle_threads avec param null
	*/
	int		result;

	result = cycle_threads(NULL);
	return (result == 0);
}

static int		ut_key_functions_12(void)
{
	/*
	** cycle_threads avec storage vide
	*/
	t_storage	*st;
	int		result;

	st = NULL;
	result = cycle_threads(&st);
	return (result == 0);
}

static int		ut_key_functions_13(void)
{
	/*
	** cycle_threads avec storage sans threads
	*/
	t_storage	*st;
	int		result;

	add_storage(&st);
	result = cycle_threads(&st);
	free_storage(&st);
	return (result == 0);
}

static int		ut_key_functions_14(void)
{
	/*
	** cycle_threads avec storage et threads
	*/
	t_storage	*st;
	int		result;

	add_storage(&st);
	add_thread(&st);
	add_grid(&st);
	thread_change_nb_champion(&(st->last_thread), 1);
	thread_change_action(&(st->last_thread), 2);
	write_in_grid(&(st->grid), 5, 10);
	result = cycle_threads(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_key_functions_15(void)
{
	int		*tab;
	decrypt_op_code(&tab, 144);
	free(tab);
	return (1);
}


//cycle_threads fonctionnel et non fonctionnel a faire
//decrypt_op_code fonctionnel et non fonctionnel a faire

static int		ut_utilities_01(void)
{
	return (1);
}

//convert_to_binary fonctionnel et non fonctionnel a faire

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
	result += ft_strcmp(st->last_champion->name, name);
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
	result += ft_strcmp(st->last_champion->desc, desc);
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

static int		ut_print_struct_01(void)
{
	/*
	** print_byte_list avec param null
	*/
	int			result;

	result = print_byte_list(NULL);
	return (result == 0);
}

static int		ut_print_struct_02(void)
{
	/*
	** print_byte_list avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = print_byte_list(&ch);
	return (result == 0);
}

static int		ut_print_struct_03(void)
{
	/*
	** print_byte_list avec champion valide
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

static int		ut_print_struct_04(void)
{
	/*
	** print_champion_list avec param null
	*/
	int			result;

	result = print_champion_list(NULL);
	return (result == 0);
}

static int		ut_print_struct_05(void)
{
	/*
	** print_champion_list avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_champion_list(&st);
	return (result == 0);
}

static int		ut_print_struct_06(void)
{
	/*
	** print_champion_list avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = print_champion_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_print_struct_07(void)
{
	/*
	** print_grid avec param null
	*/
	int			result;

	result = print_grid(NULL);
	return (result == 0);
}

static int		ut_print_struct_08(void)
{
	/*
	** print_grid avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = print_grid(&st);
	free_storage(&st);
	return (result == 0);
}

static int		ut_print_struct_09(void)
{
	/*
	** print_grid avec grid valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st);
	result = print_grid(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_print_struct_10(void)
{
	/*
	** print_storage avec param null
	*/
	int			result;

	result = print_storage(NULL);
	return (result == 0);
}

static int		ut_print_struct_11(void)
{
	/*
	** print_storage avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_storage(&st);
	return (result == 0);
}

static int		ut_print_struct_12(void)
{
	/*
	** print_storage avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = print_storage(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_print_struct_13(void)
{
	/*
	** print_thread_list avec param null
	*/
	int			result;

	result = print_thread_list(NULL);
	return (result == 0);
}

static int		ut_print_struct_14(void)
{
	/*
	** print_thread_list avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_thread_list(&st);
	return (result == 0);
}

static int		ut_print_struct_15(void)
{
	/*
	** print_thread_list avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = print_thread_list(&st);
	free_storage(&st);
	return (result == 1);
}

static int		ut_print_struct_16(void)
{
	/*
	** print_thread_list_compact avec param null
	*/
	int			result;

	result = print_thread_list_compact(NULL);
	return (result == 0);
}

static int		ut_print_struct_17(void)
{
	/*
	** print_thread_list_compact avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_thread_list_compact(&st);
	return (result == 0);
}

static int		ut_print_struct_18(void)
{
	/*
	** print_thread_list_compact avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = print_thread_list_compact(&st);
	free_storage(&st);
	return (result == 1);
}

int				ut_byte(void)
{
	ft_putstr(ut_byte_01() ? "ut_byte_01		OK\n" : "ut_byte_01		ERROR\n");
	ft_putstr(ut_byte_02() ? "ut_byte_02		OK\n" : "ut_byte_02		ERROR\n");
	ft_putstr(ut_byte_03() ? "ut_byte_03		OK\n" : "ut_byte_03		ERROR\n");
	ft_putstr(ut_byte_04() ? "ut_byte_04		OK\n" : "ut_byte_04		ERROR\n");
	ft_putstr(ut_byte_05() ? "ut_byte_05		OK\n" : "ut_byte_05		ERROR\n");
	ft_putstr(ut_byte_06() ? "ut_byte_06		OK\n" : "ut_byte_06		ERROR\n");
	ft_putstr(ut_byte_10() ? "ut_byte_10		OK\n" : "ut_byte_10		ERROR\n");
	ft_putstr(ut_byte_11() ? "ut_byte_11		OK\n" : "ut_byte_11		ERROR\n");
	ft_putstr(ut_byte_12() ? "ut_byte_12		OK\n" : "ut_byte_12		ERROR\n");
	ft_putstr(ut_byte_13() ? "ut_byte_13		OK\n" : "ut_byte_13		ERROR\n");
	ft_putstr(ut_byte_14() ? "ut_byte_14		OK\n" : "ut_byte_14		ERROR\n");
	return (1);
}

int				ut_champion(void)
{
	ft_putstr(ut_champion_01() ? "ut_champion_01		OK\n" : "ut_champion_01		ERROR\n");
	ft_putstr(ut_champion_02() ? "ut_champion_02		OK\n" : "ut_champion_02		ERROR\n");
	ft_putstr(ut_champion_03() ? "ut_champion_03		OK\n" : "ut_champion_03		ERROR\n");
	ft_putstr(ut_champion_04() ? "ut_champion_04		OK\n" : "ut_champion_04		ERROR\n");
	ft_putstr(ut_champion_05() ? "ut_champion_05		OK\n" : "ut_champion_05		ERROR\n");
	ft_putstr(ut_champion_06() ? "ut_champion_06		OK\n" : "ut_champion_06		ERROR\n");
	ft_putstr(ut_champion_10() ? "ut_champion_10		OK\n" : "ut_champion_10		ERROR\n");
	ft_putstr(ut_champion_11() ? "ut_champion_11		OK\n" : "ut_champion_11		ERROR\n");
	ft_putstr(ut_champion_12() ? "ut_champion_12		OK\n" : "ut_champion_12		ERROR\n");
	ft_putstr(ut_champion_13() ? "ut_champion_13		OK\n" : "ut_champion_13		ERROR\n");
	ft_putstr(ut_champion_14() ? "ut_champion_14		OK\n" : "ut_champion_14		ERROR\n");
	ft_putstr(ut_champion_15() ? "ut_champion_15		OK\n" : "ut_champion_15		ERROR\n");
	ft_putstr(ut_champion_16() ? "ut_champion_16		OK\n" : "ut_champion_16		ERROR\n");
	ft_putstr(ut_champion_17() ? "ut_champion_17		OK\n" : "ut_champion_17		ERROR\n");
	ft_putstr(ut_champion_18() ? "ut_champion_18		OK\n" : "ut_champion_18		ERROR\n");
	ft_putstr(ut_champion_19() ? "ut_champion_19		OK\n" : "ut_champion_19		ERROR\n");
	ft_putstr(ut_champion_20() ? "ut_champion_20		OK\n" : "ut_champion_20		ERROR\n");
	ft_putstr(ut_champion_21() ? "ut_champion_21		OK\n" : "ut_champion_21		ERROR\n");
	ft_putstr(ut_champion_22() ? "ut_champion_22		OK\n" : "ut_champion_22		ERROR\n");
	ft_putstr(ut_champion_23() ? "ut_champion_23		OK\n" : "ut_champion_23		ERROR\n");
	ft_putstr(ut_champion_24() ? "ut_champion_24		OK\n" : "ut_champion_24		ERROR\n");
	ft_putstr(ut_champion_25() ? "ut_champion_25		OK\n" : "ut_champion_25		ERROR\n");
	ft_putstr(ut_champion_26() ? "ut_champion_26		OK\n" : "ut_champion_26		ERROR\n");
	return (1);
}

int				ut_grid(void)
{
	ft_putstr(ut_grid_01() ? "ut_grid_01		OK\n" : "ut_grid_01		ERROR\n");
	ft_putstr(ut_grid_02() ? "ut_grid_02		OK\n" : "ut_grid_02		ERROR\n");
	ft_putstr(ut_grid_03() ? "ut_grid_03		OK\n" : "ut_grid_03		ERROR\n");
	ft_putstr(ut_grid_04() ? "ut_grid_04		OK\n" : "ut_grid_04		ERROR\n");
	ft_putstr(ut_grid_05() ? "ut_grid_05		OK\n" : "ut_grid_05		ERROR\n");
	ft_putstr(ut_grid_06() ? "ut_grid_06		OK\n" : "ut_grid_06		ERROR\n");
	ft_putstr(ut_grid_10() ? "ut_grid_10		OK\n" : "ut_grid_10		ERROR\n");
	ft_putstr(ut_grid_11() ? "ut_grid_11		OK\n" : "ut_grid_11		ERROR\n");
	ft_putstr(ut_grid_12() ? "ut_grid_12		OK\n" : "ut_grid_12		ERROR\n");
	ft_putstr(ut_grid_13() ? "ut_grid_13		OK\n" : "ut_grid_13		ERROR\n");
	ft_putstr(ut_grid_14() ? "ut_grid_14		OK\n" : "ut_grid_14		ERROR\n");
	ft_putstr(ut_grid_15() ? "ut_grid_15		OK\n" : "ut_grid_15		ERROR\n");
	ft_putstr(ut_grid_16() ? "ut_grid_16		OK\n" : "ut_grid_16		ERROR\n");
	ft_putstr(ut_grid_17() ? "ut_grid_17		OK\n" : "ut_grid_17		ERROR\n");
	ft_putstr(ut_grid_18() ? "ut_grid_18		OK\n" : "ut_grid_18		ERROR\n");
	return (1);
}

int				ut_storage(void)
{
	ft_putstr(ut_storage_01() ? "ut_storage_01		OK\n" : "ut_storage_01		ERROR\n");
	ft_putstr(ut_storage_02() ? "ut_storage_02		OK\n" : "ut_storage_02		ERROR\n");
	ft_putstr(ut_storage_03() ? "ut_storage_03		OK\n" : "ut_storage_03		ERROR\n");
	ft_putstr(ut_storage_04() ? "ut_storage_04		OK\n" : "ut_storage_04		ERROR\n");
	ft_putstr(ut_storage_05() ? "ut_storage_05		OK\n" : "ut_storage_05		ERROR\n");
	ft_putstr(ut_storage_09() ? "ut_storage_09		OK\n" : "ut_storage_09		ERROR\n");
	ft_putstr(ut_storage_10() ? "ut_storage_10		OK\n" : "ut_storage_10		ERROR\n");
	ft_putstr(ut_storage_11() ? "ut_storage_11		OK\n" : "ut_storage_11		ERROR\n");
	ft_putstr(ut_storage_12() ? "ut_storage_12		OK\n" : "ut_storage_12		ERROR\n");
	ft_putstr(ut_storage_13() ? "ut_storage_13		OK\n" : "ut_storage_13		ERROR\n");
	ft_putstr(ut_storage_14() ? "ut_storage_14		OK\n" : "ut_storage_14		ERROR\n");
	ft_putstr(ut_storage_15() ? "ut_storage_15		OK\n" : "ut_storage_15		ERROR\n");
	ft_putstr(ut_storage_16() ? "ut_storage_16		OK\n" : "ut_storage_16		ERROR\n");
	ft_putstr(ut_storage_17() ? "ut_storage_17		OK\n" : "ut_storage_17		ERROR\n");
	return (1);
}

int				ut_thread(void)
{
	ft_putstr(ut_thread_01() ? "ut_thread_01		OK\n" : "ut_thread_01		ERROR\n");
	ft_putstr(ut_thread_02() ? "ut_thread_02		OK\n" : "ut_thread_02		ERROR\n");
	ft_putstr(ut_thread_03() ? "ut_thread_03		OK\n" : "ut_thread_03		ERROR\n");
	ft_putstr(ut_thread_04() ? "ut_thread_04		OK\n" : "ut_thread_04		ERROR\n");
	ft_putstr(ut_thread_05() ? "ut_thread_05		OK\n" : "ut_thread_05		ERROR\n");
	ft_putstr(ut_thread_06() ? "ut_thread_06		OK\n" : "ut_thread_06		ERROR\n");
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
	ft_putstr(ut_thread_30() ? "ut_thread_30		OK\n" : "ut_thread_30		ERROR\n");
	ft_putstr(ut_thread_31() ? "ut_thread_31		OK\n" : "ut_thread_31		ERROR\n");
	ft_putstr(ut_thread_32() ? "ut_thread_32		OK\n" : "ut_thread_32		ERROR\n");
	ft_putstr(ut_thread_33() ? "ut_thread_33		OK\n" : "ut_thread_33		ERROR\n");
	ft_putstr(ut_thread_34() ? "ut_thread_34		OK\n" : "ut_thread_34		ERROR\n");
	ft_putstr(ut_thread_35() ? "ut_thread_35		OK\n" : "ut_thread_35		ERROR\n");
	ft_putstr(ut_thread_36() ? "ut_thread_36		OK\n" : "ut_thread_36		ERROR\n");
	ft_putstr(ut_thread_37() ? "ut_thread_37		OK\n" : "ut_thread_37		ERROR\n");
	ft_putstr(ut_thread_38() ? "ut_thread_38		OK\n" : "ut_thread_38		ERROR\n");
	ft_putstr(ut_thread_39() ? "ut_thread_39		OK\n" : "ut_thread_39		ERROR\n");
	ft_putstr(ut_thread_40() ? "ut_thread_40		OK\n" : "ut_thread_40		ERROR\n");
	return (1);
}

int				ut_key_functions(void)
{
	ft_putstr(ut_key_functions_01() ? "ut_key_functions_01	OK\n" : "ut_key_functions_01	ERROR\n");
	ft_putstr(ut_key_functions_02() ? "ut_key_functions_02	OK\n" : "ut_key_functions_02	ERROR\n");
	ft_putstr(ut_key_functions_03() ? "ut_key_functions_03	OK\n" : "ut_key_functions_03	ERROR\n");
	ft_putstr(ut_key_functions_04() ? "ut_key_functions_04	OK\n" : "ut_key_functions_04	ERROR\n");
	ft_putstr(ut_key_functions_05() ? "ut_key_functions_05	OK\n" : "ut_key_functions_05	ERROR\n");
	ft_putstr(ut_key_functions_06() ? "ut_key_functions_06	OK\n" : "ut_key_functions_06	ERROR\n");
	ft_putstr(ut_key_functions_07() ? "ut_key_functions_07	OK\n" : "ut_key_functions_07	ERROR\n");
	ft_putstr(ut_key_functions_08() ? "ut_key_functions_08	OK\n" : "ut_key_functions_08	ERROR\n");
	ft_putstr(ut_key_functions_09() ? "ut_key_functions_09	OK\n" : "ut_key_functions_09	ERROR\n");
	ft_putstr(ut_key_functions_10() ? "ut_key_functions_10	OK\n" : "ut_key_functions_10	ERROR\n");
	ft_putstr(ut_key_functions_11() ? "ut_key_functions_11	OK\n" : "ut_key_functions_11	ERROR\n");
	ft_putstr(ut_key_functions_12() ? "ut_key_functions_12	OK\n" : "ut_key_functions_12	ERROR\n");
	ft_putstr(ut_key_functions_13() ? "ut_key_functions_13	OK\n" : "ut_key_functions_13	ERROR\n");
	ft_putstr(ut_key_functions_14() ? "ut_key_functions_14	OK\n" : "ut_key_functions_14	ERROR\n");
	ft_putstr(ut_key_functions_15() ? "ut_key_functions_15	OK\n" : "ut_key_functions_15	ERROR\n");
	return (1);
}

int				ut_utilities(void)
{
	ft_putstr(ut_utilities_01() ? "ut_utilities_01		OK\n" : "ut_utilities_01		ERROR\n");
	return (1);
}

int				ut_bin_extractor(void)
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

int				ut_print_struct(void)
{
	ft_putstr(ut_print_struct_01() ? "ut_print_struct_01	OK\n" : "ut_print_struct_01	ERROR\n");
	ft_putstr(ut_print_struct_02() ? "ut_print_struct_02	OK\n" : "ut_print_struct_02	ERROR\n");
	ft_putstr(ut_print_struct_03() ? "ut_print_struct_03	OK\n" : "ut_print_struct_03	ERROR\n");
	ft_putstr(ut_print_struct_04() ? "ut_print_struct_04	OK\n" : "ut_print_struct_04	ERROR\n");
	ft_putstr(ut_print_struct_05() ? "ut_print_struct_05	OK\n" : "ut_print_struct_05	ERROR\n");
	ft_putstr(ut_print_struct_06() ? "ut_print_struct_06	OK\n" : "ut_print_struct_06	ERROR\n");
	ft_putstr(ut_print_struct_07() ? "ut_print_struct_07	OK\n" : "ut_print_struct_07	ERROR\n");
	ft_putstr(ut_print_struct_08() ? "ut_print_struct_08	OK\n" : "ut_print_struct_08	ERROR\n");
	ft_putstr(ut_print_struct_09() ? "ut_print_struct_09	OK\n" : "ut_print_struct_09	ERROR\n");
	ft_putstr(ut_print_struct_10() ? "ut_print_struct_10	OK\n" : "ut_print_struct_10	ERROR\n");
	ft_putstr(ut_print_struct_11() ? "ut_print_struct_11	OK\n" : "ut_print_struct_11	ERROR\n");
	ft_putstr(ut_print_struct_12() ? "ut_print_struct_12	OK\n" : "ut_print_struct_12	ERROR\n");
	ft_putstr(ut_print_struct_13() ? "ut_print_struct_13	OK\n" : "ut_print_struct_13	ERROR\n");
	ft_putstr(ut_print_struct_14() ? "ut_print_struct_14	OK\n" : "ut_print_struct_14	ERROR\n");
	ft_putstr(ut_print_struct_15() ? "ut_print_struct_15	OK\n" : "ut_print_struct_15	ERROR\n");
	ft_putstr(ut_print_struct_16() ? "ut_print_struct_16	OK\n" : "ut_print_struct_16	ERROR\n");
	ft_putstr(ut_print_struct_17() ? "ut_print_struct_17	OK\n" : "ut_print_struct_17	ERROR\n");
	ft_putstr(ut_print_struct_18() ? "ut_print_struct_18	OK\n" : "ut_print_struct_18	ERROR\n");
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
	if (UT_PRINT >= 2)
		ut_print_struct();
	return (1);
}
