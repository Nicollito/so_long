/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:34:52 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/11 10:38:02 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_press(int keycode, t_alloc *all)
{
	if (keycode == 119)
		move_player(all, 'y', '-');
	if (keycode == 115)
		move_player(all, 'y', '+');
	if (keycode == 97)
		move_player(all, 'x', '-');
	if (keycode == 100)
		move_player(all, 'x', '+');
	if (keycode == 65307)
		exit(free_all(all));
	return (0);
}

int	close_window(t_alloc *all)
{
	exit(free_all(all));
	return (0);
}

int	print_chara(t_alloc *all)
{
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win,
		all->mlx.ca, all->dc.x, all->dc.y);
	return (0);
}

void	all_actions(t_alloc *all)
{
	mlx_hook(all->mlx.win, 2, 1L << 0, key_press, all);
	mlx_loop_hook(all->mlx.mlx, print_chara, all);
	mlx_hook(all->mlx.win, 17, 0L, close_window, all);
}

void	move_player(t_alloc *all, char coord, char sign)
{
	int	new_x;
	int	new_y;
	int	map_x;
	int	map_y;

	new_x = all->dc.x;
	new_y = all->dc.y;
	if (coord == 'x' && sign == '+')
		new_x += 120;
	else if (coord == 'x' && sign == '-')
		new_x -= 120;
	else if (coord == 'y' && sign == '+')
		new_y += 120;
	else if (coord == 'y' && sign == '-')
		new_y -= 120;
	map_x = new_x / 120;
	map_y = new_y / 120;
	if (all->dm.map[map_y][map_x] == '1')
		return ;
	decrement_coll(all, map_y, map_x);
	all->dc.x = new_x;
	all->dc.y = new_y;
	display_map(all);
	if (all->dm.map[map_y][map_x] == 'E' && all->dm.nbr_coll == 0)
		exit(free_all(all));
}
