/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_find_nth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:33:27 by antofern          #+#    #+#             */
/*   Updated: 2024/12/11 00:30:38 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ring.h"

/* returns the number that will be in the nth position when the stack is
sorted */
int	ring_find_nth(t_ring *ring, int n_elements, int nth)
{
	int	i;
	int	j;
	int	counter;

	j = 0;
	while (j < n_elements)
	{
		i = 0;
		counter = 0;
		while (i < n_elements)
		{
			if (ring_get_level(ring, j) > ring_get_level(ring, i))
				counter++;
			i++;
		}
		if (counter == nth)
			return (ring_get_level(ring, j));
		j++;
	}
	return (0);
}
