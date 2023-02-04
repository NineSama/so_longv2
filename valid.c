/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:25:33 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/04 19:25:34 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	is_rectangle(t_data *data)
{
	int	standard;
	int	i;
	int	j;

	standard = ft_strlen(data->map.map[0]);
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (data->map.map[i][j])
			j++;
		if (j != standard)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded(t_data *data)
{
	int	i;
	int	j;
	int	standard;

	standard = ft_strlen(data->map.map[0]);
	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if ((i == 0 || i == data->map.height - 1)
				&& data->map.map[i][j] != '1')
				return (0);
			if (data->map.map[i][0] != '1' ||
				data->map.map[i][standard - 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_good_amount(t_data *data)
{
	if (data->map.count_pers != 1)
		return (0);
	else if (data->map.count_exit != 1)
		return (0);
	else if (data->map.count_cons < 1)
		return (0);
	else
		return (1);
}

int	count_amount(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
				data->map.count_pers++;
			else if (data->map.map[i][j] == 'E')
				data->map.count_exit++;
			else if (data->map.map[i][j] == 'C')
				data->map.count_cons++;
			else if (data->map.map[i][j] != '0' && data->map.map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (is_good_amount(data));
}

int	is_valid(t_data *data)
{
	if (!is_rectangle(data))
	{
		write(2, "Map isn't a rectangle\n", 22);
		return (close(data->map.fd), 0);
	}
	if (!is_surrounded(data))
	{
		write(2, "Map isn't surrounded by walls\n", 30);
		return (close(data->map.fd), 0);
	}
	if (!count_amount(data))
	{
		write(2, "Map not right\n", 14);
		return (close(data->map.fd), 0);
	}
	if (!init_pathfind(data))
	{
		write(2, "No path available\n", 18);
		return (close(data->map.fd), 0);
	}
	return (close(data->map.fd), 1);
}
