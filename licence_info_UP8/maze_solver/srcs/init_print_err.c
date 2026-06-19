#include "../maze.h"

void init_maze(maze *maze, FILE *file) {
    maze->map = copy_map(file);
    maze->x_map_size = strlen(maze->map[0]);
    for (int y = 0; maze->map[y]; y++) {
        for (int x = 0; maze->map[y][x]; x++) {
            if (maze->map[y][x] == 'E') {
                maze->x_player = x;
                maze->y_player = y;
            }
        }
       // maze->y_map_size = y;
    }
}

char **copy_map(FILE *file) {
    char read_file[1024];
    char **copy_file = malloc(sizeof(char *) * 1024);
    if (!copy_file)
        return (NULL);

    int y = 0;
    while (fgets(read_file, sizeof(read_file), file)) {
        int x = strlen(read_file);
        if (x > 0 && read_file[x - 1] == '\n')
            x--;
        copy_file[y] = malloc(sizeof(char) * (x + 1));
        if (!copy_file[y])
            return (NULL);
        for (int i = 0; i < x; i++)
            copy_file[y][i] = read_file[i];
        copy_file[y][x] = '\0';
        y++;
    }
    copy_file[y] = NULL;
    return (copy_file);
}

void print_map(char **map, int visited)
{
    for (int y = 0; map[y]; y++)
    {
        for (int x = 0; map[y][x]; x++)
        {
            if (map[y][x] == '.')
                printf(GREEN "0" RESET);
            else if (visited && map[y][x] == 'S')
                printf(GREEN "S" RESET);
            else
                printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

void exit_msg(char *msg) {
	if (msg)
		printf("%s\n", msg);
	exit (1);
}