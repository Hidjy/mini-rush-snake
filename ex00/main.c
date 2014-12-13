/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 10:13:55 by laime             #+#    #+#             */
/*   Updated: 2014/12/11 11:35:42 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "snake.h"
#include "libft/libft.h"

int		main(int ac, char **av)
{
	int		key;
	int		**map;
	t_list	*player;
	t_point	*snake;

	map = map_init(MAP_X, MAP_Y);
	snake = pt_new(MAP_X / 2, MAP_Y / 2);
	player = ft_lstnew(snake, sizeof(snake));
	while (42)
	{
		key = getarrowkey();
		if (key)
			pt_move(player->content, key);
		if (pt_hit(player->content, map) == 1)
			stop("Player hit a wall.");
		screen_clear();
		map_draw(map, player, MAP_X, MAP_Y);
		usleep(10000);
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
