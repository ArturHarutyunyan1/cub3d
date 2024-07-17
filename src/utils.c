/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <arturhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:39:51 by arturhar          #+#    #+#             */
/*   Updated: 2024/07/18 00:50:03 by arturhar         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../include/cub.h"
void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int is_identifier(const char *line)
{
    if (ft_strncmp(line, "NO", 2) == 0
        || ft_strncmp(line, "SO", 2) == 0
        || ft_strncmp(line, "EA", 2) == 0
        || ft_strncmp(line, "WE", 2) == 0
        || ft_strncmp(line, "C", 1) == 0
        || ft_strncmp(line, "F", 1) == 0)
            return (1);
        return (0);
}

void	remove_extra_spaces(char *dup, char *trimmed_line)
{
	int	i;
	int	j;
	int	flg;

	i = 0;
	j = 0;
	flg = 0;
	while (dup[i])
	{
		if ((dup[i] == ' ' || dup[i] == '\t') && flg == 0)
		{
			trimmed_line[j++] = ' ';
			flg = 1;
		}
		else if (dup[i] != ' ' && dup[i] != '\t')
		{
			trimmed_line[j++] = dup[i];
			flg = 0;
		}
		i++;
	}
	trimmed_line[j] = '\0';
}

int	ft_exit(t_game *game, char *msg, int status)
{
	printf("%s", msg);
	if (status == 2)
	{
		mlx_destroy_image(game->vars.mlx, game->textures[0].img);
		mlx_destroy_image(game->vars.mlx, game->textures[1].img);
		mlx_destroy_image(game->vars.mlx, game->textures[2].img);
		mlx_destroy_image(game->vars.mlx, game->textures[3].img);
		mlx_destroy_image(game->vars.mlx, game->img.img);
		mlx_destroy_window(game->vars.mlx, game->vars.mlx_win);
	}
	free_matrix(game->map.grid);
	exit(status);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	exit_game(t_game *game)
{
	ft_exit(game, "Game was closed successfully\n", 0);
	return (0);
}

void	cleanup(t_game *game)
{
	free_matrix(game->map.grid);
	free(game->map.no);
	free(game->map.so);
	free(game->map.we);
	free(game->map.ea);
	free(game->map.f);
	free(game->map.c);
}
