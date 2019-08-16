/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 22:00:55 by kmira             #+#    #+#             */
/*   Updated: 2019/08/07 16:31:58 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "default.h"

char	*spaceship01_sprite(void)
{
	static char *spaceship_char_sprite;

	if (spaceship_char_sprite != 0)
		return (spaceship_char_sprite);
	else
		spaceship_char_sprite = " c>\n>*\n [=)\n>*\n c>";
	return (spaceship_char_sprite);
}

int		*spaceship01_attributes(void)
{
	static int *spaceship_attribute;

	if (spaceship_attribute != 0)
		return (spaceship_attribute);
	spaceship_attribute = malloc(sizeof(*spaceship_attribute) * (19));
	spaceship_attribute[0] = COLOR_PAIR(0);
	spaceship_attribute[1] = COLOR_PAIR(0);
	spaceship_attribute[2] = COLOR_PAIR(6) | A_BOLD;
	spaceship_attribute[3] = COLOR_PAIR(0);
	spaceship_attribute[4] = COLOR_PAIR(4);
	spaceship_attribute[5] = COLOR_PAIR(0);
	spaceship_attribute[6] = COLOR_PAIR(0);
	spaceship_attribute[7] = COLOR_PAIR(0);
	spaceship_attribute[8] = COLOR_PAIR(0);
	spaceship_attribute[9] = COLOR_PAIR(7) | A_BOLD;
	spaceship_attribute[10] = COLOR_PAIR(0);
	spaceship_attribute[11] = COLOR_PAIR(0);
	spaceship_attribute[12] = COLOR_PAIR(4);
	spaceship_attribute[13] = COLOR_PAIR(0);
	spaceship_attribute[14] = COLOR_PAIR(0);
	spaceship_attribute[15] = COLOR_PAIR(0);
	spaceship_attribute[16] = COLOR_PAIR(0);
	spaceship_attribute[17] = COLOR_PAIR(6) | A_BOLD;
	spaceship_attribute[18] = COLOR_PAIR(0);
	return (spaceship_attribute);
}

char	*spaceship02_sprite(void)
{
	static char *spaceship_char_sprite;

	if (spaceship_char_sprite != 0)
		return (spaceship_char_sprite);
	else
		spaceship_char_sprite = "^\n*EEE\no\n*EEE\nv\n";
	return (spaceship_char_sprite);
}

int		*spaceship02_attributes(void)
{
	static int *spaceship_attribute;

	if (spaceship_attribute != 0)
		return (spaceship_attribute);
	spaceship_attribute = malloc(sizeof(*spaceship_attribute) * (15));
	spaceship_attribute[0] = COLOR_PAIR(13);
	spaceship_attribute[1] = COLOR_PAIR(0);
	spaceship_attribute[2] = COLOR_PAIR(4);
	spaceship_attribute[3] = COLOR_PAIR(13);
	spaceship_attribute[4] = COLOR_PAIR(14);
	spaceship_attribute[5] = COLOR_PAIR(14);
	spaceship_attribute[6] = COLOR_PAIR(0);
	spaceship_attribute[7] = COLOR_PAIR(0);
	spaceship_attribute[8] = COLOR_PAIR(0);
	spaceship_attribute[9] = COLOR_PAIR(4);
	spaceship_attribute[10] = COLOR_PAIR(13);
	spaceship_attribute[11] = COLOR_PAIR(14);
	spaceship_attribute[12] = COLOR_PAIR(14);
	spaceship_attribute[13] = COLOR_PAIR(0);
	spaceship_attribute[14] = COLOR_PAIR(13);
	return (spaceship_attribute);
}

char	*enemy01_sprite(void)
{
	static char *enemy01_char_sprite;

	if (enemy01_char_sprite != 0)
		return (enemy01_char_sprite);
	else
		enemy01_char_sprite = " /\n<+\n o\n<+\n \\";
	return (enemy01_char_sprite);
}

int		*enemy01_attribute(void)
{
	static int	*enemy01_attribute;

	if (enemy01_attribute != 0)
		return (enemy01_attribute);
	enemy01_attribute = malloc(sizeof(*enemy01_attribute) * (15));
	enemy01_attribute[0] = COLOR_PAIR(0);
	enemy01_attribute[1] = COLOR_PAIR(4);
	enemy01_attribute[2] = COLOR_PAIR(0);
	enemy01_attribute[3] = COLOR_PAIR(6) | A_BOLD;
	enemy01_attribute[4] = COLOR_PAIR(12);
	enemy01_attribute[5] = COLOR_PAIR(0);
	enemy01_attribute[6] = COLOR_PAIR(0);
	enemy01_attribute[7] = COLOR_PAIR(0);
	enemy01_attribute[8] = COLOR_PAIR(0);
	enemy01_attribute[9] = COLOR_PAIR(6) | A_BOLD;
	enemy01_attribute[10] = COLOR_PAIR(12);
	enemy01_attribute[11] = COLOR_PAIR(0);
	enemy01_attribute[12] = COLOR_PAIR(0);
	enemy01_attribute[13] = COLOR_PAIR(4);
	enemy01_attribute[14] = COLOR_PAIR(0);
	return (enemy01_attribute);
}

char	*enemy02_sprite(void)
{
	static char *enemy02_char_sprite;

	if (enemy02_char_sprite != 0)
		return (enemy02_char_sprite);
	else
		enemy02_char_sprite = " *\n*o*\n *";
	return (enemy02_char_sprite);
}

int		*enemy02_attribute(void)
{
	static int	*enemy02_attribute;

	if (enemy02_attribute != 0)
		return (enemy02_attribute);
	enemy02_attribute = malloc(sizeof(*enemy02_attribute) * (9));
	enemy02_attribute[0] = COLOR_PAIR(0);
	enemy02_attribute[1] = COLOR_PAIR(13);
	enemy02_attribute[2] = COLOR_PAIR(0);
	enemy02_attribute[3] = COLOR_PAIR(13);
	enemy02_attribute[4] = COLOR_PAIR(4);
	enemy02_attribute[5] = COLOR_PAIR(13);
	enemy02_attribute[6] = COLOR_PAIR(0);
	enemy02_attribute[7] = COLOR_PAIR(0);
	enemy02_attribute[8] = COLOR_PAIR(13);
	return (enemy02_attribute);
}

char	*bullet01_sprite(void)
{
	static char *bullet_sprite;

	if (bullet_sprite != 0)
		return (bullet_sprite);
	else
		bullet_sprite = ">";
	return (bullet_sprite);
}

int		*bullet01_attribute(void)
{
	static int	*bullet_attribute;

	if (bullet_attribute != 0)
		return (bullet_attribute);
	bullet_attribute = malloc(sizeof(*bullet_attribute) * (1));
	bullet_attribute[0] = COLOR_PAIR(6) | A_BOLD;
	return (bullet_attribute);
}

char	*bullet02_sprite(void)
{
	static char *bullet_sprite;

	if (bullet_sprite != 0)
		return (bullet_sprite);
	else
		bullet_sprite = "*";
	return (bullet_sprite);
}

int		*bullet02_attribute(void)
{
	static int	*bullet_attribute;

	if (bullet_attribute != 0)
		return (bullet_attribute);
	bullet_attribute = malloc(sizeof(*bullet_attribute) * (1));
	bullet_attribute[0] = COLOR_PAIR(4) | A_BOLD;
	return (bullet_attribute);
}

char	*main_menu_sprite(void)
{
	static char	*main_menu_sprite;

	if (main_menu_sprite != 0)
		return (main_menu_sprite);
	main_menu_sprite = "  ___________________  _____  _________ ___________\n /   _____/\\______   \\/  _  \\ \\_   ___ \\_   _____/\n \\_____  \\  |     ___/  /_\\  \\/    \\  \\/ |    __)_ \n /        \\ |    |  /    |    \\     \\____|        \\\n/_______  / |____|  \\____|__  /\\______  /_______  /\n        \\/                  \\/        \\/        \\/ \n                            _____ ________         \n                           /  |  |\\_____  \\        \n                          /   |  |_/  ____/        \n                         /    ^   /       \\        \n                         \\____   |\\_______ \\       \n                              |__|        \\/       ";
	return (main_menu_sprite);
}

int		*main_menu_attribute(void)
{
	static int	*main_menu_attribute;
	int			j;

	if (main_menu_attribute != 0)
		return (main_menu_attribute);
	main_menu_attribute = malloc(sizeof(*main_menu_attribute) * (623));
	bzero(main_menu_attribute, sizeof(*main_menu_attribute) * (623));
	j = 0;
	while (j < 623)
	{
		main_menu_attribute[j] = COLOR_PAIR(6) | A_BOLD;
		j++;
	}
	return (main_menu_attribute);
}

char	*hitpoints_sprite(void)
{
	static char	*hitpoints_sprite;

	if (hitpoints_sprite != 0)
		return (hitpoints_sprite);
	hitpoints_sprite = strdup("//////////////////////////////////////////////////");
	return (hitpoints_sprite);
}

int		*hitpoints_attribute(void)
{
	static int	*hitpoints_attribute;

	if (hitpoints_attribute != 0)
		return (hitpoints_attribute);
	hitpoints_attribute = malloc(sizeof(*hitpoints_attribute) * (51));
	hitpoints_attribute[0] = COLOR_PAIR(4);
	hitpoints_attribute[1] = COLOR_PAIR(4);
	hitpoints_attribute[2] = COLOR_PAIR(4);
	hitpoints_attribute[3] = COLOR_PAIR(4);
	hitpoints_attribute[4] = COLOR_PAIR(4) | A_BOLD;
	hitpoints_attribute[5] = COLOR_PAIR(4) | A_BOLD;
	hitpoints_attribute[6] = COLOR_PAIR(4) | A_BOLD;
	hitpoints_attribute[7] = COLOR_PAIR(4) | A_BOLD;
	hitpoints_attribute[8] = COLOR_PAIR(4) | A_BOLD;
	hitpoints_attribute[9] = COLOR_PAIR(4) | A_BOLD;
	hitpoints_attribute[10] = COLOR_PAIR(13) | A_BOLD;
	hitpoints_attribute[11] = COLOR_PAIR(13) | A_BOLD;
	hitpoints_attribute[12] = COLOR_PAIR(13) | A_BOLD;
	hitpoints_attribute[13] = COLOR_PAIR(13) | A_BOLD;
	hitpoints_attribute[14] = COLOR_PAIR(13) | A_BOLD;
	hitpoints_attribute[15] = COLOR_PAIR(14) | A_BOLD;
	hitpoints_attribute[16] = COLOR_PAIR(14) | A_BOLD;
	hitpoints_attribute[17] = COLOR_PAIR(14) | A_BOLD;
	hitpoints_attribute[18] = COLOR_PAIR(14) | A_BOLD;
	hitpoints_attribute[19] = COLOR_PAIR(14) | A_BOLD;
	hitpoints_attribute[20] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[21] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[22] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[23] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[24] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[25] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[26] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[27] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[28] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[29] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[30] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[31] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[32] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[33] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[34] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[35] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[36] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[37] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[38] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[39] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[40] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[41] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[42] = COLOR_PAIR(15) | A_BOLD;
	hitpoints_attribute[43] = COLOR_PAIR(6) | A_BOLD;
	hitpoints_attribute[44] = COLOR_PAIR(6) | A_BOLD;
	hitpoints_attribute[45] = COLOR_PAIR(6) | A_BOLD;
	hitpoints_attribute[46] = COLOR_PAIR(6) | A_BOLD;
	hitpoints_attribute[47] = COLOR_PAIR(6) | A_BOLD;
	hitpoints_attribute[48] = COLOR_PAIR(6) | A_BOLD;
	hitpoints_attribute[49] = COLOR_PAIR(6) | A_BOLD;
	hitpoints_attribute[50] = COLOR_PAIR(6) | A_BOLD;

	return (hitpoints_attribute);
}

