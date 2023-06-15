/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:55:19 by thong-bi          #+#    #+#             */
/*   Updated: 2023/03/27 21:30:25 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strjoin_2(char *s1, char *s2, int bytes);
char	*ft_strchr(const char *str, int c);
char	*ft_get_line(char *str);
char	*ft_renew(char *str);
char	*ft_read_line(int fd, char *str);
int		ft_line_len(char *str);

#endif
