/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args (1).c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdurand- <jdurand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 18:37:21 by jdurand-          #+#    #+#             */
/*   Updated: 2019/06/18 19:45:13 by jdurand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

int				print_error(int **args)
{
	ft_putstr(2, "usage : ./corewar [-v | -dump N] [-n N] <champion1.cor> ...\n", 60);
	if (args != NULL && *args != NULL)
		free(args);
	return (SUCCESS);
}

/*
int				*init_args(void)
{
	int			*args;
	int			i;

	i = 10;
	if (!(args = malloc(sizeof(int) * i)))
		return (NULL);
	while (i >= 0)
	{
		args[i] = -1;
		i--;
	}
	return (args);
}
*/

static int		init_args(int **args)
{
	int			i;

	i = -1;
	if (!((*args) = malloc(sizeof(int) * (i + 1))))
		return (MALLOC_FAILED);
	while (++i < 10)
		(*args)[i] = -1;
	return (SUCCESS);
}

int				is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int		get_nbr(int x, char *str)
{
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		if (is_number(str[i]) != 1)
			return (-1);
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}

int				get_cor(char **argv, int i, int **args)
{
	int			j;
	static int	k = 3;

	if ((*args)[10] > 3)
		print_error(*args);
	j = 0;
	while (argv[i][j] != '\0')
		j++;
	if (j > 4)
	{
		j = j - 4;
		if (ft_strcmp(&argv[i][j], ".cor") == 0)
		{
			args[0][k] = i;
			k = k + 2;
			(*args)[10]++;
		}
	}
	else
		print_error(*args);
	return (i);
}

int				get_n(int **args, char **argv, int i)
{
	static int	n = 0;
	static int	j = 2;

	n++;
	i++;
	j = (*args)[10] * 2 + 2;
	if (n > (*args)[10] + 1)
		print_error(*args);
	*args = get_nbr(j, argv[i], *args);
	args[0][j] == -1 ? i-- : 0;
	return (i);
}

static int		get_v(int **args)
{
	if (args == NULL || *args == NULL
		|| (*args)[0] != -1 || (*args)[1] != -1 || (*args)[10] != 0)
		return (BAD_PARAM);
	(*args)[1] = 1;
	return (SUCCESS);
}

static int		get_dump(char *str, int **args)
{
	int			result;

	if (args == NULL || *args == NULL
		|| str == NULL
		|| (*args)[1] != -1 || (*args)[0] != 1 || (*args)[10] != 0)
		return (BAD_PARAM);
	if ((result = get_nbr(0, str, args)) == -1)
		return (FAILURE);
	(*args)[1] = result;
	// nb peut etre inferieur a 0 ?
	// si oui changement necessaire
	return (SUCCESS);
}

int				sub_get_args(int argc, char **argv, int **args)
{
	int			i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
		{
			if (get_v(args) != SUCCESS)
				return (CALL_FAILED);
		}
		else if (ft_strcmp(argv[i], "-dump") == 0)
		{
			i++;
			if (argc >= i || get_dump(argv[i], args) != SUCCESS)
				return (CALL_FAILED);
		}
		else if (ft_strcmp(argv[i], "-n") == 0)
		{
			i++;
			if (argc >= i + 1 || get_n(argv[i], args) != SUCCESS)
				return (CALL_FAILED);
		}
		else
			i = get_cor(argv, i, (*args)[10], &args);
	}
	return (SUCCESS);
}

int				get_args(int argc, char **argv)
{
	int			*args;

	args = NULL;
	if (argc < 2 || argv == NULL)
		return (print_error(args));
	if (init_args(&args) != SUCCESS)
		return (CALL_FAILED);

	sub_get_args(argc, argv, &args);
	if (args[10] == 0)
	{
		print_error(args);
	}
	printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", args[0], args[1], args[2], args[3],
		args[4], args[5], args[6], args[7], args[8], args[9], args[10]);
	free(args);
	return (args);


// declaration tableau ints
//		-1 pour chaque int de base
// check chaque param
// si un param correspond a un flag
//		on active le flag dans le tableau d'ints
// flags :
// [0] = nbr cycles -dump
// [1] = -v
// [2] = number -n ch1.
// [3] = nom ch1.
// [4] = number -n ch2.
// [5] = nom ch2.
// [6] = number -n ch3.
// [7] = nom ch3.
// [8] = number -n ch4.
// [9] = nom ch4.
// [10] = ???
// [11] = 0













}


int				main(int argc, char **argv)
{
	return (0);
}

