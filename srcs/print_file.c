/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:57:30 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/07/06 13:18:10 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		print_octet(int fd, unsigned int val, size_t nb)
{
	unsigned int	tmp;
	unsigned int	index;

	if (nb > 4)
		return ;
	while (nb--)
	{
		index = (unsigned int)255 << 8 * nb;
		tmp = index & val;
		while (tmp > 255)
			tmp = tmp >> 8;
		write(fd, &tmp, 1);
	}
}

static void		print_tab(int fd, t_ins *ins)
{
	int	i;

	i = -1;
	while (++i < ins->ins.len_params)
	{
		if ((ins->ins.indirect == 0 && ins->codage[i] == IND_CODE)
			|| (ins->ins.direct == 0 && ins->codage[i] == DIR_CODE))
			print_octet(fd, (unsigned int)ins->params[i], 4);
		else if (ins->codage[i] == REG_CODE)
			print_octet(fd, (unsigned int)ins->params[i], 1);
		else
			print_octet(fd, (unsigned short)ins->params[i], 2);
	}
}

static void		write_header(t_data *data)
{
	print_octet(data->fd_file, data->header.magic, 4);
	write(data->fd_file, data->header.prog_name, PROG_NAME_LENGTH);
	print_octet(data->fd_file, 0, 4);
	print_octet(data->fd_file, data->header.prog_size, 4);
	write(data->fd_file, data->header.comment, COMMENT_LENGTH);
	print_octet(data->fd_file, 0, 4);
}

void			write_file(t_data *data, int i)
{
	t_ins	*tmp;

	if ((data->fd_file = open(data->name_cor, O_CREAT | O_RDWR | O_TRUNC,
		S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH)) == -1)
	{
		ft_fprintf(NO_FILE, S_ERR, CREAT, data->name_cor);
		return ;
	}
	write_header(data);
	tmp = data->ins;
	while (tmp)
	{
		i = -1;
		print_octet(data->fd_file, tmp->ins.opcode, 1);
		if (tmp->ins.opcode != LIVE && tmp->ins.opcode != FORK
			&& tmp->ins.opcode != ZJMP && tmp->ins.opcode != LFORK)
			print_octet(data->fd_file, tmp->octet, 1);
		print_tab(data->fd_file, tmp);
		tmp = tmp->next;
	}
	close(data->fd_file);
	ft_printf(SUCCESS, data->name_cor);
	free_line(&data->name_cor);
}
