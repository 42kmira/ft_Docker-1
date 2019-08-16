/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   levels_common.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:54:24 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 15:47:10 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

#define KEY_ITER 1

int			break__of_normal_level(t_normal_level *level_cont)
{
	int result;

	result = 1;
	if (level_cont->player.e.x > GAME_COLS || level_cont->player.e.x < -1)
		result = 0;
	if (level_cont->player.e.y > GAME_ROWS || level_cont->player.e.y < -1)
		result = 0;
	if (level_cont->player.class.hitpoints <= ZERO_HP)
		result = 0;
	if (level_cont->exit_condition == 0)
		result = 0;
	if (result == 0)
		level_cont->scenes.destination = EXIT_SCENE;
	return (result);
}

void		listen_of_normal_level(WINDOW *window, t_game_input *input)
{
	int				j;
	char			in_char;

	input->keys_pressed = 0;
	j = 0;
	while (j < KEY_ITER)
	{
		in_char = wgetch(window);
		if (in_char == 'w')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_UP;
		if (in_char == 's')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_DOWN;
		if (in_char == 'a')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_LEFT;
		if (in_char == 'd')
			input->keys_pressed = input->keys_pressed | FLAG_MOVE_RIGHT;
		if (in_char == ' ')
			input->keys_pressed = input->keys_pressed | FLAG_FIRE;
		if (in_char == 't')
			input->keys_pressed = input->keys_pressed | FLAG_SPECIAL;
		if (in_char == 'h')
			input->keys_pressed = input->keys_pressed | FLAG_HEAL;
		j++;
	}
	return ;
}

void		clean_up_empty_sprites(t_pawn *entities, t_sprite *sprites)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (entities[j].type_entity.sprites.sprite != NULL)
		j++;
	while (entities[i].type_entity.sprites.sprite != NULL)
	{
		if (entities[i].type_entity.sprites.sprite == (char *)1)
		{
			while (&entities[i] < &entities[j] &&
			(entities[j].type_entity.sprites.sprite == NULL
			|| entities[j].type_entity.sprites.sprite == (char *)1))
				j--;
			entities[i] = entities[j];
			sprites[i] = entities[i].type_entity.sprites;
			entities[j].type_entity.sprites = NULL_SPRITE;
			sprites[j] = NULL_SPRITE;
		}
		i++;
	}
}

