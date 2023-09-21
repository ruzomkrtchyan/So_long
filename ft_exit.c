/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:16:04 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/13 19:38:24 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_anim
{
	int	j1;	
	int	j2;	
	int	j3;	
	int	j4;	
	int	j5;	
}	t_anim;

void	*ft_ex(t_game *game)
{
	static t_anim	ban;
	static void		*blt = NULL;

	if (!blt)
		blt = game->image.exit[0];
	if (ban.j1++ % 15 == 0)
		blt = game->image.exit[1];
	if (ban.j2++ % 30 == 0)
		blt = game->image.exit[2];
	if (ban.j3++ % 45 == 0)
		blt = game->image.exit[3];
	if (ban.j4++ % 60 == 0)
		blt = game->image.exit[4];
	if (ban.j5++ % 75 == 0)
		blt = game->image.exit[5];
	return (blt);
}

void	ft_exitanim(t_game *game, void *blt)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					game->image.jur, j * 48, i * 48);
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
					blt, j * 48, i * 48);
			}
			j++;
		}
		i++;
	}
}

int	ft_blt(t_game *game)
{
	void	*blt;

	blt = ft_ex(game);
	ft_exitanim(game, blt);
	return (0);
}
