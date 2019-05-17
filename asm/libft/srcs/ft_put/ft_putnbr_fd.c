/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:25:04 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:25:06 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == (-2147483648))
		{
			n = (-n) - 1;
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd('8', fd);
		}
		else if (n < (-9))
		{
			ft_putnbr_fd(-n / 10, fd);
			ft_putchar_fd(-n % 10 + '0', fd);
		}
		else
			ft_putchar_fd(-n + '0', fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
