/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/07/28 19:19:58 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 3 algorithms: 5 -, 100 -, 500 -
	// t_lst	*a;
	// t_lst	*b;
	// a = NULL;
	// b = NULL;
void	push_swap(t_lst *lst)
{
	// pl(lst);
	(void)lst;
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
// time to create the operations
/*
#include "func_lib.c"
#include "ft_split.c"
#include "list_lib.c"
*/

int	main(int ac, char **av)
{
	int		i;
	t_lst	*lst;
	t_lst	*head;

	i = ac;
	head = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split_m(av[1], ' ', &ac);
	if (av)
		head = check_error(ac, av);
	if (!head)
		write(2, "Error\n", 6);
	else
		push_swap(head);
	if (i == 2)
	{
		i = ac;
		while (--i >= 0)
			free(av[i]);
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
