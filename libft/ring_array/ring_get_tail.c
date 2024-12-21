/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_get_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:45:45 by antofern          #+#    #+#             */
/*   Updated: 2024/12/11 00:33:10 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ring.h"

/*Returns the value contained in the last element of the array*/
int	ring_get_tail(t_ring *ring)
{
	if (ring->fill == 0)
		return (0);
	return (ring->buff[ring->tail]);
}
