// #ifndef BSQ_H
// #define BSQ_H

// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

// typedef struct s_bsq
// {

//     int n;
//     int e;
//     int o;
//     int f;
//     char **map;
//     int size;
//     int w;
//     int h;
//     int x;
//     int y;

// } t_bsq;
// #endif



#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_bsq
{
	int	n;
	int	e;
	int	o;
	int	f;

	char	**map;
	int	w;
	int	h;

	int	size;
	int	x;
	int	y;

}t_bsq;

#endif