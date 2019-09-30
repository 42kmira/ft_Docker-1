/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:13:34 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 16:32:18 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULT_H
# define DEFAULT_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** GAME CONSTANTS
*/

# define GAME_ROWS (50)
# define GAME_COLS (160)

# define TOP_WINDOW_CLIP (2)
# define SIDE_WINDOW_CLIP (2)

# define WIN_ROWS (GAME_ROWS + (TOP_WINDOW_CLIP * 2))
# define WIN_COLS (GAME_COLS + (SIDE_WINDOW_CLIP * 2))

# define VIEW_OFFSET (WIN_COLS * (TOP_WINDOW_CLIP) + SIDE_WINDOW_CLIP)

# define TOTAL_WIN_CHAR WIN_ROWS * WIN_COLS

# define GAME_TICK 25000

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include "macros.h"
# include "game_structs.h"
# include "entity.h"

# include <ncurses.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>


/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** LAUNCH SCENES
*/

void	enter_main_menu(int *scene);
void	enter_level_1(int *scene);
void	enter_exit_scene(int *scene);

void	transition(int from, int destination);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: render.c
*/

void	render(t_sprite *sprites, t_screen *screen);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: preperation.c
*/

WINDOW	*init_setup(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: assets.c
*/

char	*spaceship01_sprite(void);
int		*spaceship01_attributes(void);

char	*spaceship02_sprite(void);
int		*spaceship02_attributes(void);

char	*enemy01_sprite(void);
int		*enemy01_attribute(void);

char	*bullet01_sprite(void);
int		*bullet01_attribute(void);

char	*bullet02_sprite(void);
int		*bullet02_attribute(void);

char	*main_menu_sprite(void);
int		*main_menu_attribute(void);

char	*hitpoints_sprite(void);
int		*hitpoints_attribute(void);

char	*enemy02_sprite(void);
int		*enemy02_attribute(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: guns.c
*/

#endif
