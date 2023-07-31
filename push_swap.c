/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/07/31 19:18:23 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 3 algorithms: 5 -, 100 -, 500 -
// make algorithm for 3 nodes maybe 5 and then the rest
// #include <stdio.h>
// #include <string.h>
// 	char	c[6] = "h";
// 	while (*c != 'q')
// 	{
// 		system("clear");
// 		prt("a | ");
// 		pl(a);
// 		prt("b | ");
// 		pl(b);
// 		ps("> ");
// 		scanf("%5s", c);
// 		if (*c == 'h' || !strcmp(c, "help"))
// 			ps("(h)elp: sa/b/s, pa/b, ra/b/r, rra/b/r, (q)uit\n");
// 		if (!strcmp(c, "sa"))
// 			sa_sb(&a);
// 		if (!strcmp(c, "sb"))
// 			sa_sb(&b);
// 		if (!strcmp(c, "ss"))
// 			ss(&a, &b);
// 		if (!strcmp(c, "pa"))
// 			pa_pb(&a, &b, 0);
// 		if (!strcmp(c, "pb"))
// 			pa_pb(&a, &b, 1);
// 		if (!strcmp(c, "ra"))
// 			ra_rb(&a);
// 		if (!strcmp(c, "rb"))
// 			ra_rb(&b);
// 		if (!strcmp(c, "rr"))
// 			rr(&a, &b);
// 		if (!strcmp(c, "rra"))
// 			rra_rrb(&a);
// 		if (!strcmp(c, "rrb"))
// 			rra_rrb(&b);
// 		if (!strcmp(c, "rrr"))
// 			rrr(&a, &b);
// 	}

void	push_swap(t_lst *a)
{
	t_lst	*b;

	b = NULL;
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
		longarr = (long *)malloc(sizeof(long) * (ac - 1));
		if (!longarr)
			return (NULL);
		while (++i < ac)
			longarr[i - 1] = stol(av[i]);
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

/*
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
	if (!head)
		write(2, "Error\n", 6);
	else
		push_swap(head);
	if (ac == 2)
	{
		while (--wc >= 0)
			free(av[wc]);
		free(av);
	}
	return (0);
}
