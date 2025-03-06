/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:34:52 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/06 16:50:34 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_press(int keycode, t_alloc *all)
{
	if (keycode == 119) // for 'w' key
		all->dc.x -= 120;
	if (keycode == 115) // for 's' key
		all->dc.x += 120;
	if (keycode == 97) // for 'a' key
		all->dc.y -= 120;
	if (keycode == 100) // for 'd' key
		all->dc.y += 120;
	if (keycode == 65307) // for 'esc' key
		exit(free_all(all));
	return (0);
}

void	all_actions(t_alloc *all)
{
	mlx_hook(all->mlx.win, 2, 1L << 0, key_press, all);
}
