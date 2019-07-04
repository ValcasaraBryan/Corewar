/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:28:55 by jdurand-          #+#    #+#             */
/*   Updated: 2018/04/05 16:02:50 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		((char*)s)[i] = '\0';
		i++;
		n--;
	}
}
