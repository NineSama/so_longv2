/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:25:57 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/04 16:35:17 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	map_to_win_3(t_data *data, char c, int y, int x)
{
	char	*itoto;

	itoto = ft_itoa(data->pas);
	if (c == 'A')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.pers_left, x * 100, y * 100);
		data->pos_x = x;
		data->pos_y = y;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		20, 20, 0xFEFEFF, "Nombre de pas :");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		150, 20, 0xFEFEFF, itoto);
	free(itoto);
}

void	map_to_win_2(t_data *data, char c, int y, int x)
{
	if (c == 'W')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.pers_up, x * 100, y * 100);
		data->pos_x = x;
		data->pos_y = y;
	}
	if (c == 'D')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.pers_right, x * 100, y * 100);
		data->pos_x = x;
		data->pos_y = y;
	}
	else
		map_to_win_3(data, c, y, x);
}

void	map_to_win(t_data *data, char c, int y, int x)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.ground, x * 100, y * 100);
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.wall, x * 100, y * 100);
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.pers_down, x * 100, y * 100);
		data->pos_x = x;
		data->pos_y = y;
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.exit, x * 100, y * 100);
		data->exit_x = x;
		data->exit_y = y;
	}
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image.cons, x * 100, y * 100);
	else
		map_to_win_2(data, c, y, x);
}

int	transfer(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			map_to_win(data, data->map.map[i][j], i, j);
			j++;
		}
		i++;
	}
	return (1);
}
