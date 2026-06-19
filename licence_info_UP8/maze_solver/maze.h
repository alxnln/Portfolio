#ifndef MAZE_H
# define MAZE_H

typedef struct maze {
    char **map;
    int x_player;
    int y_player;
    int x_map_size;
    int y_map_size;
}   maze;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"

int is_map_valid(char **map);
int is_map_rectangle(char **map);
int is_map_has_valid_cases(char **map);
void exit_msg(char *msg);

int DFS(maze *maze, int y, int x);

void print_map(char **map, int visited);
char **copy_map(FILE *file);
void init_maze(maze *maze, FILE *file);

#endif 