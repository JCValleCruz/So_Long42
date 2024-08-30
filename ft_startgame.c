/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startgame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:06:18 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/23 17:40:21 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_startgame(t_game game)
{
	mlx_t	*mlx;

	ft_getsizemap2(&game);
	mlx = mlx_init(160 * game.map_width, 160 * game.map_height, "Goblin", true);
	if (!mlx)
		exit_error("Error\nMLX", &game);
	game.image = mlx_new_image(mlx, mlx->width, mlx->height);
	game.mlx = mlx;
	ft_findcollectables(&game);
	mlx_key_hook(mlx, handle_key, &game);
	mlx_loop_hook(mlx, ft_draw, &game);
	mlx_loop(mlx);
	ft_finalgg_ok(&game);
}
