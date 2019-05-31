/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:56:52 by jdurand-          #+#    #+#             */
/*   Updated: 2019/05/31 16:02:29 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static int		create_tempo_str(char **res, int fd, int type)
{
	int				i;
	unsigned char	buf[1];

	if (res != NULL)
	{
		*res = NULL;
		if (type < 1 || type > 2)
			return (-1);
		lseek(fd, type == 1 ? 4 : 140, SEEK_SET);
		i = 0;
		buf[0] = 1;
		while (buf[0] != '\0')
		{
			read(fd, buf, 1);
			i++;
		}
		if (!((*res) = malloc(sizeof(**res) * (i + 1))))
			return (-2);
		(*res)[i] = '\0';
		while (--i >= 0)
			(*res)[i] = '0';
		return (1);
	}
	return (0);
}

static int		extract_bytes(int fd, t_champion **ch)
{
	int				i;
	unsigned char	buf[1];

	if (champion_check(ch) >= 0)
	{
		lseek(fd, 2192, SEEK_SET);
		buf[0] = 1;
		i = -1;
		while ((i = read(fd, buf, 1)) > 0)
		{
			if (add_byte(ch) != 1)
				return (-1);
			if (byte_change_value(&((*ch)->last_byte), buf[0]) != 1)
				return (-2);
		}
		return (1);
	}
	return (0);
}

static int		extract_magic_numbers(int fd, t_champion **ch)
{
	int				i;
	unsigned char	buf[1];

	if (champion_check(ch) >= 0)
	{
		lseek(fd, 0, SEEK_SET);
		i = -1;
		buf[0] = 1;
		while (++i < 4)
		{
			read(fd, buf, 1);
			if (add_byte(ch) != 1)
				return (-1);
			if (byte_change_value(&((*ch)->last_byte), buf[0]) != 1)
				return (-2);
		}
		return (1);
	}
	return (0);
}

static int		extract_str(int fd, t_champion **ch, int type)
{
	int				i;
	char			*res;
	unsigned char	buf[1];

	if (champion_check(ch) >= 0)
	{
		if (create_tempo_str(&res, fd, type) < 1)
			return (-1);
		if (type < 1 || type > 2)
			return (-2);
		lseek(fd, type == 1 ? 4 : 140, SEEK_SET);
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
		free(res);
		return (i);
	}
	return (0);
}

int				bin_extractor(t_champion **ch, char *path)
{
	int				fd;
	int				i;

	if (champion_check(ch) >= 0)
	{
		if ((fd = open(path, O_RDONLY)) < 0)
			return (-1);
		i = extract_magic_numbers(fd, ch);
		i = i == 1 ? extract_str(fd, ch, 1) : i;
		i = i == 1 ? extract_str(fd, ch, 2) : i;
		i = i == 1 ? extract_bytes(fd, ch) : i;
		return (1);
	}
	return (0);
}
