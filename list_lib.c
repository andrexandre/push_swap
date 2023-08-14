/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:15:51 by analexan          #+#    #+#             */
/*   Updated: 2023/08/14 19:35:36 by analexan         ###   ########.fr       */
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
	int	i;
	int	len;

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

// fill the node_price of a based on target b
t_lst	*fill_node_price(t_lst *a, t_lst *b)
{
	t_lst	*target;
	t_lst	*cheapest;

	if (!a || !b)
		return (a);
	cheapest = a;
	while (a)
	{
		if (is_smallest(a->data, b) || is_biggest(a->data, b))
			target = find_target(b, 1, 0);
		else
			target = find_target(b, 3, a->data);
		a->target = target;
		a->node_price = a->push_price + target->push_price;
		if (a->node_price < cheapest->node_price)
			cheapest = a;
		a = a->next;
	}
	return (cheapest);
}
/*
100/1000
612
613
// max 701
500/200
5479
// max more than 5500
*/
// mode = 0: smallest; = 1: biggest; = 2: 1st between node_data
// from smallest; = 3: 1st between node_data from biggest;
// this has TOO_MANY_LINES
t_lst	*find_target(t_lst *lst, int mode, int node_data)
{
	t_lst	*temp;

	temp = lst;
	if (!mode || mode == 1)
	{
		while (lst)
		{
			if (!mode && lst->data < temp->data)
				temp = lst;
			else if (mode == 1 && lst->data > temp->data)
				temp = lst;
			lst = lst->next;
		}
	}
	else if (mode == 2 || mode == 3)
	{
		if (mode == 2)
		{
			if (lst->data > node_data && node_data > lstlast(lst, 0)->data)
				return (lst);		
			while (lst->next && !(lst->data < node_data 
					&& node_data < lst->next->data))
				lst = lst->next;
		}
		else if (mode == 3)
		{
			if (lst->data < node_data && node_data < lstlast(lst, 0)->data)
				return (lst);
			while (lst->next && !(lst->data > node_data 
					&& node_data > lst->next->data))
				lst = lst->next;
		}
		temp = lst->next;
	}
	return (temp);
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
