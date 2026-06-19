#ifndef SUTOM_H
# define SUTOM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void les_consignes(int len, char *word);
int real_words(FILE *file, char *my_word);
char *gen_word(FILE *file);
char *is_inside(char *argv, char *word);
int is_correct(char *colors, int len);
void is_error(char *user, int len);
char *print_colors(char *user, char *word, int len);

char **create_lexique(FILE *file, int size, char *word);
void remove_word(char **lexique, int index);
void solver(char **lexique, char *user, char *word);

#endif