/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init_sdl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:55:52 by glebouch          #+#    #+#             */
/*   Updated: 2019/07/05 11:09:56 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int			ft_fill_alphabet_color(t_storage **st, SDL_Texture ***tab,
	int color)
{
	int		i;
	char	*letter;

	i = -1;
	while (++i < 36)
	{
		letter = i < 10 ? ft_itoa(i) : ft_ctoa((char)(i + 87));
		(*st)->win->surface = TTF_RenderText_Solid((*st)->win->ttf_text,
				letter, argb_to_sdl(color));
		free(letter);
		if ((*st)->win->surface == NULL)
			return (FAILURE);
		if (((*tab)[i] = SDL_CreateTextureFromSurface((*st)->win->renderer,
			(*st)->win->surface)) == NULL)
		{
			SDL_FreeSurface((*st)->win->surface);
			(*st)->win->surface = NULL;
			return (FAILURE);
		}
		SDL_FreeSurface((*st)->win->surface);
		(*st)->win->surface = NULL;
	}
	return (SUCCESS);
}

int			ft_init_alphabet_color(t_storage **st)
{
	if (!((*st)->win->tab_w = malloc(sizeof(*(*st)->win->tab_w) * 36)))
		return (FAILURE);
	if (!((*st)->win->tab_b = malloc(sizeof(SDL_Texture *) * 36)))
		return (FAILURE);
	if (!((*st)->win->tab_o = malloc(sizeof(SDL_Texture *) * 36)))
		return (FAILURE);
	if (!((*st)->win->tab_v = malloc(sizeof(SDL_Texture *) * 36)))
		return (FAILURE);
	if (!((*st)->win->tab_g = malloc(sizeof(SDL_Texture *) * 36)))
		return (FAILURE);
	ft_bzero((*st)->win->tab_w, sizeof(*(*st)->win->tab_w) * 36);
	ft_bzero((*st)->win->tab_b, sizeof(*(*st)->win->tab_b) * 36);
	ft_bzero((*st)->win->tab_o, sizeof(*(*st)->win->tab_o) * 36);
	ft_bzero((*st)->win->tab_v, sizeof(*(*st)->win->tab_v) * 36);
	ft_bzero((*st)->win->tab_g, sizeof(*(*st)->win->tab_g) * 36);
	if ((ft_fill_alphabet_color(st, &(*st)->win->tab_w, WHITE)) != SUCCESS
		|| ft_fill_alphabet_color(st, &(*st)->win->tab_b, P1) != SUCCESS
		|| ft_fill_alphabet_color(st, &(*st)->win->tab_o, P2) != SUCCESS
		|| ft_fill_alphabet_color(st, &(*st)->win->tab_v, P3) != SUCCESS
		|| ft_fill_alphabet_color(st, &(*st)->win->tab_g, P4) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int			ft_init_win(t_storage **st)
{
	(*st)->win->pause = 0;
	if (TTF_Init() < 0)
		return (FAILURE);
	if (((*st)->win->ttf_text = TTF_OpenFont("monofonto.ttf", 80)) == NULL)
		return (FAILURE);
	if (!((*st)->win->rect = malloc(sizeof(SDL_Rect))))
		return (FAILURE);
	ft_bzero((*st)->win->rect, sizeof(SDL_Rect));
	if (!((*st)->win->event = malloc(sizeof(SDL_Event))))
		return (FAILURE);
	ft_bzero((*st)->win->event, sizeof(SDL_Event));
	(*st)->win->nb_threads = 0;
	(*st)->win->surface = NULL;
	(*st)->win->texture = NULL;
	(*st)->win->tab_w = NULL;
	(*st)->win->tab_b = NULL;
	(*st)->win->tab_o = NULL;
	(*st)->win->tab_v = NULL;
	(*st)->win->tab_g = NULL;
	if (ft_init_alphabet_color(st) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

int			ft_init_sdl(t_storage **st)
{
	t_win	*win;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (FAILURE);
	if (!(win = malloc(sizeof(t_win *))))
		return (FAILURE);
	ft_bzero(win, sizeof(t_win *));
	(*st)->win = win;
	if (((*st)->win->window = SDL_CreateWindow("Virtual Corewar Arena",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE)) == NULL)
		return (FAILURE);
	if (((*st)->win->renderer = SDL_CreateRenderer((*st)->win->window, -1, 0))
		== NULL)
		return (FAILURE);
	if (SDL_SetRenderDrawColor((*st)->win->renderer, 0, 0, 0, 255) < 0)
		return (FAILURE);
	if (SDL_RenderClear((*st)->win->renderer) < 0)
		return (FAILURE);
	return (SUCCESS);
}

int			ft_print_game(t_storage **st, int *var_cycle_to_die)
{
	if (ft_print_threads(st) != SUCCESS)
		return (FAILURE);
	if (ft_print_grid(st) != SUCCESS)
		return (FAILURE);
	if (ft_print_infos_a(st, var_cycle_to_die) != SUCCESS)
		return (FAILURE);
	SDL_RenderPresent((*st)->win->renderer);
	if (SDL_RenderClear((*st)->win->renderer) < 0)
		return (FAILURE);
	return (SUCCESS);
}
