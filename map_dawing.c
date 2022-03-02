/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:03:27 by modysseu          #+#    #+#             */
/*   Updated: 2022/01/06 20:57:50 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_coin(int i, int j, t_game game)
{
	mlx_put_image_to_window(game.mlx, game.mlx_win,
		game.img.img_c, j * 80, i * 80);
}

static void	render_background(int i, int j, t_game game)
{
	mlx_put_image_to_window(game.mlx, game.mlx_win,
		game.img.img_bg, j * 80, i * 80);
}

static void	render_steps(t_game game)
{
	char	*count;

	count = ft_itoa(game.map.count);
	mlx_string_put(game.mlx, game.mlx_win, 0, 0, 0x0C5249, count);
	free(count);
}

static void	arrangement_of_pictures2(int i, int j, t_game game, int keycode)
{
	if (game.map.map[i][j] == '!')
		render_enemy(i, j, game);
	if (game.map.map[i][j] == '1')
		render_walls(i, j, game);
	if (game.map.map[i][j] == 'P' && game.map.end != 1
		&& game.map.fire != 1)
		render_player(i, j, game, keycode);
	if (game.map.map[i][j] == 'C')
		render_coin(i, j, game);
	if (game.map.map[i][j] == 'E')
		render_exit(i, j, game);
}

void	arrangement_of_pictures(t_game game, int keycode)
{
	int		i;
	int		j;

	i = 0;
	game.img = initialization_of_pictures(game);
	while (game.map.map[i])
	{
		j = 0;
		while (game.map.map[i][j])
		{
			render_background(i, j, game);
			arrangement_of_pictures2(i, j, game, keycode);
			render_steps(game);
			j++;
		}
		i++;
	}
}
