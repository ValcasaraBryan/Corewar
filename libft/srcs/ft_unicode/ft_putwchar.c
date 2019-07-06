/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:50:24 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/15 17:50:25 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_putwchar(int *tab, unsigned int octet, int fd)
{
	int				i;
	int				ret;

	i = -1;
	ret = 0;
	while (++i < (int)octet)
	{
		if (ft_putchar_fd((char)tab[i], fd) == -1)
		{
			free(tab);
			return (-1);
		}
		ret++;
	}
	free(tab);
	return (ret);
}
