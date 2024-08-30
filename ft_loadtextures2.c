/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadtextures2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:04:49 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/23 12:09:29 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_texture_t	*load_player_texture(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/player.png");
	return (texture);
}

mlx_texture_t	*load_finalplayer_texture(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/playerfinal.png");
	return (texture);
}

mlx_texture_t	*load_collectable(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/collectable.png");
	return (texture);
}
