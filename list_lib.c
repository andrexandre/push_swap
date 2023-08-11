/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:15:51 by analexan          #+#    #+#             */
/*   Updated: 2023/08/11 12:36:45 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smallest(int node_data, t_lst *lst)
{
	while (lst)
	{
		if (lst->data < node_data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_biggest(int node_data, t_lst *lst)
{
	while (lst)
	{
		if (lst->data > node_data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

// fill the list with the correct index, above_median and push_price
void	fill_list(t_lst *lst)
{
	int		i;
	int		len;

	if (!lst)
		return ;
	len = lstlen(lst);
	i = -1;
	while (++i < len)
	{
		lst->index = i;
		if (i <= len / 2)
			lst->above_median = 1;
		else
			lst->above_median = 0;
		if (lst->above_median)
			lst->push_price = i;
		else
			lst->push_price = len - i;
		if (lst->next)
			lst = lst->next;
	}
}

// mode = 0: fill a based on b; mode = 1: fill b based on a
void	fill_node_price(t_lst *a, t_lst *b, int mode)
{
	t_lst	*target;
	int		len;
	int		i;

	target = NULL;
	if (!a || !b)
		return ;
	i = -1;
	if (!mode)
		len = lstlen(a);
	else
		len = lstlen(b);
	while (!mode && ++i < len)
	{
		if (is_smallest(a->data, b) || is_biggest(a->data, b))
			target = find_target(b, 1, 0);
		else
			target = find_target(b, 2, a->data);
		a->node_price = a->push_price + target->push_price;
		if (a->next)
			a = a->next;
	}
	i = -1;
	while (mode && ++i < len)
	{
		if (is_smallest(a->data, b) || is_biggest(a->data, b))
			target = find_target(b, 1, 0);
		else
			target = find_target(a, 2, b->data);
		b->node_price = b->push_price + target->push_price;
		if (b->next)
			b = b->next;
	}
}

// mode = 0: smallest; = 1: biggest; = 2: between node_data;
// if 0 or 1, node_data is used to check if its a or b
t_lst	*find_target(t_lst *lst, int mode, int node_data)
{
	t_lst	*target;
	t_lst	*last;

	target = lst;
	if (!mode)
	{
		while (lst->next)
		{
			if (lst->data < target->data)
				target = lst;
			lst = lst->next;
		}
		if (lst->data < target->data)
			target = lst;
	}
	else if (mode == 1)
	{
		while (lst->next)
		{
			if (lst->data > target->data)
				target = lst;
			lst = lst->next;
		}
		if (lst->data > target->data)
			target = lst;
	}
	else if (mode == 2)
	{
		last = lstlast(lst, 0);
		while (lst->next && !(same(last->data, node_data, lst->data)))
			lst = lst->next;
		return (lst);
	}
	return (target);
}
/*
int	main(void)
{
	t_lst	*lst;
	t_lst	*head;

	head = NULL;
	addfrt(&head, 123);
	addfrt(&head, 1);
	plh(head);
	while (head)
	{
		lst = head;
		head = head->next;
		free(lst);
	}
	return (0);
}
*/
