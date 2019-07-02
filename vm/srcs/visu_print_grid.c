/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:56:01 by glebouch          #+#    #+#             */
/*   Updated: 2019/07/02 15:56:04 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static SDL_Texture		*ft_grep_caract(SDL_Texture **tab, char c)
{
	if (c >= '0' && c <= '9')
		return (tab[c - 48]);
	else if (c >= 'a' && c <= 'z')
		return (tab[c - 97 + 10]);
	return (NULL);
}

static SDL_Texture		*ft_grep_texture(t_storage **st, char c, int color)
{
	if (color == 0)
		return (ft_grep_caract((*st)->win->tab_w, c));
	else if (color == 1)
		return (ft_grep_caract((*st)->win->tab_b, c));
	else if (color == 2)
		return (ft_grep_caract((*st)->win->tab_o, c));
	else if (color == 3)
		return (ft_grep_caract((*st)->win->tab_v, c));
	else if (color == 4)
		return (ft_grep_caract((*st)->win->tab_g, c));
	return (NULL);
}

static int				ft_write_caract_in_renderer(t_storage **st, int i,
	int j, char *str)
{
	int		k;

	k = -1;
	while (++k < 4)
	{
		(*st)->win->rect->y = i * OCT_H;
		(*st)->win->rect->x = j * OCT_W + k * LETTER_W;
		(*st)->win->rect->h = OCT_H;
		(*st)->win->rect->w = LETTER_W;
		if (k == 0 || k == 3)
		{
			if (SDL_RenderCopy((*st)->win->renderer, (*st)->win->tab_w[36],
				NULL, (*st)->win->rect) < 0)
				return (FAILURE);
		}
		else
		{
			if (SDL_RenderCopy((*st)->win->renderer,
				ft_grep_texture(st, str[k - 1],
				(*st)->color_grid[i][j]), NULL, (*st)->win->rect) < 0)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}

int						ft_print_grid(t_storage **st)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
			ft_write_caract_in_renderer(st, i, j,
				ft_itoa_hexa((*st)->grid[i][j]));
	}
	return (SUCCESS);
}
