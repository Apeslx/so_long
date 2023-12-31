/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:16:04 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/11 20:26:44 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 53
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2

typedef struct s_program
{
	void	*mlx;
	void	*win;
	char	*img_path[16];
	void	*img_ptr[16];
	int		valid_c;
	int		valid_e;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		k;
	char	**map;
	char	*map_path;
	int		num_players;
	int		num_exits;
	int		num_collect;
	int		collect_taken;
}	t_prog;

void	move_player(t_prog *mlx, int direction, int img);
int		press_key(int key, t_prog *mlx);
int		exit_game(t_prog *mlx, int type);
void	render_map(t_prog *mlx, int j, int fd);
void	store_map(t_prog *mlx);
void	init_img(t_prog *mlx);
void	create_window(t_prog *mlx);
void	check_walls(t_prog *mlx);
void	error_msg(int type, t_prog *mlx);
void	check_square(t_prog *mlx);
void	check_lines(t_prog *mlx);
void	inicialize_var(t_prog *mlx);
void	store_exit(t_prog *mlx, int i, int j);
int		animate(t_prog *mlx);
int		get_path(t_prog *mlx, char *str);
void	render_loop(t_prog *mlx);
void	check_ber(char *str);
void	floodfill(char **map, t_prog *mlx, int p_x, int p_y);
void	get_map(t_prog *mlx);
void	check_path(t_prog *mlx);
void	free_mem(t_prog *mlx);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*get_stash(int fd, char *stash);
char	*ft_strjoin_v2(char *stash, char *buffer);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *c);
char	*clean_stash(char *stash);
char	*get_lines(char *stash);

#endif