#include "../maze.h"

int DFS(maze *maze, int y, int x)
{
    if (maze->map[y][x] == '1' || maze->map[y][x] == '.')
        return (0);
    if (maze->map[y][x] == 'S')
        return (1);

    maze->map[y][x] = '.';

    if (DFS(maze, y + 1, x) || DFS(maze, y - 1, x) 
    || DFS(maze, y, x + 1) || DFS(maze, y, x - 1))
		return (1);
    return (0);
}