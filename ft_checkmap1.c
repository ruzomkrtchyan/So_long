/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:13:52 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/17 19:20:12 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_er(void)
{
	write(2, "Error file\n", 11);
	exit(1);
}

char	*ft_read(char *girq)
{
	int		fd;
	char	*line;
	char	*ej;

	line = NULL;
	ej = NULL;
	fd = open(girq, O_RDONLY);
	if (fd == -1)
		ft_er();
	while (1)
	{
		ej = get_next_line(fd);
		if (ej == NULL)
			break ;
		line = ft_strjoin(line, ej);
		free(ej);
	}
	if (!line)
		ft_er();
	close(fd);
	ej = ft_strtrim(line, "\n");
	free(line);
	return (ej);
}

void	ft_error0(char *m)
{
	if ((ft_strcmp(ft_strrchr(m, '.'), ".ber")) != 0)
	{
		write(2, "Error filename\n", 15);
		exit(1);
	}
}

char	**ft_error1(char *m)
{
	int		i;
	char	*line;
	char	**map;

	i = 0;
	map = NULL;
	ft_error0(m);
	line = ft_read(m);
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			write (2, "Error map\n", 10);
			exit (1);
		}
		i++;
	}
	map = ft_split(line, '\n');
	free(line);
	return (map);
}

void	ft_errors(char *title, t_game *game)
{
	char	**map;
	char	**new;

	game->mapik.n_collect = 0;
	game->mapik.n_exits = 0;
	game->mapik.n_players = 0;
	map = ft_error1(title);
	ft_error2(map);
	ft_error3(map, &game->mapik);
	if (game->mapik.n_collect < 1 || game->mapik.n_exits != 1
		|| game->mapik.n_players != 1)
	{
		write (2, "Error symbols5\n", 15);
		exit(1);
	}
	ft_error4(map);
	ft_coordinates(map, game);
	game->map = map;
	new = ft_mapcpy(map, game);
	flood_fill(new, game->size, game->mard);
}
