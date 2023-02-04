/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:18:58 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/04 19:34:20 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_int.h"
#include "mlx/mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	check_dir(char *path)
{
	int	fd;

	fd = open(path, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		write(2, "Trying to open a dir ?\n", 23);
		return (0);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cant open file\n", 15);
		return (0);
	}
	close(fd);
	return (1);
}

int	so_long_core(t_data *data)
{
	if (!create_map(data))
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->map.width * 100, data->map.height * 100, "HEHEXD");
	if (!data->win_ptr)
		return (trucdu(data), 0);
	transfer(data);
	mlx_loop_hook(data->mlx_ptr, &transfer, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0L, &trucdu, data);
	mlx_loop(data->mlx_ptr);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{
		write(2, "Not 2 args\n", 11);
		return (1);
	}
	data = malloc(sizeof(t_data));
	data->path = av[1];
	if (!check_dir(data->path))
		return (free(data), 2);
	if (!data)
		return (3);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (4);
	if (!so_long_core(data))
		return (5);
	return (0);
}
