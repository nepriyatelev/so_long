/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:46:56 by modysseu          #+#    #+#             */
/*   Updated: 2022/01/06 19:51:05 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define ESC 53
# define W 13
# define D 2
# define S 1
# define A 0

# define IMG_EVE_FRONT "./asset/Eve_front.xpm"
# define IMG_EVE_RIGHT "./asset/Eve_right.xpm"
# define IMG_EVE_LEFT "./asset/Eve_left.xpm"
# define IMG_EVE_BACK "./asset/Eve_back.xpm"
# define IMG_C "./asset/Present.xpm"
# define IMG_1 "./asset/Stone.xpm"
# define IMG_11 "./asset/Stone1.xpm"
# define IMG_111 "./asset/Stone2.xpm"
# define IMG_1111 "./asset/Stone3.xpm"
# define IMG_E1 "./asset/Wall-e1.xpm"
# define IMG_E2 "./asset/Wall-e2.xpm"
# define IMG_FINAL "./asset/Final.xpm"
# define IMG_FIRE "./asset/Fire.xpm"
# define IMG_BG "./asset/Background.xpm"

typedef struct img
{
	void	*img_ef;
	void	*img_er;
	void	*img_el;
	void	*img_eb;
	void	*img_c;
	void	*img_1;
	void	*img_11;
	void	*img_111;
	void	*img_1111;
	void	*img_e1;
	void	*img_e2;
	void	*img_final;
	void	*img_fire;
	void	*img_bg;
	int		width;
	int		height;
}		t_img;

typedef struct map
{
	char	**map;
	int		player_x;
	int		player_y;
	int		count;
	int		coin;
	int		width;
	int		height;
	int		end;
	int		fire;
}		t_map;

typedef struct game
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_map	map;
}		t_game;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);

void	render_walls(int i, int j, t_game game);
void	render_player(int i, int j, t_game game, int keycode);
void	render_exit(int i, int j, t_game game);
void	render_enemy(int i, int j, t_game game);

t_map	read_map(char	*argv);

void	checking_card_expansion(const char *argv);
void	border_check(char **map);
void	square_check(char **map);
void	check_exit_and_player(t_map map);
void	print_error(void);

void	arrangement_of_pictures(t_game game, int keycode);

t_img	initialization_of_pictures(t_game game);

int		handling_keystrokes(int keycode, t_game *game);

#endif