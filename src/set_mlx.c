/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:37:28 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/10 13:50:29 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mlx_pointer(t_alloc *all)
{
	int	w;
	int	h;

	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx, all->dm.w * 120,
			all->dm.h * 120, "so_long");
	all->mlx.ca = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/character/face.xpm", &w, &h);
	all->mlx.grd = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/tileset/ground.xpm", &w, &h);
	all->mlx.wl = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/tileset/tree.xpm", &w, &h);
	all->mlx.drc = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/tileset/door_close.xpm", &w, &h);
	all->mlx.dro = mlx_xpm_file_to_image(all->mlx.mlx,
		"assets/tileset/door_open.xpm", &w, &h);
	all->mlx.col = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/tileset/milk_full.xpm", &w, &h);
}
