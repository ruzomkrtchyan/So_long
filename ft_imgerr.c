/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgerr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:34:33 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/13 20:11:16 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_imgerr(t_game *game)
{
	if (!game->image.player || !game->image.pat
		|| !game->image.pok || !game->image.tshnami[0] || !game->image.exit[0]
		|| !game->image.exit[1] || !game->image.exit[2] || !game->image.exit[3]
		|| !game->image.exit[4] || !game->image.exit[5] || !game->image.jur
		|| !game->image.tshnami[1] || !game->image.tshnami[2]
		|| !game->image.tshnami[3])
	{
		write (1, "Images error\n", 13);
		exit(1);
	}
}
