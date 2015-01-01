/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:23:22 by hhismans          #+#    #+#             */
/*   Updated: 2015/01/01 20:13:59 by laime            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

# include "../libft/libft.h"

# define MAP_X 8
# define MAP_Y 16

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

int		pt_here(t_list *pts, int x, int y);
t_point	*pt_new(int x, int y);
void	pt_set(t_point *pt, int x, int y);
int		pt_hit(t_point *pt, int **map);
void	pt_move(t_point *pt, int key);

#endif
