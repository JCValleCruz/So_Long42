/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findobjects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:49:44 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/22 20:28:31 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	ft_findplayer(t_game *game)
{
	int		x;
	int		y;
	t_point	pp;

	y = 0;
	x = 0;
	while (game->area[y])
	{
		while (game->area[y][x])
		{
			if (game->area[y][x] == 'P')
			{
				game->playery = y;
				game->playerx = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	pp.x = game->playerx;
	pp.y = game->playery;
	return (pp);
}

void	ft_findexit(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (game->area[y])
	{
		while (game->area[y][x])
		{
			if (game->area[y][x] == 'E')
			{
				game->exit_y = y;
				game->exit_x = x;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	ft_findcollectables(t_game *game)
{
	int	y;
	int	x;
	int	n;

	y = 0;
	n = 0;
	while (game->area[y])
	{
		x = 0;
		while (game->area[y][x])
		{
			if (game->area[y][x] == 'C')
				n++;
			x++;
		}
		y++;
	}
	return (n);
}
