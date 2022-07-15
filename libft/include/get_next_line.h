#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define    BUFFER_SIZE     1024

void	free_resources(char **str);
char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char **str, char *buffer, size_t n);

#endif