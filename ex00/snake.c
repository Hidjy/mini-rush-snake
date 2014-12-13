/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 11:06:28 by laime             #+#    #+#             */
/*   Updated: 2014/12/11 11:29:59 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "snake.h"
#include "libft/libft.h"

t_point	*pt_new(int x, int y)
{
	t_point	*pt;

	pt = (t_point *)malloc(sizeof(t_point));
	pt->x = x;
	pt->y = y;
	return (pt);
}

void	pt_set(t_point *pt, int x, int y)
{
	pt->x = x;
	pt->y = y;
}

void	pt_move(t_point *pt, int key)
{
	if (key == 1)
		pt_set(pt, pt->x, pt->y - 1);
	else if (key == 2)
		pt_set(pt, pt->x - 1, pt->y);
	else if (key == 3)
		pt_set(pt, pt->x + 1, pt->y);
	else if (key == 4)
		pt_set(pt, pt->x, pt->y + 1);
}

int		pt_hit(t_point *pt, int **map)
{
	return (map[pt->x][pt->y]);
}

int		pt_here(t_list *pts, int x, int y)
{
	t_point	*pt;

	while (pts)
	{
		pt = pts->content;
		if (pt->x == x && pt->y == y)
			return (1);
		pts = pts->next;
	}
	return (0);
}
