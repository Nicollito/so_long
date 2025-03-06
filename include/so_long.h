/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nimadela <nimadela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:57:33 by nimadela          #+#    #+#             */
/*   Updated: 2025/03/06 16:57:44 by nimadela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../mlx-linux/mlx.h"
# include "../mlx-linux/mlx_int.h"

typedef struct data_character
{
	char	*path;
	int		x;
	int		y;
}			t_dc;

typedef struct data_map
{
	char	**map;
	int		h;
	int		w;
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

// character.c
void	set_chara(t_alloc *all);

// error_manage.c
void	print_error(char *msg);

// fill_map.c
void	fill_map(t_alloc *all, char *name);
void	nbr_line_map(t_alloc *all, char *name);

// map.c
void	display_map(t_alloc *all);

// parsing.c
void	shape_map(t_alloc *all);
void	format_name(char *name);
void	border_map(t_alloc *all);
void	map_content(t_alloc *all);
int	verif_char(t_alloc *all, char c);

// set_mlx.c
void	mlx_pointer(t_alloc *all);

// so_long.c
t_alloc	*init_all(void);
t_alloc	*set_and_pars(char *name);

// user_actions.c
int		key_press(int keycode, t_alloc *all);
void	all_actions(t_alloc *all);

#endif