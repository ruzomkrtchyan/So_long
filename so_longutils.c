/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:30:19 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/13 21:36:38 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*ptr;

	ptr = 0;
	if (s1 && set)
	{
		i = 0;
		start = 0;
		end = ft_strlen(s1);
		while (ft_strchr(set, s1[start]) && start < end)
			start++;
		while (ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		ptr = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!ptr)
			return (0);
		while (start < end)
			ptr[i++] = s1[start++];
		ptr[i] = '\0';
	}
	return (ptr);
}

int	ft_pow(int count)
{
	int	res;

	res = 1;
	while (count - 1)
	{
		res = res * 10;
		count--;
	}
	return (res);
}

char	*other(int n, int i, char *s, int count)
{
	if (n == 0)
	{	
		s[i++] = '0';
	}
	if (n == -2147483648)
	{
		s[i] = '-';
		s[i + 1] = '2';
		n = 147483648;
		i = i + 2;
		count--;
	}
	if (n < 0)
	{
		s[i++] = '-';
		n = -n;
	}
	while (count)
	{
		s[i++] = n / ft_pow(count) + '0';
		n = n % ft_pow(count);
		count--;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	int		i;
	int		count;
	int		tmp;
	char	*s;

	i = 0;
	count = 0;
	tmp = n;
	while (tmp)
	{
		tmp = tmp / 10;
		count ++;
	}
	if (n > 0)
		s = malloc(sizeof(char) * count + 1);
	else
		s = malloc(sizeof(char) * (count + 2));
	if (!s)
		return (NULL);
	s = other(n, i, s, count);
	return (s);
}
