/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:19:34 by analexan          #+#    #+#             */
/*   Updated: 2023/07/24 18:46:24 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	// ps("intarr = { ");
	// while (*iarr)
	// {
	// 	pn(*iarr++);
	// 	if (*iarr)
	// 		ps(", ");
	// }
	// ps(" }");
	// write(1, "\n", 1);
void	push_swap(int *iarr)
{
	(void)iarr;
}

int	check_size_dup(int ac, char **av, int mode)
{
	long	*longarr;
	int		i;
	int		j;
	int		bol;

	bol = -1 * mode;
	if (!av[!mode][0])
		return (-1);
	longarr = malloc(sizeof(long) * (ac - !mode));
	if (!longarr)
		return (-1);
	i = bol;
	while (++i < ac)
		longarr[i - !bol] = stol(av[i]);
	i = bol;
	while (++i < ac)
	{
		j = i;
		while (longarr[j - !bol])
			if (longarr[i - !bol] > 2147483647 
				|| longarr[i - !bol] < -2147483648
				|| longarr[i - !bol] == longarr[++j - !bol])
				return (1);
	}
	free(longarr);
	return (0);
}

int	*check_error(int ac, char **av, int mode)
{
	int		i;
	int		j;
	int		*intarr;

	i = -1 * mode;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				return (NULL);
			j++;
		}
	}
	if (check_size_dup(ac, av, mode))
		return (NULL);
	intarr = malloc(sizeof(int) * (ac - !mode));
	if (!intarr)
		return (NULL);
	i = -1 * mode;
	while (++i < ac)
		intarr[i -1 * !mode] = stoi(av[i]);
	return (intarr);
}
/*
#include "functions.c"
#include "ft_split.c"
// make 0 work, idk if this is needed
	// ac = 2;
	// av[1] = "0\0";

	// ac = 2;
	// av[1] = "-2147483649";

	// t_lst	*a;
	// t_lst	*b;
	// a = NULL;
	// b = NULL;
*/

int	main(int ac, char **av)
{
	int		*iarr;
	char	*temp;
	int		mode;

	iarr = NULL;
	if (ac == 1)
		return (0);
	mode = 0;
	if (ac == 2)
	{
		temp = av[1];
		av = ft_split_m(temp, ' ', &ac);
		mode = 1;
	}
	if (av)
		iarr = check_error(ac, av, mode);
	if (!iarr)
		write(2, "Error\n", 6);
	else
		push_swap(iarr);
	return (0);
}
