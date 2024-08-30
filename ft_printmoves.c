/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmoves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:21:34 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/08/23 13:31:24 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_get_digits(int n)
{
	size_t	i;

	i = 1;
	while ((n / 10) != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = ft_get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!(str_num))
		return (NULL);
	str_num[digits] = '\0';
	while (digits-- > 0)
	{
		str_num[digits] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	return (str_num);
}

void	ft_putstrr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_print_count(void *g)
{
	t_game	*game;
	char	*count;

	game = (t_game *)g;
	count = ft_itoa(game->move_count);
	write(1, "\r", 1);
	ft_putstrr(count);
	free(count);
}
