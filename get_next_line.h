/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikaismou <ikaismou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:29:19 by ikaismou          #+#    #+#             */
/*   Updated: 2022/12/11 11:09:50 by ikaismou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_newtmp(char *tmp);
char	*ft_get_line(char *tmp);
char	*ft_tmp(int fd, char *tmp);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
