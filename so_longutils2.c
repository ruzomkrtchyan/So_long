/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longutils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:39:44 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/13 21:40:26 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = &s[i];
		i++;
	}
	if ((char)c == '\0')
		ptr = s + i;
	return ((char *)ptr);
}

static int	free_malloc(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
	return (0);
}

size_t	count_words(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	if (s[0] == '\0')
		count = 1;
	return (count);
}

int	fill(char **tmp, char *s, char c)
{
	int		i;
	int		j;
	int		m;

	i = 0;
	j = 0;
	m = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i] && ++j)
			i++;
		if (s[i - 1] != c)
			tmp[m++] = ft_substr(s, i - j, j);
		if (m != 0 && !tmp[m - 1])
			return (free_malloc(tmp));
		j = 0;
	}
	tmp[m] = NULL;
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**tmp;

	if (!s)
		return (NULL);
	tmp = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (tmp == NULL)
		return (NULL);
	if (fill(tmp, s, c) == 0)
		return (NULL);
	return (tmp);
}
