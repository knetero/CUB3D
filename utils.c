#include "cub3d.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	w_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	*fill_tab(const char *s1, int *index, char c)
{
	char	*copy;
	int		word_len;
	int		i;

	word_len = 0;
	while (s1[*index] == c)
		(*index)++;
	i = *index;
	while (s1[i] && s1[i] != c)
	{
		word_len++;
		i++;
	}
	copy = malloc(sizeof(char) * (word_len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[*index] && s1[*index] != c)
		copy[i++] = s1[(*index)++];
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		index;
	int		wc;
	int		i;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = w_count((char *)s, c);
	tab = malloc(sizeof(char *) * (wc + 1));
	if (!tab)
		return (NULL);
	while (i < wc)
	{
		tab[i] = fill_tab(s, &index, c);
		if (!tab[i])
			return (ft_free(tab));
		i++;
	}
	tab[i] = 0;
	return (tab);
}


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char **join_space(char **map, t_var *v)
{
    size_t j = 0;
    while(j < (v->big_line - v->len_s - 1))
    {
        v->new_line[j] = ' ';
        j++;
    }
    v->new_line[j] = '\0';
    map[v->i] = ft_strjoin(map[v->i], v->new_line);
    return (map);
}

void	ft_puterror(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
    exit(1);
}

void    ft_freetab(char **map)
{
    int i = 0;
    while(map[i])
        free(map[i++]);
    free(map);
}

int get_biggest_line(char **str)
{
    int i = 0;
    size_t len = 0;
    while(str[i])
    {
        if(ft_strlen(str[i]) > len)
            len = ft_strlen(str[i]);
        i++;
    }
    return (len);
}

void    get_map_len(t_var *v, char *str)
{
    v->fd1 = open(str, O_RDWR);
    v->s = get_next_line(v->fd1);
    while(v->s != NULL)
    {
        free(v->s);
        v->map_len++;
        v->s = get_next_line(v->fd1);
    }
    free(v->s);
    close(v->fd1);
    if (v->map_len == 0)
        ft_puterror("Error: the map is empty\n", 2);
}
