/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:43:16 by rmkrtchy          #+#    #+#             */
/*   Updated: 2023/05/17 19:12:04 by rmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "get_next_line.h"
# include <mlx.h>
# include "ft_printf.h"

typedef struct s_map
{
	int		w;
	int		h;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}				t_exit;

typedef struct s_maperrors
{
	int	n_players;
	int	n_tshnami;
	int	n_collect;
	int	n_exits;
}	t_maperrors;

typedef struct s_image
{
	int			image_w;
	int			image_h;
	void		*player;
	void		*pat;
	void		*pok;
	void		*tshnami[4];
	void		*exit[6];
	void		*jur;
}				t_image;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	int			qayl;
	char		*s;
	t_maperrors	mapik;
	t_image		image;
	t_map		size;
	t_player	mard;
	t_exit		exit;
}				t_game;

char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
char	**ft_mapcpy(char **map, t_game *game);
void	ft_errors(char *title, t_game *game);
char	**ft_error1(char *m);
void	ft_error2(char **map);
void	ft_error3(char **s, t_maperrors *mapik);
void	ft_error4(char **map);
void	ft_coordinates(char	**map, t_game *game);
void	fill_2(char **tab, t_map size, t_player cur);
void	flood_fill(char **new, t_map size, t_player mard);
void	ft_initgame(t_game *game);
void	ft_init_img(t_game *game);
void	ft_putimg(t_game *game, void *de);
int		ft_loxal(int command, t_game *game);
void	ft_cases(t_game *game);
void	ft_imgerr(t_game *game);
int		ft_animation(t_game *game);
void	ft_enemy_animation(t_game *game, void *de);
char	*ft_itoa(int n);
int		ft_blt(t_game *game);

#endif
