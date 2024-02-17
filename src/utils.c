#include "../incl/cub3d.h"

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

int ft_atoi_from_malloc(char *str)
{
	int result;

	result = ft_atoi(str);
	free(str);
	return (result);
}
