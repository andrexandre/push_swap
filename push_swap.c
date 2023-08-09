/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/08/09 18:38:11 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/* make algorithms
3=3- perfect
5=12- perfect
100=max=700min=-1500 works at least
500=max=5500min=-11500 works at least
*/
void	push_swap(t_lst *a, int len)
{
	char	c[6];
	t_lst	*b;
	t_lst	*target;

	target = NULL;
	b = NULL;
	--len;
	fill_am(a);
	if (check_sort(a))
		len = 0;
	if (
		0
		// 1
	)
	{
		while (*c != 'q')
		{
			plv(a, b);
			scanf(" %5s", c);
			if (*c == 't')
				target = find_target(a, stoi(&c[1]), stoi(&c[2]));
			if (*c == 't' && target)
				prt("tg[%i]->am: %i\n", target->data, target->above_median);
			else if (*c == 's' && c[1] == 'a')
				sa_sb(&a, c[1]);
			else if (*c == 's' && c[1] == 'b')
				sa_sb(&b, c[1]);
			else if (c[1] == 's')
				ss(&a, &b);
			else if (*c == 'p')
				pa_pb(&a, &b, c[1] - 97);
			else if (*c == 'r' && c[1] == 'a' && !c[2])
				ra_rb(&a, c[1]);
			else if (*c == 'r' && c[1] == 'b' && !c[2])
				ra_rb(&b, c[1]);
			else if (c[1] == 'r' && !c[2])
				rr(&a, &b);
			else if (*c == 'r' && c[1] == 'r' && c[2] == 'a')
				rra_rrb(&a, c[2]);
			else if (*c == 'r' && c[1] == 'r' && c[2] == 'b')
				rra_rrb(&b, c[2]);
			else if (c[2] == 'r')
				rrr(&a, &b);
		}
		len = -1;
	}
	if (len == 2)
		sa_sb(&a, 'a');
	else if (len == 3)
		lilsort(&a);
	else if (len == 4 || len == 5
		// make this into a function
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
				target = find_target(a, 2, b->data);
				while (!(a->data < b->data && a->next->data > b->data))
					if (target->above_median)
						ra_rb(&a, 'a');
				else
					rra_rrb(&a, 'a');
				if (a->data < b->data && a->next->data > b->data)
					ra_rb(&a, 'a');
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
			target = find_target(a, 2, b->data);
			while (!(a->data < b->data && a->next->data > b->data))
				if (target->above_median)
					ra_rb(&a, 'a');
			else
				rra_rrb(&a, 'a');
			if (a->data < b->data && a->next->data > b->data)
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
		// make this into a function
	)
	{
		pa_pb(&a, &b, 1);
		pa_pb(&a, &b, 1);
		if (b->data < b->next->data)
			sa_sb(&b, 'b');
		while (a)
		{
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
				target = find_target(a, 2, b->data);
				while (!(b->data > a->data && b->next->data < a->data))
					if (target->above_median)
						ra_rb(&b, 'b');
				else
					rra_rrb(&b, 'b');
				if (b->data > a->data && b->next->data < a->data)
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
	freeall(a, b);
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

t_lst	*check_error(int ac, char **av)
{
	int		i;
	int		j;
	t_lst	*lst;

	i = 0;
	lst = NULL;
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
	lst = (t_lst *)createarr(ac, av, 1);
	if (!lst)
		return (NULL);
	return (lst);
}

/* includes for raw test
#include "func_lib.c"
#include "ft_split.c"
#include "list_lib.c"
#include "operations.c"
#include "operations2.c"
#include "debug.c"
*/

int	main(int ac, char **av)
{
	int		wc;
	t_lst	*head;

	wc = ac;
	head = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split_m(av[1], ' ', &wc);
	if (av)
		head = check_error(wc, av);
	if (head)
		push_swap(head, wc);
	else
		write(2, "Error\n", 6);
	if (ac == 2)
	{
		while (--wc >= 0)
			free(av[wc]);
		free(av);
	}
	return (0);
}
