/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:56:01 by glebouch          #+#    #+#             */
/*   Updated: 2019/07/04 10:17:23 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static SDL_Texture	*ft_grep_caract(SDL_Texture **tab, char c)
{
	if (c >= '0' && c <= '9')
		return (tab[c - 48]);
	else if (c >= 'a' && c <= 'z')
		return (tab[c - 97 + 10]);
	return (NULL);
}

static SDL_Texture	*ft_grep_texture(t_storage **st, char c, int color)
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

static int			ft_write_caract_in_renderer(t_storage **st, int i,
	int j, char *str)
{
	int		k;

	k = -1;
	(*st)->win->rect->y = i * OCT_H;
	(*st)->win->rect->x = j * OCT_W + 4;
	(*st)->win->rect->h = OCT_H;
	(*st)->win->rect->w = LETTER_W;
	if (SDL_RenderCopy((*st)->win->renderer,
			ft_grep_texture(st, str[0],
			(*st)->color_grid[i][j]), NULL, (*st)->win->rect) < 0)
	{
		free(str);
		return (FAILURE);
	}
	(*st)->win->rect->x = j * OCT_W + 4 + LETTER_W;
	if (SDL_RenderCopy((*st)->win->renderer,
			ft_grep_texture(st, str[1],
			(*st)->color_grid[i][j]), NULL, (*st)->win->rect) < 0)
	{
		free(str);
		return (FAILURE);
	}
	free(str);
	return (SUCCESS);
}

int					ft_print_grid(t_storage **st)
{
	int				i;
	int				j;

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
