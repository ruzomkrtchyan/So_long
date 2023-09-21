/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:37:56 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/17 18:26:47 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_xachik(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	exit (0);
	return (0);
}

void	*ft_hey(t_game *game)
{
	static int	i = 0;
	static void	*esim;

	if (!esim)
		esim = game->image.tshnami[0];
	if (i % 30 == 0)
		esim = game->image.tshnami[1];
	if (i % 60 == 0)
		esim = game->image.tshnami[2];
	if (i % 90 == 0)
		esim = game->image.tshnami[3];
	i++;
	return (esim);
}

int	ft_animation(t_game *game)
{
	void	*de;

	de = NULL;
	de = ft_hey(game);
	ft_enemy_animation(game, de);
	if (game->mapik.n_collect == 0)
		ft_blt(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	int			i;

	i = 0;
	game.qayl = 0;
	if (argc != 2)
		return (0);
	else
	{
		ft_errors(argv[1], &game);
		ft_initgame(&game);
		ft_putimg(&game, game.image.tshnami[0]);
		mlx_string_put(game.mlx_ptr, game.mlx_win, 8, 12, 0xFFFFFF, "0");
		mlx_hook(game.mlx_win, 2, 0, ft_loxal, &game);
		mlx_loop_hook(game.mlx_ptr, &ft_animation, &game);
		mlx_hook(game.mlx_win, 17, 0, ft_xachik, &game);
		mlx_loop(game.mlx_ptr);
	}
}
