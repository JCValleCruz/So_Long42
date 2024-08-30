/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:55:12 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/22 19:53:13 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_getsizemap2(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(game->area[0]);
	while (game->area[i])
		i++;
	game->map_height = i;
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'X';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

void	ft_clonearea(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	game->clonearea = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->clonearea)
		free_split(game->clonearea);
	while (++y < game->map_height)
	{
		game->clonearea[y] = malloc(game->map_width + 1);
		x = -1;
		while (++x < game->map_width)
		{
			if (game->area[y][x] == 'P' || game->area[y][x] == 'E'
				|| game->area[y][x] == 'C' || game->area[y][x] == '0')
				game->clonearea[y][x] = 'o';
			else
				game->clonearea[y][x] = game->area[y][x];
		}
		game->clonearea[y][game->map_width] = '\0';
	}
	game->clonearea[y] = game->area[y];
}
