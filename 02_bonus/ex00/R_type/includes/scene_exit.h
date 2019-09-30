/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_exit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:00:52 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 16:15:43 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_EXIT_H
# define SCENE_EXIT_H

# include "default.h"

typedef struct		s_exit
{
	struct
	{
		int			at;
		int			destination;
	}				scenes;

	t_game_input	input;

	t_char_map		map;

	int				exit_condition;

	t_sprite		*sprites;

	t_screen		*screen;
}					t_exit;

int					_break_of_exit(struct s_exit *exit_cont);
t_exit				*_alloc_of_exit(void);
void				listen_of_exit(WINDOW *window, t_game_input *input);
void				update_of_exit(t_exit *exit_cont);
void				_clean_of_exit(void);

#endif
