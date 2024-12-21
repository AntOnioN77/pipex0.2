/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_pop_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:49:16 by antofern          #+#    #+#             */
/*   Updated: 2024/12/11 00:37:06 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ring.h"
#include "../headers/libft.h"

/* If the stack becomes empty after popping `if (ring->fill == 0)`, we
compensate for ring_add_head() adding to buff[head -1], thus ensuring that the
first element inserted afterwards becomes both head and tail. */
int	ring_pop_head(t_ring *ring)
{
	if (ring->fill > 0)
	{
		ring->buff[ring->head] = 0;
		ring->head = ring_next_index(ring->head, ring->slots);
		ring->fill--;
		if (ring->fill == 0)
			ring->head = ring_next_index(ring->head, ring->slots);
		return (OK);
	}
	else
		return (EMPTY_STACK);
}
