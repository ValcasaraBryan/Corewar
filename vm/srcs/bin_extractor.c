/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:56:52 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 08:54:20 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int			create_tempo_str(char **res, int fd, int type)
{
	int				i;
	unsigned char	buf[1];

	if (res == NULL || type < 1 || type > 2)
		return (BAD_PARAM);
	*res = NULL;
	lseek(fd, type == 1
		? M_NB_LENGTH : M_NB_LENGTH + NAME_LENGTH + 8, SEEK_SET);
	i = 0;
	buf[0] = 1;
	while (buf[0] != '\0')
	{
		read(fd, buf, 1);
		i++;
	}
	if (!((*res) = malloc(sizeof(**res) * (i + 1))))
		return (MALLOC_FAILED);
	ft_bzero((*res), sizeof(**res) * (i + 1));
	(*res)[i] = '\0';
	while (--i >= 0)
		(*res)[i] = '0';
	return (SUCCESS);
}

static int			extract_bytes(int fd, t_champion **ch)
{
	int				i;
	unsigned char	buf[1];

	if (champion_check(ch) < VALID_EMPTY)
		return (BAD_PARAM);
	lseek(fd, M_NB_LENGTH + NAME_LENGTH + 8 + DESC_LENGTH + 4, SEEK_SET);
	buf[0] = 1;
	i = -1;
	while ((i = (int)read(fd, buf, 1)) > 0)
	{
		if (add_byte(ch) != SUCCESS
			|| byte_change_value(&((*ch)->last_byte), buf[0]) != SUCCESS)
			return (CALL_FAILED);
	}
	return (SUCCESS);
}

static int			extract_magic_numbers(int fd, t_champion **ch)
{
	int				i;
	int				res;
	unsigned char	buf[1];

	if (champion_check(ch) < VALID_EMPTY)
		return (BAD_PARAM);
	lseek(fd, 0, SEEK_SET);
	i = -1;
	res = 0;
	buf[0] = 1;
	while (++i < 4)
	{
		read(fd, buf, 1);
		res += buf[0];
		res = i != 3 ? res << 8 : res;
	}
	if (res != MAGIC_NB)
		return (FAILURE);
	return (SUCCESS);
}

static int			extract_str(int fd, t_champion **ch, int type)
{
	int				i;
	char			*res;
	unsigned char	buf[1];

	if (champion_check(ch) < VALID_EMPTY || type < 1 || type > 2)
		return (BAD_PARAM);
	if (create_tempo_str(&res, fd, type) != SUCCESS)
		return (CALL_FAILED);
	lseek(fd, type == 1
		? M_NB_LENGTH : M_NB_LENGTH + NAME_LENGTH + 8, SEEK_SET);
	i = 0;
	buf[0] = 1;
	while (buf[0] != '\0')
	{
		read(fd, buf, 1);
		res[i] = buf[0];
		i++;
	}
	i = type == 1 ? champion_change_name(ch, res)
		: champion_change_desc(ch, res);
	if (i != SUCCESS)
		return (CALL_FAILED);
	free(res);
	return (SUCCESS);
}

int					bin_extractor(t_champion **ch, char *path)
{
	int				fd;

	if (champion_check(ch) < VALID_EMPTY)
		return (BAD_PARAM);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (BAD_FD);
	if (extract_magic_numbers(fd, ch) != SUCCESS
		|| extract_str(fd, ch, 1) != SUCCESS
		|| extract_str(fd, ch, 2) != SUCCESS
		|| extract_bytes(fd, ch) != SUCCESS)
		return (CALL_FAILED);
	return (SUCCESS);
}
