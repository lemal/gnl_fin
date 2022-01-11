/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:10:31 by tapulask          #+#    #+#             */
/*   Updated: 2021/11/24 11:10:38 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_find_n(t_type	*var, char	*str)
{
	int	count;

	count = 0;
	while (str && str[count])
	{
		if (str[count] == '\n')
		{
			var->n_loc = &str[count];
			break ;
		}
		count++;
	}
}

char	*ft_ret_and_rem(t_type	*var, char	**str)
{
	char	*temp;
	size_t	len;

	len = (var->n_loc + 1) - *str;
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	ft_write(*str, 0, temp, len);
	if (var->ret)
		free(var->ret);
	var->ret = ft_strjoin(NULL, temp);
	free(temp);
	len = ft_strlen(var->n_loc + 1);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	ft_write(var->n_loc + 1, 0, temp, len);
	var->rem = ft_strjoin(NULL, temp);
	free(*str);
	*str = var->rem;
	free(temp);
	return (var->ret);
}

char	*ft_no_n_ret(t_type	*var, char	**str)
{
	char	*temp;
	size_t	len;

	if (!*str[0])
	{
		free(*str);
		*str = NULL;
		return (NULL);
	}
	len = ft_strlen(*str);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	temp[len] = '\0';
	ft_write(*str, 0, temp, len);
	free(*str);
	*str = NULL;
	if (var->ret)
		free(var->ret);
	var->ret = ft_strjoin(NULL, temp);
	free(temp);
	return (var->ret);
}

void	ft_setup(t_type *var)
{
	var->n_loc = NULL;
	var->ret = NULL;
	var->num_read = 1;
}

char	*get_next_line(int fd)
{
	t_type		var;
	char		buf[BUFFER_SIZE + 1];
	static char	*buf_collect;

	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	ft_setup(&var);
	ft_find_n(&var, buf_collect);
	while (!var.n_loc && var.num_read)
	{
		var.num_read = read(fd, buf, BUFFER_SIZE);
		buf[var.num_read] = '\0';
		buf_collect = ft_strjoin(buf_collect, buf);
		ft_find_n(&var, buf_collect);
	}
	if (var.n_loc)
	{
		if (!ft_ret_and_rem(&var, &buf_collect))
			return (NULL);
		return (var.ret);
	}
	if (!ft_no_n_ret(&var, &buf_collect))
		return (NULL);
	return (var.ret);
}
