/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:04:41 by analexan          #+#    #+#             */
/*   Updated: 2023/08/09 18:23:52 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_lst **fst_nd, char c)
{
	t_lst	*tmp;

	if (c)
		prt("s%c\n", c);
	if (!*fst_nd || !(*fst_nd)->next)
		return ;
	tmp = (*fst_nd)->next;
	(*fst_nd)->next = (*fst_nd)->next->next;
	tmp->next = *fst_nd;
	*fst_nd = tmp;
	fill_am(*fst_nd);
}

void	ss(t_lst **a, t_lst **b)
{
	sa_sb(a, '\0');
	sa_sb(b, '\0');
	ps("ss\n");
}

// mode = 0: pa, mode = 1: pb
void	pa_pb(t_lst **a, t_lst **b, int mode)
{
	t_lst	*tmp;

	prt("p%c\n", "ab"[mode]);
	if ((!*b && !mode) || (!*a && mode))
		return ;
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
	fill_am(*a);
	fill_am(*b);
}

void	ra_rb(t_lst **fst_nd, char c)
{
	t_lst	*tmp;

	if (c)
		prt("r%c\n", c);
	if (!*fst_nd || !(*fst_nd)->next)
		return ;
	tmp = (*fst_nd)->next;
	lstlast(*fst_nd, 0)->next = *fst_nd;
	(*fst_nd)->next = NULL;
	*fst_nd = tmp;
	fill_am(*fst_nd);
}

void	rr(t_lst **a, t_lst **b)
{
	ra_rb(a, '\0');
	ra_rb(b, '\0');
	ps("rr\n");
}
