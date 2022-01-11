/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:10:46 by tapulask          #+#    #+#             */
/*   Updated: 2021/11/24 11:10:49 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_struct
{
	char		*ret;
	char		*rem;
	char		*n_loc;
	ssize_t		num_read;
	short int	nl_or_nt;
	int			n_count;

}	t_type;
char	*get_next_line(int fd);
size_t	ft_strlen(char	const	*str);
void	ft_write(char	const	*str,
			size_t current_loc, char *ptr_to_arr, int len);
char	*ft_strjoin(char	const	*s1, char	const	*s2);
#endif
