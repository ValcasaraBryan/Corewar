/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 15:56:11 by glebouch          #+#    #+#             */
/*   Updated: 2019/07/04 12:26:27 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

/* RESTE A CHECKER ft_put_players */

static int			ft_print_text(t_storage **st, char *str, int line)
{
	SDL_Surface		*srf;
	SDL_Texture		*msg;
	SDL_Rect		rect;

	if ((srf = TTF_RenderText_Solid((*st)->win->ttf_text, str,
		argb_to_sdl(WHITE))) == NULL)
		return (FAILURE);
	if ((msg = SDL_CreateTextureFromSurface((*st)->win->renderer, srf)) == NULL)
	{
		SDL_FreeSurface(srf);
		srf = NULL;
		return (FAILURE);
	}
	rect.x = 66 * OCT_W;
	rect.y = line * OCT_H;
	rect.w = ft_strlen(str) * 9;
	rect.h = OCT_H;
	SDL_FreeSurface(srf);
	srf = NULL;
	if ((SDL_RenderCopy((*st)->win->renderer, msg, NULL, &rect)) < 0)
	{
		SDL_DestroyTexture(msg);
		msg = NULL;
		return (FAILURE);
	}
	SDL_DestroyTexture(msg);
	msg = NULL;
	return (SUCCESS);
}

static int			ft_print_name_colored(t_storage **st, char *intro,
	char *name, int num_player)
{
	SDL_Surface		*srf;
	SDL_Texture		*msg;
	SDL_Rect		rect;

	if ((srf = TTF_RenderText_Solid((*st)->win->ttf_text, name,
		argb_to_sdl(ft_color_octet(num_player)))) == NULL)
		return (FAILURE);
	if ((msg = SDL_CreateTextureFromSurface((*st)->win->renderer, srf)) == NULL)
	{
		SDL_FreeSurface(srf);
		srf = NULL;
		return (FAILURE);
	}
	rect.x = 66 * OCT_W + ft_strlen(intro) * 9;
	rect.y = (8 + (num_player - 1) * 4) * OCT_H;
	rect.w = ft_strlen(name) * 9;
	rect.h = OCT_H;
	SDL_FreeSurface(srf);
	srf = NULL;
	if ((SDL_RenderCopy((*st)->win->renderer, msg, NULL, &rect)) < 0)
	{
		SDL_DestroyTexture(msg);
		msg = NULL;
		return (FAILURE);
	}
	SDL_DestroyTexture(msg);
	msg = NULL;
	return (SUCCESS);
}

static int			ft_str_create_and_print(t_storage **st, char *str1,
	char *str2, int line)
{
	char			*dest;
	int				size_total;

	size_total = ft_strlen(str1) + ft_strlen(str2);
	if (!(dest = (char *)malloc(sizeof(char) * (size_total + 1))))
		return (FAILURE);
	ft_bzero(dest, sizeof(char) * (size_total + 1));
	dest = ft_strcat(dest, str1);
	dest = ft_strcat(dest, str2);
	free(str2);
	if (ft_print_text(st, dest, line) != SUCCESS)
	{
		free(dest);
		return (FAILURE);
	}
	free(dest);
	return (SUCCESS);
}

static int			ft_put_players(t_storage **st, int line)
{
	char			*str;
	int				nb_players;
	t_champion		*tmp;

	nb_players = 0;
	tmp = (*st)->first_champion;
	//////////////////////free tmp
	while (tmp != NULL)
	{
		nb_players += 1;
		if (!(str = malloc(sizeof(char) * (10 + ft_size(tmp->number)))))
			return (FAILURE);
		ft_bzero(str, sizeof(char) * (10 + ft_size(tmp->number)));
		//////////?????????
		// bzero(str, 10 + ft_size(12));
		///////////
		str = ft_strcat(str, "Player ");
		str = ft_strcat(str, ft_itoa(tmp->number));
		str = ft_strcat(str, ": ");
		///////////////////////////////////////////////
		ft_str_create_and_print(st, str, ft_strdup(tmp->name), line);
		ft_print_name_colored(st, str, tmp->name, nb_players);
		line++;
		ft_str_create_and_print(st, "   Last_live :                   ", ft_itoa(tmp->last_live), line);
		line++;
		ft_str_create_and_print(st, "   Lives in current periode :    ", ft_itoa(tmp->current_lives), line);
		///////////////////////////////////////////////
		line += 2;
		free(str);
		tmp = tmp->next;
	}
	return (nb_players * 3);
}

int					ft_print_infos(t_storage **st)
{
	int				line;

	line = 1;
	if ((ft_print_text(st, (*st)->win->pause == 1 ? "PAUSE" : "RUNNING", line)) != SUCCESS
		|| ft_str_create_and_print(st, "Cycles : ", ft_itoa((*st)->cycle), line + 2) != SUCCESS
		|| ft_str_create_and_print(st, "Processes : ", ft_itoa((*st)->win->nb_threads), line + 4) != SUCCESS)
		return (FAILURE);
	if ((line += ft_put_players(st, line + 7) + 10) < 12)
		return (FAILURE);
	if ((ft_str_create_and_print(st, "CYCLE_TO_DIE : ", ft_itoa(CYCLE_TO_DIE), line)) != SUCCESS
		|| ft_str_create_and_print(st, "CYCLE_DELTA : ", ft_itoa(CYCLE_DELTA), line + 2) != SUCCESS
		|| ft_str_create_and_print(st, "NBR_LIVE : ", ft_itoa((*st)->nb_live_current), line + 4) != SUCCESS
		|| ft_str_create_and_print(st, "MAX_CHECKS : ", ft_itoa(MAX_CHECKS), line + 6) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}
