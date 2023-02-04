/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:08:05 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/04 16:34:28 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	initialising_imgs2(t_data *data)
{
	data->image.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/exit.xpm", &data->image.width, &data->image.height);
	if (!data->image.exit)
		return (0);
	data->image.cons = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/cons.xpm", &data->image.width, &data->image.height);
	if (!data->image.cons)
		return (0);
	data->image.pers_left = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/pers_left.xpm", &data->image.width, &data->image.height);
	if (!data->image.pers_left)
		return (0);
	return (1);
}

int	initialising_imgs(t_data *data)
{
	data->image.ground = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/ground.xpm", &data->image.width, &data->image.height);
	if (!data->image.ground)
		return (0);
	data->image.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/wall.xpm", &data->image.width, &data->image.height);
	if (!data->image.wall)
		return (0);
	data->image.pers_right = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/pers_right.xpm", &data->image.width, &data->image.height);
	if (!data->image.pers_right)
		return (0);
	data->image.pers_up = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/pers_up.xpm", &data->image.width, &data->image.height);
	if (!data->image.pers_up)
		return (0);
	data->image.pers_down = mlx_xpm_file_to_image(data->mlx_ptr,
			"img/pers_down.xpm", &data->image.width, &data->image.height);
	if (!data->image.pers_down)
		return (0);
	return (initialising_imgs2(data));
}

void	initialising_values(t_data *data)
{
	data->image.ground = NULL;
	data->image.wall = NULL;
	data->image.exit = NULL;
	data->image.cons = NULL;
	data->image.pers_right = NULL;
	data->image.pers_up = NULL;
	data->image.pers_down = NULL;
	data->image.pers_left = NULL;
	data->map.count_pers = 0;
	data->map.count_exit = 0;
	data->map.count_cons = 0;
	data->image.height = 0;
	data->image.width = 0;
	data->counter = 0;
	data->pas = 0;
	data->image.width = 100;
	data->image.height = 100;
	data->pf.count_cons = 0;
	data->pf.count_exit = 0;
}

int	init_pathfind(t_data *data)
{
	while (data->pf.count_cons < data->map.count_cons)
	{
		get_obj(data);
		if (!pathfind(data, data->pos_y, data->pos_x))
			return (0);
		data->pf.count_cons++;
		free_for_pf(data);
		get_map(data);
	}
	if (!pathfind_exit(data, data->pos_y, data->pos_x))
		return (0);
	free_for_pf(data);
	if (!get_map(data))
		return (trucdu(data), 0);
	return (1);
}
