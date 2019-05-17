/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:55:53 by brvalcas          #+#    #+#             */
/*   Updated: 2019/05/17 17:35:05 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		parsing_asm(int ac, char **av)
{
	(void)ac;
	(void)av;
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	else
		if (!(parsing_asm(argc, argv)))
			return (0);
	return (0);
}