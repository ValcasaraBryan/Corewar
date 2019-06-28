/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:57:10 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/27 18:39:36 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

char	*desc = "test comm";
char 	*name = "test";
char	*path_all_ok = "../vm_champs/champs/test_1.cor";
char	*path_fake = "lol.cor";
char	*path_folder = "../vm_champs/champs/";
char	*path_no_rights = "../vm_champs/champs/maxidef_bis.cor";
char	*path_dev_zero = "/dev/zero";
char	*path_dev_random = "/dev/random";
char	*path_dev_null = "/dev/null";

static int		ut_bin_extractor_01(void)
{
	/*
	** bin_extractor avec param null
	*/
	int		result;

	result = bin_extractor(NULL, path_all_ok);
	return (result == BAD_PARAM);
}

static int		ut_bin_extractor_02(void)
{
	/*
	** bin_extractor avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = bin_extractor(&ch, path_all_ok);
	return (result == BAD_PARAM);
}

static int		ut_bin_extractor_03(void)
{
	/*
	** bin_extractor avec champion valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_all_ok);
	free_storage(&st);
	return (result == SUCCESS);
}

static int		ut_bin_extractor_04(void)
{
	/*
	** bin_extractor avec chemin invalide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_fake);
	free_storage(&st);
	return (result == BAD_FD);
}

static int		ut_bin_extractor_05(void)
{
	/*
	** bin_extractor verification name
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_all_ok);
	result += ft_strcmp(st->last_champion->name, name) == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1);
}

static int		ut_bin_extractor_06(void)
{
	/*
	** bin_extractor verification commentaire
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_all_ok);
	result += ft_strcmp(st->last_champion->desc, desc) == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1);
}

static int		ut_bin_extractor_07(void)
{
	/*
	** bin_extractor avec chemin dossier
	** A REVOIR
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
	** bin_extractor avec fichier sans droits
	*/
	t_storage	*st;
	int			result;
	
	add_storage(&st);
	add_champion(&st);
	result = bin_extractor(&(st->last_champion), path_no_rights);
	free_storage(&st);
	return (result == BAD_FD);
}

static int		ut_bin_extractor_09(void)
{
	/*
	** bin_extractor avec fichier dev zero
	** A REVOIR
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
	** bin_extractor avec fichier dev random
	** A REVOIR
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
	** bin_extractor avec fichier dev null
	** A REVOIR
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

static int		ut_byte_01(void)
{
	/*
	** add_byte avec param null
	*/
	int			result;

	result = add_byte(NULL);
	return (result == BAD_PARAM);
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
	return (result == BAD_PARAM);
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
	return (result == SUCCESS);
}

static int		ut_byte_04(void)
{
	/*
	** free_byte_list avec param null
	*/
	int			result;

	result = free_byte_list(NULL);
	return (result == BAD_PARAM);
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
	return (result == BAD_PARAM);
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
	return (result == SUCCESS);
}

static int		ut_byte_07(void)
{
	/*
	** byte_change_value valeurs charnieres
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = byte_change_value(&(st->last_champion->last_byte), 255);
	result += st->last_champion->last_byte->value == 255 ? 1 : 0;
	result += byte_change_value(&(st->last_champion->last_byte), 0);
	result += st->last_champion->last_byte->value == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_byte_08(void)
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
	result = byte_change_value(&(st->last_champion->last_byte), -1);
	result += st->last_champion->last_byte->value == 5 ? 1 : 0;
	result += byte_change_value(&(st->last_champion->last_byte), 256);
	result += st->last_champion->last_byte->value == 5 ? 1 : 0;
	free_storage(&st);
	return (result == BAD_PARAM + 1 + BAD_PARAM + 1);
}

static int		ut_champion_01(void)
{
	/*
	** add_champion avec param null
	*/
	int			result;

	result = add_champion(NULL);
	return (result == BAD_PARAM);
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
	return (result == BAD_PARAM);
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
	return (result == SUCCESS);
}

static int		ut_champion_04(void)
{
	/*
	** free_champion_list avec param null
	*/
	int			result;

	result = free_champion_list(NULL);
	return (result == BAD_PARAM);
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
	return (result == BAD_PARAM);
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
	return (result == SUCCESS);
}

static int		ut_champion_07(void)
{
	/*
	** champion_change_desc avec param null
	*/
	int			result;

	result = champion_change_desc(NULL, "test");
	return (result == BAD_PARAM);
}

static int		ut_champion_08(void)
{
	/*
	** champion_change_desc avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = champion_change_desc(&ch, "test");
	return (result == BAD_PARAM);
}

static int		ut_champion_09(void)
{
	/*
	** champion_change_desc avec valeur impossible (NULL)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_desc(&(st->last_champion), "test 2");
	result += ft_strcmp(st->last_champion->desc, "test 2") == 0 ? 1 : 0;
	result += champion_change_desc(&(st->last_champion), NULL);
	result += ft_strcmp(st->last_champion->desc, "test 2") == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + BAD_PARAM + 1);
}

static int		ut_champion_10(void)
{
	/*
	** champion_change_desc avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_desc(&(st->last_champion), "test 2");
	result += ft_strcmp(st->last_champion->desc, "test 2") == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1);
}

static int		ut_champion_11(void)
{
	/*
	** champion_change_name avec param null
	*/
	int			result;

	result = champion_change_name(NULL, "test");
	return (result == BAD_PARAM);
}

static int		ut_champion_12(void)
{
	/*
	** champion_change_name avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = champion_change_name(&ch, "test");
	return (result == BAD_PARAM);
}

static int		ut_champion_13(void)
{
	/*
	** champion_change_name avec valeur impossible (NULL)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_name(&(st->last_champion), "test 1");
	result += ft_strcmp(st->last_champion->name, "test 1") == 0 ? 1 : 0;
	result += champion_change_name(&(st->last_champion), NULL);
	result += ft_strcmp(st->last_champion->name, "test 1") == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + BAD_PARAM + 1);
}

static int		ut_champion_14(void)
{
	/*
	** champion_change_name avec params valides
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_name(&(st->last_champion), "test 1");
	result += ft_strcmp(st->last_champion->name, "test 1") == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1);
}

static int		ut_champion_15(void)
{
	/*
	** champion_change_size avec param null
	*/
	int			result;

	result = champion_change_size(NULL, 1);
	return (result == BAD_PARAM);
}

static int		ut_champion_16(void)
{
	/*
	** champion_change_size avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = champion_change_size(&ch, 1);
	return (result == BAD_PARAM);
}

static int		ut_champion_17(void)
{
	/*
	** champion_change_size avec valeurs charnieres (1 / 2147483647)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_size(&(st->last_champion), 1);
	result += st->last_champion->size == 1 ? 1 : 0;
	result += champion_change_size(&(st->last_champion), 2147483647);
	result += st->last_champion->size == 2147483647 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_champion_18(void)
{
	/*
	** champion_change_size avec valeurs impossibles (0 / -1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	result = champion_change_size(&(st->last_champion), 1);
	result += st->last_champion->size == 1 ? 1 : 0;
	result += champion_change_size(&(st->last_champion), 0);
	result += st->last_champion->size == 1 ? 1 : 0;
	result += champion_change_size(&(st->last_champion), -1);
	result += st->last_champion->size == 1 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + BAD_PARAM + 1 + BAD_PARAM + 1);
}

static int		ut_grid_01(void)
{
	/*
	** add_grid avec param null
	*/
	int			result;

	result = add_grid(NULL, 1);
	return (result == BAD_PARAM);
}

static int		ut_grid_02(void)
{
	/*
	** add_grid avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = add_grid(&st, 1);
	return (result == BAD_PARAM);
}

static int		ut_grid_03(void)
{
	/*
	** add_grid avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = add_grid(&st, 1);
	free_storage(&st);
	return (result == SUCCESS);
}

static int		ut_grid_04(void)
{
	/*
	** free_grid avec param null
	*/
	int			result;

	result = free_grid(NULL, 1);
	return (result == BAD_PARAM);
}

static int		ut_grid_05(void)
{
	/*
	** free_grid avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = free_grid(&st, 1);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_grid_06(void)
{
	/*
	** free_grid avec grid valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = free_grid(&st, 1);
	free_storage(&st);
	return (result == SUCCESS);
}

static int		ut_grid_07(void)
{
	/*
	** grid_fill_with_champ avec grid null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_byte(&(st->last_champion));
	result = grid_fill_with_champ(NULL, &(st->last_champion), 1, 1);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_grid_08(void)
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
	result = grid_fill_with_champ(&gr, &(st->last_champion), 1, 1);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_grid_09(void)
{
	/*
	** grid_fill_with_champ avec champion null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = grid_fill_with_champ(&(st->grid), NULL, 1, 1);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_grid_10(void)
{
	/*
	** grid_fill_with_champ avec champion vide
	*/
	t_champion	*ch;
	t_storage	*st;
	int			result;

	ch = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = grid_fill_with_champ(&(st->grid), &ch, 1, 1);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_grid_11(void)
{
	/*
	** grid_fill_with_champ avec champion sans bytes
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_champion(&st);
	add_grid(&st, 1);
	result = grid_fill_with_champ(&(st->grid), &(st->last_champion), 1, 1);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_grid_12(void)
{
	/*
	** grid_fill_with_champ avec valeurs possibles (1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_champion(&st);
	st->last_champion->number = 1;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 1);
	result = grid_fill_with_champ(&(st->grid), &(st->last_champion), 1, 1);
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 1 * 0, 1) == 1 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1);
}

static int		ut_grid_13(void)
{
	/*
	** grid_fill_with_champ avec valeurs possibles (2)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_champion(&st);
	st->last_champion->number = 1;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 1);
	result = grid_fill_with_champ(&(st->grid), &(st->last_champion), 1, 2);
	add_champion(&st);
	st->last_champion->number = 2;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 2);
	result += grid_fill_with_champ(&(st->grid), &(st->last_champion), 2, 2);
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 2 * 0, 1) == 1 ? 1 : 0;
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 2 * 1, 1) == 2 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + SUCCESS + 1 + 1);
}

static int		ut_grid_14(void)
{
	/*
	** grid_fill_with_champ avec valeurs possibles (3)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_champion(&st);
	st->last_champion->number = 1;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 1);
	result = grid_fill_with_champ(&(st->grid), &(st->last_champion), 1, 3);
	add_champion(&st);
	st->last_champion->number = 2;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 2);
	result += grid_fill_with_champ(&(st->grid), &(st->last_champion), 2, 3);
	add_champion(&st);
	st->last_champion->number = 3;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 3);
	result += grid_fill_with_champ(&(st->grid), &(st->last_champion), 3, 3);
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 3 * 0, 1) == 1 ? 1 : 0;
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 3 * 1, 1) == 2 ? 1 : 0;
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 3 * 2, 1) == 3 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + SUCCESS + SUCCESS + 1 + 1 + 1);
}

static int		ut_grid_15(void)
{
	/*
	** grid_fill_with_champ avec valeurs possibles (4)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_champion(&st);
	st->last_champion->number = 1;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 1);
	result = grid_fill_with_champ(&(st->grid), &(st->last_champion), 1, 4);
	add_champion(&st);
	st->last_champion->number = 2;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 2);
	result += grid_fill_with_champ(&(st->grid), &(st->last_champion), 2, 4);
	add_champion(&st);
	st->last_champion->number = 3;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 3);
	result += grid_fill_with_champ(&(st->grid), &(st->last_champion), 3, 4);
	add_champion(&st);
	st->last_champion->number = 4;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 4);
	result += grid_fill_with_champ(&(st->grid), &(st->last_champion), 4, 4);
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 4 * 0, 1) == 1 ? 1 : 0;
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 4 * 1, 1) == 2 ? 1 : 0;
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 4 * 2, 1) == 3 ? 1 : 0;
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE / 4 * 3, 1) == 4 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + SUCCESS + SUCCESS + SUCCESS + 1 + 1 + 1 + 1);
}

static int		ut_grid_16(void)
{
	/*
	** grid_fill_with_champ avec valeurs impossibles
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_champion(&st);
	st->last_champion->number = 1;
	add_byte(&(st->last_champion));
	byte_change_value(&(st->last_champion->last_byte), 1);
	result = grid_fill_with_champ(&(st->grid), &(st->last_champion), 0, 4);
	result += grid_fill_with_champ(&(st->grid), &(st->last_champion), 5, 4);
	result += grid_fill_with_champ(&(st->grid), &(st->last_champion), 1, 0);
	result += grid_fill_with_champ(&(st->grid), &(st->last_champion), 1, 5);
	result += read_in_grid(&(st->grid), 0, 1) == 0 ? 1 : 0;
	free_storage(&st);
	return (result == BAD_PARAM + BAD_PARAM + BAD_PARAM + BAD_PARAM + 1);
}

static int		ut_key_functions_01(void)
{
	/*
	** read_in_grid avec param null
	*/
	int			result;

	result = read_in_grid(NULL, 0, 1);
	return (result == BAD_PARAM);
}

static int		ut_key_functions_02(void)
{
	/*
	** read_in_grid avec grid vide
	*/
	int			result;
	int			**gr;

	gr = NULL;
	result = read_in_grid(&gr, 0, 1);
	return (result == BAD_PARAM);
}

static int		ut_key_functions_04(void)
{
	/*
	** read_in_grid avec nb invalide (0)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = read_in_grid(&(st->grid), 0, 0);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_key_functions_05(void)
{
	/*
	** read_in_grid avec valeurs charnieres (0 / GRID_SIZE * GRID_SIZE - 1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	write_in_grid(&(st->grid), 3, 0, 1);
	write_in_grid(&(st->grid), 4, GRID_SIZE * GRID_SIZE - 1, 1);
	result = read_in_grid(&(st->grid), 0, 1);
	result += result == 3 ? 1 : 0;
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE - 1, 1);
	result += result == 8 ? 1 : 0;
	free_storage(&st);
	return (result == 3 + 1 + 4 + 1);
}

static int		ut_key_functions_06(void)
{
	/*
	** write_in_grid avec values charnieres (short min / max, long long min / max)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	write_in_grid(&(st->grid), -256, 0, 1);
	write_in_grid(&(st->grid), 255, 1, 1);
	write_in_grid(&(st->grid), -65536, 2, 2);
	write_in_grid(&(st->grid), 65535, 4, 2);
	write_in_grid(&(st->grid), -9223372036854775807, 6, 4);
	write_in_grid(&(st->grid), 9223372036854775807, 10, 4);
	result = read_in_grid(&(st->grid), 0, 1) == 0 ? 1 : 0;
	result += read_in_grid(&(st->grid), 1, 1) == 255 ? 1 : 0;
	result += read_in_grid(&(st->grid), 2, 2) == 0 ? 1 : 0;
	result += read_in_grid(&(st->grid), 4, 2) == 65535 ? 1 : 0;
	result += read_in_grid(&(st->grid), 6, 4) == 1 ? 1 : 0;
	result += read_in_grid(&(st->grid), 10, 4) == -1 ? 1 : 0;
	free_storage(&st);
	return (result == 1 + 1 + 1 + 1 + 1 + 1);
}

static int		ut_key_functions_07(void)
{
	/*
	** write_in_grid avec param null
	*/
	int			result;

	result = write_in_grid(NULL, 0, 0, 1);
	return (result == BAD_PARAM);
}

static int		ut_key_functions_08(void)
{
	/*
	** write_in_grid avec grid vide
	*/
	int			result;
	int			**gr;

	gr = NULL;
	result = write_in_grid(&gr, 0, 0, 1);
	return (result == BAD_PARAM);
}

static int		ut_key_functions_10(void)
{
	/*
	** write_in_grid avec nb invalide (0)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = write_in_grid(&(st->grid), 0, 0, 0);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_key_functions_12(void)
{
	/*
	** write_in_grid avec where charnieres (0 / GRID_SIZE * GRID_SIZE - 1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = write_in_grid(&(st->grid), 5, GRID_SIZE * GRID_SIZE - 1, 1);
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE - 1, 1) == 5 ? 1 : 0;
	result += write_in_grid(&(st->grid), 0, GRID_SIZE * GRID_SIZE - 1, 1);
	result += read_in_grid(&(st->grid), GRID_SIZE * GRID_SIZE - 1, 1) == 0 ? 1 : 0;
	result += write_in_grid(&(st->grid), 5, 0, 1);
	result += read_in_grid(&(st->grid), 0, 1) == 5 ? 1 : 0;
	result += write_in_grid(&(st->grid), 0, 0, 1);
	result += read_in_grid(&(st->grid), 0, 1) == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_key_functions_13(void)
{
	/*
	** write_in_grid avec values charnieres (short min / max, long long min / max)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = write_in_grid(&(st->grid), -256, 0, 1);
	result += read_in_grid(&(st->grid), 0, 1) == 0 ? 1 : 0;
	result += write_in_grid(&(st->grid), 255, 1, 1);
	result += read_in_grid(&(st->grid), 1, 1) == 255 ? 1 : 0;
	result += write_in_grid(&(st->grid), -65536, 2, 2);
	result += read_in_grid(&(st->grid), 2, 2) == 0 ? 1 : 0;
	result += write_in_grid(&(st->grid), 65535, 4, 2);
	result += read_in_grid(&(st->grid), 4, 2) == 65535 ? 1 : 0;
	result += write_in_grid(&(st->grid), -9223372036854775807, 6, 4);
	result += read_in_grid(&(st->grid), 6, 4) == 1 ? 1 : 0;
	result += write_in_grid(&(st->grid), 9223372036854775807, 10, 4);
	result += read_in_grid(&(st->grid), 10, 4) == -1 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_storage_01(void)
{
	/*
	** add_storage avec param null
	*/
	int			result;

	result = add_storage(NULL);
	return (result == BAD_PARAM);
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
	return (result == SUCCESS);
}

static int		ut_storage_03(void)
{
	/*
	** free_storage avec param null
	*/
	int			result;

	result = free_storage(NULL);
	return (result == BAD_PARAM);
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
	return (result == BAD_PARAM);
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
	return (result == SUCCESS);
}

static int		ut_struct_check_01(void)
{
	/*
	** byte_check avec param null
	*/
	int			result;

	result = byte_check(NULL);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_02(void)
{
	/*
	** byte_check avec byte vide
	*/
	t_byte		*bt;
	int			result;

	bt = NULL;
	result = byte_check(&bt);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_03(void)
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
	return (result == VALID_FULL);
}

static int		ut_struct_check_04(void)
{
	/*
	** champion_check avec param null
	*/
	int			result;

	result = champion_check(NULL);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_05(void)
{
	/*
	** champion_check avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = champion_check(&ch);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_06(void)
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
	return (result == VALID_EMPTY);
}

static int		ut_struct_check_07(void)
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
	return (result == VALID_FULL);
}

static int		ut_struct_check_08(void)
{
	/*
	** grid_check avec param null
	*/
	int			result;

	result = grid_check(NULL);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_09(void)
{
	/*
	** grid_check avec grid vide
	*/
	int			**gr;
	int			result;

	gr = NULL;
	result = grid_check(&gr);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_10(void)
{
	/*
	** grid_check avec grid valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = grid_check(&(st->grid));
	free_storage(&st);
	return (result == VALID_FULL);
}

static int		ut_struct_check_11(void)
{
	/*
	** storage_check avec param null
	*/
	int			result;

	result = storage_check(NULL, 0);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_12(void)
{
	/*
	** storage_check avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = storage_check(&st, 0);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_13(void)
{
	/*
	** storage_check sans champion
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = storage_check(&st, 0);
	free_storage(&st);
	return (result == VALID_EMPTY);
}

static int		ut_struct_check_14(void)
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
	return (result == VALID_FULL);
}

static int		ut_struct_check_15(void)
{
	/*
	** storage_check sans grid
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = storage_check(&st, 1);
	free_storage(&st);
	return (result == VALID_EMPTY);
}

static int		ut_struct_check_16(void)
{
	/*
	** storage_check avec grid
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = storage_check(&st, 1);
	free_storage(&st);
	return (result == VALID_FULL);
}

static int		ut_struct_check_17(void)
{
	/*
	** storage_check sans thread
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = storage_check(&st, 2);
	free_storage(&st);
	return (result == VALID_EMPTY);
}

static int		ut_struct_check_18(void)
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
	return (result == VALID_FULL);
}

static int		ut_struct_check_19(void)
{
	/*
	** storage_check mauvais type
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = storage_check(&st, 3);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_20(void)
{
	/*
	** thread_check avec param null
	*/
	int			result;

	result = thread_check(NULL);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_21(void)
{
	/*
	** thread_check avec thread vide
	*/
	t_thread	*th;
	int			result;

	th = NULL;
	result = thread_check(&th);
	return (result == BAD_PARAM);
}

static int		ut_struct_check_22(void)
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
	return (result == VALID_FULL);
}

static int		ut_struct_print_01(void)
{
	/*
	** print_byte_list avec param null
	*/
	int			result;

	result = print_byte_list(NULL);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_02(void)
{
	/*
	** print_byte_list avec champion vide
	*/
	t_champion	*ch;
	int			result;

	ch = NULL;
	result = print_byte_list(&ch);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_03(void)
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
	return (result == SUCCESS);
}

static int		ut_struct_print_04(void)
{
	/*
	** print_champion_list avec param null
	*/
	int			result;

	result = print_champion_list(NULL);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_05(void)
{
	/*
	** print_champion_list avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_champion_list(&st);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_06(void)
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
	return (result == SUCCESS);
}

static int		ut_struct_print_07(void)
{
	/*
	** print_grid avec param null
	*/
	int			result;

	result = print_grid(NULL, 1);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_08(void)
{
	/*
	** print_grid avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = print_grid(&st, 1);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_09(void)
{
	/*
	** print_grid avec grid valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = print_grid(&st, 1);
	free_storage(&st);
	return (result == SUCCESS);
}

static int		ut_struct_print_10(void)
{
	/*
	** print_storage avec param null
	*/
	int			result;

	result = print_storage(NULL);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_11(void)
{
	/*
	** print_storage avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_12(void)
{
	/*
	** print_storage avec storage valide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	result = print_storage(&st);
	free_storage(&st);
	return (result == SUCCESS);
}

static int		ut_struct_print_13(void)
{
	/*
	** print_thread_list avec param null
	*/
	int			result;

	result = print_thread_list(NULL);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_14(void)
{
	/*
	** print_thread_list avec storage vide
	*/
	t_storage	*st;
	int			result;

	st = NULL;
	result = print_thread_list(&st);
	return (result == BAD_PARAM);
}

static int		ut_struct_print_15(void)
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
	return (result == SUCCESS);
}

static int		ut_struct_setup_01(void)
{
	/*
	** setup_champions avec 1er param null
	*/
	char		**array_1;
	char		**tab_argc;
	int			*array_2;
	int			*tab_args;
	int			result;
	int			i;

	i = -1;
	if (!((tab_args) = malloc(sizeof(*tab_args) * 12)))
		return (MALLOC_FAILED);
	while (++i < 12)
		tab_args[i] = -1;
	i = -1;
	if (!((tab_argc) = malloc(sizeof(*tab_argc) * 5)))
		return (MALLOC_FAILED);
	while (++i < 5)
		tab_argc[i] = NULL;
	tab_char_create(&array_1, &tab_argc, &tab_args);
	tab_int_create(&array_2, &tab_args);
	result = setup_champions(NULL, &array_1, &array_2);
	free_tab_char(&array_1);
	free_tab_char(&tab_argc);
	free_tab_int(&array_2);
	free_tab_int(&tab_args);
	return (result == BAD_PARAM);
}

static int		ut_struct_setup_02(void)
{
	/*
	** setup_champions avec 2eme param null
	*/
	t_storage	*st;
	int			*array_2;
	int			*tab_args;
	int			result;
	int			i;

	i = -1;
	if (!((tab_args) = malloc(sizeof(*tab_args) * 12)))
		return (MALLOC_FAILED);
	while (++i < 12)
		tab_args[i] = -1;
	add_storage(&st);
	tab_int_create(&array_2, &tab_args);
	result = setup_champions(&st, NULL, &array_2);
	free_storage(&st);
	free_tab_int(&array_2);
	free_tab_int(&tab_args);
	return (result == BAD_PARAM);
}

static int		ut_struct_setup_03(void)
{
	/*
	** setup_champions avec 3eme param null
	*/
	t_storage	*st;
	char		**array_1;
	char		**tab_argc;
	int			*tab_args;
	int			result;
	int			i;

	i = -1;
	if (!((tab_args) = malloc(sizeof(*tab_args) * 12)))
		return (MALLOC_FAILED);
	while (++i < 12)
		tab_args[i] = -1;
	i = -1;
	if (!((tab_argc) = malloc(sizeof(*tab_argc) * 5)))
		return (MALLOC_FAILED);
	while (++i < 5)
		tab_argc[i] = NULL;
	add_storage(&st);
	tab_char_create(&array_1, &tab_argc, &tab_args);
	result = setup_champions(&st, &array_1, NULL);
	free_storage(&st);
	free_tab_char(&array_1);
	free_tab_char(&tab_argc);
	free_tab_int(&tab_args);
	return (result == BAD_PARAM);
}

static int		ut_struct_setup_04(void)
{
	/*
	** setup_champions avec 1er param vide
	*/
	t_storage	*st;
	char		**array_1;
	char		**tab_argc;
	int			*array_2;
	int			*tab_args;
	int			result;
	int			i;

	i = -1;
	if (!((tab_args) = malloc(sizeof(*tab_args) * 12)))
		return (MALLOC_FAILED);
	while (++i < 12)
		tab_args[i] = -1;
	i = -1;
	if (!((tab_argc) = malloc(sizeof(*tab_argc) * 5)))
		return (MALLOC_FAILED);
	while (++i < 5)
		tab_argc[i] = NULL;
	st = NULL;
	tab_char_create(&array_1, &tab_argc, &tab_args);
	tab_int_create(&array_2, &tab_args);
	result = setup_champions(&st, &array_1, &array_2);
	free_tab_char(&array_1);
	free_tab_char(&tab_argc);
	free_tab_int(&array_2);
	free_tab_int(&tab_args);
	return (result == BAD_PARAM);
}

static int		ut_struct_setup_05(void)
{
	/*
	** setup_champions avec 2eme param vide
	*/
	t_storage	*st;
	char		**array_1;
	char		**tab_argc;
	int			*array_2;
	int			*tab_args;
	int			result;
	int			i;

	i = -1;
	if (!((tab_args) = malloc(sizeof(*tab_args) * 12)))
		return (MALLOC_FAILED);
	while (++i < 12)
		tab_args[i] = -1;
	i = -1;
	if (!((tab_argc) = malloc(sizeof(*tab_argc) * 5)))
		return (MALLOC_FAILED);
	while (++i < 5)
		tab_argc[i] = NULL;
	add_storage(&st);
	array_1 = NULL;
	tab_int_create(&array_2, &tab_args);
	result = setup_champions(&st, &array_1, &array_2);
	free_storage(&st);
	free_tab_char(&tab_argc);
	free_tab_int(&array_2);
	free_tab_int(&tab_args);
	return (result == BAD_PARAM);
}

static int		ut_struct_setup_06(void)
{
	/*
	** setup_champions avec 3eme param vide
	*/
	t_storage	*st;
	char		**array_1;
	char		**tab_argc;
	int			*array_2;
	int			*tab_args;
	int			result;
	int			i;

	i = -1;
	if (!((tab_args) = malloc(sizeof(*tab_args) * 12)))
		return (MALLOC_FAILED);
	while (++i < 12)
		tab_args[i] = -1;
	i = -1;
	if (!((tab_argc) = malloc(sizeof(*tab_argc) * 5)))
		return (MALLOC_FAILED);
	while (++i < 5)
		tab_argc[i] = NULL;
	add_storage(&st);
	tab_char_create(&array_1, &tab_argc, &tab_args);
	array_2 = NULL;
	result = setup_champions(&st, &array_1, &array_2);
	free_storage(&st);
	free_tab_char(&array_1);
	free_tab_char(&tab_argc);
	free_tab_int(&tab_args);
	return (result == BAD_PARAM);
}

static int		ut_struct_setup_07(void)
{
	/*
	** setup_champions avec champion dans storage
	*/
	t_storage	*st;
	char		**array_1;
	char		**tab_argc;
	int			*array_2;
	int			*tab_args;
	int			result;
	int			i;

	i = -1;
	if (!((tab_args) = malloc(sizeof(*tab_args) * 12)))
		return (MALLOC_FAILED);
	while (++i < 12)
		tab_args[i] = -1;
	i = -1;
	if (!((tab_argc) = malloc(sizeof(*tab_argc) * 5)))
		return (MALLOC_FAILED);
	while (++i < 5)
		tab_argc[i] = NULL;
	add_storage(&st);
	add_champion(&st);
	tab_char_create(&array_1, &tab_argc, &tab_args);
	tab_int_create(&array_2, &tab_args);
	result = setup_champions(&st, &array_1, &array_2);
	free_storage(&st);
	free_tab_char(&array_1);
	free_tab_char(&tab_argc);
	free_tab_int(&array_2);
	free_tab_int(&tab_args);
	return (result == BAD_PARAM);
}

static int		ut_struct_setup_08(void)
{
	/*
	** setup_champions avec params valides
	*/
	t_storage	*st;
	char		**array_1;
	char		**tab_argc;
	int			*array_2;
	int			*tab_args;
	int			result;
	int			i;

	i = -1;
	if (!((tab_args) = malloc(sizeof(*tab_args) * 12)))
		return (MALLOC_FAILED);
	while (++i < 12)
		tab_args[i] = -1;
	i = -1;
	if (!((tab_argc) = malloc(sizeof(*tab_argc) * 5)))
		return (MALLOC_FAILED);
	while (++i < 5)
		tab_argc[i] = NULL;
	add_storage(&st);
	tab_char_create(&array_1, &tab_argc, &tab_args);
	tab_int_create(&array_2, &tab_args);
	result = setup_champions(&st, &array_1, &array_2);
	free_storage(&st);
	free_tab_char(&array_1);
	free_tab_int(&array_2);
	return (result == SUCCESS);
}

static int		ut_thread_01(void)
{
	/*
	** add_thread avec param null
	*/
	int			result;

	result = add_thread(NULL);
	return (result == BAD_PARAM);
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
	return (result == BAD_PARAM);
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
	return (result == SUCCESS);
}

static int		ut_thread_04(void)
{
	/*
	** free_thread_list avec param null
	*/
	int			result;

	result = free_thread_list(NULL);
	return (result == BAD_PARAM);
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
	return (result == BAD_PARAM);
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
	return (result == SUCCESS);
}

static int		ut_thread_07(void)
{
	/*
	** thread_change_action avec param null
	*/
	int			result;

	result = thread_change_action(NULL, 0);
	return (result == BAD_PARAM);
}

static int		ut_thread_08(void)
{
	/*
	** thread_change_action avec thread vide
	*/
	t_thread	*th;
	int			result;

	th = NULL;
	result = thread_change_action(&th, 0);
	return (result == BAD_PARAM);
}

static int		ut_thread_09(void)
{
	/*
	** thread_change_action avec valeurs charnieres (0 / 16)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_action(&(st->last_thread), 16);
	result += st->last_thread->action == 16 ? 1 : 0;
	result += thread_change_action(&(st->last_thread), 0);
	result += st->last_thread->action == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_thread_10(void)
{
	/*
	** thread_change_action avec valeurs impossibles (-1 / 17)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_action(&(st->last_thread), 16);
	result += st->last_thread->action == 16 ? 1 : 0;
	result += thread_change_action(&(st->last_thread), -1);
	result += st->last_thread->action == 0 ? 1 : 0;
	result += thread_change_action(&(st->last_thread), 17);
	result += st->last_thread->action == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_thread_11(void)
{
	/*
	** thread_change_cycle avec params null
	*/
	int			result;

	result = thread_change_cycle(NULL, NULL, 0);
	return (result == BAD_PARAM);
}

static int		ut_thread_12(void)
{
	/*
	** thread_change_cycle avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = thread_change_cycle(NULL, &st, 0);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_thread_13(void)
{
	/*
	** thread_change_cycle avec storage null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_cycle(&(st->last_thread), NULL, 0);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_thread_14(void)
{
	/*
	** thread_change_cycle avec params vides
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	st = NULL;
	th = NULL;
	result = thread_change_cycle(&th, &st, 0);
	return (result == BAD_PARAM);
}

static int		ut_thread_15(void)
{
	/*
	** thread_change_cycle avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = thread_change_cycle(&th, &st, 0);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_thread_16(void)
{
	/*
	** thread_change_cycle avec storage vide
	*/
	t_storage	*st;
	t_storage	*st2;
	int			result;

	st2 = NULL;
	add_storage(&st);
	add_thread(&st);
	result = thread_change_cycle(&(st->last_thread), &st2, 0);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_thread_17(void)
{
	/*
	** thread_change_cycle avec grid vide
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_cycle(&(st->last_thread), &st, 0);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_thread_18(void)
{
	/*
	** thread_change_cycle avec valeurs charnieres (0 / 1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	add_grid(&st, 1);
	thread_change_action(&(st->last_thread), 2);
	result = thread_change_cycle(&(st->last_thread), &st, 1);
	result += st->last_thread->cycle == 1 ? 1 : 0;
	result += thread_change_cycle(&(st->last_thread), &st, 0);
	result += st->last_thread->cycle == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_thread_19(void)
{
	/*
	** thread_change_cycle avec valeurs impossibles (-1 / 2)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	add_grid(&st, 1);
	thread_change_action(&(st->last_thread), 2);
	result = thread_change_cycle(&(st->last_thread), &st, 1);
	result += st->last_thread->cycle == 1 ? 1 : 0;
	result += thread_change_cycle(&(st->last_thread), &st, -1);
	result += st->last_thread->cycle == 1 ? 1 : 0;
	result += thread_change_cycle(&(st->last_thread), &st, 2);
	result += st->last_thread->cycle == 1 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + BAD_PARAM + 1 + BAD_PARAM + 1);
}

static int		ut_thread_20(void)
{
	/*
	** thread_change_cycle jusqu'a activation de la fonction
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	add_grid(&st, 1);
	thread_change_action(&(st->last_thread), 2);
	thread_change_cycle(&(st->last_thread), &st, 0);
	thread_change_cycle(&(st->last_thread), &st, 1);
	thread_change_cycle(&(st->last_thread), &st, 1);
	thread_change_cycle(&(st->last_thread), &st, 1);
	thread_change_cycle(&(st->last_thread), &st, 1);
	result = thread_change_cycle(&(st->last_thread), &st, 1);
	result += st->last_thread->cycle == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1);
}

static int		ut_thread_24(void)
{
	/*
	** thread_change_where avec params null
	*/
	int			result;

	result = thread_change_where(NULL, NULL, 0);
	return (result == BAD_PARAM);
}

static int		ut_thread_25(void)
{
	/*
	** thread_change_where avec thread null
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	result = thread_change_where(NULL, &(st->grid), 0);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_thread_26(void)
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
	return (result == BAD_PARAM);
}

static int		ut_thread_27(void)
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
	return (result == BAD_PARAM);
}

static int		ut_thread_28(void)
{
	/*
	** thread_change_where avec thread vide
	*/
	t_storage	*st;
	t_thread	*th;
	int			result;

	th = NULL;
	add_storage(&st);
	add_grid(&st, 1);
	result = thread_change_where(&th, &(st->grid), 0);
	free_storage(&st);
	return (result == BAD_PARAM);
}

static int		ut_thread_29(void)
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
	return (result == BAD_PARAM);
}

static int		ut_thread_30(void)
{
	/*
	** thread_change_where avec valeurs charnieres (0 / GRID_SIZE * GRID_SIZE - 1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	result = thread_change_where(&(st->last_thread), &(st->grid), GRID_SIZE * GRID_SIZE - 1);
	result += st->last_thread->where == GRID_SIZE * GRID_SIZE - 1 ? 1 : 0;
	result += thread_change_where(&(st->last_thread), &(st->grid), 0);
	result += st->last_thread->where == 0 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_thread_31(void)
{
	/*
	** thread_change_where avec valeur impossible (-1)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_grid(&st, 1);
	add_thread(&st);
	result = thread_change_where(&(st->last_thread), &(st->grid), GRID_SIZE * GRID_SIZE - 1);
	result += st->last_thread->where == GRID_SIZE * GRID_SIZE - 1 ? 1 : 0;
	result += thread_change_where(&(st->last_thread), &(st->grid), -1);
	result += st->last_thread->where == GRID_SIZE * GRID_SIZE - 1 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + BAD_PARAM + 1);
}

static int		ut_thread_32(void)
{
	/*
	** thread_change_value_reg avec param null
	*/
	int			result;

	result = thread_change_value_reg(NULL, 1, 1);
	return (result == BAD_PARAM);
}

static int		ut_thread_33(void)
{
	/*
	** thread_change_value_reg avec thread vide
	*/
	t_thread	*th;
	int			result;

	th = NULL;
	result = thread_change_value_reg(&th, 1, 1);
	return (result == BAD_PARAM);
}

static int		ut_thread_34(void)
{
	/*
	** thread_change_value_reg avec valeurs charnieres (0 / 15)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_value_reg(&(st->last_thread), 1, 1);
	result += st->last_thread->reg[0] == 1 ? 1 : 0;
	result += thread_change_value_reg(&(st->last_thread), 16, 1);
	result += st->last_thread->reg[15] == 1 ? 1 : 0;
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_thread_35(void)
{
	/*
	** thread_change_value_reg avec valeurs impossibles (0 / 17)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_value_reg(&(st->last_thread), 0, 1);
	result += thread_change_value_reg(&(st->last_thread), 17, 1);
	free_storage(&st);
	return (result == BAD_PARAM + BAD_PARAM);
}

static int		ut_thread_36(void)
{
	/*
	** thread_get_value_reg avec param null
	*/
	int			result;

	result = thread_get_value_reg(NULL, 0);
	return (result == BAD_PARAM);
}

static int		ut_thread_37(void)
{
	/*
	** thread_get_value_reg avec thread vide
	*/
	t_thread	*th;
	int			result;

	th = NULL;
	result = thread_get_value_reg(&th, 1);
	return (result == BAD_PARAM);
}

static int		ut_thread_38(void)
{
	/*
	** thread_get_value_reg avec valeurs charnieres (0 / 15)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_change_value_reg(&(st->last_thread), 1, 2);
	result += st->last_thread->reg[0] == 2 ? 1 : 0;
	result += thread_change_value_reg(&(st->last_thread), 16, 5);
	result += st->last_thread->reg[15] == 5 ? 1 : 0;
	result += thread_get_value_reg(&(st->last_thread), 1);
	result += thread_get_value_reg(&(st->last_thread), 16);
	free_storage(&st);
	return (result == SUCCESS + 1 + SUCCESS + 1 + 2 + 5);
}

static int		ut_thread_39(void)
{
	/*
	** thread_get_value_reg avec valeurs impossibles (0 / 17)
	*/
	t_storage	*st;
	int			result;

	add_storage(&st);
	add_thread(&st);
	result = thread_get_value_reg(&(st->last_thread), 0);
	result += thread_get_value_reg(&(st->last_thread), 17);
	free_storage(&st);
	return (result == BAD_PARAM + BAD_PARAM);
}

static int		ut_utilities_01(void)
{
	/*
	** convert_to_binary avec param null
	*/
	int		result;

	result = convert_to_binary(NULL, 0);
	return (result == BAD_PARAM);
}

static int		ut_utilities_02(void)
{
	/*
	** convert_to_binary avec valeurs charnieres (0 / 255)
	*/
	char	*tab_res;
	int		result;

	result = convert_to_binary(&tab_res, 0);
	result += ft_strcmp(tab_res, "00000000") == 0 ? 1 : 0;
	free(tab_res);
	result += convert_to_binary(&tab_res, 255);
	result += ft_strcmp(tab_res, "11111111") == 0 ? 1 : 0;
	free(tab_res);
	result += convert_to_binary(&tab_res, 192);
	result += ft_strcmp(tab_res, "11000000") == 0 ? 1 : 0;
	free(tab_res);
	result += convert_to_binary(&tab_res, 240);
	result += ft_strcmp(tab_res, "11110000") == 0 ? 1 : 0;
	free(tab_res);
	result += convert_to_binary(&tab_res, 156);
	result += ft_strcmp(tab_res, "10011100") == 0 ? 1 : 0;
	free(tab_res);
	return (result == SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_utilities_03(void)
{
	/*
	** convert_to_binary avec valeurs impossibles (-1 / 256)
	*/
	char	*res;
	int		result;

	result = convert_to_binary(&res, -1);
	result += convert_to_binary(&res, 256);
	return (result == BAD_PARAM + BAD_PARAM);
}

static int		ut_utilities_04(void)
{
	/*
	** decrypt_op_code avec param null
	*/
	int		result;

	result = decrypt_op_code(NULL, 0);
	return (result == BAD_PARAM);
}

static int		ut_utilities_05(void)
{
	/*
	** decrypt_op_code avec valeurs cle
	*/
	int		*tab;
	int		result;

	result = decrypt_op_code(&tab, 0);
	result += tab[0] == 0 && tab[1] == 0 && tab[2] == 0 ? 1 : 0;
	free(tab);
	result += decrypt_op_code(&tab, 255);
	result += tab[0] == 3 && tab[1] == 3 && tab[2] == 3 ? 1 : 0;
	free(tab);
	result += decrypt_op_code(&tab, 192);
	result += tab[0] == 3 && tab[1] == 0 && tab[2] == 0 ? 1 : 0;
	free(tab);
	result += decrypt_op_code(&tab, 240);
	result += tab[0] == 3 && tab[1] == 3 && tab[2] == 0 ? 1 : 0;
	free(tab);
	result += decrypt_op_code(&tab, 156);
	result += tab[0] == 2 && tab[1] == 1 && tab[2] == 3 ? 1 : 0;
	free(tab);
	return (result == SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1 + SUCCESS + 1);
}

static int		ut_utilities_06(void)
{
	/*
	** decrypt_op_code avec valeurs impossibles (-1 / 256)
	*/
	int		*tab;
	int		result;

	result = decrypt_op_code(&tab, -1);
	result += decrypt_op_code(&tab, 256);
	return (result == BAD_PARAM + BAD_PARAM);
}

void			ut_bin_extractor(void)
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
}

void			ut_byte(void)
{
	ft_putstr(ut_byte_01() ? "ut_byte_01		OK\n" : "ut_byte_01		ERROR\n");
	ft_putstr(ut_byte_02() ? "ut_byte_02		OK\n" : "ut_byte_02		ERROR\n");
	ft_putstr(ut_byte_03() ? "ut_byte_03		OK\n" : "ut_byte_03		ERROR\n");
	ft_putstr(ut_byte_04() ? "ut_byte_04		OK\n" : "ut_byte_04		ERROR\n");
	ft_putstr(ut_byte_05() ? "ut_byte_05		OK\n" : "ut_byte_05		ERROR\n");
	ft_putstr(ut_byte_06() ? "ut_byte_06		OK\n" : "ut_byte_06		ERROR\n");
	ft_putstr(ut_byte_07() ? "ut_byte_07		OK\n" : "ut_byte_07		ERROR\n");
	ft_putstr(ut_byte_08() ? "ut_byte_08		OK\n" : "ut_byte_08		ERROR\n");
}

void			ut_champion(void)
{
	ft_putstr(ut_champion_01() ? "ut_champion_01		OK\n" : "ut_champion_01		ERROR\n");
	ft_putstr(ut_champion_02() ? "ut_champion_02		OK\n" : "ut_champion_02		ERROR\n");
	ft_putstr(ut_champion_03() ? "ut_champion_03		OK\n" : "ut_champion_03		ERROR\n");
	ft_putstr(ut_champion_04() ? "ut_champion_04		OK\n" : "ut_champion_04		ERROR\n");
	ft_putstr(ut_champion_05() ? "ut_champion_05		OK\n" : "ut_champion_05		ERROR\n");
	ft_putstr(ut_champion_06() ? "ut_champion_06		OK\n" : "ut_champion_06		ERROR\n");
	ft_putstr(ut_champion_07() ? "ut_champion_07		OK\n" : "ut_champion_07		ERROR\n");
	ft_putstr(ut_champion_08() ? "ut_champion_08		OK\n" : "ut_champion_08		ERROR\n");
	ft_putstr(ut_champion_09() ? "ut_champion_09		OK\n" : "ut_champion_09		ERROR\n");
	ft_putstr(ut_champion_10() ? "ut_champion_10		OK\n" : "ut_champion_10		ERROR\n");
	ft_putstr(ut_champion_11() ? "ut_champion_11		OK\n" : "ut_champion_11		ERROR\n");
	ft_putstr(ut_champion_12() ? "ut_champion_12		OK\n" : "ut_champion_12		ERROR\n");
	ft_putstr(ut_champion_13() ? "ut_champion_13		OK\n" : "ut_champion_13		ERROR\n");
	ft_putstr(ut_champion_14() ? "ut_champion_14		OK\n" : "ut_champion_14		ERROR\n");
	ft_putstr(ut_champion_15() ? "ut_champion_15		OK\n" : "ut_champion_15		ERROR\n");
	ft_putstr(ut_champion_16() ? "ut_champion_16		OK\n" : "ut_champion_16		ERROR\n");
	ft_putstr(ut_champion_17() ? "ut_champion_17		OK\n" : "ut_champion_17		ERROR\n");
	ft_putstr(ut_champion_18() ? "ut_champion_18		OK\n" : "ut_champion_18		ERROR\n");
	/*
	ft_putstr(ut_champion_19() ? "ut_champion_19		OK\n" : "ut_champion_19		ERROR\n");
	ft_putstr(ut_champion_20() ? "ut_champion_20		OK\n" : "ut_champion_20		ERROR\n");
	ft_putstr(ut_champion_21() ? "ut_champion_21		OK\n" : "ut_champion_21		ERROR\n");
	ft_putstr(ut_champion_22() ? "ut_champion_22		OK\n" : "ut_champion_22		ERROR\n");
	ft_putstr(ut_champion_23() ? "ut_champion_23		OK\n" : "ut_champion_23		ERROR\n");
	*/
}

void			ut_grid(void)
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
	ft_putstr(ut_grid_10() ? "ut_grid_10		OK\n" : "ut_grid_10		ERROR\n");
	ft_putstr(ut_grid_11() ? "ut_grid_11		OK\n" : "ut_grid_11		ERROR\n");
	ft_putstr(ut_grid_12() ? "ut_grid_12		OK\n" : "ut_grid_12		ERROR\n");
	ft_putstr(ut_grid_13() ? "ut_grid_13		OK\n" : "ut_grid_13		ERROR\n");
	ft_putstr(ut_grid_14() ? "ut_grid_14		OK\n" : "ut_grid_14		ERROR\n");
	ft_putstr(ut_grid_15() ? "ut_grid_15		OK\n" : "ut_grid_15		ERROR\n");
	ft_putstr(ut_grid_16() ? "ut_grid_16		OK\n" : "ut_grid_16		ERROR\n");
}

void			ut_key_functions(void)
{
	ft_putstr(ut_key_functions_01() ? "ut_key_functions_01	OK\n" : "ut_key_functions_01	ERROR\n");
	ft_putstr(ut_key_functions_02() ? "ut_key_functions_02	OK\n" : "ut_key_functions_02	ERROR\n");
	//ft_putstr(ut_key_functions_03() ? "ut_key_functions_03	OK\n" : "ut_key_functions_03	ERROR\n");
	ft_putstr(ut_key_functions_04() ? "ut_key_functions_04	OK\n" : "ut_key_functions_04	ERROR\n");
	ft_putstr(ut_key_functions_05() ? "ut_key_functions_05	OK\n" : "ut_key_functions_05	ERROR\n");
	ft_putstr(ut_key_functions_06() ? "ut_key_functions_06	OK\n" : "ut_key_functions_06	ERROR\n");
	ft_putstr(ut_key_functions_07() ? "ut_key_functions_07	OK\n" : "ut_key_functions_07	ERROR\n");
	ft_putstr(ut_key_functions_08() ? "ut_key_functions_08	OK\n" : "ut_key_functions_08	ERROR\n");
	//ft_putstr(ut_key_functions_09() ? "ut_key_functions_09	OK\n" : "ut_key_functions_09	ERROR\n");
	ft_putstr(ut_key_functions_10() ? "ut_key_functions_10	OK\n" : "ut_key_functions_10	ERROR\n");
	//ft_putstr(ut_key_functions_11() ? "ut_key_functions_11	OK\n" : "ut_key_functions_11	ERROR\n");
	ft_putstr(ut_key_functions_12() ? "ut_key_functions_12	OK\n" : "ut_key_functions_12	ERROR\n");
	ft_putstr(ut_key_functions_13() ? "ut_key_functions_13	OK\n" : "ut_key_functions_13	ERROR\n");
	/*
	ft_putstr(ut_key_functions_14() ? "ut_key_functions_14	OK\n" : "ut_key_functions_14	ERROR\n");
	ft_putstr(ut_key_functions_15() ? "ut_key_functions_15	OK\n" : "ut_key_functions_15	ERROR\n");
	ft_putstr(ut_key_functions_16() ? "ut_key_functions_16	OK\n" : "ut_key_functions_16	ERROR\n");
	ft_putstr(ut_key_functions_17() ? "ut_key_functions_17	OK\n" : "ut_key_functions_17	ERROR\n");
	ft_putstr(ut_key_functions_18() ? "ut_key_functions_18	OK\n" : "ut_key_functions_18	ERROR\n");
	ft_putstr(ut_key_functions_19() ? "ut_key_functions_19	OK\n" : "ut_key_functions_19	ERROR\n");
	ft_putstr(ut_key_functions_20() ? "ut_key_functions_20	OK\n" : "ut_key_functions_20	ERROR\n");
	ft_putstr(ut_key_functions_21() ? "ut_key_functions_21	OK\n" : "ut_key_functions_21	ERROR\n");
	ft_putstr(ut_key_functions_22() ? "ut_key_functions_22	OK\n" : "ut_key_functions_22	ERROR\n");
	ft_putstr(ut_key_functions_23() ? "ut_key_functions_23	OK\n" : "ut_key_functions_23	ERROR\n");
	ft_putstr(ut_key_functions_24() ? "ut_key_functions_24	OK\n" : "ut_key_functions_24	ERROR\n");
	ft_putstr(ut_key_functions_25() ? "ut_key_functions_25	OK\n" : "ut_key_functions_25	ERROR\n");
	*/
}

void			ut_storage(void)
{
	ft_putstr(ut_storage_01() ? "ut_storage_01		OK\n" : "ut_storage_01		ERROR\n");
	ft_putstr(ut_storage_02() ? "ut_storage_02		OK\n" : "ut_storage_02		ERROR\n");
	ft_putstr(ut_storage_03() ? "ut_storage_03		OK\n" : "ut_storage_03		ERROR\n");
	ft_putstr(ut_storage_04() ? "ut_storage_04		OK\n" : "ut_storage_04		ERROR\n");
	ft_putstr(ut_storage_05() ? "ut_storage_05		OK\n" : "ut_storage_05		ERROR\n");
}

void			ut_struct_check(void)
{
	ft_putstr(ut_struct_check_01() ? "ut_struct_check_01	OK\n" : "ut_struct_check_01	ERROR\n");
	ft_putstr(ut_struct_check_02() ? "ut_struct_check_02	OK\n" : "ut_struct_check_02	ERROR\n");
	ft_putstr(ut_struct_check_03() ? "ut_struct_check_03	OK\n" : "ut_struct_check_03	ERROR\n");
	ft_putstr(ut_struct_check_04() ? "ut_struct_check_04	OK\n" : "ut_struct_check_04	ERROR\n");
	ft_putstr(ut_struct_check_05() ? "ut_struct_check_05	OK\n" : "ut_struct_check_05	ERROR\n");
	ft_putstr(ut_struct_check_06() ? "ut_struct_check_06	OK\n" : "ut_struct_check_06	ERROR\n");
	ft_putstr(ut_struct_check_07() ? "ut_struct_check_07	OK\n" : "ut_struct_check_07	ERROR\n");
	ft_putstr(ut_struct_check_08() ? "ut_struct_check_08	OK\n" : "ut_struct_check_08	ERROR\n");
	ft_putstr(ut_struct_check_09() ? "ut_struct_check_09	OK\n" : "ut_struct_check_09	ERROR\n");
	ft_putstr(ut_struct_check_10() ? "ut_struct_check_10	OK\n" : "ut_struct_check_10	ERROR\n");
	ft_putstr(ut_struct_check_11() ? "ut_struct_check_11	OK\n" : "ut_struct_check_11	ERROR\n");
	ft_putstr(ut_struct_check_12() ? "ut_struct_check_12	OK\n" : "ut_struct_check_12	ERROR\n");
	ft_putstr(ut_struct_check_13() ? "ut_struct_check_13	OK\n" : "ut_struct_check_13	ERROR\n");
	ft_putstr(ut_struct_check_14() ? "ut_struct_check_14	OK\n" : "ut_struct_check_14	ERROR\n");
	ft_putstr(ut_struct_check_15() ? "ut_struct_check_15	OK\n" : "ut_struct_check_15	ERROR\n");
	ft_putstr(ut_struct_check_16() ? "ut_struct_check_16	OK\n" : "ut_struct_check_16	ERROR\n");
	ft_putstr(ut_struct_check_17() ? "ut_struct_check_17	OK\n" : "ut_struct_check_17	ERROR\n");
	ft_putstr(ut_struct_check_18() ? "ut_struct_check_18	OK\n" : "ut_struct_check_18	ERROR\n");
	ft_putstr(ut_struct_check_19() ? "ut_struct_check_19	OK\n" : "ut_struct_check_19	ERROR\n");
	ft_putstr(ut_struct_check_20() ? "ut_struct_check_20	OK\n" : "ut_struct_check_20	ERROR\n");
	ft_putstr(ut_struct_check_21() ? "ut_struct_check_21	OK\n" : "ut_struct_check_21	ERROR\n");
	ft_putstr(ut_struct_check_22() ? "ut_struct_check_22	OK\n" : "ut_struct_check_22	ERROR\n");
}

void			ut_struct_print(void)
{
	ft_putstr(ut_struct_print_01() ? "ut_struct_print_01	OK\n" : "ut_struct_print_01	ERROR\n");
	ft_putstr(ut_struct_print_02() ? "ut_struct_print_02	OK\n" : "ut_struct_print_02	ERROR\n");
	ft_putstr(ut_struct_print_03() ? "ut_struct_print_03	OK\n" : "ut_struct_print_03	ERROR\n");
	ft_putstr(ut_struct_print_04() ? "ut_struct_print_04	OK\n" : "ut_struct_print_04	ERROR\n");
	ft_putstr(ut_struct_print_05() ? "ut_struct_print_05	OK\n" : "ut_struct_print_05	ERROR\n");
	ft_putstr(ut_struct_print_06() ? "ut_struct_print_06	OK\n" : "ut_struct_print_06	ERROR\n");
	ft_putstr(ut_struct_print_07() ? "ut_struct_print_07	OK\n" : "ut_struct_print_07	ERROR\n");
	ft_putstr(ut_struct_print_08() ? "ut_struct_print_08	OK\n" : "ut_struct_print_08	ERROR\n");
	ft_putstr(ut_struct_print_09() ? "ut_struct_print_09	OK\n" : "ut_struct_print_09	ERROR\n");
	ft_putstr(ut_struct_print_10() ? "ut_struct_print_10	OK\n" : "ut_struct_print_10	ERROR\n");
	ft_putstr(ut_struct_print_11() ? "ut_struct_print_11	OK\n" : "ut_struct_print_11	ERROR\n");
	ft_putstr(ut_struct_print_12() ? "ut_struct_print_12	OK\n" : "ut_struct_print_12	ERROR\n");
	ft_putstr(ut_struct_print_13() ? "ut_struct_print_13	OK\n" : "ut_struct_print_13	ERROR\n");
	ft_putstr(ut_struct_print_14() ? "ut_struct_print_14	OK\n" : "ut_struct_print_14	ERROR\n");
	ft_putstr(ut_struct_print_15() ? "ut_struct_print_15	OK\n" : "ut_struct_print_15	ERROR\n");
}

void			ut_struct_setup(void)
{
	ft_putstr(ut_struct_setup_01() ? "ut_struct_setup_01	OK\n" : "ut_struct_setup_01	ERROR\n");
	ft_putstr(ut_struct_setup_02() ? "ut_struct_setup_02	OK\n" : "ut_struct_setup_02	ERROR\n");
	ft_putstr(ut_struct_setup_03() ? "ut_struct_setup_03	OK\n" : "ut_struct_setup_03	ERROR\n");
	ft_putstr(ut_struct_setup_04() ? "ut_struct_setup_04	OK\n" : "ut_struct_setup_04	ERROR\n");
	ft_putstr(ut_struct_setup_05() ? "ut_struct_setup_05	OK\n" : "ut_struct_setup_05	ERROR\n");
	ft_putstr(ut_struct_setup_06() ? "ut_struct_setup_06	OK\n" : "ut_struct_setup_06	ERROR\n");
	ft_putstr(ut_struct_setup_07() ? "ut_struct_setup_07	OK\n" : "ut_struct_setup_07	ERROR\n");
	ft_putstr(ut_struct_setup_08() ? "ut_struct_setup_08	OK\n" : "ut_struct_setup_08	ERROR\n");
	/*ft_putstr(ut_struct_setup_09() ? "ut_struct_setup_09	OK\n" : "ut_struct_setup_09	ERROR\n");
	ft_putstr(ut_struct_setup_10() ? "ut_struct_setup_10	OK\n" : "ut_struct_setup_10	ERROR\n");
	ft_putstr(ut_struct_setup_11() ? "ut_struct_setup_11	OK\n" : "ut_struct_setup_11	ERROR\n");*/
}

void			ut_thread(void)
{
	ft_putstr(ut_thread_01() ? "ut_thread_01		OK\n" : "ut_thread_01		ERROR\n");
	ft_putstr(ut_thread_02() ? "ut_thread_02		OK\n" : "ut_thread_02		ERROR\n");
	ft_putstr(ut_thread_03() ? "ut_thread_03		OK\n" : "ut_thread_03		ERROR\n");
	ft_putstr(ut_thread_04() ? "ut_thread_04		OK\n" : "ut_thread_04		ERROR\n");
	ft_putstr(ut_thread_05() ? "ut_thread_05		OK\n" : "ut_thread_05		ERROR\n");
	ft_putstr(ut_thread_06() ? "ut_thread_06		OK\n" : "ut_thread_06		ERROR\n");
	ft_putstr(ut_thread_07() ? "ut_thread_07		OK\n" : "ut_thread_07		ERROR\n");
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
	/*
	ft_putstr(ut_thread_21() ? "ut_thread_21		OK\n" : "ut_thread_21		ERROR\n");
	ft_putstr(ut_thread_22() ? "ut_thread_22		OK\n" : "ut_thread_22		ERROR\n");
	ft_putstr(ut_thread_23() ? "ut_thread_23		OK\n" : "ut_thread_23		ERROR\n");
	*/
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
}

void			ut_utilities(void)
{
	ft_putstr(ut_utilities_01() ? "ut_utilities_01		OK\n" : "ut_utilities_01		ERROR\n");
	ft_putstr(ut_utilities_02() ? "ut_utilities_02		OK\n" : "ut_utilities_02		ERROR\n");
	ft_putstr(ut_utilities_03() ? "ut_utilities_03		OK\n" : "ut_utilities_03		ERROR\n");
	ft_putstr(ut_utilities_04() ? "ut_utilities_04		OK\n" : "ut_utilities_04		ERROR\n");
	ft_putstr(ut_utilities_05() ? "ut_utilities_05		OK\n" : "ut_utilities_05		ERROR\n");
	ft_putstr(ut_utilities_06() ? "ut_utilities_06		OK\n" : "ut_utilities_06		ERROR\n");
}

void			all_ut(void)
{
	/*
	*/
	ut_bin_extractor();
	ut_byte();
	ut_champion();
	ut_grid();
	ut_key_functions();
	ut_storage();
	ut_struct_check();
		ut_struct_print();
	ut_struct_setup();
	ut_thread();
	ut_utilities();
	/*
	*/
}




/*
print_dump
get_size_int
setup_all
setup_champions
setup_grid
*/


/*
tests get_args

ok
./corewar 1.cor
./corewar 1.cor 2.cor
./corewar 1.cor 2.cor 3.cor
./corewar 1.cor 2.cor 3.cor 4.cor
./corewar -n 1.cor 2.cor 3.cor 4.cor
./corewar -n 56 1.cor -n 69 2.cor 3.cor 4.cor
./corewar -n 56 1.cor -n 69 2.cor -n 95 3.cor -n 48 4.cor
./corewar -dump 5699 -n 56 1.cor -n 69 2.cor -n 95 3.cor -n 48 4.cor
./corewar -v -n 56 1.cor -n 69 2.cor -n 95 3.cor -n 48 4.cor
./corewar -v -n 56 1.cor          2.cor -n 95 3.cor 4.cor
./corewar 1.cor 2.cor -n 95 3.cor -n 17 4.cor 
./corewar -v fr.cor 

ko
./corewar 1.cor 2.cor 3.cor 4.cor 5.cor
./corewar -n 56 1.cor -n 69 2.cor -n 95 3.cor -n 4.cor
./corewar -n 56 1.cor -n 69 2.cor -n 95 3.cor -n 48 4.cor 5.cor
./corewar -n 56 1.cor -n 69 2.cor -n 95 3.cor -n 48 4.cor -n
./corewar -dump -n 56 1.cor -n 69 2.cor -n 95 3.cor -n 48 4.cor
./corewar -v -dump 5699 -n 56 1.cor -n 69 2.cor -n 95 3.cor -n 48 4.cor
./corewar -v -dump -n 56 1.cor -n 69 2.cor -n 95 3.cor -n 48 4.cor
./corewar -v -n 56 1.cor 69 2.cor -n 95 3.cor 4.cor
./corewar 1.cor 2.cor -n 95 3.cor 4.cor -dump 6555
./corewar 1.cor  2.cor 3.cor 4.cor -dump 6555
./corewar 1.cor 2.cor -n 95 3.cor -n 17 4.cor -n 26
./corewar 1.cor 2.cor -n 95 3.cor -n 17 4.cor -n 26 -dump 65
./corewar 1.cor 2.cor -n 26
./corewar -v
*/