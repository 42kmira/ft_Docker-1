/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:02:12 by kmira             #+#    #+#             */
/*   Updated: 2019/08/10 19:39:38 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

/*
** Fires two '>' bullets
*/

void		fire_bullet01(t_pawn *entities, int row, int col)
{
	int i;

	i = 0;
	while (entities[i].type_entity.sprites.sprite != NULL)
		i++;
	entities[i].type_bullet = spawn_bullet01();
	entities[i].type_entity.x = col + 2;
	entities[i].type_entity.y = row;
	while (entities[i].type_entity.sprites.sprite  != NULL)
		i++;
	entities[i].type_bullet = spawn_bullet01();
	entities[i].type_entity.x = col + 2;
	entities[i].type_entity.y = row + 4;
	return ;
}

/*
** Fires two '*' bullets
*/

void		fire_bullet02(t_pawn *entities, int row, int col)
{
	int i;

	i = 0;
	while (entities[i].type_entity.sprites.sprite != NULL)
		i++;
	entities[i].type_bullet = spawn_bullet02();
	entities[i].type_entity.x = col + 3;
	entities[i].type_entity.y = row + 1;
	while (entities[i].type_entity.sprites.sprite  != NULL)
		i++;
	entities[i].type_bullet = spawn_bullet02();
	entities[i].type_entity.x = col + 3;
	entities[i].type_entity.y = row + 3;
	return ;
}

/*
** Changed the ship type and the types of bullets spawned
*/

void		use_special(t_spaceship *player)
{
	if (player->e.sprites.sprite == spaceship01_sprite())
	{
		player->e.sprites.sprite = spaceship02_sprite();
		player->e.sprites.sprite_attribute = spaceship02_attributes();
		player->class.bullet.spawn = fire_bullet02;
	}
	else
	{
		player->class.e.sprites.sprite = spaceship01_sprite();
		player->e.sprites.sprite_attribute = spaceship01_attributes();
		player->class.bullet.spawn = fire_bullet01;
	}
}

/*
** Testing healing powerup
*/

void		use_heal(t_spaceship *player)
{
	player->class.hitpoints = player->class.hitpoints + 100;
	if (player->class.hitpoints > MAX_HP)
		player->class.hitpoints = MAX_HP;
}
