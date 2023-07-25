/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/07/25 16:40:20 by analexan         ###   ########.fr       */
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

int	check_size_dup(int ac, char **av)
{
	long	*longarr;
	int		i;
	int		j;

	longarr = malloc(sizeof(long) * (ac - 1));
	if (!longarr)
		return (-1);
	i = 0;
	while (++i < ac)
		longarr[i - 1] = stol(av[i]);
	i = 0;
	while (++i < ac)
	{
		j = i;
		while (longarr[j - 1])
			if (longarr[i - 1] > 2147483647 
				|| longarr[i - 1] < -2147483648
				|| longarr[i - 1] == longarr[++j - 1])
				return (1);
	}
	free(longarr);
	return (0);
}

int	*check_error(int ac, char **av)
{
	int		i;
	int		j;
	int		*intarr;

	i = 0;
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
	intarr = malloc(sizeof(int) * (ac - 1));
	if (!intarr)
		return (NULL);
	i = 0;
	while (++i < ac)
		intarr[i - 1] = stoi(av[i]);
	return (intarr);
}
/*
#include "functions.c"
#include "ft_split.c"
*/
	// t_lst	*a;
	// t_lst	*b;
	// a = NULL;
	// b = NULL;
	// ac = 2;
	// av[1] = "1";

int	main(int ac, char **av)
{
	int		*iarr;

	iarr = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split_m(av[1], ' ', &ac);
	if (av[1])
		iarr = check_error(ac, av);
	if (!iarr)
		write(2, "Error\n", 6);
	else
		push_swap(iarr, ac);
	return (0);
}
