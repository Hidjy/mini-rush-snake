/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laime <laime@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/11 11:06:28 by laime             #+#    #+#             */
/*   Updated: 2014/12/13 18:00:38 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "snake.h"
#include "libft/libft.h"

int		canturn(int key, int lkey)
{
	if (key == 1 && lkey == 4)
		return (0);
	else if (key == 2 && lkey == 3)
		return (0);
	else if (key == 3 && lkey == 2)
		return (0);
	else if (key == 4 && lkey == 1)
		return (0);

	return (1);
}

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

// Function fixed just after the mini-rush (in 15m)
void	snake_move(t_list **snake, int key, int grow)
{
	t_list		*tmp;
	t_point		*pt;

	pt = (*snake)->content;
	if (key == 1)
		ft_lstadd(snake, ft_lstnew(pt_new(pt->x, pt->y - 1), sizeof(t_point)));
	else if (key == 2)
		ft_lstadd(snake, ft_lstnew(pt_new(pt->x - 1, pt->y), sizeof(t_point)));
	else if (key == 3)
		ft_lstadd(snake, ft_lstnew(pt_new(pt->x + 1, pt->y), sizeof(t_point)));
	else if (key == 4)
		ft_lstadd(snake, ft_lstnew(pt_new(pt->x, pt->y + 1), sizeof(t_point)));
	if (grow)
		return ;
	tmp = *snake;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
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
