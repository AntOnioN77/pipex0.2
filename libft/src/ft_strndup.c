/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:09:01 by antofern          #+#    #+#             */
/*   Updated: 2024/12/21 14:12:22 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strndup(const char *src, int length)
{
	char	*new_string;
	int		i;

	new_string = (char *)malloc((length + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_string[i] = src[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
