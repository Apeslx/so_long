/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:52:07 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/08 18:47:01 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	ft2_strcpy(t_prog *mlx, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	mlx->map_path = (char *)malloc(sizeof(char) * i + 1);
	if (mlx->map_path == NULL)
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		mlx->map_path[i] = str[i];
		i++;
	}
	mlx->map_path[i] = '\0';
	return (0);
}

int	exit_game(t_prog *mlx, int type)
{
	int	a;

	a = 0;
	if (type == 1)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
		while (a < 9)
		{
			mlx_destroy_image(mlx->mlx, mlx->img_ptr[a]);
			mlx->img_ptr[a] = NULL;
			a++;
		}
		mlx->win = NULL;
	}
	mlx->mlx = NULL;
	exit(0);
	return (0);
}

void	store_exit(t_prog *mlx, int i, int j)
{
	mlx->num_exits++;
	mlx->exit_x = i * 32;
	mlx->exit_y = j * 32;
}

void	inicialize_var(t_prog *mlx)
{
	mlx->num_players = 0;
	mlx->num_exits = 0;
	mlx->num_collect = 0;
	mlx->collect_taken = 0;
}

void	render_loop(t_prog *mlx)
{
	int	fd;
	int	j;

	j = 0;
	fd = open(mlx->map_path, O_RDONLY);
	while (j < mlx->map_height)
	{
		render_map(&*mlx, j, fd);
		j++;
	}
	close(fd);
}
