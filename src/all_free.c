/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:13:11 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/06 17:10:34 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_all(t_alloc *all)
{
	if (all->dm.map)
		free_map(all->dm.map);
	if (all->mlx.mlx)
		free_mlx(all);
	free(all);
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
void	free_mlx(t_alloc *all)
{
	if (all->mlx.ca)
		mlx_destroy_image(all->mlx.mlx, all->mlx.ca);
	if (all->mlx.col)
		mlx_destroy_image(all->mlx.mlx, all->mlx.col);
	if (all->mlx.drc)
		mlx_destroy_image(all->mlx.mlx, all->mlx.drc);
	if (all->mlx.dro)
		mlx_destroy_image(all->mlx.mlx, all->mlx.dro);
	if (all->mlx.grd)
		mlx_destroy_image(all->mlx.mlx, all->mlx.grd);
	if (all->mlx.wl)
		mlx_destroy_image(all->mlx.mlx, all->mlx.wl);
	if (all->mlx.win)
		mlx_destroy_window(all->mlx.mlx, all->mlx.win);
	mlx_destroy_display(all->mlx.mlx);
	free(all->mlx.mlx);
}
