/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:58:09 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/23 19:05:22 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pf_check_exit(t_data *data, char c, int y, int x)
{
	if (c == 'u' && data->map.map[y - 1][x] == '1')
		return (0);
	if (c == 'l' && data->map.map[y][x - 1] == '1')
		return (0);
	if (c == 'd' && data->map.map[y + 1][x] == '1')
		return (0);
	if (c == 'r' && data->map.map[y][x + 1] == '1')
		return (0);
	return (1);
}

int	pf_check_next(t_data *data, char c, int y, int x)
{
	if (c == 'u' && (data->map.map[y - 1][x] == '1'
		|| data->map.map[y - 1][x] == 'E'))
		return (0);
	if (c == 'l' && (data->map.map[y][x - 1] == '1'
		|| data->map.map[y][x - 1] == 'E'))
		return (0);
	if (c == 'd' && (data->map.map[y + 1][x] == '1'
		|| data->map.map[y + 1][x] == 'E'))
		return (0);
	if (c == 'r' && (data->map.map[y][x + 1] == '1'
		|| data->map.map[y][x + 1] == 'E'))
		return (0);
	return (1);
}

void	get_obj(t_data *data)
{
	int	i;
	int	j;
	int	step;

	i = 0;
	step = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] == 'C')
			{
				if (step == data->pf.count_cons)
				{
					data->pf.obj_x = j;
					data->pf.obj_y = i;
					return ;
				}
				step++;
			}
			j++;
		}
		i++;
	}
}

int	pathfind_exit(t_data *data, int y, int x)
{
	if (x == data->exit_x && y == data->exit_y)
		return (1);
	data->map.map[y][x] = '1';
	if (pf_check_exit(data, 'u', y, x))
	{
		if (pathfind_exit(data, y - 1, x))
			return (1);
	}
	if (pf_check_exit(data, 'l', y, x))
	{
		if (pathfind_exit(data, y, x - 1))
			return (1);
	}
	if (pf_check_exit(data, 'd', y, x))
	{
		if (pathfind_exit(data, y + 1, x))
			return (1);
	}
	if (pf_check_exit(data, 'r', y, x))
	{
		if (pathfind_exit(data, y, x + 1))
			return (1);
	}
	return (0);
}

int	pathfind(t_data *data, int y, int x)
{
	if (x == data->pf.obj_x && y == data->pf.obj_y)
		return (1);
	data->map.map[y][x] = '1';
	if (pf_check_next(data, 'u', y, x))
	{
		if (pathfind(data, y - 1, x))
			return (1);
	}
	if (pf_check_next(data, 'l', y, x))
	{
		if (pathfind(data, y, x - 1))
			return (1);
	}
	if (pf_check_next(data, 'd', y, x))
	{
		if (pathfind(data, y + 1, x))
			return (1);
	}
	if (pf_check_next(data, 'r', y, x))
	{
		if (pathfind(data, y, x + 1))
			return (1);
	}
	return (0);
}
