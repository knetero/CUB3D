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

void    check_id_range(t_var *v, int i , int j)
{
    char **numbers;
    int id_number;
    char *s;
    int start;

    start = j;
    while (v->new_map[i][j] && v->new_map[i][j] != ' ')
        j++;
    s = ft_substr(v->new_map[i], start, j);
    numbers = ft_split(s, ',');
    start = 0;
    while(numbers[start])
    {
        //CONDITION 3LA QBEL (C ,,)
        if (ft_strcmp(numbers[start], "  ") == 0)
        {
            ft_freetab(numbers);
            ft_puterror("Error: in rgb numbers\n", 2);
        }
        id_number = ft_atoi(numbers[start]);
        if (id_number < 0 || id_number > 255)
        {
            ft_freetab(numbers);
            ft_puterror("Error: in rgb numbers\n", 2);
        }
        start++;
    }
    ft_freetab(numbers);
}


void    is_rgb_valid(t_var *v)
{
    int i = 0;
    int j = 0;
    int start = 0;

    while (i < v->i)
    {
        j = 0;
        while (v->new_map[i][j])
        {
            if (v->new_map[i][j] == 'C' || v->new_map[i][j] == 'F')
            {
                if (is_comma(v->new_map, i, j) == 1)
                    ft_puterror("Error: in rgb numbers\n", 2);
                j++;
                while(v->new_map[i][j] && v->new_map[i][j] == ' ')
                    j++;
                start = j;
                if  (check_after_d(v->new_map, i, j) == 1)
                    ft_puterror("Error: in rgb numbers\n", 2);
                while(v->new_map[i][j] && v->new_map[i][j] != ' ')
                {
                    if (check_digit(v->new_map, i, j) == 1)
                        ft_puterror("Error: in rgb numbers\n", 2);
                    j++;
                }
                check_id_range(v, i, start);
            }
            j++;
        }
        if (v->new_map[i][j] == 'F')
            break;
        i++;
    }
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
    if (fd0 == -1)
        ft_puterror("Error: Failed to open file path 0\n", 2);
    int fd1 = open(s[1], O_RDONLY);
    if (fd1 == -1)
        ft_puterror("Error: Failed to open file path 1\n", 2);
    int fd2 = open(s[2], O_RDONLY);
    if (fd2 == -1)
        ft_puterror("Error: Failed to open file path 2\n", 2);
    int fd3 = open(s[3], O_RDONLY);
    if (fd3 == -1)
        ft_puterror("Error: Failed to open file path 3\n", 2);

}

int check_id(t_var *v)
{
    int i = 0;
    int j = 0;
    v->i = 0;
    v->j = 0;
    int flag = 0;
    int len = 0;
    int n = 0;
    char    *s;

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
            len = n;
            while(v->new_map[i][n] && v->new_map[i][n] != '.' && v->new_map[i][n - 1] != 'C' && v->new_map[i][n - 1] != 'F')
            {
                if (v->new_map[i][n] != ' ')
                    return(ft_puterror("Error: in the type identifiers!\n", 2), 1);
                n++;
            }
            s = ft_substr(v->new_map[i], 0, len);
            if (ft_strcmp(s, "NO") != 0 && ft_strcmp(s, "SO") != 0   
                && ft_strcmp(s, "WE") != 0 && ft_strcmp(s, "EA") != 0 && ft_strcmp(s, "C") != 0 && ft_strcmp(s, "F") != 0)
                    return(ft_puterror("Error: in the type identifiers!\n", 2), 1);
            else
                flag++;
        }
        i++;
    }
    if (flag < 6)
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
    // printf("----------------->  %d\n", i);
    // printf("**player pos = %d\n", v->player_pos);
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
