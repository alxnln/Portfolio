#include "../maze.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
		exit_msg("./maze <nb> (nb = [1,2,3,4,5])");

	FILE *file = NULL;
	if (strcmp(argv[1], "1") == 0)
    	file = fopen("maps/map_1.txt", "r"); 
	else if (strcmp(argv[1], "2") == 0)
    	file = fopen("maps/map_2.txt", "r"); 
	else if (strcmp(argv[1], "3") == 0)
    	file = fopen("maps/map_3.txt", "r");
	else if (strcmp(argv[1], "4") == 0)
    	file = fopen("maps/map_4.txt", "r"); 
	else if (strcmp(argv[1], "5") == 0)
    	file = fopen("maps/map_5.txt", "r");
	else 
		exit_msg("./maze <nb> (nb = [1,2,3,4,5])");

    maze *maze;
    maze = malloc(sizeof(*maze));
    if (!maze)
        exit_msg("malloc failed.");
    init_maze(maze, file);	
    if (!is_map_valid(maze->map)) 
        exit_msg("Erreur.\n");
	
    print_map(maze->map, 0);
    printf("\n");

	DFS(maze, maze->y_player, maze->x_player);

    print_map(maze->map, 1); 

    return (0);
}
