/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:34:26 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/13 17:34:28 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst)
		return (NULL);
	if (!(tmp = f(lst)))
		return (NULL);
	lst = lst->next;
	tmp2 = tmp;
	while (lst)
	{
		if (!(tmp2->next = f(lst)))
			return (NULL);
		tmp2 = tmp2->next;
		lst = lst->next;
	}
	return (tmp);
}
