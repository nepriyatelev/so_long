/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:27:29 by modysseu          #+#    #+#             */
/*   Updated: 2022/01/07 14:15:16 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' &&
				map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '!')
				print_error();
			j++;
		}
		i++;
	}
}

static int	map_width(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int	map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static t_map	position_player(char **map, t_map position)
{
	int	i;
	int	j;
	int	coin;

	i = 0;
	coin = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				position.player_x = j;
				position.player_y = i;
			}
			if (map[i][j] == 'C')
				coin++;
			j++;
		}
		i++;
	}
	check_char(map);
	position.coin = coin;
	return (position);
}

t_map	read_map(char	*argv)
{
	int		fd;
	char	*buf;
	char	*tmp;
	t_map	map;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit(0);
	buf = (char *)malloc(2 * sizeof(char));
	if (!buf)
		exit(0);
	tmp = NULL;
	buf[1] = '\0';
	while (read(fd, &buf[0], 1) > 0)
		tmp = ft_strjoin(tmp, buf);
	free(buf);
	map.map = ft_split(tmp, '\n');
	free(tmp);
	map.height = map_height(map.map) * 80;
	map.width = map_width(map.map[0]) * 80;
	map = position_player(map.map, map);
	map.count = 0;
	map.end = 0;
	map.fire = 0;
	return (map);
}
