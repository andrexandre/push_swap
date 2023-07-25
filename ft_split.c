/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:30:11 by analexan          #+#    #+#             */
/*   Updated: 2023/07/25 16:20:24 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strlcpy_m(char const *src, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(n + 1);
	if (!str)
		return (NULL);
	while (src[i] && i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static int	wordcount(char const *s, char c)
{
	int	i;
	int	wc;

	i = -1;
	wc = 0;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			wc++;
		if (s[i] == '-')
			i++;
	}
	return (wc);
}

static char	**writestring(char const *s, char **strs, char c, int wc)
{
	int	i;
	int	j;

	i = 0;
	strs[i] = ft_strlcpy_m("\0", 0);
	if (!strs[i])
		return (NULL);
	while (i < wc)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] && s[j] != c)
			j++;
		strs[i + 1] = ft_strlcpy_m(s, j);
		if (!strs[i + 1])
			return (NULL);
		s += j;
		i++;
	}
	strs[i + 1] = NULL;
	return (strs);
}

char	**ft_split_m(char const *s, char c, int *wc)
{
	char	**strs;
	int		i;

	i = -1;
	*wc = wordcount(s, c);
	strs = malloc((*wc + 2) * sizeof(char *));
	if (!strs || !s || *wc < 1)
	{
		free(strs);
		strs = NULL;
		return (NULL);
	}
	strs = writestring(s, strs, c, *wc);
	while (++i < *wc)
		if (!strs[i])
			return (NULL);
	(*wc)++;
	return (strs);
}

/*
#include <stdio.h>
int	main(void)
// int	main(int ac, char **av)
{
	// (void)ac;
	// char *str = av[1];
	char	str[] = "1 1";
	int sussus = 0;
	char	**arr_of_arr = ft_split_m(str, ' ', &sussus);
	int	i = -1;

	while (arr_of_arr[++i])
		printf("arr[%i]: '%s'\n", i, arr_of_arr[i]);
	i = -1;
	while (arr_of_arr[++i])
		free(arr_of_arr[i]);
	free(arr_of_arr);
	return (0);
}
*/
