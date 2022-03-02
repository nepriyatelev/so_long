/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 21:29:45 by modysseu          #+#    #+#             */
/*   Updated: 2022/01/06 20:20:21 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_walls(int i, int j, t_game game)
{
	if (i % 2 == 0 && j % 2 == 0)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_111, j * 80, i * 80);
	else if (j % 2 == 0)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_1, j * 80, i * 80);
	else if (j % 3 == 0)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_11, j * 80, i * 80);
	else
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_1111, j * 80, i * 80);
}

void	render_player(int i, int j, t_game game, int keycode)
{
	if (keycode == D)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_er, j * 80, i * 80);
	else if (keycode == A)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_el, j * 80, i * 80);
	else if (keycode == W)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_eb, j * 80, i * 80);
	else
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_ef, j * 80, i * 80);
}

void	render_exit(int i, int j, t_game game)
{
	if (game.map.coin > 0)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_e1, j * 80, i * 80);
	else if (game.map.coin == 0 && game.map.end != 1)
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_e2, j * 80, i * 80);
	else
	{
		game.map.map[game.map.player_y][game.map.player_x] = '0';
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_final, j * 80, i * 80);
		mlx_string_put(game.mlx, game.mlx_win, game.map.width / 2,
			0, 0x0C5249, "YOU WON!");
	}
}

void	render_enemy(int i, int j, t_game game)
{
	if (game.map.fire == 1)
	{	
		game.map.map[game.map.player_y][game.map.player_x] = '0';
		mlx_string_put(game.mlx, game.mlx_win, game.map.width / 2,
			0, 0x0C5249, "YOU LOSE!");
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_fire, j * 80, i * 80);
	}
	else
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.img.img_fire, j * 80, i * 80);
}
