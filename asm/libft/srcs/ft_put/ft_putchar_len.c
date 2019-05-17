/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:35:51 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/16 12:35:53 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putchar_len(char c, int len, int fd)
{
	int		ret;
	char	*str;

	str = NULL;
	if (len == 1)
		return (ft_putchar_fd(c, fd));
	if (len == 0)
		return (0);
	if (len < 0)
		return (-1);
	str = ft_strnew(len);
	str = ft_memset(str, c, len);
	ret = write(fd, str, len);
	free(str);
	return (ret);
}
