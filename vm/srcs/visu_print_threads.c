/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_threads.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glebouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:56:22 by glebouch          #+#    #+#             */
/*   Updated: 2019/07/02 15:56:24 by glebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int		ft_print_threads(t_storage **st)
{
	t_thread	*tmp;

	tmp = (*st)->first_thread;
	(*st)->win->nb_threads = 0;
	if (((*st)->win->texture = SDL_CreateTexture((*st)->win->renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT)) == NULL
		|| SDL_SetRenderTarget((*st)->win->renderer, (*st)->win->texture) < 0
		|| SDL_SetRenderDrawColor((*st)->win->renderer, 0, 0, 0, 255) < 0
		|| SDL_RenderFillRect((*st)->win->renderer, &(SDL_Rect){0, 0, WIDTH, HEIGHT}) < 0
		|| SDL_SetRenderDrawColor((*st)->win->renderer, 100, 100, 100, 255) < 0)
		return (FAILURE);
	(*st)->win->rect->w = OCT_W;
	(*st)->win->rect->h = OCT_H;
	while (tmp != NULL)
	{
		(*st)->win->rect->x = tmp->where % 64 * OCT_W;
		(*st)->win->rect->y = tmp->where / 64 * OCT_H;
		if (SDL_RenderFillRect((*st)->win->renderer, (*st)->win->rect) < 0)
			return (FAILURE);
		tmp = tmp->next;
		(*st)->win->nb_threads += 1;
	}
	if (SDL_SetRenderTarget((*st)->win->renderer, NULL) < 0
		|| SDL_RenderCopy((*st)->win->renderer, (*st)->win->texture, NULL, &(SDL_Rect){0, 0, WIDTH, HEIGHT}) < 0)
		return (FAILURE);
	SDL_DestroyTexture((*st)->win->texture);
	(*st)->win->texture = NULL;
	return (SUCCESS);
}
