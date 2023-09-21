/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:00:25 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/17 19:22:36 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verev(t_game *game)
{
	if (game->map[game->mard.y - 1][game->mard.x] == '1')
		return ;
	game->qayl++;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->image.jur, game->mard.x * 48, game->mard.y * 48);
	game->mard.y--;
	ft_cases(game);
	if (game->map[game->mard.y + 1][game->mard.x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->image.exit[0], game->mard.x * 48, (game->mard.y + 1) * 48);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->image.player,
		game->mard.x * 48, game->mard.y * 48);
}

void	ft_aj(t_game *game)
{
	if (game->map[game->mard.y][game->mard.x + 1] == '1')
		return ;
	game->qayl++;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->image.jur, game->mard.x * 48, game->mard.y * 48);
	game->mard.x++;
	ft_cases(game);
	if (game->map[game->mard.y][game->mard.x - 1] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->image.exit[0], (game->mard.x - 1) * 48, game->mard.y * 48);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->image.player,
		game->mard.x * 48, game->mard.y * 48);
}

void	ft_dzax(t_game *game)
{
	if (game->map[game->mard.y][game->mard.x - 1] == '1')
		return ;
	game->qayl++;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->image.jur, game->mard.x * 48, game->mard.y * 48);
	game->mard.x--;
	ft_cases(game);
	if (game->map[game->mard.y][game->mard.x + 1] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->image.exit[0], (game->mard.x + 1) * 48, game->mard.y * 48);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->image.player,
		game->mard.x * 48, game->mard.y * 48);
}

void	ft_nerqev(t_game *game)
{
	if (game->map[game->mard.y + 1][game->mard.x] == '1')
		return ;
	game->qayl++;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->image.jur, game->mard.x * 48, game->mard.y * 48);
	game->mard.y++;
	ft_cases(game);
	if (game->map[game->mard.y - 1][game->mard.x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->image.exit[0], game->mard.x * 48, (game->mard.y - 1) * 48);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->image.player,
		game->mard.x * 48, game->mard.y * 48);
}

int	ft_loxal(int command, t_game *game)
{
	if (command == 126 || command == 13)
		ft_verev(game);
	if (command == 124 || command == 2)
		ft_aj(game);
	if (command == 123 || command == 0)
		ft_dzax(game);
	if (command == 125 || command == 1)
		ft_nerqev(game);
	if (command == 53)
		exit (0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->image.jur, 0 * 48, 0 * 48 * 1024 + 2 * 0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->image.pat, 0 * 48, 0 * 48 * 1024 + 2 * 0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->image.jur, 1 * 48, 0 * 48 * 1024 + 2 * 0);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->image.pat, 1 * 48, 0 * 48 * 1024 + 2 * 0);
	game->s = ft_itoa(game->qayl);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 8, 12, 0xFFFFFF, game->s);
	free(game->s);
	return (0);
}
