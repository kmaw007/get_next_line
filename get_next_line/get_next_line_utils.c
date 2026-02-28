/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:28:57 by kwafi             #+#    #+#             */
/*   Updated: 2026/02/28 16:28:57 by kwafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gn1_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gn1_strchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	if (!s)
		return (NULL);
	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

char	*gn1_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*res;

	len1 = gn1_strlen(s1);
	len2 = gn1_strlen(s2);
	res = (char *)malloc((len1 + len2 + 1));
	if (!res)
		return (NULL);
	i = (size_t)0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	j = (size_t)0;
	while (j < len2)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*gn1_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
	len = gn1_strlen(s);
	dup = (char *)malloc((len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*gn1_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*res;

	if (!s)
		return (NULL);
	slen = gn1_strlen(s);
	if (start >= slen)
		return (gn1_strdup(""));
	if (len > slen - start)
		len = slen - start;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
