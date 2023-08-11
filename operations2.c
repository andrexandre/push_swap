/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:04:41 by analexan          #+#    #+#             */
/*   Updated: 2023/08/10 16:39:59 by analexan         ###   ########.fr       */
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
	fill_list(*fst_nd);
}

void	rrr(t_lst **a, t_lst **b)
{
	rra_rrb(a, '\0');
	rra_rrb(b, '\0');
	ps("rrr\n");
}

// mode = 0: last one, mode = 1: one before last
t_lst	*lstlast(t_lst *head, int mode)
{
	if (!head)
		return (NULL);
	if (!mode)
		while (head->next)
			head = head->next;
	else
		while (head->next->next)
			head = head->next;
	return (head);
}

void	addbck(t_lst **head, int n)
{
	t_lst	*node;
	t_lst	*temp;

	node = malloc(sizeof(t_lst));
	if (!node)
		return ;
	node->data = n;
	node->next = NULL;
	temp = lstlast(*head, 0);
	if (!*head)
		*head = node;
	else
		temp->next = node;
}

int	check_sort(t_lst *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}
