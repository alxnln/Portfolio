#include "../sutom.h"

// stock tous les mots de Wordsize et 1e lettre dans double tableau
// au fur et a mesure, le tableau retreci

char **create_lexique(FILE *file, int size, char *word){
    char read[999];
    char **lexique = malloc(sizeof(char *) * (300000 + 1));
    if (!lexique)
        return NULL;

    int i = 0;
    while (fgets(read, sizeof(read), file))
    {
        if (((word[0] == read[0])) 
            && (strlen(read) == (size + 1))) {
            lexique[i] = malloc(sizeof(char) * (size + 1));
            if (!lexique[i])
                return NULL;
            for (int j = 0; j < size; j++) {
                lexique[i][j] = read[j];
                lexique[i][j + 1] = '\0';
            }
            i++;
        }
    }
    lexique[i] = NULL;
    return (lexique);
}

void remove_word(char **lexique, int index)
{
    free(lexique[index]);
    int j = index;
    while (lexique[j]) {
        lexique[j] = lexique[j + 1];
        j++;
    }
    lexique[j] = NULL;
}

void solver(char **lexique, char *user, char *word) {
    int word_len = strlen(user);
    int lexique_len = 0;
    while (lexique[lexique_len])
        lexique_len++;

    // si une lettre est bien placé, on supprime tous les mots où elle n'est pas au meme index
    for (int i = 0; i < word_len; i++) {
        if (user[i] == word[i]) {
            for (int j = 0; j < lexique_len; j++) {
                if (lexique[j][i] != word[i]) {
                    remove_word(lexique, j);
                    lexique_len--;
                    j--;
                }
            }
        }
    }
    // lettre presente, mal placee (Y):
    // la lettre ne doit pas etre au meme index et doit exister ailleurs dans le mot.
    for (int i = 0; i < word_len; i++) {
        if (user[i] == word[i] || !strchr(word, user[i]))
            continue;
        for (int j = 0; j < lexique_len; j++) {
            int inside = 0;
            if (lexique[j][i] == user[i]) {
                remove_word(lexique, j);
                lexique_len--;
                j--;
                continue;
            }
            for (int l = 0; l < word_len; l++) {
                if (l != i && lexique[j][l] == user[i])
                    inside = 1;
            }
            if (!inside) {
                remove_word(lexique, j);
                lexique_len--;
                j--;
            }
        }
    }
    // la lettre n'est pas presente, on supprime tous les mots qui contiennent cette lettre
    for (int i = 0; i < word_len; i++) {
        if (!strchr(word, user[i])) {
            for (int j = 0; j < lexique_len; j++) {
                if (strchr(lexique[j], user[i])) {
                    remove_word(lexique, j);
                    lexique_len--;
                    j--;
                }
            }
        }
    }

    printf("\nPropositions possibles: \n");
    for (int j = 0; lexique[j]; j++)
        printf("%s\n", lexique[j]);
    printf("Total de choix possible: %d.\n", lexique_len);

}
