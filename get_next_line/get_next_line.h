/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:01:54 by kwafi             #+#    #+#             */
/*   Updated: 2026/02/28 16:01:54 by kwafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

char	*gn1_strdup(const char *s);
char	*gn1_strchr(const char *s, int c);
char	*gn1_strjoin(char const *s1, char const *s2);
size_t	gn1_strlen(const char *s);
char	*gn1_substr(const char *s, unsigned int start, size_t len);

#endif