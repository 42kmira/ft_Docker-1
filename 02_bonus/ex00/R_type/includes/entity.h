/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:43:10 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 15:22:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "game_structs.h"

typedef union s_pawn t_pawn;
typedef struct	s_normal_level t_normal_level;

typedef struct	s_entity
{
	char			*type;
	t_sprite		sprites;
	void			(*update)(t_pawn *, t_normal_level *);
	int				x;
	int				y;
}				t_entity;

typedef union	u_spawn_bullet
{
	void		(*spawn)(t_pawn *pawn, int row, int col);
}				t_spawn_bullet;

typedef union	s_bullet
{
	t_entity	e;
	struct
	{
		t_entity	e;
	}			class;
}				t_bullet;

typedef union	s_spaceship
{
	t_entity	e;
	struct
	{
		t_entity		e;
		t_spawn_bullet	bullet;
		int				hitpoints;
	}			class;
}				t_spaceship;

typedef	union	s_enemy01
{
	t_entity		e;
	struct
	{
		t_entity	e;
		int			hitpoints;
	}				class;
}			t_enemy01;

typedef	union	s_enemy02
{
	t_entity		e;
	struct
	{
		t_entity	e;
		int			hitpoints;
	}				class;
}			t_enemy02;

typedef union s_pawn
{
	t_entity	type_entity;
	t_enemy01	type_enemy01;
	t_enemy02	type_enemy02;
	t_spaceship	type_spaceship;
	t_bullet	type_bullet;
}				t_pawn;

#endif
