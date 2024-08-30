/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:12:00 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/22 20:27:48 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkchar(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->area[y])
	{
		x = 0;
		while (game->area[y][x])
		{
			if (game->area[y][x] != 'P' && game->area[y][x] != 'E'
				&& game->area[y][x] != 'C' && game->area[y][x] != '0'
					&& game->area[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_checkparam(t_game *game)
{
	int		y;
	int		x;
	int		player;
	int		exit;

	y = 0;
	player = 0;
	exit = 0;
	while (game->area[y])
	{
		x = 0;
		while (game->area[y][x])
		{
			if (game->area[y][x] == 'P')
				player++;
			if (game->area[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (player != 1 || exit != 1 || game->n_collectables < 1)
		return (0);
	return (1);
}

int	ft_checkwalls(t_game *game)
{
	int	y;
	int	x;
	int	xsize;
	int	ysize;

	y = 0;
	x = 0;
	xsize = game->map_width;
	ysize = game->map_height;
	while (game->area[y])
	{
		while (game->area[y][x])
		{
			if (game->area[0][x] != '1' || game->area[ysize - 1][x] != '1')
				return (0);
			if (game->area[y][0] != '1' || game->area[y][xsize - 1] != '1')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	ft_checkmapsize(t_game *game)
{
	int		i;
	int		strlen;

	i = 0;
	while (game->area[i] != NULL)
	{
		strlen = ft_strlen(game->area[i]);
		if (strlen != game->map_width)
			return (0);
		i++;
		if (game->area[i] == NULL)
			break ;
	}
	return (1);
}

int	ft_checkpath(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->clonearea[y])
	{
		x = 0;
		while (game->clonearea[y][x])
		{
			if (game->clonearea[y][x] == 'o' && ((game->area[y][x] == 'E')
				|| (game->area[y][x] == 'C')))
				return (0);
			if (game->clonearea[y][x] != 'o' && game->clonearea[y][x] != 'X'
				&& game->clonearea[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
