/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:15:24 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/04 19:14:05 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_data *data)
{
	char	*itoto;

	if (data->pos_x == data->exit_x && data->pos_y == data->exit_y)
	{
		itoto = ft_itoa(data->pas);
		ft_putstr("T'as dead ca en [");
		ft_putstr(itoto);
		free(itoto);
		ft_putstr("] coups! bv\n");
		free_all(data, 't');
		exit(0);
	}
}

void	destroy_images(t_data *data)
{
	if (data->image.cons)
		mlx_destroy_image(data->mlx_ptr, data->image.cons);
	if (data->image.pers_left)
		mlx_destroy_image(data->mlx_ptr, data->image.pers_left);
	if (data->image.pers_up)
		mlx_destroy_image(data->mlx_ptr, data->image.pers_up);
	if (data->image.pers_down)
		mlx_destroy_image(data->mlx_ptr, data->image.pers_down);
	if (data->image.pers_right)
		mlx_destroy_image(data->mlx_ptr, data->image.pers_right);
	if (data->image.wall)
		mlx_destroy_image(data->mlx_ptr, data->image.wall);
	if (data->image.ground)
		mlx_destroy_image(data->mlx_ptr, data->image.ground);
	if (data->image.exit)
		mlx_destroy_image(data->mlx_ptr, data->image.exit);
}

void	free_for_pf(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.height)
	{
		if (data->map.map[i])
			free(data->map.map[i]);
		i++;
	}
}

void	free_all(t_data *data, char c)
{
	int	i;

	i = 0;
	if (c == 't')
	{
		while (i < data->map.height)
		{
			if (data->map.map[i])
				free(data->map.map[i]);
			i++;
		}
	}
	if (data->map.map)
		free(data->map.map);
	destroy_images(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
}

int	trucdu(t_data *data)
{
	close(data->map.fd);
	free_all(data, 't');
	exit (0);
}
