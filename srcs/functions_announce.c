/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_announce.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:03:00 by jdurand-          #+#    #+#             */
/*   Updated: 2019/07/06 10:44:31 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				announce_champions(t_storage **st)
{
	t_champion	*current;
	int			i;

	if (storage_check(st, 0) != VALID_FULL)
		return (BAD_PARAM);
	current = (*st)->first_champion;
	ft_putstr("Introducing contestants...\n");
	i = 1;
	while (current != NULL)
	{
		ft_putstr("* Player ");
		ft_putnbr(i);
		ft_putstr(", weighing ");
		ft_putnbr(current->size);
		ft_putstr(" bytes, \"");
		ft_putstr(current->name);
		ft_putstr("\" (\"");
		ft_putstr(current->desc);
		ft_putstr("\") !\n");
		current = current->next;
		i++;
	}
	return (SUCCESS);
}

int				announce_winner(t_storage **st)
{
	t_champion	*current;
	int			i;

	if (storage_check(st, 0) != VALID_FULL)
		return (BAD_PARAM);
	current = (*st)->first_champion;
	i = 1;
	while (current != NULL)
	{
		if (current->number == (*st)->nb_champ_last_live)
		{
			ft_putstr("le joueur ");
			ft_putnbr(i);
			ft_putstr("(");
			ft_putstr(current->name);
			ft_putstr(") a gagne\n");
		}
		current = current->next;
		i++;
	}
	return (SUCCESS);
}
