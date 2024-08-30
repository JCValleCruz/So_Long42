/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadtextures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:54:18 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/23 12:09:43 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_texture_t	*load_wall_texture(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/Wall0.png");
	return (texture);
}

mlx_texture_t	*load_wall_texture_int(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/Wallint.png");
	return (texture);
}

mlx_texture_t	*load_unlocked_exit(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/exit.png");
	return (texture);
}

mlx_texture_t	*load_ground(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/background.png");
	return (texture);
}

mlx_texture_t	*load_locked_exit(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/exit_locked.png");
	return (texture);
}
