#include "../include/cub.h"

void display_map_data(t_map *map)
{
    printf("Map Data:\n");
    printf("  - North Texture: %s\n", map->no ? map->no : "Not set");
    printf("  - South Texture: %s\n", map->so ? map->so : "Not set");
    printf("  - East Texture: %s\n", map->ea ? map->ea : "Not set");
    printf("  - West Texture: %s\n", map->we ? map->we : "Not set");
    printf("  - Ceiling Color: %s\n", map->c ? map->c : "Not set");
    printf("  - Floor Color: %s\n", map->f ? map->f : "Not set");
    for (int i = 0; map->grid[i]; i++)
    {
        printf("%s", map->grid[i]);
    }
}

void init_game(char *argv)
{
    t_game game;
    
    game.map.grid = read_map(argv);
    game.map.width = 8;
    game.map.height = 5;
    init_rays(&game);
    init_img(&game);
    init_player(&game);
    get_paths(&game, argv);
    display_map_data(&game.map); 
    // game.vars.mlx = mlx_init();
    // game.vars.mlx_win = mlx_new_window(game.vars.mlx, WIDTH, HEIGHT, "Cub3D");
    // game.img.img = mlx_new_image(game.vars.mlx, WIDTH, HEIGHT);
    // game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
    // mlx_hook(game.vars.mlx_win, 17, 0, exit_game, &game);
    // mlx_loop(game.vars.mlx);
}