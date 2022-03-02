/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_keystrokes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:56:26 by modysseu          #+#    #+#             */
/*   Updated: 2022/01/06 20:56:47 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	upward_movement(t_map *map)
{
	if (map->map[map->player_y - 1][map->player_x] == '!')
		map->fire = 1;
	if (map->map[map->player_y - 1][map->player_x] == 'E' && map->coin == 0)
		map->end = 1;
	if (map->map[map->player_y - 1][map->player_x] != '1'
		&& map->map[map->player_y - 1][map->player_x] != 'E'
		&& map->map[map->player_y - 1][map->player_x] != '!')
	{
		if (map->map[map->player_y - 1][map->player_x] == 'C')
			map->coin--;
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y - 1][map->player_x] = 'P';
		map->player_y -= 1;
		printf("%d\n", ++map->count);
	}
}

static void	downward_movement(t_map *map)
{
	if (map->map[map->player_y + 1][map->player_x] == '!')
		map->fire = 1;
	if (map->map[map->player_y + 1][map->player_x] == 'E' && map->coin == 0)
		map->end = 1;
	if (map->map[map->player_y + 1][map->player_x] != '1'
		&& map->map[map->player_y + 1][map->player_x] != 'E'
		&& map->map[map->player_y + 1][map->player_x] != '!')
	{
		if (map->map[map->player_y + 1][map->player_x] == 'C')
			map->coin--;
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y + 1][map->player_x] = 'P';
		map->player_y += 1;
		printf("%d\n", ++map->count);
	}
}

static void	movement_to_the_left(t_map *map)
{
	if (map->map[map->player_y][map->player_x - 1] == '!')
		map->fire = 1;
	if (map->map[map->player_y][map->player_x - 1] == 'E' && map->coin == 0)
		map->end = 1;
	if (map->map[map->player_y][map->player_x - 1] != '1'
		&& map->map[map->player_y][map->player_x - 1] != 'E'
		&& map->map[map->player_y][map->player_x - 1] != '!')
	{
		if (map->map[map->player_y][map->player_x - 1] == 'C')
			map->coin--;
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y][map->player_x - 1] = 'P';
		map->player_x -= 1;
		printf("%d\n", ++map->count);
	}
}

static void	movement_to_the_right(t_map *map)
{
	if (map->map[map->player_y][map->player_x + 1] == '!')
		map->fire = 1;
	if (map->map[map->player_y][map->player_x + 1] == 'E' && map->coin == 0)
		map->end = 1;
	if (map->map[map->player_y][map->player_x + 1] != '1'
		&& map->map[map->player_y][map->player_x + 1] != 'E'
		&& map->map[map->player_y][map->player_x + 1] != '!')
	{
		if (map->map[map->player_y][map->player_x + 1] == 'C')
			map->coin--;
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y][map->player_x + 1] = 'P';
		map->player_x += 1;
		printf("%d\n", ++map->count);
	}
}

int	handling_keystrokes(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit (0);
	else if (keycode == W && game->map.end != 1
		&& game->map.fire != 1)
		upward_movement(&game->map);
	else if (keycode == D && game->map.end != 1
		&& game->map.fire != 1)
		movement_to_the_right(&game->map);
	else if (keycode == S && game->map.end != 1
		&& game->map.fire != 1)
		downward_movement(&game->map);
	else if (keycode == A && game->map.end != 1
		&& game->map.fire != 1)
		movement_to_the_left(&game->map);
	arrangement_of_pictures(*game, keycode);
	return (0);
}
