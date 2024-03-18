/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:50:35 by jakim             #+#    #+#             */
/*   Updated: 2024/03/19 01:11:01 by jakim            ###   ########.fr       */
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
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	size = BUFFER_SIZE;
	pre = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while(1)
    {
		ptr = ft_strdup(ptr, size);
		if (save)
		{
			tmp = ft_strchr(save, '\n');
			ft_strncat(ptr, save, tmp + 1);
			if (tmp < (int)ft_strlen(save))
			{
				free(pre);
				pre = save;
				save = ft_substr(pre, tmp + 1, BUFFER_SIZE);
				free(pre);
				break ;
			}
			//ft_strncat(ptr, save, size);
			size += BUFFER_SIZE;
			ptr = ft_strdup(ptr, size);
			free(save);
			save = NULL;
		}
        tmp = read(fd, pre, BUFFER_SIZE);
		if (!*ptr && !save && tmp <= 0)
		{
			free(pre);
			free(ptr);
			return (NULL);
		}
		pre[tmp] = 0;
		tmp = ft_strchr(pre, '\n');
		ft_strncat(ptr, pre, tmp + 1);
		if (tmp < BUFFER_SIZE)
		{
			save = ft_substr(pre, tmp + 1, BUFFER_SIZE);
			free(pre);
			break ;
		}
		size += BUFFER_SIZE;
    }
	return (ptr);
}
