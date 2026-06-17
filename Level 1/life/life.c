// #include "life.h"

// static void free_map(t_game *game)
// {
//    if (game->map)
//    {
//       for(int i = 0; i < game->height; i++)
//          if (game->map[i])
//             free(game->map[i]);
//       free(game->map);
//       game->map = NULL;
//    }
// }

// static void print_map(t_game game)
// {
//    for (int y = 0; y < game.height; y++)
//    {
//       for (int x = 0; x < game.width; x++)
//          putchar(game.map[y][x]);
//       putchar('\n');
//    }
// }

// static void  init_game(t_game *game, char **av)
// {
//    game->width = atoi(av[1]);
//    game->height = atoi(av[2]);
//    game->iterations = atoi(av[3]);
//    game->map = malloc(game->height * sizeof(char *));
//    for (int y = 0; y < game->height; y++)
//    {
//       game->map[y] = malloc (game->width * sizeof(char));
//       for (int x = 0; x < game->width; x++)
//          game->map[y][x] = ' ';
//    }
// }

// static void fill_map(t_game *game)
// {
//    char  buffer;
//    int   x = 0;
//    int   y = 0;
//    bool  draw = false;
//    while (read(0, &buffer, 1) == 1)
//    {
//       if (buffer == 'w' && y > 0)
//          y--;
//       else if (buffer == 'a' && x > 0)
//          x--;
//       else if (buffer == 's' && y < game->height -1)
//          y++;
//       else if (buffer == 'd' && x < game->width -1)
//          x++;
//       else if (buffer == 'x')
//          draw = !draw;
//       else 
//          continue;
//       if (draw && y >= 0 && x >= 0 && y < game->height && x < game->width)
//          game->map[y][x] = 'O';
//    }
// }

// static int count_neighbours(t_game game, int x, int y)
// {
//    int count = 0;
//    for(int dy = -1; dy < 2; dy++)
//    {
//       for(int dx = -1; dx < 2; dx++)
//       {
//          if (dx == 0 && dy == 0)
//             continue;
//          int nx = x + dx;
//          int ny = y + dy;
//          if (nx >= 0 && nx < game.width && ny >= 0 && ny < game.height)
//          {
//             if (game.map[ny][nx] == 'O')
//                count++;
//          }
//       }
//    }
// }
// static void play_game(t_game *game)
// {
//    char **new_map = malloc(game->height * sizeof(char *));
//    for (int y = 0; y < game->height; y++)
//       new_map[y] = malloc(game->width *sizeof(char));
   
//    for(int y = 0; y < game->height; y++)
//    {
//       for(int x = 0; x < game->width; x++)
//       {
//          int alive_neighbours = count_neighbours(*game, x, y);

//          if (game->map[x][y] == 'O')
//          {
//             if (alive_neighbours == 2 || alive_neighbours == 3)
//                new_map[x][y] == 'O';
//             else
//                new_map[x][y] == ' ';
//          }
//          else
//          {
//             if(alive_neighbours == 3)
//                new_map[x][y] == 'O';
//             else
//                new_map[x][y] == ' ';
//          }
//       }
//    }
//    free_map(game);
//    game->map = new_map;
// }

// int main(int ac, char **av)
// {
//    t_game game;

//    if (ac != 4)
//       return (1);
//    init_game(&game, av);
//    fill_map(&game);
//    while (game.iterations--)
//       play_game(&game);
//    print_map(game);
//    free_map(&game);
//    return (0);
// }
#include "life.h"

static void free_map(t_game *game)
{
   if (game->map)
   {
      for (int i = 0; i < game->height; i++)
         if(game->map[i])
            free(game->map[i]);
      free(game->map);
      game->map = NULL;
   }
}

static void print_map(t_game game)
{
   for (int y = 0; y < game.height; y++)
   {
      for (int x = 0; x < game.width; x++)
         putchar(game.map[y][x]);
      putchar('\n');
   }
}

int   count_ne(t_game game, int x, int y)
{
   int count = 0;
   for (int dy = -1; dy < 2; dy++)
   {
      for (int dx = -1; dx < 2; dx++)
      {
         if (dx == 0 && dy == 0)
            continue;
         int nx = x + dx;
         int ny = y + dy;
         if (nx >= 0 && nx < game.width && ny >= 0 && ny < game.height)
         {
            if (game.map[ny][nx] == 'O')
               count++;
         }
      }
   }
   return (count);
}

static void play_game(t_game *game)
{
   char **new_map = malloc(game->height * sizeof(char *));
   for (int y = 0; y < game->height; y++)
      new_map[y] = malloc(game->width * sizeof(char));
   
   for(int y = 0; y < game->height; y++)
   {
      for (int x = 0; x < game->width; x++)
      {
         int alive_ne = count_ne(*game, x, y);
         if (game->map[y][x] == 'O')
         {
            if (alive_ne == 2 || alive_ne == 3)
               new_map[y][x] = 'O';
            else
               new_map[y][x] = ' ';
         }
         else
         {
            if (alive_ne == 3)
               new_map[y][x] = 'O';
            else
               new_map[y][x] = ' ';
         }
      }
   }
   free_map(game);
   game->map = new_map;
}

static void fill_map(t_game *game)
{
   char buffer;
   int x = 0;
   int y = 0;
   bool draw = false;

   while (read(0, &buffer, 1) == 1)
   {
      if (buffer == 'w' && y > 0)
         y--;
      else if (buffer == 'a' && x > 0)
         x--;
      else if (buffer == 's' && y < game->height - 1)
         y++;
      else if (buffer == 'd' && x < game->width - 1)
         x++;
      else if (buffer == 'x')
         draw = !draw;
      else
         continue;
      if (draw && y >= 0 && x >= 0 && y < game->height && x <game->width)
         game->map[y][x] = 'O';
   }
}

static void init_game(t_game *game, char **av)
{
   game->width = atoi(av[1]);
   game->height = atoi(av[2]);
   game->iterations = atoi(av[3]);
   game->map = malloc(game->height * sizeof (char *));
   for(int y = 0; y < game->height; y++)
   {
      game->map[y] = malloc(game->width * sizeof(char));
      for(int x = 0; x < game->width; x++)
         game->map[y][x] = ' ';
   }
}

int   main(int ac, char **av)
{
   t_game game;

   if (ac != 4)
      return(1);
   init_game(&game, av);
   fill_map(&game);
   while (game.iterations--)
      play_game(&game);
   print_map(game);
   free_map(&game);
}