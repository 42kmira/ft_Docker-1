/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:41:32 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 15:52:48 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>

int			rand_min_max(int min, int max)
{
	int a;

	if (min >= max)
		return (0);
	a = (rand() % (max + 1 - min)) + min;
	return (a);
}
