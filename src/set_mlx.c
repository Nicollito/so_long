/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:37:28 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/11 11:16:22 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mlx_pointer(t_alloc *all)
{
	int	w;
	int	h;

	all->mlx.mlx = mlx_init();
	if (!all->mlx.mlx)
		exit(free_all(all));
	set_door(all);
	set_tileset(all);
	all->mlx.win = mlx_new_window(all->mlx.mlx, all->dm.w * 120,
			all->dm.h * 120, "so_long");
	if (!all->mlx.win)
		exit(free_all(all));
	all->mlx.ca = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/character/face.xpm", &w, &h);
	if (!all->mlx.ca)
		exit(free_all(all));
	all->mlx.col = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/tileset/milk_full.xpm", &w, &h);
	if (!all->mlx.col)
		exit(free_all(all));
}

void	set_door(t_alloc *all)
{
	int	w;
	int	h;

	all->mlx.drc = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/tileset/door_close.xpm", &w, &h);
	if (!all->mlx.drc)
		exit(free_all(all));
	all->mlx.dro = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/tileset/door_open.xpm", &w, &h);
	if (!all->mlx.dro)
		exit(free_all(all));
}

void	set_tileset(t_alloc *all)
{
	int	w;
	int	h;

	all->mlx.grd = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/tileset/ground.xpm", &w, &h);
	if (!all->mlx.grd)
		exit(free_all(all));
	all->mlx.wl = mlx_xpm_file_to_image(all->mlx.mlx,
			"assets/tileset/tree.xpm", &w, &h);
	if (!all->mlx.wl)
		exit(free_all(all));
}
