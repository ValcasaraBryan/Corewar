/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:56:30 by glebouch          #+#    #+#             */
/*   Updated: 2019/07/04 12:27:01 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int	ft_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

SDL_Color	argb_to_sdl(Uint32 color)
{
	t_color	c;

	c = (t_color)((int)color);
	return ((SDL_Color){c.rgb[2], c.rgb[1], c.rgb[0], c.rgb[3]});
}

int ft_color_octet(int player)
{
	if (player == 0)
		return (WHITE);
	else if (player == 1)
		return (P1);
	else if (player == 2)
		return (P2);
	else if (player == 3)
		return (P3);
	else if (player == 4)
		return (P4);
	return (-1);
}

char	*ft_ctoa(char c)
{
	char *str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (NULL);
	ft_bzero(str, sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char *ft_itoa_hexa(int a)
{
	char *str;
	char *tab;

	tab = "0123456789abcdef";
	if (!(str = malloc(sizeof(char) * 3)))
		return (NULL);
	ft_bzero(str, sizeof(char) * 3);
	str[0] = tab[a / 16];
	str[1] = tab[a % 16];
	str[2] = '\0';
	return (str);
}
