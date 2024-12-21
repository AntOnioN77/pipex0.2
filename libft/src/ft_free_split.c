/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antofern <antofern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:48:33 by antofern          #+#    #+#             */
/*   Updated: 2024/12/10 23:37:25 by antofern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	ft_free_split(char **args)
{
	char	**temp;

	if (!args)
		return ;
	temp = args;
	while (*temp)
	{
		free(*temp);
		*temp = NULL;
		temp++;
	}
	free(args);
}
