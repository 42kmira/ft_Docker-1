/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:53:26 by kmira             #+#    #+#             */
/*   Updated: 2019/08/06 15:01:16 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"
#include "scene_exit.h"

int		break__of_exit(t_exit *exit_cont)
{
	sleep(1);
	(void)exit_cont;
	return (0);
}

t_exit	*alloc__of_exit(void)
{
	t_exit *result;

	result = malloc(sizeof(*result));
	bzero(result, sizeof(*result));

	result->screen = malloc(sizeof(*result->screen));
	result->screen->window = init_setup();

	result->sprites = malloc(sizeof(*(result->sprites)) * (2));
	bzero(result->sprites, sizeof(*(result->sprites)) * (2));

	result->sprites[0].sprite = "Thank you for playing!";
	result->sprites[0].sprite_attribute = malloc(sizeof(int) * 100);
	bzero(result->sprites[0].sprite_attribute, sizeof(int) * 100);
	result->sprites[0].screen_x = 2;
	result->sprites[0].screen_y = 2;

	result->scenes.destination = NULL_SCENE;

	return (result);
}

void	listen_of_exit(WINDOW *window, t_game_input *input)
{
	(void)window;
	(void)input;
}

void	update_of_exit(t_exit *exit_cont)
{
	(void)exit_cont;
}

void	clean__of_exit(t_exit *exit_cont)
{
	(void)exit_cont;
}

void	enter_exit_scene(int *scene)
{
	SCENE_LOOP(exit, exit);
	(void)scene;
}
