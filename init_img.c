/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modysseu <modysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:48:22 by modysseu          #+#    #+#             */
/*   Updated: 2022/01/06 19:55:37 by modysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	initialization_of_pictures_2(t_game game, t_img img)
{
	img.img_ef = mlx_xpm_file_to_image(game.mlx,
			IMG_EVE_FRONT, &img.width, &img.height);
	img.img_c = mlx_xpm_file_to_image(game.mlx,
			IMG_C, &img.width, &img.height);
	img.img_er = mlx_xpm_file_to_image(game.mlx,
			IMG_EVE_RIGHT, &img.width, &img.height);
	img.img_el = mlx_xpm_file_to_image(game.mlx,
			IMG_EVE_LEFT, &img.width, &img.height);
	img.img_eb = mlx_xpm_file_to_image(game.mlx,
			IMG_EVE_BACK, &img.width, &img.height);
	img.img_1 = mlx_xpm_file_to_image(game.mlx,
			IMG_1, &img.width, &img.height);
	return (img);
}

t_img	initialization_of_pictures(t_game game)
{
	t_img	img;

	img.img_11 = mlx_xpm_file_to_image(game.mlx,
			IMG_11, &img.width, &img.height);
	img.img_111 = mlx_xpm_file_to_image(game.mlx,
			IMG_111, &img.width, &img.height);
	img.img_1111 = mlx_xpm_file_to_image(game.mlx,
			IMG_1111, &img.width, &img.height);
	img.img_e1 = mlx_xpm_file_to_image(game.mlx,
			IMG_E1, &img.width, &img.height);
	img.img_e2 = mlx_xpm_file_to_image(game.mlx,
			IMG_E2, &img.width, &img.height);
	img.img_bg = mlx_xpm_file_to_image(game.mlx,
			IMG_BG, &img.width, &img.height);
	img.img_final = mlx_xpm_file_to_image(game.mlx,
			IMG_FINAL, &img.width, &img.height);
	img.img_fire = mlx_xpm_file_to_image(game.mlx,
			IMG_FIRE, &img.width, &img.height);
	img = initialization_of_pictures_2(game, img);
	return (img);
}
