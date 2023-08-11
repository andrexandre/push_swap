/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/08/11 12:54:10 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* make algorithms
3=3- perfect
5=12- perfect
100=max=700min=-1500 works at least
500=max=5500min=-11500 works at least
*/
void	push_swap(t_lst *a, t_lst *b, int len)
{
	t_lst	*target;
	t_lst	*last;

	target = NULL;
	--len;
	fill_list(a);
	if (check_sort(a))
		len = 0;
	// (un)comment the next line to toggle debugger
	// debugger(a, b, &len);
	if (len == 2)
		sa_sb(&a, 'a');
	else if (len == 3)
		lilsort(&a);
	else if (len == 4 || len == 5
		// turn this into a function
	)
	{
		if (len == 5)
			pa_pb(&a, &b, 1);
		pa_pb(&a, &b, 1);
		lilsort(&a);
		if (len == 5)
		{
			if (is_smallest(b->data, a) || is_biggest(b->data, a))
			{
				target = find_target(a, 0, 0);
				while (!is_smallest(a->data, a))
					if (target->above_median)
						ra_rb(&a, 'a');
				else
					rra_rrb(&a, 'a');
			}
			else
			{
				last = lstlast(a, 0);
				target = find_target(a, 2, b->data);
				if (target->above_median)
					while (!(same(last->data, b->data, a->data)))
					{
						ra_rb(&a, 'a');
						last = lstlast(a, 0);
					}
				else
					while (!(same(last->data, b->data, a->data)))
					{
						rra_rrb(&a, 'a');
						last = lstlast(a, 0);
					}
				if (same(a->data, b->data, a->next->data))
					ra_rb(&a, 'a');
				// target = find_target(a, 2, b->data);
				// while (!(a->data < b->data && a->next->data > b->data))
				// 	if (target->above_median)
				// 		ra_rb(&a, 'a');
				// else
				// 	rra_rrb(&a, 'a');
				// if (a->data < b->data && a->next->data > b->data)
				// 	ra_rb(&a, 'a');
			}
			pa_pb(&a, &b, 0);
		}
		if (is_smallest(b->data, a) || is_biggest(b->data, a))
		{
			target = find_target(a, 0, 0);
			while (!is_smallest(a->data, a))
				if (target->above_median)
					ra_rb(&a, 'a');
			else
				rra_rrb(&a, 'a');
		}
		else
		{
			last = lstlast(a, 0);
			target = find_target(a, 2, b->data);
			if (target->above_median)
				while (!(same(last->data, b->data, a->data)))
				{
					ra_rb(&a, 'a');
					last = lstlast(a, 0);
				}
			else
				while (!(same(last->data, b->data, a->data)))
				{
					rra_rrb(&a, 'a');
					last = lstlast(a, 0);
				}
			if (same(a->data, b->data, a->next->data))
				ra_rb(&a, 'a');
		}
		pa_pb(&a, &b, 0);
		if (!check_sort(a))
		{
			target = find_target(a, 0, 0);
			while (!check_sort(a))
				if (target->above_median)
					ra_rb(&a, 'a');
			else
				rra_rrb(&a, 'a');
		}
	}
	else if (len > 5
		// turn this into a function
	)
	{
		pa_pb(&a, &b, 1);
		pa_pb(&a, &b, 1);
		if (b->data < b->next->data)
			sa_sb(&b, 'b');
		while (a)
		{
			fill_node_price(a, b, 0);
			if (is_smallest(a->data, b) || is_biggest(a->data, b))
			{
				target = find_target(b, 1, 0);
				while (!is_biggest(b->data, b))
					if (target->above_median)
						ra_rb(&b, 'b');
				else
					rra_rrb(&b, 'b');
			}
			else
			{
				last = lstlast(b, 0);
				target = find_target(a, 2, b->data);
				if (target->above_median)
					while (!same(b->data, a->data, last->data))
					{
						ra_rb(&b, 'b');
						last = lstlast(b, 0);
					}
				else
					while (!same(b->data, a->data, last->data))
					{
						rra_rrb(&b, 'b');
						last = lstlast(b, 0);
					}
				if (b->data > a->data && a->data > b->next->data)
					ra_rb(&b, 'b');
			}
			pa_pb(&a, &b, 1);
		}
		while (b)
			pa_pb(&a, &b, 0);
		target = find_target(a, 0, 0);
		while (!is_smallest(a->data, a))
			if (target->above_median)
				ra_rb(&a, 'a');
		else
			rra_rrb(&a, 'a');
	}
	if (len && !check_sort(a))
		prt("list not sorted!\n%l", a);
	free_all(a, b);
}

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
		push_swap(a, b, wc);
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
