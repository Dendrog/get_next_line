/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:50:35 by jakim             #+#    #+#             */
/*   Updated: 2024/03/18 00:29:11 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *save;
    char                *ptr;
    char                *pre;
	int					tmp;
	int					size;
    
	ptr = 0;
	size = BUFFER_SIZE;
	pre = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while(1)
    {
		ptr = ft_strdup(ptr, size);
		if (save)
		{
			ft_strncat(ptr, save, size);
			ptr = ft_strdup(ptr, size);
			free(save);
			save = 0;
		}
        tmp = read(fd, pre, BUFFER_SIZE);
		pre[tmp] = 0;
		tmp = ft_strchr(pre, '\n');
		ft_strncat(ptr, pre, tmp);
		if (tmp < BUFFER_SIZE)
		{
			save = ft_substr(pre, tmp, BUFFER_SIZE);
			free(pre);
			break ;
		}
		size += BUFFER_SIZE;
    }
	return (ptr);
}