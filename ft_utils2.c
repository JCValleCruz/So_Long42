/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:52:48 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/22 20:31:40 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;
	char	*ptr;
	size_t	i;

	p = malloc(num * size);
	if (!p)
	{
		return (NULL);
	}
	ptr = (char *)p;
	i = 0;
	while (i < num * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}

t_point	ft_assign(t_game *game)
{
	t_point	mapsize;

	mapsize.x = game->map_width;
	mapsize.y = game->map_height;
	return (mapsize);
}

void	ft_validmap(t_game *game)
{
	if (ft_checkparam(game) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_game(game);
	}
	if (ft_checkmapsize(game) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_game(game);
	}
	if (ft_checkwalls(game) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_game(game);
	}
	if (ft_checkpath(game) == 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_game(game);
	}
}
