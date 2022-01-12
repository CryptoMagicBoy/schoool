#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
typedef struct FLAG_STRUCT{
    char flags[100];
    char reg[100];
    char files[100][100];
    int count_files;
} flag_struct;


int s21_grep(char** argv, int argc);
