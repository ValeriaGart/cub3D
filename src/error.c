#include "../incl/cub3d.h"

void	*ft_error_msg(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	return (NULL);
}