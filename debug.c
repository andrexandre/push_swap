/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:56:14 by analexan          #+#    #+#             */
/*   Updated: 2023/08/09 16:43:51 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	plv(t_lst *a, t_lst *b)
{
	while (a || b)
	{
		if (a)
		{
			prt("%i ", a->data);
			if (a)
				a = a->next;
		}
		else
			prt("  ");
		if (b)
		{
			prt("%i", b->data);
			if (b)
				b = b->next;
		}
		else
			prt(" ");
		prt("\n");
	}
	prt("_ _\na b\n\n> ");
}

void	plh(t_lst *head)
{
	int	i;

	i = 0;
	if (head)
	{
		while (head->next)
		{
			prt("%i ", head->data);
			head = head->next;
			if (i++ > 10000)
			{
				prt("your list really has 10'000 items?\n");
				return ;
			}
		}
		prt("%i\n", head->data);
	}
	else
		prt("(NULL)\n");
}

int	lstlen(t_lst *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	if (lst)
		i++;
	return (i);
}
/*
		t_lst *tmp = a;
		fill_am(a);
		int	asd;

		asd = 0;
		if (tmp)
		{
			while (tmp->next)
			{
				prt("n[%i]: %i/a:%i\n", asd, tmp->data, tmp->above_median);
				tmp = tmp->next;
			}
			prt("n[%i]: %i/a:%i\n", asd, tmp->data, tmp->above_median);
		}
		else
			prt("(NULL)\n");

prt("a | %lb | %l> ", a, b);
cc -Wall -Wextra -Werror -D DEB=1 *.c && ./a.out 1 3 2
*/