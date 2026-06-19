#include "../maze.h"

int is_map_valid(char **map)
{
	if (!map || !map[0])
        exit_msg("La map ne peut pas etre vide.");
    if (!is_map_rectangle(map))
        exit_msg("La map n'est pas rectangle ou les murs ne sont pas delimitee des '1'.");
    if (!is_map_has_valid_cases(map))
        exit_msg("Certaines cases ont des caractères incorrects.");
    if (!is_map_rectangle(map) || !is_map_has_valid_cases(map))
        return (0);
    return (1);
}

int is_map_rectangle(char **map) {
    // regarde si la map est rectangle et délimitée en '1'
    int y = 1;
    int x_max = strlen(map[0]);

    for (int x = 0; map[0][x]; x++) {
        if (map[0][x] != '1')
            return (0);
    }
    while (map[y]) {
        if (map[y][0] != '1' || map[y][x_max - 1] != '1')
            return (0);
        y++;
    }
    y--;
    for (int x = 0; map[y][x]; x++) {
        if (map[y][x] != '1')
            return (0);
    }
    return (1);
}

int is_map_has_valid_cases(char **map) {
    // regarde si 1 sortie 'S', 1 entrée 'E', sol en '0', murs en '1'
    int E = 0;
    int S = 0;

    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            if (map[y][x] != '1' && map[y][x] != '0' 
                && map[y][x] != 'E' && map[y][x] != 'S')
                return (0);
            if (map[y][x] == 'E')
                E++;
            if (map[y][x] == 'S')
                S++;
        }
    }
    if (S != 1 || E != 1)
        return (0);
    return (1);
} 
