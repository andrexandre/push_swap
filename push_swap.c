/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/07/29 19:05:12 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// 3 algorithms: 5 -, 100 -, 500 -
	// t_lst	*a;
	// t_lst	*b;
	// a = NULL;
	// b = NULL;
	// pl(a);
// testing/making a mini terminal to test operations > make m M="1 2 3"

void	push_swap(t_lst *a)
{
	char	c = '\0';

	while (1)
	{
		prt("> ");
		scanf("%c", &c);
		if (c == 'y')
			pl(a);
		if (c == 'n')
			return ;
	}
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

/* time to create the operations
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
*/

/*
	// printf("ac: %i\nwc: %i\n", ac, wc);
#include "func_lib.c"
#include "ft_split.c"
#include "list_lib.c"
// make function to free everything to make the main less than 25 lines
*/

int	main(int ac, char **av)
{
	int		wc;
	t_lst	*lst;
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
	while (head)
	{
		lst = head;
		head = head->next;
		free(lst);
	}
	return (0);
}
