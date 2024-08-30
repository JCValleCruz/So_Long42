/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:56:36 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/22 17:31:04 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_line_size(char **map)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '\n' && map[i][j] != '\0')
			{
				size = ft_strlen(map[i]);
				return (size);
			}
		}
		i++;
	}
	return (0);
}

void	ft_draw_background(void *g)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)g;
	x = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			put_background(game, x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw_walls(void *g)
{
	t_game	*gm;
	int		x;
	int		y;

	gm = (t_game *)g;
	x = 0;
	y = 0;
	while (y < gm->map_height)
	{
		x = 0;
		while (x < gm->map_width)
		{
			if ((gm->area[y][x] == WALL) && ((y == 0 || y == gm->map_height - 1)
				|| (x == 0 || x == gm->map_width - 1)))
				put_wall(gm, x, y);
			else if (gm->area[y][x] == WALL)
				put_wallint(gm, x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw_player(void *g)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)g;
	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->area[y][x] == PLAYER && game->n_collectables != 0)
				put_player(game, x, y);
			else if (game->area[y][x] == PLAYER && game->n_collectables == 0)
				put_finalplayer(game, x, y);
		}
	}
}

void	ft_draw_map_objects(void *g)
{
	t_game	*game;
	int		x;
	int		y;

	game = (t_game *)g;
	x = -1;
	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			if (game->area[y][x] == EXIT)
			{
				game->exit_x = x;
				game->exit_y = y;
			}
			if (game->area[y][x] == COL)
				put_collectable(game, x, y);
			if (game->area[y][x] == EXIT && game->n_collectables > 0)
				put_locked_exit(game, x, y);
			else if (game->area[y][x] == EXIT)
				put_exit(game, x, y);
		}
	}
}
