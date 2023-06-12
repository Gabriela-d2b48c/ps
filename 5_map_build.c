/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_map_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:28:17 by gabriela          #+#    #+#             */
/*   Updated: 2023/06/12 14:59:15 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Put the right images in the grid based on the characters in the map 
(01CXEP). Return a sprite with the player facing either left or right */
void	*ft_character_sprite(t_struct *game, int col, int row)
{
	if (game->gta.map[row][col] == '0')
		return (game->sprite[0]->sprite);
	if (game->gta.map[row][col] == '1')
		return (game->sprite[1]->sprite);
	if (game->gta.map[row][col] == 'C')
		return (game->sprite[2]->sprite);
	if (game->gta.map[row][col] == 'X')
		return (game->sprite[8]->sprite);
	if (game->gta.map[row][col] == 'E')
		return (game->sprite[3]->sprite);
	if (game->gta.map[row][col] == 'P')
	{
		if (game->key == 42 || game->key == D || game->last_key == D)
			return (game->sprite[4]->sprite);
		else if (game->key == A || game->last_key == A)
			return (game->sprite[6]->sprite);
	}
	return (0);
}

/* Clear the window to prepare for a new frame. Fill the map with tiles,
then fill the map with corresponding characters */
void	ft_occupy_map(t_struct *game)
{
	int	col;
	int	row;

	mlx_clear_window(game->vars.mlx, game->vars.mlx_win);
	row = 0;
	col = 0;
	while (row < game->gta.map_height)
	{
		while (col < game->gta.map_width)
		{
			if (game->gta.map[row][col] != '1')
				mlx_put_image_to_window(game->vars.mlx,
					game->vars.mlx_win, game->sprite[0]->sprite,
					game->vars.img_size * col, game->vars.img_size * row);
			mlx_put_image_to_window(game->vars.mlx, game->vars.mlx_win,
				ft_which_sprite(game, col, row), game->vars.img_size * col,
				game->vars.img_size * row);
			col++;
		}
		row++;
	}
}
