/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:01:49 by mfroissa          #+#    #+#             */
/*   Updated: 2022/09/21 23:16:19 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	ft_strlen(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	len(long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		i;
	char	*str;

	nb = n;
	i = len(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
		str[i] = 48;
	while (nb > 0)
	{
		str[i--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
