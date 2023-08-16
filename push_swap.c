/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/08/16 16:24:59 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_lst *a, t_lst *b, int len)
{
	t_lst	*target;

	if (is_sorted(a))
		len = 0;
	if (len == 2)
		sa_sb(&a, 'a');
	else if (len == 3)
		lilsort(&a);
	else if (len > 3)
	{
		if (len != 4)
			pa_pb(&a, &b, 1);
		pa_pb(&a, &b, 1);
		while (a && optimize_to_list(&a, &b, 0))
			pa_pb(&a, &b, 1);
		while (b && optimize_to_list(&b, &a, 1))
			pa_pb(&a, &b, 0);
		target = find_smallest_or_biggest(a, 0);
		while (!is_sorted(a))
			if (target->above_median)
				ra_rb(&a, 'a');
		else
			rra_rrb(&a, 'a');
	}
	free_all(a, b);
}

// mode = 0: returns long array; mode = 1: returns list;
void	*createarr(int ac, char **av, int mode)
{
	long	*longarr;
	t_lst	*lst;
	int		i;

	i = 0;
	if (!mode)
	{
		longarr = NULL;
		longarr = malloc(sizeof(long) * (ac - 1));
		if (!longarr)
			return (NULL);
		while (++i < ac)
			longarr[i - 1] = (long)stol(av[i]);
		return (longarr);
	}
	else
	{
		lst = NULL;
		while (++i < ac)
			addbck(&lst, stoi(av[i]));
		return (lst);
	}
}

// check if some arguments are bigger than an integer and there are duplicates
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
			if (longarr[i -1] > 2147483647 || longarr[i -1] < -2147483648
				|| (j != ac && longarr[i - 1] == longarr[j - 1]))
				n = 1;
	}
	free(longarr);
	longarr = NULL;
	return (n);
}

// check if the arguments are integers
int	check_error(int ac, char **av, t_lst **a)
{
	int		i;
	int		j;

	i = 0;
	if (!av)
		return (0);
	while (++i < ac)
	{
		j = -1;
		if (av[i][0] == '-' || av[i][0] == '+')
			j++;
		if ((av[i][0] == '-' || av[i][0] == '+') && !av[i][1])
			return (0);
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
	}
	if (check_size_dup(ac, av))
		return (0);
	*a = (t_lst *)createarr(ac, av, 1);
	if (!*a)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_lst	*a;
	t_lst	*b;
	int		wc;

	a = NULL;
	b = NULL;
	wc = ac;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split_m(av[1], ' ', &wc);
	if (check_error(wc, av, &a))
		push_swap(a, b, wc - 1);
	else
		write(2, "Error\n", 6);
	if (ac == 2)
	{
		while (--wc >= 0)
			if (av[wc])
				free(av[wc]);
		free(av);
	}
	return (0);
}
