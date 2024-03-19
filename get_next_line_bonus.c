/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:50:35 by jakim             #+#    #+#             */
/*   Updated: 2024/03/20 01:08:58 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstadd_back(t_list **lst)
{
	t_list	*ptr;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!lst || !new)
		return ;
	new->content = 0;
	new->next = NULL;
	if (!(*lst))
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	new->next = NULL;
	ptr->next = new;
}

t_list	*ft_lstindex(t_list *lst, int *i, int version)
{
	int	k;

	if (!lst)
		return (NULL);
	if (version)
	{
		k = (*i);
		while (lst->next && k > 0)
		{
			lst = lst->next;
			k--;
		}
		return (lst);
	}
	else
	{
		(*i) = 0;
		while (lst)
		{
			lst = lst->next;
			(*i)++;
		}
		return (0);
	}
}

int	ch_save(char	**save, char **ptr, char **pre, int *size)
{
	int	tmp;

	if (*save)
	{
		tmp = ft_strchr(*save, '\n');
		ft_strncat(*ptr, *save, tmp + 1);
		if (tmp < (int)ft_strlen(*save))
		{
			free(*pre);
			(*pre) = (*save);
			*save = ft_substr(*pre, tmp + 1, BUFFER_SIZE);
			free(*pre);
			return (1);
		}
		(*size) += BUFFER_SIZE;
		*ptr = ft_strdup(*ptr, *size);
		free(*save);
		(*save) = NULL;
	}
	return (0);
}

int	make_string(char **save, char **ptr, char **pre, int fd)
{
	int	tmp;

	tmp = read(fd, *pre, BUFFER_SIZE);
	if (!(**ptr) && !(*save) && tmp <= 0)
	{
		free(*pre);
		free(*ptr);
		(*ptr) = NULL;
		return (-1);
	}
	(*pre)[tmp] = 0;
	tmp = ft_strchr(*pre, '\n');
	ft_strncat(*ptr, *pre, tmp + 1);
	if (tmp < BUFFER_SIZE)
	{
		*save = ft_substr(*pre, tmp + 1, BUFFER_SIZE);
		free(*pre);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*save;
	char			*ptr;
	char			*pre;
	int				size;

	ptr = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	size = 0;
	while (size++ < (fd + 1))
		ft_lstadd_back(&save);
	size = BUFFER_SIZE;
	pre = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!pre)
		return (NULL);
	while (1)
	{
		ptr = ft_strdup(ptr, size);
		if (ch_save(&(ft_lstindex(save, &fd, 1)->content), &ptr, &pre, &size))
			break ;
		if (make_string(&(ft_lstindex(save, &fd, 1)->content), &ptr, &pre, fd))
			break ;
		size += BUFFER_SIZE;
	}
	return (ptr);
}
