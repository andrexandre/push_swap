/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:16:37 by analexan          #+#    #+#             */
/*   Updated: 2023/07/21 16:22:18 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	stol(char *str)
{
	long	n;
	int		mc;

	mc = 1 - 2 * (*str == '-' && *str++);
	n = 0;
	while (*str)
		n = n * 10 + *str++ - 48;
	return (n * mc);
}

int	stoi(char *str)
{
	int		n;
	int		mc;

	mc = 1 - 2 * (*str == '-' && *str++);
	n = 0;
	while (*str)
		n = n * 10 + *str++ - 48;
	return (n * mc);
}

void	pn(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == INT_MIN)
		{
			write(1, "2", 1);
			n = -147483648;
		}
		n = -n;
	}
	if (n > 9)
		pn(n / 10);
	if (n == 0)
		write(1, "0", 1);
	else
		write(1, &"0123456789"[n % 10], 1);
}

void	ps(char *str)
{
	while (*str)
		write(1, str++, 1);
}
