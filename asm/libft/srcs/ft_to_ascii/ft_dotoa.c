/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dotoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 04:57:50 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/26 04:57:53 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long			ft_unite(unsigned long nb)
{
	while (nb > 9)
		nb = nb / 10;
	return (nb);
}

static char			*add_char(char *params, int len, unsigned char caractere)
{
	char			*tmp;

	if (!(tmp = ft_memalloc(len + 1)))
		return (NULL);
	if (*params && (len >= 0))
	{
		tmp = (char *)ft_memset(tmp, caractere, len);
		return (ft_strjoin_free(params, tmp, 3));
	}
	return (NULL);
}

static void			add_prec(char **str, unsigned int precision,
					double nb, int neg)
{
	if (nb < 1 && nb > 0)
	{
		while (precision--)
		{
			nb *= 10;
			if (ft_unite(nb) == 0)
				*str = add_char(*str, 1, ft_unite(nb) + 48);
		}
		if (nb - (int)nb > 0.5 && nb - (int)nb < 1)
			nb += 1;
		if (nb > 1)
			*str = ft_strjoin_free(*str, ft_lltoa(nb), 3);
	}
	if (neg)
		*str = ft_strjoin_free(ft_strdup("-"), *str, 3);
}

char				*ft_dotoa(double nb, unsigned int precision)
{
	char			*str;
	unsigned int	i;
	int				neg;

	str = NULL;
	neg = (nb < 0) ? 1 : 0;
	nb = (nb < 0) ? (nb * (-1)) : nb;
	if (nb >= 1)
	{
		str = ft_lltoa(nb);
		i = (int)ft_strlen(str) - 1;
		while (i)
			nb -= (ft_recursive_power(10, i--) * ft_unite(nb));
		nb -= ft_unite(nb);
	}
	str = (str) ? add_char(str, 1, '.') : ft_strdup("0.");
	add_prec(&str, precision, nb, neg);
	return (str);
}
