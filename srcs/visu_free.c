/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:16:29 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 10:40:08 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

static void		ft_free_tab(SDL_Texture ***tab)
{
	int			i;

	if (tab == NULL || *tab == NULL)
		return ;
	i = -1;
	while (++i < 36)
		SDL_DestroyTexture((*tab)[i]);
	free(*tab);
	*tab = NULL;
}

static void		ft_free_visu_inner(t_storage **st)
{
	if ((*st)->win->rect != NULL)
		free((*st)->win->rect);
	ft_free_tab(&(*st)->win->tab_b);
	ft_free_tab(&(*st)->win->tab_g);
	ft_free_tab(&(*st)->win->tab_o);
	ft_free_tab(&(*st)->win->tab_v);
	ft_free_tab(&(*st)->win->tab_w);
	if ((*st)->win->surface != NULL)
		SDL_FreeSurface((*st)->win->surface);
	if ((*st)->win->renderer != NULL)
		SDL_DestroyRenderer((*st)->win->renderer);
	if ((*st)->win->texture != NULL)
		SDL_DestroyTexture((*st)->win->texture);
	if ((*st)->win->window != NULL)
		SDL_DestroyWindow((*st)->win->window);
}

int				ft_free_visu(t_storage **st)
{
	if (st == NULL || (*st) == NULL || (*st)->win == NULL)
		return (BAD_PARAM);
	ft_free_visu_inner(st);
	(*st)->win->surface = NULL;
	(*st)->win->renderer = NULL;
	(*st)->win->texture = NULL;
	(*st)->win->window = NULL;
	if (TTF_WasInit())
	{
		TTF_CloseFont((*st)->win->ttf_text);
		(*st)->win->ttf_text = NULL;
		TTF_Quit();
	}
	free((*st)->win);
	(*st)->win = NULL;
	SDL_Quit();
	return (SUCCESS);
}
