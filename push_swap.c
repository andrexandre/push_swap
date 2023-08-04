/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/08/04 13:07:02 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* make algorithms
3=3- perfect
5=12- great
100=max=700min=-1500 X
500=max=5500min=-11500 X
// add 1 extra function in list_lib and then use debug
*/
#include <stdio.h>
void	push_swap(t_lst *a, int len)
{
	t_lst	*b;
	b = NULL;
	--len;
	fill_am(a, len);
	if (check_sort(a))
		len = 0;
	if (D)
		len = -10;
	if (len < 0)
	{
		char	c[6] = "h";
		while (*c != 'q')
		{
			// system("clear"); // (h)elp: sa/b/s, pa/b, ra/b/r, rra/b/r, (q)uit
			plv(a, b);
			scanf("%5s", c);
			if (*c == 's' && c[1] != 's')
				sa_sb(&a, c[1]);
			else if (c[1] == 's')
				ss(&a, &b);
			else if (*c == 'p')
				pa_pb(&a, &b, c[1]-97);
			else if (*c == 'r' && c[1] != 'r' && !c[2])
				ra_rb(&a, c[1]);
			else if (c[1] == 'r' && !c[2])
				rr(&a, &b);
			else if (*c == 'r' && c[1] == 'r' && c[2] != 'r')
				rra_rrb(&a, c[2]);
			else if (c[2] == 'r')
				rrr(&a, &b);
		}
	}
	if (len == 2)
		sa_sb(&a, 'a');
	else if (len == 3)
		lilsort(&a);
	else if (len == 4 || len == 5)
	{
		if (len != 4)
			pa_pb(&a, &b, 1);
		pa_pb(&a, &b, 1);
		lilsort(&a);
		if (len != 4)
		{
			if (smallest(b->data, a) || biggest(b->data, a))
				while (!smallest(a->data, a))
					ra_rb(&a, 'a');
			else
			{
				if (biggest(a->data, a))
					ra_rb(&a, 'a');
				while (a->data > b->data || a->next->data < b->data)
					ra_rb(&a, 'a');
				if (!(a->data > b->data && a->next->data < b->data))
					ra_rb(&a, 'a');				
			}
			pa_pb(&a, &b, 0);
		}
		if (smallest(b->data, a) || biggest(b->data, a))
			while (!smallest(a->data, a))
				ra_rb(&a, 'a');
		else
		{
			if (biggest(a->data, a))
				ra_rb(&a, 'a');
			if (!(a->next->data < b->data && a->next->next->data > b->data))
			{
				if (!(a->data > b->data && a->next->data < b->data))
					while (a->data > b->data || a->next->data < b->data)
						rra_rrb(&a, 'a');
				if (!(a->data > b->data && a->next->data < b->data))
					ra_rb(&a, 'a');
			}
			else
			{
				ra_rb(&a, 'a');
				ra_rb(&a, 'a');
			}
		}
		pa_pb(&a, &b, 0);
		if (biggest(a->next->data, a) && smallest(a->next->next->data, a))
		{
			ra_rb(&a, 'a');
			ra_rb(&a, 'a');
		}
		else
			while (!check_sort(a) && !(biggest(a->data, a) && smallest(a->next->data, a)))
				rra_rrb(&a, 'a');
		if (biggest(a->data, a) && smallest(a->next->data, a))
			ra_rb(&a, 'a');
	}
	// else if (len < 101)
	// {
	// 	t_lst *tmp = a;
	// 	fill_am(a, len);
	// 	// simple ra median algorithm
	// 	int	asd;

	// 	asd = 0;
	// 	if (tmp)
	// 	{
	// 		while (tmp->next)
	// 		{
	// 			prt("n[%i]: %i/a:%i\n", asd, tmp->data, tmp->above_median);
	// 			tmp = tmp->next;
	// 		}
	// 		prt("n[%i]: %i/a:%i\n", asd, tmp->data, tmp->above_median);
	// 	}
	// 	else
	// 		prt("(NULL)\n");
	// }
	if (!check_sort(a))
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
