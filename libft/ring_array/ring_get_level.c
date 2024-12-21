/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_get_level.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:56:45 by antofern          #+#    #+#             */
/*   Updated: 2024/12/11 00:32:52 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ring.h"

/* returns the value contained in the nth element of the list, considering
that the 0th element is ring->buff[ring->head] */
int	ring_get_level(const t_ring *ring, t_level level)
{
	int	index;

	if (level >= ring->fill || level <= -(ring->fill))
		return (0);
	if (level < 0)
	{
		level = ring->fill + level;
	}
	index = (level + ring->head) % ring->slots ;
	return (ring->buff[index]);
}
