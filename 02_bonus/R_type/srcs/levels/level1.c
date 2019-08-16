/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:30:58 by kmira             #+#    #+#             */
/*   Updated: 2019/08/10 19:37:44 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

#define SPRITE_COUNT_LEVEL_1 500

t_normal_level	*alloc__of_level_1(void)
{
	t_normal_level *result;

	result = malloc(sizeof(*result));
	bzero(result, sizeof(*result));

	result->exit_condition = 1;
	result->game_tick = 0;
	result->score = 0;

	result->screen = malloc(sizeof(*result->screen));
	result->screen->window = init_setup();

	result->name = "Level One";

	result->sprites = malloc(sizeof(*(result->sprites)) * (SPRITE_COUNT_LEVEL_1));
	bzero(result->sprites, sizeof(*(result->sprites)) * (SPRITE_COUNT_LEVEL_1));

	result->entities = malloc(sizeof(*(result->entities)) * (SPRITE_COUNT_LEVEL_1));
	bzero(result->entities, sizeof(*(result->entities)) * (SPRITE_COUNT_LEVEL_1));

	result->entities[0].type_spaceship = spawn_player(1);
	result->player = result->entities[0].type_spaceship;

	return (result);
}

void			update_of_level_1(t_normal_level *level_1_cont)
{
	int	i;

	i = 0;
	bzero(level_1_cont->sprites, sizeof(*(level_1_cont->sprites)) * (SPRITE_COUNT_LEVEL_1));
	while (level_1_cont->entities[i].type_entity.sprites.sprite != NULL)
	{
		level_1_cont->entities[i].type_entity.update(&level_1_cont->entities[i], level_1_cont);
		level_1_cont->sprites[i] = level_1_cont->entities[i].type_entity.sprites;
		level_1_cont->sprites[i].screen_x = level_1_cont->entities[i].type_entity.x;
		level_1_cont->sprites[i].screen_y = level_1_cont->entities[i].type_entity.y;
		i++;
	}
	if (level_1_cont->game_tick % 7 == 0 && rand_min_max(0, 5) == 1)
	{
		level_1_cont->entities[i].type_enemy01 = spawn_enemy01();
		level_1_cont->sprites[i] = level_1_cont->entities[i].type_entity.sprites;
		level_1_cont->sprites[i].screen_x = level_1_cont->entities[i].type_entity.x;
		level_1_cont->sprites[i].screen_y = level_1_cont->entities[i].type_entity.y;
		i++;
	}
	if (level_1_cont->game_tick % 75 == 0)
	{
		level_1_cont->entities[i].type_enemy02 = spawn_enemy02();
		level_1_cont->sprites[i] = level_1_cont->entities[i].type_entity.sprites;
		level_1_cont->sprites[i].screen_x = level_1_cont->entities[i].type_entity.x;
		level_1_cont->sprites[i].screen_y = level_1_cont->entities[i].type_entity.y;
		i++;
	}

	clean_up_empty_sprites(level_1_cont->entities, level_1_cont->sprites);

	i = 0;
	while (level_1_cont->entities[i].type_entity.sprites.sprite != NULL)
		i++;

	int hp = (level_1_cont->entities[0].type_spaceship.class.hitpoints) / 20;
	level_1_cont->sprites[i].sprite = hitpoints_sprite();
	level_1_cont->sprites[i].sprite_attribute = hitpoints_attribute();
	memset(level_1_cont->sprites[i].sprite, '/', hp);
	level_1_cont->sprites[i].sprite[hp] = '\0';
	level_1_cont->sprites[i].screen_x = level_1_cont->entities[0].type_entity.x;
	level_1_cont->sprites[i].screen_y = level_1_cont->entities[0].type_entity.y - 2;

	level_1_cont->sprites[i + 1] = NULL_SPRITE;

	level_1_cont->game_tick = level_1_cont->game_tick + 1;
}

void			clean__of_level_1(t_normal_level *level_1_cont)
{
	(void)level_1_cont;
	return ;
}

void			enter_level_1(int *scene)
{
	SCENE_LOOP(normal_level, level_1);
	(void)scene;
}
