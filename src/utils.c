/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharkush <vharkush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:40:27 by vharkush          #+#    #+#             */
/*   Updated: 2024/03/24 16:12:27 by vharkush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_emergency_exit(t_data *data)
{
	ft_map_free(data->map, -1);
	ft_free_window(data);
	exit(0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((s1[i]) - s2[i]);
}

int	ft_atoi_from_malloc(char *str)
{
	int	result;

	if (ft_strlen(str) > 3)
		return (free(str), -1);
	result = ft_atoi(str);
	free(str);
	return (result);
}
