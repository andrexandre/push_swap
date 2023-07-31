/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:04:41 by analexan          #+#    #+#             */
/*   Updated: 2023/07/31 19:16:47 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_lst **fst_nd)
{
	t_lst	*head;
	t_lst	*tmp;

	if (!*fst_nd || !(*fst_nd)->next)
		return ;
	head = *fst_nd;
	tmp = head->next;
	head->next = tmp->next;
	tmp->next = head;
	*fst_nd = tmp;
}

void	ss(t_lst **a, t_lst **b)
{
	sa_sb(a);
	sa_sb(b);
}

void	pa_pb(t_lst **a, t_lst **b, int n)
{
	t_lst	*tmp;

	if ((!*b && !n) || (!*a && n))
		return ;
	if (n)
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
}

void	ra_rb(t_lst **fst_nd)
{
	t_lst	*tmp;

	if (!*fst_nd)
		return ;
	tmp = (*fst_nd)->next;
	lstlast(*fst_nd, 0)->next = *fst_nd;
	(*fst_nd)->next = NULL;
	*fst_nd = tmp;
}

void	rr(t_lst **a, t_lst **b)
{
	ra_rb(a);
	ra_rb(b);
}
