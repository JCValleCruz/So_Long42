/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:27:57 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/23 13:49:58 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkarg(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x] != '\0')
	{
		if (str[x] == '.' && str[x + 1] != '\0')
		{
			if (str[x + 1] != 'b')
				return (0);
			if (str[x + 2] != 'e')
				return (0);
			if (str[x + 3] != 'r')
				return (0);
		}
		x++;
	}
	return (1);
}
