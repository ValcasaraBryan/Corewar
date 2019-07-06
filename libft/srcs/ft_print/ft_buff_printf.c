/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:27:46 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/09 19:27:50 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_buff_printf(int fd, int fd_sortie)
{
	char	buf[2];
	char	*str;
	int		ret;
	int		err;

	ret = 0;
	err = 0;
	str = NULL;
	buf[1] = '\0';
	while ((err = read(fd, buf, 1)))
	{
		if (err == -1)
			return (-2);
		if (str == NULL)
			str = ft_strdup(buf);
		else
			ft_strcat(str, buf);
		ret += err;
	}
	if (ret)
		return (ft_putstr_len(str, ret, fd_sortie));
	return (-3);
}
