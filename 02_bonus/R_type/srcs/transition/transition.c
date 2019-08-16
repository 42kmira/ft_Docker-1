/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 04:53:19 by kmira             #+#    #+#             */
/*   Updated: 2019/08/06 15:26:24 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"

void	transition(int from, int destination)
{
	if (destination == MAIN_MENU)
		enter_main_menu(&destination);
	else if (destination == LEVEL_01)
		enter_level_1(&destination);
	else if (destination == EXIT_SCENE)
		enter_exit_scene(&destination);
	else if (destination != NULL_SCENE)
		printf("Misdirection!");
	(void)from;
}
