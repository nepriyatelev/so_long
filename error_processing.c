/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:49:11 by modysseu          #+#    #+#             */
/*   Updated: 2022/01/07 14:09:25 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	border_check2(char **map)
{
	int	i;
	int	j;
	int	k;
	int	h;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	k = 0;
	while (map[k])
	{
		h = 0;
		while (map[k][h])
		{
			if (map[k][j - 1] != '1' || map[i - 1][h] != '1')
				print_error();
			h++;
		}
		k++;
	}
}

void	checking_card_expansion(const char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[len - 1] != 'r' || argv[len - 2] != 'e'
		|| argv[len - 3] != 'b' || argv[len - 4] != '.')
	{	
		printf("Error: wrong map name!\n");
		exit(0);
	}
}

void	border_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][0] != '1' || map[0][j] != '1')
			{
				printf("Error: bad map design!\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	border_check2(map);
}

void	square_check(char **map)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	j = 0;
	while (map[0][j])
		j++;
	res = j;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (res != j)
		{
			printf("Error: bad map design!\n");
			exit(0);
		}
		i++;
	}
}

void	check_exit_and_player(t_map map)
{
	int	i;
	int	j;
	int	p;
	int	e;

	p = 0;
	e = 0;
	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'P')
				p++;
			if (map.map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p != 1 || e == 0 || map.coin == 0)
		print_error();
}
