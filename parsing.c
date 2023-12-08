#include "cub3d.h"

int is_comma(char **str, int i, int j)
{
    int flag;

    flag = 0;
    while(str[i][j])
    {
        if (str[i][j] == ',')
            flag++;
        j++;
    }
    if (flag != 2)
        return (1);
    return (0);
}

int check_digit(char **str, int i, int j)
{
    while (str[i][j] && str[i][j] != ' ')
    {
        while(str[i][j] && str[i][j] != ',' && str[i][j] != ' ')
        {
            if (ft_isdigit(str[i][j]) != 1)
                return (1);
            j++;
        }
        j++;
    }
    return (0);
}

int check_after_d(char **str, int i, int j)
{
    while (str[i][j] && str[i][j] != ' ')
        j++;
    while(str[i][j])
    {
        if (str[i][j] != ' ')
            return (1);
        j++;
    }
    return (0);
}

void    is_range_valid(char **numbers)
{
    int i;
    int id_number;

    i = 0;
    id_number = 0;
    while (numbers[i])
    {
        id_number = ft_atoi(numbers[i]);
        if (id_number < 0 || id_number > 255)
        {
            ft_freetab(numbers);
            ft_puterror("Error: in rgb numbers\n", 2);
        }
        i++;
    }
}

void    check_rgb_range(t_var *v, int i , int j)
{
    char **numbers;
    char *s;
    int start;
    int n = 0;

    start = j;
    while (v->new_map[i][j] && v->new_map[i][j] != ' ')
        j++;
    s = ft_substr(v->new_map[i], start, j);
    numbers = ft_split(s, ',');
    free(s);
    while(numbers[n])
    {
        if (ft_strcmp(numbers[n], "  ") == 0)
        {
            ft_freetab(numbers);
            ft_puterror("Error: in rgb numbers\n", 2);
        }
        n++;
    }
    if (n != 3)
    {
        ft_freetab(numbers);
        ft_puterror("Error: in rgb numbers\n", 2);
    }
    is_range_valid(numbers);
    ft_freetab(numbers);
}

void    start_parser(t_var *v, int i, int j)
{
    int start;

    start = 0;
    count_id(v, i, j);
    if (is_comma(v->new_map, i, j) == 1)
        ft_puterror("Error: in rgb numbers\n", 2);
    j++;
    while(v->new_map[i][j] && v->new_map[i][j] == ' ')
        j++;
    start = j;
    if  (check_after_d(v->new_map, i, j) == 1)
        ft_puterror("Error: in rgb numbers\n", 2);
    while (v->new_map[i][j] && v->new_map[i][j] != ' ')
    {
        if (check_digit(v->new_map, i, j) == 1)
            ft_puterror("Error: in rgb numbers\n", 2);
        j++;
    }
    check_rgb_range(v, i, start);
}

void    is_rgb_valid(t_var *v)
{
    int i;
    int j;

    i = 0;
    j = 0;
    v->flag_F = 0;
    v->flag_C = 0;
    while (i < v->i)
    {
        j = 0;
        while (v->new_map[i][j])
        {
            if (v->new_map[i][j] == 'C' || v->new_map[i][j] == 'F')
                start_parser(v, i, j);
            j++;
        }
        i++;
    }
    if (v->flag_C < 1 || v->flag_F < 1 )
        ft_puterror("Error: rgb identifiers is missing\n", 2);
}

void is_path_valid(t_var *v)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int n = 0;
    int index = 0;
    char *s[4];

    while (i < v->i)
    {
        j = 0;
        n = 0;
        x = 0;
        while (v->new_map[i][j] && (v->new_map[i][j] == ' ' || v->new_map[i][j] == '\t'))
            j++;
        if (v->new_map[i][j] != '\0')
        {
            j = 0;
            while (v->new_map[i][j] && v->new_map[i][j] != '/')
                j++;
            j++;
            n = j;
            while (v->new_map[i][n] && v->new_map[i][n] != ' ')
            {
                n++;
                x++;
            }
            while (v->new_map[i][n])
            {
                if (v->new_map[i][n] != ' ')
                    ft_puterror("Error: in path\n", 2);
                n++;
            }
            s[index] = ft_substr(v->new_map[i], j, x);
            if (ft_strcmp(s[index], "textures/EA") == 0)
                break;
            index++;
        }
        i++;
    }
    index++;
    s[index] = NULL;
    printf("--------> %s\n", s[0]);
    printf("--------> %s\n", s[1]);
    printf("--------> %s\n", s[2]);
    printf("--------> %s\n", s[3]);

    int fd0 = open(s[0], O_RDONLY);
    int fd00 = open(s[0], O_DIRECTORY);
    if (fd0 == -1 || fd00 != -1)
        ft_puterror("Error: Failed to open file path 0\n", 2);
    int fd1 = open(s[1], O_RDONLY);
    int fd01 = open(s[1], O_DIRECTORY);
    if (fd1 == -1 || fd01 != -1)
        ft_puterror("Error: Failed to open file path 1\n", 2);
    int fd2 = open(s[2], O_RDONLY);
    int fd02 = open(s[2], O_DIRECTORY);
    if (fd2 == -1 || fd02 != -1)
        ft_puterror("Error: Failed to open file path 2\n", 2);
    int fd3 = open(s[3], O_RDONLY | O_RDWR);
    int fd03 = open(s[3], O_DIRECTORY);
    if (fd3 == -1 || fd03 != -1)
        ft_puterror("Error: Failed to open file path 3\n", 2);
    index = 0;
    while(s[index])
        free(s[index++]);
}

void    check_id_help(t_var *v, int i, int n)
{
    char *s;
    int len;

    len = n;
    while(v->new_map[i][n] && v->new_map[i][n] != '.' && v->new_map[i][n - 1] != 'C' && v->new_map[i][n - 1] != 'F')
    {
        if (v->new_map[i][n] != ' ')
            return(ft_puterror("Error: in the type identifiers!\n", 2));
        n++;
    }
    s = ft_substr(v->new_map[i], 0, len);
    if (ft_strcmp(s, "NO") != 0 && ft_strcmp(s, "SO") != 0   
        && ft_strcmp(s, "WE") != 0 && ft_strcmp(s, "EA") != 0 && ft_strcmp(s, "C") != 0 && ft_strcmp(s, "F") != 0)
            return(ft_puterror("Error: in the type identifiers!\n", 2), free(s));
    else
        v->flag++;
    free(s);
}

int check_id(t_var *v)
{
    int i = 0;
    int j = 0;
    v->i = 0;
    v->j = 0;
    int n = 0;
    v->flag = 0;

    search_map(v->new_map, v);
    while (i < v->i)
    {
        j = 0;
        n = 0;
        while (v->new_map[i][j] && (v->new_map[i][j] == ' ' || v->new_map[i][j] == '\t'))
            j++;
        if (v->new_map[i][j] != '\0')
        {
            while (v->new_map[i][j] && v->new_map[i][j] != '.')
                j++;
            while (v->new_map[i][n] && v->new_map[i][n] != ' ')
                n++;
            check_id_help(v, i, n);
        }
        i++;
    }
    if (v->flag < 6)
        return(ft_puterror("Error: one of the type identifiers is missing!\n", 2), 1);
    is_path_valid(v);
    is_rgb_valid(v);
    return (0);
}

void    get_player_pos(t_var *v)
{
    int i = 0;
    int j = 0;
    int flag = 0;
    v->player_pos = 0;
    i = v->map_pos;
    while (v->new_map[i])
    {
        j = 0;
        while (v->new_map[i][j])
        {
            if (v->new_map[i][j] == 'N' || v->new_map[i][j] == 'E' 
                || v->new_map[i][j] == 'S'|| v->new_map[i][j] == 'W')
                {
                    v->player_pos = j;
                    flag = 1;
                }
            j++;
        }
        v->player_pos += j;
        if (flag == 1)
            break;
        i++;
    }
}

void    parsing(t_var *v)
{
    v->new_map = fill_empty(v->new_map, v);
    check_id(v);
    // exit(0);
    check_valid_chars(v->new_map, v);
	parse_path(v->new_map, v);
    get_player_pos(v);
}

int count_directions(char **map, t_var *v)
{
    int counter = 0;
    while (map[v->i])
    {
		v->j = 0;
		while (map[v->i][v->j])
		{
			if (map[v->i][v->j] == 'N' || map[v->i][v->j] == 'S' || map[v->i][v->j] == 'E' || map[v->i][v->j] == 'W')
				counter++;
			v->j++;
		}
		v->i++;
    }
	if (counter == 0 || counter > 1)
        return(1);
    return (0);
}

void    search_map(char **map, t_var *v)
{
    int found = 0;
    while (map[v->i])
    {
		v->j = 0;
		while (map[v->i][v->j])
		{
            if (map[v->i][v->j] == ' ')
                v->j++;
            else if (map[v->i][v->j] == '1')
            {
                found = 1;
                v->j = 0;
                break;
            }
            else
                break;
		}
        if (found == 1)
            break;
		v->i++;
    }
}

void    check_valid_chars(char **map, t_var *v)
{
    v->i = 0;
    v->j = 0;
    int found = 0;
    v->map_pos = 0;

    search_map(map, v);
    v->map_pos = v->i;
    while (map[v->i])
    {
        if (found == 1)
		    v->j = 0;
		while (map[v->i][v->j])
		{
			if (map[v->i][v->j] != '1' && map[v->i][v->j] != '0' && map[v->i][v->j] != 'N'
				&& map[v->i][v->j] != 'S' && map[v->i][v->j] != 'E' && map[v->i][v->j] != 'W' && map[v->i][v->j] != ' ')
					ft_puterror("Error: Invalid map\n", 2);
			v->j++;  
		}
        found = 1;
		v->i++;
    }
	v->i = v->map_pos;
    if (count_directions(map, v))
		ft_puterror("Error: Invalid map\n", 2);
}

void    check_ex(char *s)
{   
    int i = 0;
    i = ft_strlen(s);
    if(s[i - 4] == '.' && s[i - 3] == 'c' && s[i - 2] == 'u' && s[i - 1] == 'b')
        return ;
    else
        ft_puterror("Error in map extention!\n", 2);
}

char **fill_empty(char **map, t_var *v)
{
    v->i = 0;
    size_t j = 0;
    v->len_s = 0;
    while(v->i < v->map_len)
    {
        if(ft_strlen(map[v->i]) <= v->big_line)
        {
            j = 0;
            while(map[v->i][j] && map[v->i][j] != '\n')
                j++;
            map[v->i][j] = '\0';
            v->len_s = j;
            v->new_line = malloc(sizeof(char) * (v->big_line - j));
            if(!v->new_line)
                return(NULL);
            j = 0;
            map = join_space(map, v);
            free(v->new_line);
            v->new_line = NULL;
        }
        v->i++;
    }
    map[v->i] = NULL;
    return (map);
}
