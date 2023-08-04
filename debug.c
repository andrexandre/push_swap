/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:56:14 by analexan          #+#    #+#             */
/*   Updated: 2023/08/04 13:04:14 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
