/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/07/26 19:02:18 by analexan         ###   ########.fr       */
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

	longarr = NULL;
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
		{
			if (longarr[i -1] > 2147483647 || longarr[i -1] < -2147483648
				|| longarr[i - 1] == longarr[++j - 1])
			{
				free(longarr);
				longarr = NULL;
				return (1);
			}
		}
	}
	return (0);
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
	intarr = malloc(sizeof(int) * (ac - 1));
	if (!intarr)
		return (NULL);
	i = 0;
	while (++i < ac)
		intarr[i - 1] = stoi(av[i]);
	return (intarr);
}
// solve the memory leaks with
// make v v="1 2"
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
	av[1] = " a ";
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
		while (i && av[--i])
			free(av[i]);
		if (av)
			free(av);
	}
	return (0);
}
