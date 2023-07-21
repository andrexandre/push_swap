/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/07/21 16:31:03 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *iarr)
{
	ps("intarr = { ");
	while (*iarr)
	{
		pn(*iarr++);
		if (*iarr)
			ps(", ");
	}
	ps(" }");
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
		while (longarr[++j - 1])
			if (longarr[i - 1] == longarr[j - 1] || longarr[i - 1] > INT_MAX)
				return (1);
	}
	return (0);
}

int	*check_error(int ac, char **av)
{
	int		i;
	int		j;
	int		*intarr;

	if (ac == 1 || !av[1][0])
		return (NULL);
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

#include "functions.c"
#include "ft_split.c"
// make 0 work
// if ac == 2, ft_split
	// t_lst	*a;
	// t_lst	*b;
	// a = NULL;
	// b = NULL;
// fix ft_split in the push_swap
int	main(int ac, char **av)
{
	int		*iarr;
	char	*temp;

	// ac = 2;
	// av[1] = "-1\0";
	if (ac == 2)
	{
		temp = av[1];
		av = ft_split(temp, ' ');
		int	i = 0;
		while (av[++i])
		{
			ps(av[i]);
			write(1, "\n", 1);
		}
	}
	iarr = check_error(ac, av);
	if (!iarr)
	{
		if (ac != 1)
			write(2, "Error\n", 6);
		return (0);
	}
	push_swap(iarr);
	write(1, "\n", 1);
	return (0);
}
