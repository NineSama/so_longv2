/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:56:22 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/04 18:14:45 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(data->map.fd);
	if (!line || line == NULL)
		return (0);
	data->map.width = ft_strlen(line) - 1;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.height = i;
	return (i);
}

void	get_pos_exit(t_data *data, int y, int x)
{
	if (data->map.map[y][x] == 'P')
	{
		data->pos_x = x;
		data->pos_y = y;
	}
	if (data->map.map[y][x] == 'E')
	{
		data->exit_x = x;
		data->exit_y = y;
	}
}

int	get_map(t_data *data)
{
	int		i;
	int		n_line;
	char	*line;

	data->map.fd = open(data->path, O_RDONLY);
	line = get_next_line(data->map.fd);
	n_line = 0;
	while (line)
	{
		data->map.map[n_line] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!data->map.map[n_line])
			return (0);
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			data->map.map[n_line][i] = line[i];
			get_pos_exit(data, n_line, i);
			i++;
		}
		data->map.map[n_line][i] = '\0';
		n_line++;
		free(line);
		line = get_next_line(data->map.fd);
	}
	return (1);
}

int	is_ber(t_data *data)
{
	int	i;

	i = 0;
	while (data->path[i] && data->path[i] != '.')
		i++;
	if (data->path[i] == '.' && data->path[i + 1] == 'b'
		&& data->path[i + 2] == 'e' && data->path[i + 3] == 'r'
		&& data->path[i + 4] == '\0')
		return (1);
	return (0);
}

int	create_map(t_data *data)
{
	if (!is_ber(data))
	{
		write(2, "Map not a .ber\n", 15);
		return (free_ber(data), 0);
	}
	data->map.fd = open(data->path, O_RDONLY);
	if (!data->map.fd)
		return (0);
	if (!get_map_height(data))
		return (free_ber(data), 0);
	data->map.map = malloc(sizeof(char *) * get_map_height(data));
	if (!data->map.map)
		return (0);
	initialising_values(data);
	if (!initialising_imgs(data))
		return (free_all(data, 'h'), 0);
	if (!get_map(data))
		trucdu(data);
	return (is_valid(data));
}
