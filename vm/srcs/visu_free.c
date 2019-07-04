/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:16:29 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/04 12:40:31 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		ft_free_visu(t_storage **st)
{
	if (st == NULL || (*st) == NULL || (*st)->win == NULL)
		return (BAD_PARAM);
	if ((*st)->win->rect != NULL)
		free((*st)->win->rect);
	if ((*st)->win->event != NULL)
		free((*st)->win->event);
	if ((*st)->win->tab_b != NULL)
		free((*st)->win->tab_b);
	if ((*st)->win->tab_g != NULL)
		free((*st)->win->tab_g);
	if ((*st)->win->tab_o != NULL)
		free((*st)->win->tab_o);
	if ((*st)->win->tab_v != NULL)
		free((*st)->win->tab_v);
	if ((*st)->win->tab_w != NULL)
		free((*st)->win->tab_w);
	if ((*st)->win->surface != NULL)
		SDL_FreeSurface((*st)->win->surface);
	if ((*st)->win->renderer != NULL)
		SDL_DestroyRenderer((*st)->win->renderer);
	if ((*st)->win->texture != NULL)
		SDL_DestroyTexture((*st)->win->texture);
	if ((*st)->win->window != NULL)
		SDL_DestroyWindow((*st)->win->window);
	if (TTF_WasInit())
	{
		TTF_CloseFont((*st)->win->ttf_text);
		TTF_Quit();
	}
	SDL_Quit();
	while(1);
	free((*st)->win);
	(*st)->win = NULL;
	return (SUCCESS);
}
