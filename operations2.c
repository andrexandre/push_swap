/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:04:41 by analexan          #+#    #+#             */
/*   Updated: 2023/08/04 12:58:05 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_lst **fst_nd, char c)
{
	t_lst	*last;

	if (c)
		prt("rr%c\n", c);
	if (!*fst_nd || !(*fst_nd)->next)
		return ;
	last = lstlast(*fst_nd, 1);
	last->next->next = *fst_nd;
	*fst_nd = last->next;
	last->next = NULL;
}

void	rrr(t_lst **a, t_lst **b)
{
	rra_rrb(a, '\0');
	rra_rrb(b, '\0');
	ps("rrr\n");
}

int	smallest(int n, t_lst *lst)
{
	int	i;

	i = 1;
	while (lst)
	{
		if (lst->data < n)
		{
			i = 0;
			break ;
		}
		else
			lst = lst->next;
	}
	return (i);
}

int	biggest(int n, t_lst *lst)
{
	int	i;

	i = 1;
	while (lst)
	{
		if (lst->data > n)
		{
			i = 0;
			break ;
		}
		else
			lst = lst->next;
	}
	return (i);
}

void	fill_am(t_lst *lst, int len)
{
	int	i;
	
	i = 0;
	while (i <= len / 2)
	{
		lst->above_median = 0;
		lst = lst->next;
		i++;
	}
	while (i < len)
	{
		lst->above_median = 1;
		if (lst->next)
			lst = lst->next;
		i++;
	}
}
