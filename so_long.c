/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:46:47 by modysseu          #+#    #+#             */
/*   Updated: 2022/01/06 19:57:52 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void)
{
	printf("Error: bad map design!\n");
	exit(0);
}

static int	pressing_the_red_cross(void)
{
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		checking_card_expansion(argv[1]);
		game.map = read_map(argv[1]);
		square_check(game.map.map);
		check_exit_and_player(game.map);
		border_check(game.map.map);
	}
	else
		exit (0);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx,
			game.map.width, game.map.height, "Wall-E");
	arrangement_of_pictures(game, -1);
	mlx_key_hook(game.mlx_win, &handling_keystrokes, &game);
	mlx_hook(game.mlx_win, 17, 0, &pressing_the_red_cross, &game);
	mlx_loop(game.mlx);
	exit (0);
}
