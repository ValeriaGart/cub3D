/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynguyen <ynguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:50:56 by ynguyen           #+#    #+#             */
/*   Updated: 2024/03/14 19:25:37 by ynguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_buffer(char *save, int fd)
{
	int		check;
	char	*buffer;

	check = 42;
	buffer = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(save, '\n') == 0 && check > 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (free(buffer), free(save), NULL);
		if (check == 0 && !save)
		{
			free(buffer);
			free(save);
			return (ft_strdup(""));
		}
		buffer[check] = '\0';
		save = ft_stringjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*ft_finishline(char *save)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	new[i] = '\0';
	while (i--)
		new[i] = save[i];
	return (new);
}

char	*ft_saverest(char *save)
{
	char			*temp;
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	if (save[i] == '\n')
		i++;
	while (save[i + k] != '\0')
		k++;
	temp = malloc(k + 1);
	if (!temp)
		return (NULL);
	temp[k] = '\0';
	while (k--)
		temp[k] = save[i + k];
	free(save);
	return (temp);
}

char	*get_next_line(int fd, int freee)
{
	static char	*save[4096];
	char		*out;

	if (freee == 1)
	{
		if (save[fd] != NULL)
			free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_buffer(save[fd], fd);
	if (save[fd] == NULL)
		return (NULL);
	if (save[fd][0] == '\0')
		return (save[fd]);
	out = ft_finishline(save[fd]);
	save[fd] = ft_saverest(save[fd]);
	return (out);
}

/*
int	main(void)
{
	int		fd;
	int		i;
	char	*buf;

	i = 1;
	fd = open("hello.txt", O_RDONLY);
	while (i < 10)
		printf("%i: %s\n", i++, get_next_line(fd));
	return (0);
}

char	*ft_finishline(char *save)
{
	char	*new;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
	{
		i++;
	}
	if (save[i] == '\n') // überprüft ob save noch eine neue Line hat.
		i++;             // plus extra \n in save
	new = ft_calloc(i + 1, 1);
	i = 0; //i fängt wieder bei 0 an.
	while (save[i] && save[i] != '\n')
	{
		new[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		new[i] = save[i];
	//oder new[i] = '\n';
	return (new);
}
*/
