/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_normal_level.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 07:34:29 by kmira             #+#    #+#             */
/*   Updated: 2019/08/10 19:16:16 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_NORMAL_LEVEL_H
# define SCENE_NORMAL_LEVEL_H

# include "default.h"

typedef struct		s_normal_level
{
	char			*name;
	struct
	{
		int			at;
		int			destination;
	}				scenes;

	t_game_input	input;

	t_char_map		map;
	t_screen		*screen;

	int				exit_condition;
	int				game_tick;
	int				score;

	t_sprite		*sprites;
	t_pawn			*entities;

	t_spaceship		player;

}					t_normal_level;

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MACROS
*/

/*
** MAX HP is 100 but multiplied with 10 to have at least a precision of 1
**
** ZERO_HP is 9 because 10 is 1.0 HP. We can lower this to 5 or 0 to give
** players last second chances!
*/

# define MAX_HP 1000
# define ZERO_HP 9

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: levels_common.c
*/

int					break__of_normal_level(t_normal_level *level_1_cont);
void				listen_of_normal_level(WINDOW *window, t_game_input *input);
void				clean_up_empty_sprites(t_pawn *entities, t_sprite *sprites);

t_spaceship			spawn_player(int no);

t_bullet			spawn_bullet01(void);
t_bullet			spawn_bullet02(void);

t_enemy01			spawn_enemy01(void);
t_enemy02			spawn_enemy02(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: level_spawners.c
*/

t_spaceship			spawn_player(int no);
t_bullet			spawn_bullet01(void);
t_bullet			spawn_bullet02(void);
t_enemy01			spawn_enemy01(void);
t_enemy02			spawn_enemy02(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: level_entity_update.c
*/

void				player_step(t_pawn *pawn, t_normal_level *level_cont);
void				bullet_step(t_pawn *pawn, t_normal_level *level_cont);
void				enemy01_step(t_pawn *pawn, t_normal_level *level_cont);
void				enemy02_step(t_pawn *pawn, t_normal_level *level_cont);
void				enemy_bullet_step(t_pawn *pawn, t_normal_level *level_cont);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: weapons.c
*/

void				fire_bullet01(t_pawn *sprites, int row, int col);
void				fire_bullet02(t_pawn *sprites, int row, int col);
void				use_special(t_spaceship *player);
void				use_heal(t_spaceship *player);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: level_utils.c
*/

int					rand_min_max(int min, int max);

#endif
