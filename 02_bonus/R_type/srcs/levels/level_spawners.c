/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_spawners.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:41:17 by kmira             #+#    #+#             */
/*   Updated: 2019/08/10 19:25:42 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_normal_level.h"

t_spaceship	spawn_player(int no)
{
	t_spaceship	player;

	player.e.type = strdup("Player_n");
	player.e.type[7] = no + '0';
	player.e.sprites.sprite = spaceship02_sprite();
	player.e.sprites.sprite_attribute = spaceship02_attributes();
	player.e.update = player_step;
	player.class.hitpoints = 100;
	player.e.x = 5;
	player.e.y = 5;
	player.class.bullet.spawn = fire_bullet02;
	return (player);
}


t_bullet	spawn_bullet01(void)
{
	t_bullet	bullet;

	bullet.e.type = strdup("Bullet");
	bullet.e.sprites.sprite = bullet01_sprite();
	bullet.e.sprites.sprite_attribute = bullet01_attribute();
	bullet.e.update = bullet_step;
	return (bullet);
}

t_bullet	spawn_bullet02(void)
{
	t_bullet	bullet;

	bullet.e.type = strdup("Bullet");
	bullet.e.sprites.sprite = bullet02_sprite();
	bullet.e.sprites.sprite_attribute = bullet02_attribute();
	bullet.e.update = bullet_step;
	return (bullet);
}

t_enemy01	spawn_enemy01(void)
{
	t_enemy01	enemy;

	enemy.e.type = strdup("enemy");
	enemy.e.sprites.sprite = enemy01_sprite();
	enemy.e.sprites.sprite_attribute = enemy01_attribute();
	enemy.e.update = enemy01_step;
	enemy.class.hitpoints = 100;
	enemy.e.x = GAME_COLS - 1;
	enemy.e.y = rand_min_max(3, GAME_ROWS - 3);
	return (enemy);
}

t_enemy02	spawn_enemy02(void)
{
	t_enemy02	enemy;

	enemy.e.type = strdup("enemy");
	enemy.e.sprites.sprite = enemy02_sprite();
	enemy.e.sprites.sprite_attribute = enemy02_attribute();
	enemy.e.update = enemy02_step;
	enemy.class.hitpoints = 100;
	enemy.e.x = GAME_COLS - 1;
	enemy.e.y = rand_min_max(3, GAME_ROWS - 3);
	return (enemy);
}
