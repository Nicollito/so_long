/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:57:33 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/11 11:18:27 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"
# include "../mlx-linux/mlx.h"
# include "../mlx-linux/mlx_int.h"

#include "tmp2.h"

typedef struct data_character
{
	int		x;
	int		y;
	int		steps;
}			t_dc;

typedef struct data_map
{
	char	**map;
	int		h;
	int		w;
	int		nbr_coll;
}			t_map;

typedef struct pointer_mlx
{
	void	*mlx;
	void	*win;
	void	*ca;
	void	*wl;
	void	*grd;
	void	*dro;
	void	*drc;
	void	*col;
	void	*col_empt;
}			t_mlx;

typedef struct allocaion
{
	t_dc	dc;
	t_map	dm;
	t_mlx	mlx;
}			t_alloc;

// all_free.c
int		free_all(t_alloc *all);
void	free_map(char **map);
void	free_mlx(t_alloc *all);

// error_manage.c
void	print_error(char *msg);

// fill_map.c
void	fill_map(t_alloc *all, char *name);
void	nbr_line_map(t_alloc *all, char *name);

// flood_fill.c
void	flood_fill(t_alloc *all, char **map, int x, int y);
void	check_flood_fill(char **map, t_alloc *all);
void	set_flood_fill(t_alloc *all);

// map_content.c
void	format_name(char *name);
void	map_content(t_alloc *all);
char	**copy_map(t_alloc *all);
int		verif_char(t_alloc *all, char c);

// map.c
void	display_map(t_alloc *all);
void	print_assets(t_alloc *all, int i, int j);
void	decrement_coll(t_alloc *all, int map_y, int map_x);
void	set_coord_character(t_alloc *all);

// set_mlx.c
void	mlx_pointer(t_alloc *all);
void	set_door(t_alloc *all);
void	set_tileset(t_alloc *all);

// shape_map.c
void	size_map(t_alloc *all);
void	shape_map(t_alloc *all);
void	border_map(t_alloc *all);

// so_long.c
t_alloc	*init_all(void);
t_alloc	*set_and_pars(char *name);
void	pars_char(t_alloc *all);

// user_actions.c
int		key_press(int keycode, t_alloc *all);
int		close_window(t_alloc *all);
void	all_actions(t_alloc *all);
void	move_player(t_alloc *all, char coord, char sign);

#endif