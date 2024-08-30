/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:09:33 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/22 17:31:09 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fd_exit_error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(1);
}

void	exit_error(char *str, t_game *g)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	free_game(g);
	exit(1);
}

void	error(t_game *game)
{
	free_game(game);
	puts(mlx_strerror(mlx_errno));
	exit(1);
}

void	ft_free_error(char **lines)
{
	free_split(lines);
	write(STDERR_FILENO, "Error\n", 6);
	exit (1);
}

void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit (1);
}
