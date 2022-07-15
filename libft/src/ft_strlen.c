#include	"libft.h"

/*
* The strlen() function calculates the length of the string s, 
* excluding the terminating null byte ('\0')
*/
size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
