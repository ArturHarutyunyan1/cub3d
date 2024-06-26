#ifndef CUB
#define CUB

#include "../libft/include/libft.h"
#include "../mlx/mlx.h"
#include <stdbool.h>

typedef struct s_map
{
    int rows;
    int cols;
} t_map;

typedef struct s_player
{
    int x;
    int y;
} t_player;

typedef struct s_game
{
    void *mlx;
    void *mlx_win;
    char **map;
    char *t_line;
    char *trim;
    int map_width;
    int map_height;
    int x;
    int y;

} t_game;

void	validation(int argc, char **argv);
bool check_format(char *path);
void exit_program(char *msg, int status);
int	get_size(char *path);
char	**read_map(char *path);
t_map	get_dimensions(char **str);
void	free_matrix(char **matrix);
void	validate_map(char *path);
void	check_chars(char c);
bool	surrounded_by_walls(char **map);

#endif