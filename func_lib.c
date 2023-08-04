/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:16:37 by analexan          #+#    #+#             */
/*   Updated: 2023/08/04 13:04:04 by analexan         ###   ########.fr       */
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
		if (n == -2147483648)
		{
			write(1, "2", 1);
			n = -147483648;
		}
		n = -n;
	}
	if (n > 9)
		pn(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	ps(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	prt(char *string, ...)
{
	va_list	args;
	int		i;

	va_start(args, string);
	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == 'i')
				pn(va_arg(args, int));
			else if (string[i] == 's')
				ps(va_arg(args, char *));
			else if (string[i] == 'c')
				write(1, &"abcdefghijklmnopqrstu"[(va_arg(args, int)) - 97], 1);
			else if (string[i] == 'l')
				plh(va_arg(args, t_lst *));
			i++;
		}
		else
			write(1, &string[i++], 1);
	}
	va_end(args);
}
