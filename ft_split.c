/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:30:11 by analexan          #+#    #+#             */
/*   Updated: 2023/08/04 11:53:20 by analexan         ###   ########.fr       */
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

int	wordcount(char const *s, char c)
{
	int	i;
	int	wc;

	i = -1;
	wc = 0;
	while (s[++i])
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			wc++;
	return (wc);
}

char	**writestring(char const *s, char **strs, char c, int wc)
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
	if (*wc < 1)
		return (NULL);
	strs = malloc((*wc + 2) * sizeof(char *));
	if (!strs || !s)
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
#include <stdio.h>
int	main(void)
{
	char	str[] = "1 1";
	int wc = 0;
	char	**arr_of_arr = ft_split_m(str, ' ', &wc);
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
