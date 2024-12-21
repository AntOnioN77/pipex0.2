/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_prev_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:10:40 by antofern          #+#    #+#             */
/*   Updated: 2024/12/11 00:37:35 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Receives <index>, and t_ring.slots. Returns the previous index. When <index>
is 0, it will return the last index of the buffer t_ring.buff, according to the
circular logic*/
int	ring_prev_index(int index, int slots)
{
	return ((index - 1 + slots) % slots);
}
