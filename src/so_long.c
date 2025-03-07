/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:46:33 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/07 16:44:36 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_alloc	*all;

	if (ac != 2)
		return (0);
	all = set_and_pars(av[1]);
	print_matrix(all->dm.map);
	mlx_pointer(all);
	display_map(all, 0);
	all_actions(all);
	mlx_loop(all->mlx.mlx);
	free_all(all);
}

t_alloc	*init_all(void)
{
	t_alloc	*all;

	all = malloc(sizeof(t_alloc));
	if (!all)
		exit(EXIT_FAILURE);
	all->dm.map = NULL;
	all->mlx.mlx = NULL;
	all->mlx.win = NULL;
	all->mlx.ca = NULL;
	all->mlx.wl = NULL;
	all->mlx.grd = NULL;
	all->mlx.dro = NULL;
	all->mlx.drc = NULL;
	all->mlx.col = NULL;
	all->mlx.col_empt = NULL;
	return (all);
}

t_alloc	*set_and_pars(char *name)
{
	t_alloc	*all;

	format_name(name);
	all = init_all();
	fill_map(all, name);
	shape_map(all);
	border_map(all);
	map_content(all);
	all->dm.nbr_coll = verif_char(all, 'C');
	if (!all->dm.nbr_coll)
	{
		print_error("Error\nNo collectibles on the map.\n");
		exit(free_all(all));
	}
	if (verif_char(all, 'E') != 1)
	{
		print_error("Error\nThe map must contain only one exit.\n");
		exit(free_all(all));
	}
	if (verif_char(all, 'P') != 1)
	{
		print_error("Error\nThe map must have only one spawn point.\n");
		exit(free_all(all));
	}
	return (all);
}
