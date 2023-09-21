/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:34:47 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/13 19:46:43 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initexit(t_game *game)
{
	game->image.exit[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/Ex1.xpm", &game->image.image_w, &game->image.image_h);
	game->image.exit[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/Ex2.xpm", &game->image.image_w, &game->image.image_h);
	game->image.exit[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/Ex3.xpm", &game->image.image_w, &game->image.image_h);
	game->image.exit[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/Ex4.xpm", &game->image.image_w, &game->image.image_h);
	game->image.exit[4] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/Ex5.xpm", &game->image.image_w, &game->image.image_h);
	game->image.exit[5] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/Ex6.xpm", &game->image.image_w, &game->image.image_h);
}

void	ft_init_img(t_game *game)
{
	game->image.image_w = 48;
	game->image.image_h = 48;
	game->image.player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/Arie.xpm", &game->image.image_w, &game->image.image_h);
	game->image.pat = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/cutexot.xpm", &game->image.image_w, &game->image.image_h);
	game->image.pok = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/Pokik.xpm", &game->image.image_w, &game->image.image_h);
	game->image.tshnami[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/81.xpm", &game->image.image_w, &game->image.image_h);
	game->image.tshnami[1] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/82.xpm", &game->image.image_w, &game->image.image_h);
	game->image.tshnami[2] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/83.xpm", &game->image.image_w, &game->image.image_h);
	game->image.tshnami[3] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/84.xpm", &game->image.image_w, &game->image.image_h);
	game->image.jur = mlx_xpm_file_to_image(game->mlx_ptr,
			"./pics/jrik.xpm", &game->image.image_w, &game->image.image_h);
	ft_initexit(game);
}

void	ft_enemy_animation(t_game *game, void *de)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'T')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->image.jur, j * 48, i * 48);
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					de, j * 48, i * 48);
			}
		}
	}
}

void	ft_putimg2(t_game *game, int w, int h, void *de)
{
	if (game->map[h][w] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->image.pok, w * 48, h * 48);
	if (game->map[h][w] == 'T')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			de, w * 48, h * 48);
	if (game->map[h][w] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->image.exit[0], w * 48, h * 48);
}

void	ft_putimg(t_game *game, void *de)
{
	int	h;
	int	w;

	h = 0;
	while (game->map[h])
	{
		w = 0;
		while (game->map[h][w])
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->image.jur, w * 48, h * 48);
			if (game->map[h][w] == 'P')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->image.player, w * 48, h * 48);
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->image.pat, w * 48, h * 48);
			ft_putimg2(game, w, h, de);
			w++;
		}
		h++;
	}
}
