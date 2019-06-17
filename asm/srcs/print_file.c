/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryanvalcasara <bryanvalcasara@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 22:57:30 by bryanvalcas       #+#    #+#             */
/*   Updated: 2019/06/16 22:57:54 by bryanvalcas      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_octet(int fd, unsigned int val, size_t nb)
{
	unsigned int	tmp;
	unsigned int	index;

	if (nb > 4)
		return ;
	while (nb--)
	{
		index = 255 << 8 * nb;
		tmp = index & val;
		while (tmp > 255)
			tmp = tmp >> 8;
		write(fd, &tmp, 1);
	}
}

void	print_tab(int fd, t_ins *ins)
{
	int	i;

	i = -1;
	while (++i < ins->ins.len_params)
	{
		if ((ins->ins.indirect == 0 && ins->codage[i] == IND_CODE)
			|| (ins->ins.direct == 0 && ins->codage[i] == DIR_CODE))
			print_octet(fd, ins->params[i], 4);
		else if (ins->codage[i] == REG_CODE)
			print_octet(fd, ins->params[i], 1);
		else
			print_octet(fd, (unsigned short)ins->params[i], 2);
	}
}

int		write_file(t_data *data, int i)
{
	if ((data->fd_file = open(data->name_cor, O_CREAT | O_RDWR | O_TRUNC,
		S_IRUSR + S_IWUSR + S_IRGRP + S_IROTH)) == -1)
	{
		ft_printf("error name file\n");
		return (0);
	}
	print_octet(data->fd_file, data->header.magic, 4);
	write(data->fd_file, data->header.prog_name, PROG_NAME_LENGTH);
	print_octet(data->fd_file, 0, 4);
	print_octet(data->fd_file, data->header.prog_size, 4);
	write(data->fd_file, data->header.comment, COMMENT_LENGTH);
	print_octet(data->fd_file, 0, 4);
	while (data->ins)
	{
		i = -1;
		print_octet(data->fd_file, data->ins->ins.opcode, 1);
		if (data->ins->ins.opcode != LIVE && data->ins->ins.opcode != FORK
			&& data->ins->ins.opcode != ZJMP && data->ins->ins.opcode != LFORK)
			print_octet(data->fd_file, data->ins->octet, 1);
		print_tab(data->fd_file, data->ins);
		data->ins = data->ins->next;
	}
	close(data->fd_file);
	return (1);
}
