/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:15:51 by analexan          #+#    #+#             */
/*   Updated: 2023/07/31 19:19:56 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*lstlast(t_lst *head, int n)
{
	if (!head)
		return (NULL);
	if (!n)
		while (head->next)
			head = head->next;
	else
		while (head->next->next)
			head = head->next;
	return (head);
}

void	addfrt(t_lst **head, int n)
{
	t_lst	*node;

	node = malloc(sizeof(t_lst));
	if (!node)
		return ;
	node->data = n;
	if (*head)
		node->next = *head;
	else
		node->next = NULL;
	*head = node;
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

void	pl(t_lst *head)
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

void	freeall(t_lst *a, t_lst *b)
{
	t_lst	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	while (b)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
}
/*
int	main(void)
{
	t_lst	*lst;
	t_lst	*head;

	head = NULL;
	addfrt(&head, 123);
	addfrt(&head, 1);
	pl(head);
	while (head)
	{
		lst = head;
		head = head->next;
		free(lst);
	}
	return (0);
}
*/
