/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobrycki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:54:58 by mobrycki          #+#    #+#             */
/*   Updated: 2021/01/29 11:39:50 by mobrycki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

int					get_next_line(int fd, char **line);
int					ft_return(char *str);
size_t				ft_strlen(const char *s);
char				*join_str(const char *s1, const char *s2);

#endif
