/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 12:32:53 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/13 15:26:11 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				j;
	unsigned char	*dest;
	unsigned char	*src;

	i = 0;
	j = 0;
	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (dest[i])
	{
		if (dest[i] != src[i])
			return (j = dest[i] - src[i]);
		i++;
	}
	return (j = dest[i] - src[i]);
}
