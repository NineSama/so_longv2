/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:23:45 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/04 15:42:06 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "get_next_line.h"
# include <X11/X.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

# define A_KEY			97
# define W_KEY			119
# define S_KEY			115
# define D_KEY			100
# define ESC			65307

typedef struct s_pf
{
	int		count_cons;
	int		count_exit;
	int		obj_x;
	int		obj_y;
	int		pos_x;
	int		pos_y;
}				t_pf;

typedef struct s_map
{
	int		fd;
	char	**map;
	int		height;
	int		width;
	int		count_cons;
	int		count_pers;
	int		count_exit;

}				t_map;

typedef struct s_image
{
	int		width;
	int		height;
	void	*cons;
	void	*ground;
	void	*wall;
	void	*pers_up;
	void	*pers_down;
	void	*pers_right;
	void	*pers_left;
	void	*exit;
}				t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*path;
	int		pas;
	int		exit_x;
	int		exit_y;
	int		pos_x;
	int		pos_y;
	int		counter;
	t_image	image;
	t_map	map;
	t_pf	pf;
}				t_data;

/* utils.c */
int		ft_strlen(char *line);
int		len(long nb);
char	*ft_itoa(int n);
void	ft_putstr(char *str);

/* valid.c */
int		is_rectangle(t_data *data);
int		is_surrounded(t_data *data);
int		is_good_amount(t_data *data);
int		count_amount(t_data *data);
int		is_valid(t_data *data);

/* parsing.c */
int		get_map(t_data *data);
int		get_map_height(t_data *data);
int		create_map(t_data *data);

/* map_to_win */
void	map_to_win_3(t_data *data, char c, int y, int x);
void	map_to_win_2(t_data *data, char c, int y, int x);
void	map_to_win(t_data *data, char c, int y, int x);
int		transfer(t_data *data);

/* init.c */
void	initialising_values(t_data *data);
int		initialising_imgs(t_data *data);
int		init_pathfind(t_data *data);

/* move.c */
int		my_exit(t_data *data, char c);
int		check_next_case(t_data *data, char c);
void	move_player2(t_data *data, int c);
void	move_player(t_data *data, int c);
int		handle_keypress(int keysym, t_data *data);

/* end.c */
void	exit_game(t_data *data);
void	destroy_images(t_data *data);
void	free_for_pf(t_data *data);
void	free_all(t_data *data, char c);
int		trucdu(t_data *data);

/* free.c*/
void free_ber(t_data *data);

/* pathfinding.c */
int		pathfind(t_data *data, int y, int x);
int		pf_check_next(t_data *data, char c, int y, int x);
int		pf_check_exit(t_data *data, char c, int y, int x);
void	get_obj(t_data *data);
int		pathfind_exit(t_data *data, int y, int x);

/* main.c */
int		so_long_core(t_data *data);
int		check_dir(char *path);

#endif