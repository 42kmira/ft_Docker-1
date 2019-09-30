/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 21:23:26 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 01:30:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include <ncurses.h>

/*
** If necessary one can create another map view for 'particle-effects'
** and print it ontop of the previous one after it has been printed.
**
** There is also no need for erasing the window because the entire game
** screen is being overwritten.
*/

void	render_sprites(t_sprite sprite_frame, WINDOW *window)
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = sprite_frame.screen_y;
	col = sprite_frame.screen_x;
	while (sprite_frame.sprite[i] != '\0')
	{
		if (sprite_frame.sprite[i] == ' ')
			col = col + 1;
		else if (sprite_frame.sprite[i] == '\n')
		{
			row = row + 1;
			col = sprite_frame.screen_x;
		}
		else
		{
			wattron(window, sprite_frame.sprite_attribute[i]);
			mvwaddch(window, row, col, sprite_frame.sprite[i]);
			wattroff(window, sprite_frame.sprite_attribute[i]);
			col = col + 1;
		}
		i++;
	}
}

void	render(t_sprite *sprites, t_screen *screen)
{
	int	j;

	wclear(screen->window);
	j = 0;
	while (sprites[j].sprite != NULL)
	{
		render_sprites(sprites[j], screen->window);
		j++;
	}
	box(screen->window, 0, 0);
	wrefresh(screen->window);
}
