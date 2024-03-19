/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakim <jakim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:50:20 by jakim             #+#    #+#             */
/*   Updated: 2024/03/19 02:05:38 by jakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	char	*ptr;

	if (!s)
		return (NULL);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (mem == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*mem = 0;
		return (mem);
	}
	len = len + start;
	ptr = mem;
	while (start < len)
	{
		*ptr = s[start];
		if (*ptr == 0)
			return (mem);
		ptr++;
		start++;
	}
	*ptr = 0;
	//free(s);
	return (mem);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (1)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i);
		if (!s[i])
			return (i);
		i++;
	}
}

char	*ft_strdup(const char *s, int len)
{
	char	*mem;
	char	*ptr;
	char	*f;

	mem = NULL;
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (mem == NULL)
		return (mem);
	if (!s)
	{
		mem[0] = 0;
		return (mem);
	}
	f = (char *)s;
	ptr = mem;
	while (*s)
		*(ptr++) = *(char *)(s++);
	*ptr = 0;
	free(f);
	return (mem);
}

char	*ft_strncat(char *s1, char *s2, int n)
{
	int	l1;
	int	l2;

	l1 = ft_strlen(s1);
	l2 = 0;

	while (s2[l2] && l2 < n)
	{
		s1[l1 + l2] = s2[l2];
		l2++;
	}
	s1[l1 + l2] = 0;
	return (s1); 
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst || !new)
		return ;
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

t_list	*ft_lstnew()
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = 0;
	ptr->next = NULL;
	return (ptr);
}

t_list	*ft_lstindex(t_list *lst, int i)
{
	if (!lst)
		return (NULL);
	while (lst->next && i > 0)
	{
		lst = lst->next;
		i--;
	}
	return (lst);
}