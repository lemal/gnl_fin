/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:10:59 by tapulask          #+#    #+#             */
/*   Updated: 2021/11/24 11:11:01 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	const *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_write(char	const *str,
					size_t current_loc, char *ptr_to_arr, int len)
{
	size_t	i;

	i = 0;
	while (str[i] && len)
	{
		ptr_to_arr[current_loc] = str[i];
		current_loc++;
		i++;
		len--;
	}
}

char	*ft_strjoin(char	const *s1, char	const *s2)
{
	size_t	len_1;
	size_t	len_2;
	char	*ptr_to_first;

	len_1 = 0;
	if (s1)
		len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	ptr_to_first = (char *)malloc(sizeof(char) * (len_1 + len_2) + 1);
	if (ptr_to_first == NULL)
		return (NULL);
	if (s1)
		ft_write(s1, 0, ptr_to_first, len_1);
	ft_write(s2, len_1, ptr_to_first, len_2);
	ptr_to_first[len_1 + len_2] = '\0';
	if (s1)
	{
		free((char *)s1);
		s1 = NULL;
	}
	return (ptr_to_first);
}
