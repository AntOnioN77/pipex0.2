/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_index_get_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:48:04 by antofern          #+#    #+#             */
/*   Updated: 2024/12/11 00:33:52 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ring.h"

/* Returns the level corresponding to an index in the circular buffer array.
The initial level is 0. A level of -1 indicates that the stack does not contain
any element at that position. */
int	ring_index_get_level(t_ring *ring, int index)
{
	int	result;

	result = (index - ring->head + ring->slots) % ring->slots;
	if ((result +1) > ring->fill)
		return (-1);
	return (result);
}
