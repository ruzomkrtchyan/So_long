/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:37:14 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/17 19:00:43 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error5(int n, char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (map[i][0] == '1' && map[i][n - 1] == '1')
			i++;
		else
		{
			write (2, "Error symbols2\n", 15);
			exit (1);
		}
	}
	n = 0;
	while (map[i - 1][n])
	{
		if (map[i - 1][n] == '1')
			n++;
		else
		{
			write (2, "Error symbols3\n", 15);
			exit (1);
		}
	}
}

void	ft_error4(char **map)
{
	int	n;

	n = 0;
	while (map[0][n] == '1' && map[0][n])
		n++;
	if (map[0][n] != '\0')
	{
		write (2, "Error symbols\n", 14);
		exit (1);
	}
	ft_error5(n, map);
}

char	**ft_mapcpy(char **map, t_game *game)
{
	int		i;
	char	**new;

	i = 0;
	new = (char **)malloc((game->size.h + 1) * sizeof(char *));
	if (!new)
		return (0);
	while (map[i])
	{
		new[i] = ft_strdup(map[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	ft_error2(char **map)
{
	int	i;

	i = 0;
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) == ft_strlen(map[i + 1]))
			i++;
		else
		{
			write(2, "Error size\n", 11);
			exit (1);
		}
	}
}

void	ft_error3(char **s, t_maperrors *mapik)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && s)
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'C')
				mapik->n_collect++;
			else if (s[i][j] == 'E')
				mapik->n_exits++;
			else if (s[i][j] == 'P')
				mapik->n_players++;
			else if (s[i][j] != '1' && s[i][j] != '0' && s[i][j] != 'T')
			{
				write (2, "Error symbols1\n", 15);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
