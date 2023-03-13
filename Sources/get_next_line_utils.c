/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:42:53 by lreille           #+#    #+#             */
/*   Updated: 2023/03/12 00:14:38 by lreille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		ptr[i] = 0;
		i++;
		total--;
	}
	return ((void *)ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
char	*ft_strjoin(ichar *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		str = (char *)malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		free(s1);
		return (str);
	}
	return (NULL);
}*/
