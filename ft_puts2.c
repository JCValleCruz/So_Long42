/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:51:15 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/22 17:31:43 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(void *g, int x, int y)
{
	t_game		*game;
	mlx_image_t	*sticker;

	game = (t_game *)g;
	sticker = mlx_texture_to_image(game->mlx, game->player_texture);
	if (!sticker)
		error(game);
	paste_sticker(game->image, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}

void	put_finalplayer(void *g, int x, int y)
{
	t_game		*game;
	mlx_image_t	*sticker;

	game = (t_game *)g;
	sticker = mlx_texture_to_image(game->mlx, game->finalplayer_texture);
	if (!sticker)
		error(game);
	paste_sticker(game->image, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}

void	put_background(void *g, int x, int y)
{
	t_game		*game;
	mlx_image_t	*sticker;

	game = (t_game *)g;
	sticker = mlx_texture_to_image(game->mlx, game->background);
	if (!sticker)
		error(game);
	paste_sticker(game->image, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}

void	put_collectable(void *g, int x, int y)
{
	t_game		*game;
	mlx_image_t	*sticker;

	game = (t_game *)g;
	sticker = mlx_texture_to_image(game->mlx, game->collectable);
	if (!sticker)
		error(game);
	paste_sticker(game->image, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}
