/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:32:00 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/23 17:36:07 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->area[new_y][new_x] != '1')
	{
		if (game->area[new_y][new_x] == 'C')
			game->n_collectables--;
		if (game->area[new_y][new_x] != 'E')
		{
			game->area[game->playery][game->playerx] = '0';
			game->area[new_y][new_x] = 'P';
			game->playerx = new_x;
			game->playery = new_y;
		}
		if (game->area[new_y][new_x] == 'E' && game->n_collectables == 0)
		{
			game->area[game->playery][game->playerx] = '0';
			game->area[new_y][new_x] = 'P';
			game->playerx = new_x;
			game->playery = new_y;
		}
		if (game->playery == game->exit_y && game->playerx
			== game->exit_x && game->n_collectables == 0)
			if (game->n_collectables == 0)
				ft_finalgg_ok(game);
		game->move_count++;
	}
}

void	handle_key(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_findplayer(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_finalgg_ok(game);
	else if ((keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS))
		move_player(game, game->playerx, game->playery - 1);
	else if ((keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS))
		move_player(game, game->playerx, game->playery + 1);
	else if ((keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS))
		move_player(game, game->playerx - 1, game->playery);
	else if ((keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS))
		move_player(game, game->playerx + 1, game->playery);
}
