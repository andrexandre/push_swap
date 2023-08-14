/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:56:14 by analexan          #+#    #+#             */
/*   Updated: 2023/08/14 18:05:56 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// this has TOO_MANY_LINES
void	debugger(t_lst *a, t_lst *b, int *len)
{
	char	c[6];
	t_lst	*tmp;
	int		pl;

	tmp = a;
	pl = 1;
	pa_pb(&a, &b, 1);
	pa_pb(&a, &b, 1);
	while (*c != 'q')
	{
		if (*c == 'f')
			(void)0;
		else if (pl == 1)
			plv(a, b);
		else
			prt("a | %lb | %l> ", a, b);
		scanf("%5s", c);
		if (*c == 'l')
			pl = -pl;
		else if (*c == 'f')
		{
			tmp = fill_node_price(a, b);
			prt("tar[%i]: %i a:%i p:%i n:%i\n", tmp->index, tmp->data,
				tmp->above_median, tmp->push_price,
				tmp->node_price);
			tmp = a;
			if (tmp)
			{
				while (tmp->next)
				{
					prt("n[%i]: %i a:%i p:%i n:%i\n", tmp->index, tmp->data,
						tmp->above_median, tmp->push_price, tmp->node_price);
					tmp = tmp->next;
				}
				prt("n[%i]: %i a:%i p:%i n:%i\n> ", tmp->index, tmp->data,
					tmp->above_median, tmp->push_price, tmp->node_price);
			}
			else
				prt("(NULL)\n> ");
			tmp = b;
			if (tmp)
			{
				prt("\n");
				while (tmp->next)
				{
					prt("n[%i]: %i a:%i p:%i n:%i\n", tmp->index, tmp->data,
						tmp->above_median, tmp->push_price, tmp->node_price);
					tmp = tmp->next;
				}
				prt("n[%i]: %i a:%i p:%i n:%i\n> ", tmp->index, tmp->data,
					tmp->above_median, tmp->push_price, tmp->node_price);
			}
			else
				prt("(NULL)\n> ");
		}
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
	*len = -1;
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
	int	i;

	i = 0;
	if (head)
	{
		while (head->next)
		{
			prt("%i ", head->data);
			head = head->next;
			if (i++ > 1000)
			{
				prt("Does your list really have 1000 items?\n");
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
