/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <mnathali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:05:08 by mnathali          #+#    #+#             */
/*   Updated: 2022/03/25 13:05:11 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_atoi(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (16777215);
	i = 0;
	j = 0;
	while (str[i] == ',' || str[i] == '0' || str[i] == 'x')
		i++;
	while ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 65 && str[i] <= 70)
		|| (str[i] >= 97 && str[i] <= 102))
	{
		if (str[i] >= 48 && str[i] <= 57)
			j = j * 16 + (str[i] - '0');
		else if (str[i] >= 65 && str[i] <= 70)
			j = j * 16 + 10 + (str[i] - 'A');
		else if ((str[i] >= 97 && str[i] <= 102))
			j = j * 16 + 10 + (str[i] - 'a');
		i++;
	}
	return (j);
}
