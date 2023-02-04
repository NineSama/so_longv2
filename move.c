/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:23:38 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/21 23:15:51 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_exit(t_data *data, char c)
{
	if (c == 'w' && data->map.map[data->pos_y - 1][data->pos_x] == 'E')
	{
		if (data->counter == data->map.count_cons)
			return (1);
		return (0);
	}
	if (c == 'a' && data->map.map[data->pos_y][data->pos_x - 1] == 'E')
	{
		if (data->counter == data->map.count_cons)
			return (1);
		return (0);
	}
	if (c == 's' && data->map.map[data->pos_y + 1][data->pos_x] == 'E')
	{
		if (data->counter == data->map.count_cons)
			return (1);
		return (0);
	}
	if (c == 'd' && data->map.map[data->pos_y][data->pos_x + 1] == 'E')
	{
		if (data->counter == data->map.count_cons)
			return (1);
		return (0);
	}
	return (1);
}

int	check_next_case(t_data *data, char c)
{
	if (c == 'w' && data->map.map[data->pos_y - 1][data->pos_x] == 'C')
		data->counter++;
	if (c == 'a' && data->map.map[data->pos_y][data->pos_x - 1] == 'C')
		data->counter++;
	if (c == 's' && data->map.map[data->pos_y + 1][data->pos_x] == 'C')
		data->counter++;
	if (c == 'd' && data->map.map[data->pos_y][data->pos_x + 1] == 'C')
		data->counter++;
	if (c == 'w' && data->map.map[data->pos_y - 1][data->pos_x] == '1')
		return (0);
	if (c == 'a' && data->map.map[data->pos_y][data->pos_x - 1] == '1')
		return (0);
	if (c == 's' && data->map.map[data->pos_y + 1][data->pos_x] == '1')
		return (0);
	if (c == 'd' && data->map.map[data->pos_y][data->pos_x + 1] == '1')
		return (0);
	return (1);
}

void	move_player2(t_data *data, int c)
{
	if (c == 's' && check_next_case(data, c) && my_exit(data, c))
	{
		data->map.map[data->pos_y][data->pos_x] = '0';
		data->pos_y += 1;
		data->pas++;
		data->map.map[data->pos_y][data->pos_x] = 'P';
		exit_game(data);
	}
	else if (c == 'd' && check_next_case(data, c) && my_exit(data, c))
	{
		data->map.map[data->pos_y][data->pos_x] = '0';
		data->pos_x += 1;
		data->pas++;
		data->map.map[data->pos_y][data->pos_x] = 'D';
		exit_game(data);
	}
}

void	move_player(t_data *data, int c)
{
	if (c == 'w' && check_next_case(data, c) && my_exit(data, c))
	{
		data->map.map[data->pos_y][data->pos_x] = '0';
		data->pos_y -= 1;
		data->pas++;
		data->map.map[data->pos_y][data->pos_x] = 'W';
		exit_game(data);
	}
	else if (c == 'a' && check_next_case(data, c) && my_exit(data, c))
	{
		data->map.map[data->pos_y][data->pos_x] = '0';
		data->pos_x -= 1;
		data->pas++;
		data->map.map[data->pos_y][data->pos_x] = 'A';
		exit_game(data);
	}
	else
		move_player2(data, c);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		free_all(data, 't');
		exit (0);
	}
	else if (keysym == 'w' || keysym == 'a' || keysym == 's' || keysym == 'd')
		move_player(data, keysym);
	return (0);
}
