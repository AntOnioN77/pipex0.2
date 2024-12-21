/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:08:26 by antofern          #+#    #+#             */
/*   Updated: 2024/12/11 00:38:35 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ring.h"
#include "../headers/libft.h"

int	ring_swap(t_ring *ring)
{
	int	tmp;

	if (ring->fill < 2)
		return (ERROR);
	tmp = ring_get_head(ring);
	ring->buff[ring->head] = ring_get_level(ring, 1);
	ring->buff[ring_next_index(ring->head, ring->slots)] = tmp;
	return (0);
}
