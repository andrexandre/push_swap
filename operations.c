/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:04:41 by analexan          #+#    #+#             */
/*   Updated: 2023/08/16 15:30:36 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_lst **head, char c)
{
	t_lst	*tmp;

	if (!*head || !(*head)->next)
		return ;
	if (c)
		prt("s%c\n", c);
	tmp = (*head)->next;
	(*head)->next = (*head)->next->next;
	tmp->next = *head;
	*head = tmp;
	fill_list(*head);
}

void	ss(t_lst **a, t_lst **b)
{
	sa_sb(a, '\0');
	sa_sb(b, '\0');
	prt("ss\n");
}

// mode = 0: pa, mode = 1: pb
void	pa_pb(t_lst **a, t_lst **b, int mode)
{
	t_lst	*tmp;

	if ((!*b && !mode) || (!*a && mode))
		return ;
	prt("p%c\n", "ab"[mode]);
	if (mode)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
	else
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
	fill_list(*a);
	fill_list(*b);
}

void	ra_rb(t_lst **head, char c)
{
	t_lst	*tmp;

	if (!*head || !(*head)->next)
		return ;
	if (c)
		prt("r%c\n", c);
	tmp = (*head)->next;
	lstlast(*head, 0)->next = *head;
	(*head)->next = NULL;
	*head = tmp;
	fill_list(*head);
}

void	rr(t_lst **a, t_lst **b)
{
	ra_rb(a, '\0');
	ra_rb(b, '\0');
	prt("rr\n");
}
