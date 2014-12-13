/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:23:22 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/13 17:47:07 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

# include "libft/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

int		getarrowkey(void);
int		rand_a_b(int a, int b);

void	stop(char *str);
void	screen_clear(void);
int		**map_init(int x, int y);
void	map_draw(int **map, t_list *player, int x, int y);
void	map_change(int **map, int item, int x, int y);

int		canturn(int key, int lkey);

int		pt_here(t_list *pts, int x, int y);
t_point	*pt_new(int x, int y);
void	pt_set(t_point *pt, int x, int y);
int		pt_hit(t_point *pt, int **map);

void	snake_move(t_list **snake, int key, int grow);

#endif
