/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:24:06 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:24:08 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	char			valeur;
	char			*tab;

	i = 0;
	valeur = (char)c;
	tab = (char *)b;
	while (i < len)
		tab[i++] = valeur;
	return (tab);
}
