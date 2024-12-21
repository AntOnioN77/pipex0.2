/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:02:27 by antofern          #+#    #+#             */
/*   Updated: 2024/12/11 00:35:24 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ring.h"
#include <stdlib.h>

/* Allocates space for a struct t_ring and for the buffer contained in it.
The maximum capacity of the array will be the parameter size.
The buffer (buff) has a size of size+1, to avoid that some subsequent functions
require different logic depending on whether the buffer is full or empty.
`circular_array->head = size / 2 + 1;`
-`size / 2` we aim to keep head and tail away from the end of the array, since
copying ring[0] to ring[50] is the most costly operation possible.
-`+1`ring_add_head() places an element at head-1, so that with a single element
head and tail are at the same position, we need to start with head advanced
(head = tail+1)
Head: element at the top (level 0)
Tail: last element of the array
Fill: number of elements currently in the array
Max_fill: maximum number of elements that can be stored in the array
Slots: always equal to max_fill+1, ensuring there is always at least one empty
index in the buffer, facilitating the implementation of the functions that
manipulate it. The returned pointer must be freed with ring_free*/
t_ring	*ring_init(int size)
{
	t_ring	*circular_array;

	circular_array = (t_ring *)malloc(sizeof(t_ring));
	if (circular_array == NULL)
		return (NULL);
	circular_array->buff = (int *)malloc(sizeof(int) * (size + 1));
	if (circular_array->buff == NULL)
	{
		free(circular_array);
		return (NULL);
	}
	circular_array->head = size / 2 + 1;
	circular_array->tail = size / 2;
	circular_array->fill = 0;
	circular_array->max_fill = size;
	circular_array->slots = size + 1;
	return (circular_array);
}
