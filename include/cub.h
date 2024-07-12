/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:39:00 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/12 23:42:06 by arturhar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CUB
#define CUB

#include "../libft/include/libft.h"
#include "../mlx/mlx.h"
#include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>
#include <math.h>

// Default window size

#define WIDTH 800
#define HEIGHT 600

// Keycodes

# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_ESC XK_Escape
#define LEFT_ARROW XK_Left
#define RIGHT_ARROW 124
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
#define MOVE_SPEED 0.05
#define ROTATE_SPEED 0.03
#define KEY_COUNT 256

typedef struct s_vars
{
    void *mlx;
    void *mlx_win;
}t_vars;

typedef struct s_map
{
    int is_all_set;
    int width;
    int height;
    char *f;
    char *c;
    char *no;
    char *so;
    char *ea;
    char *we;
    char **grid;
}t_map;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_color
{
    int r;
    int g;
    int b;
}t_color;

typedef struct s_texture
{
    void    *img;
    char    *addr;
    int     width;
    int     height;
    int     bpp;
    int     line_length;
    int     endian;
}           t_texture;

typedef struct s_player
{
    double x;
    double y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
}t_player;

typedef struct s_rays
{
    double camera_x;
    double camera_y;
    double ray_dir_x;
    double ray_dir_y;
    double delta_dist_x;
    double delta_dist_y;
    double side_dist_x;
    double side_dist_y;
    double perp_wall_dist;
    double wall_x;
    double wall_y;
    double step;
    double tex_pos;
    int direction;
    int horizontal;
    int vertical;
    int line_height;
    int draw_start;
    int draw_end;
    int tex_x;
    int tex_y;
    int map_x;
    int map_y;
    int step_x;
    int step_y;
    int hit;
    int side;
}t_rays;

typedef struct s_game
{
    t_vars vars;
    t_map map;
    t_img img;
    t_texture textures[4];
    t_rays rays;
    t_color floor;
    t_color ceiling;
    t_player player;
    int key_states[KEY_COUNT];
}t_game;

void init_game(char *argv);
int keypress(int code, t_game *game);
int keyrelease(int code, t_game *game);
int game_loop(t_game *game);
int	check(char s);
void check_map(char **map, size_t j);
int get_size(char *path);
char **trim_map(char **map);
char **skip_newlines(char **map, int size);
void compare_maps(char **map, char **trim);
char **read_map(char *path);
void check_path(t_game *game, char *line);
void process_line(t_game *game, char *line);
int	ft_isspace(int c);
int	contains_only_whitespace(const char *str);
void get_paths(t_game *game, char *path);
void set_dir(char c, t_game *game);
void init_player(t_game *game);
t_map init_map(char **str);
void move_forward(t_game *game);
void move_backwards(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);
void rotate_left(t_game *game);
void rotate_right(t_game *game);
void update_player(t_game *game);
void raycaster(t_game *game);
void draw_floor_and_ceiling(t_game *game);
void clear_image(t_game *game);
void check_inits(t_game *game);
t_color set_colors(char *str);
void init_img(t_game *game);
void init_rays(t_game *game);
void init_textures(t_game *game);
void	free_matrix(char **matrix);
int	ft_exit(t_game *game, char *msg, int status);
void my_mlx_pixel_put(t_img *img, int x, int y, int color);
int exit_game(t_game *game);
void validate(char *path);
bool check_format(char *line);
bool surrounded_by_walls(t_game *game);
bool	check_chars(t_game *game, int i, int j, int count);
void cleanup(t_game *game);
char *get_trimmed_line(int fd);
char **allocate_map(int size);
void read_and_trim_lines(int fd, char **map);
char **finalize_map(char **map, int size);
void remove_extra_spaces(char *dup, char *trimmed_line);
void check_and_process_path(t_game *game, char *trimmed_line);
void trim_and_process_line(t_game *game, char *dup, char *trimmed_line);
void process_line(t_game *game, char *line);
void dda(t_game *game);
void get_sides(t_game *game);
void	setup(t_game *game, int x);
void calculate_perp_wall_dist_and_direction(t_game *game);
void calculate_draw_limits_and_tex_x(t_game *game);
void set_step_and_side_dist_x(t_game *game);
void set_step_and_side_dist_y(t_game *game);

#endif