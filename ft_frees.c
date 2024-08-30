/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:31:37 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/22 20:30:02 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *g)
{
	if (g->loaded_txt == 1)
	{
		mlx_delete_texture(g->unlocked_exit_t);
		mlx_delete_texture(g->collectable);
		mlx_delete_texture(g->locked_exit_t);
		mlx_delete_texture(g->background);
		mlx_delete_texture(g->wall);
		mlx_delete_texture(g->player_texture);
		mlx_delete_texture(g->wallint);
		mlx_delete_texture(g->finalplayer_texture);
	}
	if (g->area)
		free_split(g->area);
	if (g->clonearea)
		free_split(g->clonearea);
	g = NULL;
	exit(1);
}

void	ft_finalgg(t_game *game)
{
	free(game->readmap);
	mlx_terminate(game->mlx);
	mlx_close_window(game->mlx);
	free_game_ok(game);
}

void	free_game_ok(t_game *g)
{
	if (g->loaded_txt == 1)
	{
		mlx_delete_texture(g->unlocked_exit_t);
		mlx_delete_texture(g->collectable);
		mlx_delete_texture(g->locked_exit_t);
		mlx_delete_texture(g->background);
		mlx_delete_texture(g->wall);
		mlx_delete_texture(g->player_texture);
		mlx_delete_texture(g->wallint);
		mlx_delete_texture(g->finalplayer_texture);
	}
	if (g->area)
		free_split(g->area);
	if (g->clonearea)
		free_split(g->clonearea);
	g = NULL;
}

void	ft_finalgg_ok(t_game *game)
{
	free_game_ok(game);
	mlx_terminate(game->mlx);
	mlx_close_window(game->mlx);
	exit(0);
}
