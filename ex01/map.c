/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 10:13:55 by laime             #+#    #+#             */
/*   Updated: 2014/12/11 12:00:51 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "snake.h"
#include "libft/libft.h"

int		**map_init(int x, int y)
{
	int		**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = (int **)malloc(sizeof(int *) * x);
	if (!map)
		stop("Error on malloc.");
	while (i < x)
	{
		map[i] = (int *)malloc(sizeof(int) * y);
		if (!(map[i]))
			stop("Error on malloc.");
		i++;
	}
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
				map[i][j] = 1;
			else
				map [i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void	map_change(int **map, int item, int x, int y)
{
	map[x][y] = item;
}

void	map_draw(int **map, t_list *player, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (pt_here(player, i, j))
				ft_putchar('s');
			else if (map[i][j] == 1)
				ft_putchar('#');
			else if (map[i][j] == 2)
				ft_putchar('a');
			else
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
