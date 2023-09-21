/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:22:45 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/12 16:41:56 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_coordinates(char	**map, t_game *game)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (map[i])
		i++;
	game->size.h = i;
	game->size.w = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		while (map[i][n] != 'P' && map[i][n])
			n++;
		if (map[i][n] == 'P')
		{
			game->mard.x = n;
			game->mard.y = i;
			return ;
		}
		i++;
		n = 0;
	}
}

void	fill_2(char **tab, t_map size, t_player mard)
{
	if (mard.y < 0 || mard.y >= size.h || mard.x < 0 || mard.x >= size.w
		|| (tab[mard.y][mard.x] != 'P' && tab[mard.y][mard.x] != 'C'
		&& tab[mard.y][mard.x] != 'E' && tab[mard.y][mard.x] != '0'))
		return ;
	tab[mard.y][mard.x] = 'F';
	fill_2(tab, size, (t_player){mard.x - 1, mard.y});
	fill_2(tab, size, (t_player){mard.x + 1, mard.y});
	fill_2(tab, size, (t_player){mard.x, mard.y - 1});
	fill_2(tab, size, (t_player){mard.x, mard.y + 1});
}

void	flood_fill(char **new, t_map size, t_player mard)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	fill_2(new, size, mard);
	while (new[n])
	{
		i = 0;
		while (new[n][i])
		{
			if (new[n][i] == 'E' || new[n][i] == 'P' || new[n][i] == 'C')
			{
				write (2, "Error map\n", 10);
				exit(1);
			}
			i++;
		}
		free(new[n]);
		n++;
	}
	free(new);
}
