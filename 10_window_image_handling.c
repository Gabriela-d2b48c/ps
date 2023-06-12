/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_window_image_handling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:03:54 by gabriela          #+#    #+#             */
/*   Updated: 2023/06/12 15:26:00 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Allocate and load images of the player */
void	ft_load_player_images(t_struct *game)
{
	game->sprite[4] = malloc(sizeof(t_sprite));
	game->sprite[4]->sprite = mlx_xpm_file_to_image(game->vars.mlx, sprite_W_EAST,
			&(game->sprite[4]->width), &(game->sprite[4]->height));
	game->sprite[6] = malloc(sizeof(t_sprite));
	game->sprite[6]->sprite = mlx_xpm_file_to_image(game->vars.mlx, sprite_W_WEST,
			&(game->sprite[6]->width), &(game->sprite[6]->height));
}

/* Allocate and load images of other characters */
void	ft_load_images(t_struct *game)
{
	game->sprite[0] = malloc(sizeof(t_sprite));
	game->sprite[0]->sprite = mlx_xpm_file_to_image(game->vars.mlx,
			sprite_TILE_MUD, &(game->sprite[0]->width),
			&(game->sprite[0]->height));
	game->sprite[1] = malloc(sizeof(t_sprite));
	game->sprite[1]->sprite = mlx_xpm_file_to_image(game->vars.mlx, sprite_WALL,
			&(game->sprite[1]->width), &(game->sprite[1]->height));
	game->sprite[2] = malloc(sizeof(t_sprite));
	game->sprite[2]->sprite = mlx_xpm_file_to_image(game->vars.mlx,
			sprite_COLLECTIBLE, &(game->sprite[2]->width),
			&(game->sprite[2]->height));
	game->sprite[3] = malloc(sizeof(t_sprite));
	game->sprite[3]->sprite = mlx_xpm_file_to_image(game->vars.mlx, sprite_EXIT,
			&(game->sprite[3]->width), &(game->sprite[3]->height));
	game->sprite[8] = malloc(sizeof(t_sprite));
	game->sprite[8]->sprite = mlx_xpm_file_to_image(game->vars.mlx, sprite_ENEMY,
			&(game->sprite[8]->width), &(game->sprite[8]->height));
	ft_load_player_images(game);
}

/* Print the game starting message */
void	ft_start_message(t_struct *game)
{
	mlx_string_put(game->vars.mlx, game->vars.mlx_win, 10, 20,
		0xFFFFFFFF, GAME_INSTRUCTIONS_1);
	mlx_string_put(game->vars.mlx, game->vars.mlx_win, 10, 35,
		0xFFFFFFFF, GAME_INSTRUCTIONS_2);
	mlx_string_put(game->vars.mlx, game->vars.mlx_win, 10, 50,
		0xFFFFFFFF, GAME_INSTRUCTIONS_3);
}

void	ft_handle_sprites(t_struct *game)
{
	game->vars.mlx_win = mlx_new_window(game->vars.mlx,
			game->vars.window_width, game->vars.window_height,
			GAME_TITLE);
	ft_load_images(game);
	ft_occupy_map(game);
	ft_start_message(game);
	ft_info_message(game);
}