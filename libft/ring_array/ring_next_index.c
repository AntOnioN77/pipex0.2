/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_next_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:39:33 by antofern          #+#    #+#             */
/*   Updated: 2024/12/11 00:36:11 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ring->buff[index] ... when we talk about index, we are not referring to the
position with respect to head, but to the position in the classic buffer that
we use to "simulate circular behavior"
Receives <index>, and t_ring.slots. Returns the next index. When <index> is
the last valid index of the buffer t_ring.buff, it will return 0 (first index),
according to the circular logic*/
int	ring_next_index(int index, int slots)
{
	return ((index + 1) % slots);
}
