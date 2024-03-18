/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:50:35 by jakim             #+#    #+#             */
/*   Updated: 2024/03/19 02:03:23 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
    static t_list	*save;
    char                *ptr;
    char                *pre;
	int					tmp;
	int					size;
    
	ptr = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	size = BUFFER_SIZE;
	while(ft_lstsize(save) < (fd + 1))
		ft_lstadd_back(&save, ft_lstnew());
	pre = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while(1)
    {
		ptr = ft_strdup(ptr, size); 
		if (ft_lstindex(save, fd)->content)
		{
			tmp = ft_strchr(ft_lstindex(save, fd)->content, '\n');
			ft_strncat(ptr, ft_lstindex(save, fd)->content, tmp + 1);
			if (tmp < (int)ft_strlen(ft_lstindex(save, fd)->content))
			{
				free(pre);
				pre = ft_lstindex(save, fd)->content;
				ft_lstindex(save, fd)->content = ft_substr(pre, tmp + 1, BUFFER_SIZE);
				free(pre);
				break ;
			}
			//ft_strncat(ptr, save, size);
			size += BUFFER_SIZE;
			ptr = ft_strdup(ptr, size);
			free(ft_lstindex(save, fd)->content);
			ft_lstindex(save, fd)->content = NULL;
		}
        tmp = read(fd, pre, BUFFER_SIZE);
		if (!*ptr && !ft_lstindex(save, fd)->content && tmp <= 0)
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
			ft_lstindex(save, fd)->content = ft_substr(pre, tmp + 1, BUFFER_SIZE);
			free(pre);
			break ;
		}
		size += BUFFER_SIZE;
    }
	return (ptr);
}
