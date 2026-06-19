#include "../sutom.h"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void les_consignes(int len, char *word) {
    printf("SUTOM\n");
    printf("%s\n", word);
    printf(GREEN "vert = lettre bien placée\n" RESET);
    printf(YELLOW "jaune = lettre mal placée\n" RESET);
    printf("proposez un mot à %d lettres:\n", len);
    printf("[%c]", word[0]);
    for (int i = 1; i < len; i++)
        printf("[_]");
    printf("\n");
}

int real_words(FILE *file, char *my_word)
{
    char real_word[20];

    rewind(file);

    while (fgets(real_word, sizeof(real_word), file)) {
        int j = 0;
        while (my_word[j] == real_word[j])
            j++;
        if (real_word[j] == '\n')
            return (1);
    }
    return (0);
}

char *gen_word(FILE *file) {
    srand(time(NULL));
    int gen = rand() % 1398;
    int i = 0;
    char *word;

    while (fgets(word, sizeof(word), file))
    {
        if (i == gen)
        {
            int j = 0;
            while (word[j] && word[j] != '\n')
                j++;
            word[j] = '\0';
            return word;
        }
        i++;
    }
    return NULL;
}

char *is_inside(char *argv, char *word) {
    int len = strlen(word);
    char *colors = malloc(sizeof(char) * (len + 1));
    if (!colors)
        exit (1);
    for (int i = 0; i<len; i++) {
        for (int j = 0; j<len; j++) {
            if (argv[i] == word[i])
                colors[i] = 'G';
            else if (argv[i] == word[j] && colors[i] != 'G')
                colors[i] = 'Y';
        }
    }
    colors[len] = '\0';
    return (colors);    
}

int is_correct(char *colors, int len) {
    for (int i = 0; i<len; i++) {
        if (colors[i] != 'G') {
            return 0;
        }
    }
    return 1;    
}

void is_error(char *user, int len) {
    printf("Le mot doit faire %d lettres et/ou exister! Reessayez.\n", len);
    if (!fgets(user, sizeof(user), stdin))
        exit (1);
    user[len] = '\0';
}

char *print_colors(char *user, char *word, int len) {
    char *add_colors = is_inside(user, word);
    for (int i = 0; i < len; i++) {
        if (add_colors[i] == 'G')
            printf(GREEN "[%c]" RESET, user[i]);
        else if (add_colors[i] == 'Y')
            printf(YELLOW "[%c]" RESET, user[i]);
        else
            printf("[%c]", user[i]);
    }
    return (add_colors);
}

int main(void) {
    int try = 0;
    char user[20];
    FILE *file = fopen("mini_morphalou.txt", "r");
    char *word = "bouge";
    //char *word = gen_word(file); 
    int len = strlen(word);

    char *add_colors = calloc(len + 1, sizeof(char));
    char **lexique = create_lexique(file, len, word);

    les_consignes(len, word);
    while (try < 6) {
        if (!fgets(user, sizeof(user), stdin))
            break;
        user[len] = '\0';
        while (strlen(user) != len || !real_words(file, user))
            is_error(user, len);
        try++;
        add_colors = print_colors(user, word, len);

        solver(lexique, user, word); //solver

        printf("\nTentative(s): %d/6\n", try);
        if (is_correct(add_colors, len)) {
            printf("Bravo tu as gagné en %d essai(s)!\n", try);
            return 0;
        }
    }
    printf("Tu as perdu!\nLe mot etait: ");
    for (int i = 0; i < len; i++)
        printf("[%c]", word[i]);
    printf("\n");
    fclose(file);
    return 0;
}