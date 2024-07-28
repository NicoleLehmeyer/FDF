/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:19:34 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/10/11 10:19:35 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* F1: DO READ FUNCTION UNTIL '\n' OR '\0'
	'readed_bytes' set to 1, (can't be 0, to enter the next 'while' loop)
	While there is no '\n' in the readedline string
			(AND readed bytes is not 0, aka bytes are being read)
		-read fd to store, BUFFER_SIZE no. of bytes. Set read bytes to this value
		-if read == -1, free store and return NULL.
	make last char in store '\0'
	**NOTE: this^ could be less than BUFFER_SIZE
	RETURN: 'readedline'
*/
char	*ft_readtilnl(int fd, char *readedline)
{
	char	*store;
	int		readed_bytes;

	readed_bytes = 1;
	store = malloc(BUFFER_SIZE + 1);
	if (!store)
		return (NULL);
	while (!ft_strchr(readedline, '\n') && readed_bytes != 0)
	{
		readed_bytes = read(fd, store, BUFFER_SIZE);
		if (readed_bytes < 0)
		{
			free(store);
			free(readedline);
			return (NULL);
		}
		store[readed_bytes] = '\0';
		readedline = ft_strjoin_gnl(readedline, store);
	}
	free(store);
	return (readedline);
}

//F2: CUT READED LINE AFTER '\n' OR end
	//malloc returnline for i + 2 ('\n' and '\0')

char	*ft_cutline(char *linestart)
{
	char	*returncut;
	int		i;

	i = 0;
	if (!linestart[i])
		return (NULL);
	while (linestart[i] && linestart[i] != '\n')
		i++;
	returncut = malloc(i + 2);
	if (!returncut)
		return (NULL);
	i = 0;
	while (linestart[i] && linestart[i] != '\n')
	{
		returncut[i] = linestart[i];
		i++;
	}
	if (linestart[i] == '\n')
	{
		returncut[i] = linestart[i];
		i++;
	}
	returncut[i] = '\0';
	return (returncut);
}

/* F3: MOVE STATIC VAR TO CHAR AFTER RET LINE '\n'
	Count the number of chars in linestart, not including the '\n'
	If theres no linestart[i], then free it and return NULL.
	Malloc newlinestart for ((strlen of linestart) - i + 1).
		str ptr start of nl + \0
	Set other iterator to 0, then while linestart[i]
		(keep in mind it is the len of the prev returned line),
		set newlinestart[j++] = linestart[i++]
	FREE: linestart
	RETURN: newlinestart
*/

char	*ft_movepointer(char *linestart)
{
	char	*newlinestart;
	int		i;
	int		n;

	i = 0;
	while (linestart[i] && linestart[i] != '\n')
		i++;
	if (linestart[i] == '\n')
		i++;
	if (!linestart)
		return (NULL);
	newlinestart = malloc(ft_strlen(linestart) - i + 1);
	if (!newlinestart)
		return (NULL);
	n = 0;
	while (linestart[i])
		newlinestart[n++] = linestart[i++];
	newlinestart[n++] = '\0';
	free(linestart);
	if (newlinestart[0] == '\0')
	{
		free(newlinestart);
		return (NULL);
	}
	return (newlinestart);
}

/*
ERROR HANDLING:
if (fd<0 OR buffer < 1 OR 'read(fd, NULL, 0) )
if linestart has something in it, free it.
set linestart value to NUll
the end, ret 0.

if there is no linestart after the ft_readtilnl,
then return NULL, as there is nothing else to read
*/
char	*get_next_line(int fd)
{
	char		*returnline;
	static char	*linestart;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0))
	{
		if (linestart)
			free(linestart);
		linestart = NULL;
		return (0);
	}
	linestart = ft_readtilnl(fd, linestart);
	if (!linestart)
		return (NULL);
	returnline = ft_cutline(linestart);
	linestart = ft_movepointer(linestart);
	return (returnline);
}
