#include "bsq.h"

void print_bsq(t_bsq *bs)
{
	for(int y = bs->y; y < bs->y + bs->size; y++)
	{
		for(int x = bs->x; x < bs->x + bs->size; x++)
		{
			bs->map[y][x] = bs->f;
		}
	}
	for (int y = 0; y < bs->h; y++)
	{
		fputs(bs->map[y], stdout);
		fprintf(stdout, "\n");
	}
}

int	find_min(int a, int b, int c)
{
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	find_bsq(t_bsq *bs)
{
	int matrix[bs->h][bs->w];
	for(int y = 0; y < bs->h; y++)
	{
		for(int x = 0; x < bs->w; x++)
		{
			matrix[y][x] = 0;
		}
	}
	for(int y = 0; y < bs->h; y++)
	{
		for(int x = 0; x < bs->w; x++)
		{
			if (bs->map[y][x] == bs->o)
				matrix[y][x] = 0;
			else if (y == 0 || x == 0)
				matrix[y][x] = 1;
			else
				matrix[y][x] = find_min(matrix[y][x-1], matrix[y-1][x-1], matrix[y-1][x]) + 1;
			if (matrix[y][x] > bs->size)
			{
				bs->size = matrix[y][x];
				bs->y = y - bs->size + 1;
				bs->x = x - bs->size + 1; 
			}
		}
	}
}

void free_map(char **str)
{
	int i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

int load_map(FILE *fl, t_bsq *bs)
{
    bs->h = bs->n;
    bs->map = (char **)malloc((bs->h + 1) * sizeof(char *));
    bs->map[bs->h] = NULL;
    char *line = NULL;
    size_t len = 0;
    for(int y = 0; y < bs->h; y++)
    {
        int read = getline(&line, &len, fl);
        if(read == -1 || line[read - 1] != '\n')
        {
            free(line);
            free_map(bs->map);
            return(1);
        }
        read--;
        line[read] = '\0';
        if(y == 0)
            bs->w = read;
        else
        {
            if( bs->w != read)
            {
                free(line);
                free_map(bs->map);
                return(1);

            }
        }
        bs->map[y] = malloc((bs->w + 1) * sizeof(char));
            for(int x = 0; x < bs->w; x++)
            {
                char c = line[x];
                if(c != bs->o && c != bs->e)
                {
                    free(line);
                    free_map(bs->map);
                    return(1);
                }
                bs->map[y][x] = c;
            }
            bs->map[y][bs->w] = '\0';
    }
    free(line);
    return(0);
}

int	load_elem(FILE *f1, t_bsq *bs)
{
	int n;
	char e, o, f;
	int	result = fscanf(f1, "%d%c%c%c\n", &n, &e, &o, &f);
	if (result != 4)
		return (1);
	if (n <= 0)
		return (1);
	if (e == o || o == f || e == f)
		return (1);
	if (e < 32 || e > 126 || o < 32 || o > 126 || f < 32 || f > 126)
		return (1);
	bs->n = n;
	bs->e = e;
	bs->o = o;
	bs->f = f;
	return (0);
}

int	exec_bsq(FILE *f1)
{
	t_bsq bs;
	if (load_elem(f1, &bs))
		return (1);
	if (load_map(f1, &bs))
		return (1);
	bs.size = 0;
	bs.x = 0;
	bs.y = 0;
	find_bsq(&bs);
	print_bsq(&bs);
	free_map(bs.map);
	return (0);
}

int file_intrep(char *str)
{
	FILE *f1 = fopen(str, "r");
	if(!f1)
		return (1);
	int res = exec_bsq(f1);
	fclose (f1);
	return (res);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		if (exec_bsq(stdin))
		{
			fprintf(stderr, "Error: invalid map\n");
			return (1);
		}
	}
	for (int i = 1; i < ac; i++)
	{
		if (file_intrep(av[i]))
			fprintf(stderr, "Error: invalid map\n");
		if (i < ac - 1)
			fprintf(stdout, "\n");
	}
	return (0);
}