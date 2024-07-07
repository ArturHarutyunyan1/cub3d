#include "../include/cub.h"

void move_forward(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
    new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
    if (game->map.grid[(int)new_y][(int)game->player.x] != '1')
        game->player.y = new_y;
    if (game->map.grid[(int)game->player.y][(int)new_x] != '1')
        game->player.x = new_x;
}

void move_backwards(t_game *game)
{
    double new_x;
    double new_y;
    
    new_x = game->player.x - game->player.dir_x * MOVE_SPEED;
    new_y = game->player.y - game->player.dir_y * MOVE_SPEED;
    if (game->map.grid[(int)new_y][(int)game->player.x] != '1')
        game->player.y = new_y;
    if (game->map.grid[(int)game->player.y][(int)new_x] != '1')
        game->player.x = new_x;
}

void move_left(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.x - game->player.plane_x * MOVE_SPEED;
    new_y = game->player.y - game->player.plane_y * MOVE_SPEED;
    if (game->map.grid[(int)new_y][(int)game->player.x] != '1')
        game->player.y = new_y;
    if (game->map.grid[(int)game->player.y][(int)new_x] != '1')
        game->player.x = new_x;
}

void move_right(t_game *game)
{
    double new_x;
    double new_y;

    new_x = game->player.x + game->player.plane_x * MOVE_SPEED;
    new_y = game->player.y + game->player.plane_y * MOVE_SPEED;
    if (game->map.grid[(int)new_y][(int)game->player.x] != '1')
        game->player.y = new_y;
    if (game->map.grid[(int)game->player.y][(int)new_x] != '1')
        game->player.x = new_x;
}

void rotate_left(t_game *game)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(ROTATE_SPEED) - game->player.dir_y * sin(ROTATE_SPEED);
    game->player.dir_y = old_dir_x * sin(ROTATE_SPEED) + game->player.dir_y * cos(ROTATE_SPEED);
    old_plane_x = game->player.plane_x;
    game->player.plane_x = game->player.plane_x * cos(ROTATE_SPEED) - game->player.plane_y * sin(ROTATE_SPEED);
    game->player.plane_y = old_plane_x * sin(ROTATE_SPEED) + game->player.plane_y * cos(ROTATE_SPEED);
}

void rotate_right(t_game *game)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(-ROTATE_SPEED) - game->player.dir_y * sin(-ROTATE_SPEED);
    game->player.dir_y = old_dir_x * sin(-ROTATE_SPEED) + game->player.dir_y * cos(-ROTATE_SPEED);
    old_plane_x = game->player.plane_x;
    game->player.plane_x = game->player.plane_x * cos(-ROTATE_SPEED) - game->player.plane_y * sin(-ROTATE_SPEED);
    game->player.plane_y = old_plane_x * sin(-ROTATE_SPEED) + game->player.plane_y * cos(-ROTATE_SPEED);
}

void update_player(t_game *game)
{
    if (game->key_states[KEY_W])
        move_forward(game);
    if (game->key_states[KEY_S])
        move_backwards(game);
    if (game->key_states[KEY_A])
        move_left(game);
    if (game->key_states[KEY_D])
        move_right(game);        
    if (game->key_states[LEFT_ARROW])
        rotate_left(game);
    if (game->key_states[RIGHT_ARROW])
        rotate_right(game);
}
