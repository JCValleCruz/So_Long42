/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:06:34 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/22 17:31:39 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(void *g, int x, int y)
{
	t_game		*game;
	mlx_image_t	*sticker;

	game = (t_game *)g;
	sticker = mlx_texture_to_image(game->mlx, game->wall);
	if (!sticker)
		error(game);
	paste_sticker(game->image, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}

void	put_wallint(void *g, int x, int y)
{
	t_game		*game;
	mlx_image_t	*sticker;

	game = (t_game *)g;
	sticker = mlx_texture_to_image(game->mlx, game->wallint);
	if (!sticker)
		error(game);
	paste_sticker(game->image, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}

void	put_locked_exit(void *g, int x, int y)
{
	t_game		*game;
	mlx_image_t	*sticker;

	game = (t_game *)g;
	sticker = mlx_texture_to_image(game->mlx, game->locked_exit_t);
	if (!sticker)
		error(game);
	paste_sticker(game->image, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}

void	put_exit(void *g, int x, int y)
{
	t_game		*game;
	mlx_image_t	*sticker;

	game = (t_game *)g;
	sticker = mlx_texture_to_image(game->mlx, game->unlocked_exit_t);
	if (!sticker)
		error(game);
	paste_sticker(game->image, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}
