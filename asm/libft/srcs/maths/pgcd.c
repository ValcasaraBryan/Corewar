/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:57:52 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/21 16:34:31 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			pgcd(int x, int y)
{
	int		res_petit;
	int		res_grand;
	int		petit;
	int		grand;
	int		i;

	if ((x || y) <= 0)
		return (-1);
	petit = (x > y) ? y : x;
	grand = (x > y) ? x : y;
	res_petit = petit;
	res_grand = grand;
	i = petit + 1;
	while (i-- > 1)
	{
		res_petit = petit / i;
		res_grand = grand / i;
		if ((res_petit * i) == petit && (res_grand * i) == grand)
			return (i);
	}
	return (1);
}
