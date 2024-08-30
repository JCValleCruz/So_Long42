/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:46:11 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/23 12:33:53 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "MLX42/include/MLX42/MLX42.h"
# define WALL '1'
# define PLAYER 'P'
# define GROUND '0'
# define EXIT 'E'
# define COL 'C'

typedef struct unitsize
{
	int			x;
	int			y;
}	t_point;

typedef struct s_game
{
	int				map_width;
	int				map_height;
	mlx_image_t		*image;
	mlx_t			*mlx;
	mlx_texture_t	*collectable;
	mlx_texture_t	*unlocked_exit_t;
	mlx_texture_t	*locked_exit_t;
	mlx_texture_t	*wall;	
	mlx_texture_t	*background;
	mlx_texture_t	*wallint;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*finalplayer_texture;
	int				movement;
	char			**clonearea;	
	char			**area;
	char			*readmap;
	int				n_collectables;
	int				playerx;
	int				playery;
	int				exit_lock;
	int				exit_y;
	int				exit_x;
	int				loaded_txt;
	int				move_count;
}	t_game;

int32_t			mlx_get_pixel(mlx_image_t *image, uint32_t x, uint32_t y);
mlx_texture_t	*load_ground(void);
mlx_texture_t	*load_wall_texture(void);
mlx_texture_t	*load_wall_texture_int(void);
mlx_texture_t	*load_exit(void);
mlx_texture_t	*load_unlocked_exit(void);
mlx_texture_t	*load_locked_exit(void);
mlx_texture_t	*load_collectable(void);
mlx_texture_t	*load_player_texture(void);
mlx_texture_t	*load_finalplayer_texture(void);
mlx_texture_t	*collectable(void);
t_point			ft_getsizemap(char **map);
t_point			ft_findplayer(t_game *game);
t_point			ft_assign(t_game *game);
size_t			ft_strlen(const char *str);
char			**ft_split(const char *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_checkfinal(char *str);
int				ft_checkarg(char *str);
int				ft_checkmapsize(t_game *game);
int				ft_checkparam(t_game *game);
int				ft_checkwalls(t_game *game);
int				ft_cleanmap(char *str);
int				initialize_mlx(t_game *game);
int				ft_checkpath(t_game *game);
int				get_rgba(int r, int g, int b, int a);
int				put_pixel_valid(mlx_image_t *img, uint32_t x, uint32_t y);
void			*ft_calloc(size_t num, size_t size);
void			free_split(char **split);
void			fill(char **tab, t_point size, t_point cur, char to_fill);
void			flood_fill(char **tab, t_point size, t_point begin);
void			ft_clonearea(t_game *game);
void			ft_validmap(t_game *game);
void			ft_printmap(char **area);
void			ft_printxy(t_point location);
void			ft_set_mapsizegame(t_game game, t_point mapsize);
void			ft_getsizemap2(t_game *game);
void			ft_checkgen(t_game *game);
void			ft_startgame(t_game game);
void			handle_key(mlx_key_data_t keydata, void *param);
void			render_map(void *param);
void			move_player(t_game *game, int new_x, int new_y);
void			ft_findexit(t_game *game);
int				ft_findcollectables(t_game *game);
void			ft_draw_background(void *g);
void			put_background(void *g, int x, int y);
void			paste_sticker(mlx_image_t *dst, mlx_image_t *src, int x, int y);
void			put_wall(void *g, int x, int y);
void			put_wallint(void *g, int x, int y);
void			ft_draw(void *g);
void			ft_draw_map_objects(void *g);
void			ft_draw_walls(void *g);
void			put_locked_exit(void *g, int x, int y);
void			locked_exit(void *g, int x, int y);
void			put_exit(void *g, int x, int y);
void			put_player(void *g, int x, int y);
void			put_collectable(void *g, int x, int y);
void			put_finalplayer(void *g, int x, int y);
void			ft_free_error(char **area);
void			ft_error(void);
void			main_error_check(t_game *game, char *argv);
void			check_errors(t_game *game, size_t size);
void			error(t_game *game);
void			exit_error(char *str, t_game *g);
void			fd_exit_error(char *str);
void			ft_init_elements(t_game *game);
void			ft_draw_collectable(void *g);
void			free_game(t_game *g);
void			ft_draw_player(void *g);
void			ft_finalgg(t_game *game);
void			ft_finalgg_ok(t_game *game);
void			free_game_ok(t_game *g);
char			*ft_itoa(int n);
void			ft_putstrr(char *str);
void			ft_print_count(void *g);

#endif