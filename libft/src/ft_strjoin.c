#include	"libft.h"

static char	*hf_copy(char *join, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	size_t	join_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join_len = s1_len + s2_len;
	i = 0;
	while (i < s1_len)
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < join_len)
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	return (join);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	size_t	join_len;

	if (!s1 || !s2)
		return (NULL);
	join_len = ft_strlen(s1) + ft_strlen(s2);
	str_join = malloc((join_len + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	str_join = hf_copy(str_join, s1, s2);
	str_join[join_len] = '\0';
	return (str_join);
}