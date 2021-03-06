/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 11:28:57 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/29 11:36:26 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_save_c(char *save_c)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save_c)
		return (0);
	while (save_c[i] && save_c[i] != '\n')
		i++;
	if (!save_c[i])
	{
		free(save_c);
		return (0);
	}
	if (!(result = malloc(sizeof(char) * ((ft_strlen(save_c) - i) + 1))))
		return (0);
	i++;
	while (save_c[i])
		result[j++] = save_c[i++];
	result[j] = '\0';
	free(save_c);
	return (result);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(result = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save_c[4096];
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_return(save_c[fd]) && reader != 0)
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save_c[fd] = join_str(save_c[fd], buff);
	}
	free(buff);
	*line = ft_get_line(save_c[fd]);
	save_c[fd] = ft_get_save_c(save_c[fd]);
	if (reader == 0)
		return (0);
	return (1);
}
