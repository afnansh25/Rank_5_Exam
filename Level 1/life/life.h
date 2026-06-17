// #ifndef LIFE_H
// # define LIFE_H

// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>

// typedef struct s_game
// {
//    int width;
//    int height;
//    int iterations;
//    char **map;
// } t_game;

// #endif


#ifndef LIFE_H
# define LIFE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_game
{
   int width;
   int height;
   int iterations;
   char **map;
   
}t_game;

#endif