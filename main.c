/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:46:14 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/23 12:25:53 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_elements(t_game *game)
{
	game->wall = load_wall_texture();
	game->wallint = load_wall_texture_int();
	game->collectable = load_collectable();
	game->background = load_ground();
	game->unlocked_exit_t = load_unlocked_exit();
	game->locked_exit_t = load_locked_exit();
	game->player_texture = load_player_texture();
	game->finalplayer_texture = load_finalplayer_texture();
	game->n_collectables = 0;
	game->loaded_txt = 1;
	game->move_count = 0;
}

void	ft_checkgen(t_game *game)
{
	t_point	playerpos;
	t_point	mapsize;

	ft_init_elements(game);
	ft_getsizemap2(game);
	game->n_collectables = ft_findcollectables(game);
	mapsize = ft_assign(game);
	playerpos = ft_findplayer(game);
	ft_findexit(game);
	ft_clonearea(game);
	if (!game->clonearea)
		free_game(game);
	flood_fill(game->clonearea, mapsize, playerpos);
	ft_validmap(game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;
	int		r;

	if ((ft_checkarg(argv[1])) == 0 || argc != 2)
		ft_error();
	if (argc == 2)
	{
		game.readmap = ft_calloc(10000, 1);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_error();
		r = read(fd, game.readmap, 9999);
		if (r <= 0)
			ft_error();
		if (ft_cleanmap(game.readmap) == 0)
			ft_error();
		game.area = ft_split(game.readmap, '\n');
		close (fd);
		if (!game.area)
			ft_error();
		ft_checkgen(&game);
		ft_startgame(game);
	}
	return (0);
}
