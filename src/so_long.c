/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:46:33 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/06 17:13:30 by nimadela         ###   ########.fr       */
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
	display_map(all);
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
	all->mlx.dro = NULL;
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
	if (!verif_char(all, 'C'))
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
