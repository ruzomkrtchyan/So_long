/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movcases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:00:57 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/17 18:46:13 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->image.jur);
	mlx_destroy_image(game->mlx_ptr, game->image.pat);
	mlx_destroy_image(game->mlx_ptr, game->image.pok);
	mlx_destroy_image(game->mlx_ptr, game->image.player);
	mlx_destroy_image(game->mlx_ptr, game->image.exit[0]);
	mlx_destroy_image(game->mlx_ptr, game->image.exit[1]);
	mlx_destroy_image(game->mlx_ptr, game->image.exit[2]);
	mlx_destroy_image(game->mlx_ptr, game->image.exit[3]);
	mlx_destroy_image(game->mlx_ptr, game->image.exit[4]);
	mlx_destroy_image(game->mlx_ptr, game->image.exit[5]);
	mlx_destroy_image(game->mlx_ptr, game->image.tshnami[0]);
	mlx_destroy_image(game->mlx_ptr, game->image.tshnami[1]);
	mlx_destroy_image(game->mlx_ptr, game->image.tshnami[2]);
	mlx_destroy_image(game->mlx_ptr, game->image.tshnami[3]);
}

void	ft_cases(t_game *game)
{
	if (game->map[game->mard.y][game->mard.x] == 'T'
	|| (game->map[game->mard.y][game->mard.x] == 'E'
	&& game->mapik.n_collect == 0))
	{
		ft_destroy(game);
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		exit (0);
	}	
	if (game->map[game->mard.y][game->mard.x] == 'C')
	{
		game->mapik.n_collect--;
		game->map[game->mard.y][game->mard.x] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->image.jur, game->mard.x * 48, game->mard.y * 48);
	}
}
