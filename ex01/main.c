/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 10:13:55 by laime             #+#    #+#             */
/*   Updated: 2015/01/01 21:21:40 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "snake.h"
#include "../libft/libft.h"

int		main(int ac, char **av)
{
	int		key;
	int		**map;
	int		speed;
	int		width;
	int		height;
	int		lkey;
	int		hit;
	t_list	*player;
	t_point	*snake;

	if (ac != 4)
		stop("Usage: ./snake width height speed");
	width = atoi(av[1]);
	height = atoi(av[2]);
	speed = atoi(av[3]);
	map = map_init(height, width);
	snake = pt_new(height / 2, width / 2);
	player = ft_lstnew(snake, sizeof(snake));
	lkey = 4;
	map_change(map, 2, height / 4, width / 4);
	while (42)
	{
		key = getarrowkey();
		if (key != lkey && key != 0 && canturn(key, lkey))
			lkey = key;
		hit = pt_hit(player->content, map);
		if (hit == 1)
			stop("Player hit a wall.");
		snake_move(&player, lkey, (int)(hit == 2));
		snake = player->content;
		if (pt_here(player->next, snake->x, snake->y))
			stop("Player hit himself.");
		screen_clear();
		map_draw(map, player, height, width);
		usleep(1000000 / speed);
	}
	return (0);
}

void	stop(char *str)
{
	screen_clear();
	ft_putendl(str);
	exit(3);
}

void	screen_clear()
{
	system("clear");
}
