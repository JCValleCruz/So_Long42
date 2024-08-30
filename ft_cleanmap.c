/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:18:08 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/23 13:42:11 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_checkfinal(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (str[i] != '\0')
		i++;
	while (str[i - n] == '\n')
	{
		str[i - n] = str[i];
		n++;
	}
	return (str);
}

int	ft_cleanmap(char *str)
{
	int	i;
	int	flag;

	str = ft_checkfinal(str);
	i = 0;
	flag = 0;
	while (str[i] == '\n' && str[i] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			flag = 1;
		if (str[i + 1] == '\n' && str[i] == '\n')
			return (0);
		i++;
	}
	if (flag == 0)
		return (0);
	return (1);
}
