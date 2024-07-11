/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:39:41 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/10 06:39:42 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

int get_size(char *path)
{
    int fd;
    int flag;
    int map_size;
    char *line;

    fd = open(path, O_RDONLY);
    flag = 1;
    map_size = 0;
    while (flag)
    {
        line = get_next_line(fd);
        if (line == NULL)
        {
            if (map_size == 0)
                return (-1);
            flag = 0;
        }
        else
            map_size++;
        free (line);
    }
    close (fd);
    return (map_size);
}

char **read_map(char *path)
{
    int i;
    int fd;
    int count;
    char *line;
    char *trim;
    char **map;

    i = 0;
    count = get_size(path);
    fd = open(path, O_RDONLY);
    if (fd < 0)
        exit(printf("Error\nCannot read map!\n"));
    map = (char **)malloc((count + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    line = get_next_line(fd);
    trim = ft_strtrim(line, " \t\n");
    while (line && !(trim[0] == '1'))
    {
        free (line);
        free (trim);
        line = get_next_line(fd);
        trim = ft_strtrim(line, " \t\n");
    }
    while (line && trim[0] == '1')
    {
        map[i] = malloc((ft_strlen(line) + 1));
        if (!map[i])
            free (map);
        ft_strlcpy(map[i], line, ft_strlen(line) + 1);
        i++;
        free (line);
        free (trim);
        line = get_next_line(fd);
        trim = ft_strtrim(line, " \t\n");
    }
    map[i] = NULL;
    free (trim);
    free (line);
    close (fd);
    return (map);
}