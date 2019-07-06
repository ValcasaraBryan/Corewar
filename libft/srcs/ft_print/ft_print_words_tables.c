/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:55:00 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/21 19:22:38 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_print_words_tables(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_printf("%d = [%d]\n", i, tab[i]);
}
