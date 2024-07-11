
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:40:08 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/11 17:22:46 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void validate(char *path)
{
    t_game game;

    if (!check_format(path))
        exit(printf("Error\nInvalid format\n"));
    game.map.grid = read_map(path);
    game.map = init_map(game.map.grid);
    check_map(game.map.grid);
    if (!surrounded_by_walls(&game))
        ft_exit(&game, "Error\nMap is not surrounded by walls\n", 1);
    if (!check_chars(&game))
        ft_exit(&game, "Error\nInvalid characters in map\n", 1);
}

bool check_format(char *line)
{
    int len;

    len = ft_strlen(line);
    if (ft_strncmp(line + len - 4, ".cub", 4))
        return (false);
    return (true);
}

bool surrounded_by_walls(t_game *game)
{
    int i;
    char *trim;

    i = 0;
    trim = ft_strtrim(game->map.grid[0], " \t\n");
    if (!trim)
        return (false);
    while (trim[i])
    {
        if (trim[i] != '1')
            return (false);
        i++;
    }
    i = 0;
    free (trim);
    trim = ft_strtrim(game->map.grid[game->map.height], " \t\n");
    while (trim[i])
    {
        if (trim[i] != '1')
            return (false);
        i++;
    }
    return (true);
}


bool check_chars(t_game *game)
{
    int i;
    int j;
    int count;
    char c;

    i = 0;
    count = 0;
    while (game->map.grid[i])
    {
        j = 0;
        while (game->map.grid[i][j])
        {
            c = game->map.grid[i][j];
            if (c == 'N'
                || c == 'S'
                || c == 'W'
                || c == 'E')
                count++;
            else if (c != '1' && c != '0' && c != '\n' && c != ' ' && c != '\t')
                return (false);
            j++;
        }
        i++;
    }
    if (count != 1)
        return (false);
    return (true);
}
