/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/07/27 19:29:01 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	if (ac == 1)
		ac++;
	pn(ac);
	ps("intarr = { ");
	while (ac > 1)
	{
		pn(*iarr++);
		ac--;
		if (ac > 1)
			ps(", ");
	}
	ps(" }");
	write(1, "\n", 1);
*/

void	push_swap(int *iarr, int ac)
{
	(void)iarr;
	(void)ac;
}

void	*createarr(int ac, char **av, int mode)
{
	long	*longarr;
	int		*intarr;
	int		i;

	i = 0;
	if (!mode)
	{
		longarr = NULL;
		longarr = (long *)malloc(sizeof(long) * (ac - 1));
		if (!longarr)
			return (NULL);
		while (++i < ac)
			longarr[i - 1] = stol(av[i]);
		return (longarr);
	}
	else
	{
		intarr = NULL;
		intarr = (int *)malloc(sizeof(int) * (ac - 1));
		if (!intarr)
			return (NULL);
		while (++i < ac)
			intarr[i - 1] = stoi(av[i]);
		return (intarr);
	}
}

int	check_size_dup(int ac, char **av)
{
	long	*longarr;
	int		i;
	int		j;
	int		n;

	n = 0;
	longarr = (long *)createarr(ac, av, 0);
	if (!longarr)
		n = -1;
	i = 0;
	while (++i < ac && !n)
	{
		j = i;
		while (j++ < ac && !n)
		{
			if (longarr[i -1] > 2147483647 || longarr[i -1] < -2147483648)
				n = 1;
			if (j != ac && longarr[i - 1] == longarr[j - 1])
				n = 1;
		}
	}
	free(longarr);
	longarr = NULL;
	return (n);
}

int	*check_error(int ac, char **av)
{
	int		i;
	int		j;
	int		*intarr;

	i = 0;
	intarr = NULL;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '-')
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				return (NULL);
		}
	}
	if (check_size_dup(ac, av))
		return (NULL);
	intarr = (int *)createarr(ac, av, 1);
	if (!intarr)
		return (NULL);
	return (intarr);
}
// 3 algorithms: 5 -, 100 -, 500 -
	// t_lst	*a;
	// t_lst	*b;
	// a = NULL;
	// b = NULL;
/*
#include "functions.c"
#include "ft_split.c"
int	main(int ac, char **av)
{
	int		*iarr;
	int		i;
	ac = 2;
	av[1] = "-2147483649";
*/

int	main(int ac, char **av)
{
	int		*iarr;
	int		i;



	i = ac;
	iarr = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split_m(av[1], ' ', &ac);
	if (av)
		iarr = check_error(ac, av);
	if (!iarr)
		write(2, "Error\n", 6);
	else
		push_swap(iarr, ac);
	if (i == 2)
	{
		i = ac;
		while (--i >= 0)
			free(av[i]);
		free(av);
	}
	free(iarr);
	return (0);
}
