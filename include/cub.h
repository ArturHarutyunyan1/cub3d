/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:39:00 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/18 01:46:14 by arturhar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CUB_H
# define CUB_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include <stdbool.h>
# include <math.h>

// Default window size

# define WIDTH 800
# define HEIGHT 600

// Keycodes

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.03
# define KEY_COUNT 256

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;

typedef struct s_map
{
	int		is_all_set;
	int		width;
	int		height;
	char	*f;
	char	*c;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	**grid;
	char	*path;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_mouse
{
	int last_x;
}t_mouse;

typedef struct s_rays
{
	double	camera_x;
	double	camera_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	wall_y;
	double	step;
	double	tex_pos;
	int		direction;
	int		horizontal;
	int		vertical;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_rays;

typedef struct s_valid
{
    int     count_no;
    int     count_so;
    int     count_ea;
    int     count_we;
    int     count_c;
    int     count_f;
}t_valid;

typedef struct s_game
{
	t_vars		vars;
	t_map		map;
	t_img		img;
	t_texture	textures[4];
	t_texture	sprite[4];
	t_rays		rays;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_mouse		mouse;
	t_valid     valid;
    t_list      *file;
	int			key_states[KEY_COUNT];
}	t_game;

void	free_matrix(char **matrix);
int	ft_isspace(int c);
int	ft_strcmp(const char *str1, const char *str2);
int	contains_only_whitespace(const char *str);
int is_identifier(const char *line);
void	remove_extra_spaces(char *dup, char *trimmed_line);
void read_file_into(t_list **file, char *path);
void extract_paths(t_game *game);
void extract_map(t_game *game, char *path);
void	validate(t_game *game, char *path);
int	ft_exit(t_game *game, char *msg, int status);
t_map	init_map(char **str);
int is_valid_line(char *line);
void	init_game(t_game *game);
int	game_loop(t_game *game);
int	keyrelease(int code, t_game *game);
int	keypress(int code, t_game *game);
void	get_sides(t_game *game);
void	set_step_and_side_dist_x(t_game *game);
void	set_step_and_side_dist_y(t_game *game);
int	mouse_move(int x, int y, t_game *game);
void	init_mouse(t_game *game);
void	move_forward(t_game *game);
void	move_backwards(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	set_dir(char c, t_game *game);
void	init_player(t_game *game);
void	update_player(t_game *game);
void	setup(t_game *game, int x);
void	dda(t_game *game);
void	calculate_perp_wall_dist_and_direction(t_game *game);
void	calculate_draw_limits_and_tex_x(t_game *game);
void	raycaster(t_game *game);
void	draw_floor_and_ceiling(t_game *game);
void	clear_image(t_game *game);
void	check_inits(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);
t_color	set_colors(char *str);
void	init_img(t_game *game);
void	init_rays(t_game *game);
char	*set_path(int i, char *path, t_game *game);
void	init_textures(t_game *game);
void draw_sprite(t_game *game);
int	exit_game(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
