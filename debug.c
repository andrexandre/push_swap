/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:56:14 by analexan          #+#    #+#             */
/*   Updated: 2023/08/16 15:56:37 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	f_option(t_lst *a, t_lst *b)
{
	t_lst	*tmp;
	int		quit;

	quit = 0;
	tmp = a;
	while (!quit)
	{
		if (tmp == b)
			quit = 1;
		while (tmp)
		{
			prt("n[%i]: %i a:%i p:%i n:%i\n", tmp->index, tmp->data,
				tmp->above_median, tmp->push_price, tmp->node_price);
			tmp = tmp->next;
		}
		prt("> ");
		tmp = b;
	}
}

void	operations(t_lst **a, t_lst **b, char *c)
{
	if (*c == 's' && c[1] == 'a')
		sa_sb(a, c[1]);
	else if (*c == 's' && c[1] == 'b')
		sa_sb(b, c[1]);
	else if (c[1] == 's')
		ss(a, b);
	else if (*c == 'p')
		pa_pb(a, b, c[1] - 97);
	else if (*c == 'r' && c[1] == 'a' && !c[2])
		ra_rb(a, c[1]);
	else if (*c == 'r' && c[1] == 'b' && !c[2])
		ra_rb(b, c[1]);
	else if (c[1] == 'r' && c[1] == 'r' && !c[2])
		rr(a, b);
	else if (*c == 'r' && c[1] == 'r' && c[2] == 'a')
		rra_rrb(a, c[2]);
	else if (*c == 'r' && c[1] == 'r' && c[2] == 'b')
		rra_rrb(b, c[2]);
	else if (c[0] == 'r' && c[1] == 'r' && c[2] == 'r')
		rrr(a, b);
}

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
	if (head)
	{
		while (head->next)
		{
			prt("%i ", head->data);
			head = head->next;
		}
		prt("%i\n", head->data);
	}
	else
		prt("(NULL)\n");
}

// this line is to put in push_swap after if (is_sorted(a))
// debugger(a, b, &len); // (un)comment this line to toggle debugger
// #include <stdio.h>
// void	debugger(t_lst *a, t_lst *b, int *len)
// {
// 	char	c[6];
// 	pa_pb(&a, &b, 1);
// 	pa_pb(&a, &b, 1);
// 	while (*c != 'q')
// 	{
// 		if (*c == 'f')
// 			(void)0;
// 		else
// 			plv(a, b);
// 		scanf("%5s", c);
// 		if (*c == 'f')
// 			f_option(a, b);
// 		else
// 			operations(&a, &b, c);
// 	}
// 	*len = -1;
// }
