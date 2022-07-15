#include "get_next_line.h"

/* ************************************************************************** */
/*	Gets line searching for '\n', including this character					  */
/* ************************************************************************** */
char	*get_line(char *str, size_t *pos)
{
	size_t	i;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		return (NULL);
	*pos = i;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (i <= *pos)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

/* ************************************************************************** */
/*	Gets tail, as characters after '\n' in 'str'							  */
/* ************************************************************************** */
char	*get_tail(char **tail, char *str, size_t pos)
{
	char	*new_tail;
	size_t	len_str;
	size_t	j;

	len_str = ft_strlen(str);
	if (len_str > pos)
	{
		new_tail = malloc(len_str + 1 - pos);
		if (!new_tail)
			return (NULL);
		j = 0;
		while (pos < len_str)
			new_tail[j++] = str[pos++];
		new_tail[j] = 0;
	}
	else
		new_tail = NULL;
	free_resources(tail);
	return (new_tail);
}

/* ************************************************************************** */
/*	Reads from file descriptor until line or EOF is found 					  */
/* ************************************************************************** */
char	*search_line(int fd, char *str, char *buffer, char **tail)
{
	char	*line;
	ssize_t	rd_char;
	size_t	eol_pos;

	line = NULL;
	while (!line)
	{
		rd_char = read(fd, buffer, BUFFER_SIZE);
		if (rd_char <= 0)
		{
			free_resources(tail);
			return (str);
		}
		str = ft_gnl_strjoin(&str, buffer, rd_char);
		if (!str)
			return (NULL);
		line = get_line(str, &eol_pos);
	}
	*tail = get_tail(tail, str, eol_pos + 1);
	free_resources(&str);
	return (line);
}

char	*ft_get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*tail = NULL;
	size_t		pos;

	if (fd < 0 || fd > 255 || BUFFER_SIZE < 1)
		return (NULL);
	line = get_line(tail, &pos);
	if (line)
		tail = get_tail(&tail, tail, pos + 1);
	else
	{
		line = ft_gnl_strjoin(&line, tail, ft_strlen(tail));
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
		{
			free_resources(&line);
			return (NULL);
		}
		line = search_line(fd, line, buffer, &tail);
		free_resources(&buffer);
	}
	return (line);
}
