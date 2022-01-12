#include "s21_cat.h"

void cat_files(flag_struct* flags_files);
int filter_flags(char** argv, int argc, flag_struct* flags_files, int* err_char);
void cat_console(flag_struct* flags_files);
void replace_tabs(char* str);
void place_and_shift(char* str, int i, char sym);
void put_str(flag_struct* flags_files, char* tmp, int* row_count, int* empty_row, int end_flag);
int read_line(FILE* file, char** tmp, int* LEN);
void replace_all(char* str, int end_flag);
void add_long_flag(char** argv, int i, flag_struct* flags_files, int* count_flags);


int main(int argc, char** argv) {
    return s21_cat(argv, argc);
}

int s21_cat(char** argv, int argc) {
    int err_char = 0;
    flag_struct flags_files;
    int status = filter_flags(argv, argc, &flags_files, &err_char);
    if (status == 0) {
        if (flags_files.count_files == 0) {
            cat_console(&flags_files);
        } else {
            cat_files(&flags_files);
        }
    } else {
        printf("cat: illega l option -- %c", err_char);
    }
    return status;
}

void cat_console(flag_struct* flags_files) {
    char tmp[255];
    int b_count = 0;
    int count_empty_line = 0;

    while (1) {
        int c = scanf("%[^\n]s", tmp);
        if (getchar() == EOF) break;

        if (c == 0) snprintf(tmp, sizeof(tmp), "%s", "");
        put_str(flags_files, tmp, &b_count, &count_empty_line, 0);
    }
}

void cat_files(flag_struct* flags_files) {
    int row_count = 0, empty_row = 0;
    int LEN = 2;
    char *tmp = malloc(LEN);
    if (tmp != NULL) {
        for (int i = 0; i < flags_files->count_files; i++) {
            FILE* file;
            if ((file = fopen(flags_files->files[i], "r")) != NULL) {
                while (read_line(file, &tmp, &LEN) != EOF) {
                    if (strchr(flags_files->flags, 'e') != NULL) {
                        LEN += 2;
                        tmp = realloc(tmp, LEN);
                    }
                    put_str(flags_files, tmp, &row_count, &empty_row, 0);
                }
                if (strcmp(tmp, "") != 0)
                    put_str(flags_files, tmp, &row_count, &empty_row, 1);

                fclose(file);
            } else {
                printf("cat: %s: No such file or directory", flags_files->files[i]);
            }
            row_count = 0;
            empty_row = 0;
        }
    free(tmp);
    }
}

void replace_tabs(char* str) {
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '\t') {
            place_and_shift(str, i, 'I');
        }
    }
}

void place_and_shift(char* str, int i, char sym) {
    int copy_i1 = strlen(str);
    for (int copy_i = strlen(str); copy_i != i; copy_i--) {
        str[copy_i] = str[copy_i - 1];
    }
    str[i] = '^';
    str[i + 1] = sym;
    str[copy_i1 + 1] = 0;
}

void replace_all(char* str, int end_flag) {
    int i = 0;
    for (; str[i] != 0; i++) {
        if (str[i] < 32 && str[i] != 9 && str[i] != 10) {
            place_and_shift(str, i, str[i] + 64);
        }
        if (str[i] == 127) {
            place_and_shift(str, i, '?');
        }
    }
    if (end_flag == 1) {
        str[i++] = '^';
        str[i++] = '@';
        str[i] = 0;
    }
}

void put_str(flag_struct* flags_files, char* tmp, int* row_count, int* empty_row, int end_flag) {
    int flag = 0;
    if (strcmp(tmp, "") == 0) {
        (*empty_row)++;
    } else {
        *empty_row = 0;
    }
    if (strchr(flags_files->flags, 's') != NULL && (*empty_row) > 1) {
        flag = 1;
    }
    if (strchr(flags_files->flags, 't') != NULL) {
        replace_tabs(tmp);
    }
    if (strchr(flags_files->flags, 'v') != NULL) {
        replace_all(tmp, end_flag);
    }
    if (strchr(flags_files->flags, 'e') != NULL && end_flag != 1) {
        int LEN = strlen(tmp);
        tmp[LEN++] = '$';
        tmp[LEN] = 0;
    }
    if (strchr(flags_files->flags, 'b') != NULL && *empty_row == 0 && flag == 0) {
        printf("%6d\t", ++(*row_count));
    }
    if (strchr(flags_files->flags, 'n') != NULL \
                && strchr(flags_files->flags, 'b') == NULL && flag == 0) {
        printf("%6d\t", ++(*row_count));
    }
    if (flag == 0) {
        end_flag == 1 ? printf("%s", tmp) : printf("%s\n", tmp);
    }
}

int filter_flags(char** argv, int argc, flag_struct* flags_files, int* err_char) {
    int status = 0;
    char* flags = "benstvTE";
    int i = 1;
    int count_flags = 0;
    int count_files = 0;
    int end_flag = 0;
    while (i != argc && status == 0) {
        if (argv[i][0] == '-' && end_flag == 0) {
            int j = 1;
            if (argv[i][j] == '-') {
                add_long_flag(argv, i, flags_files, &count_flags);
            } else {
                while (argv[i][j] != 0 && status == 0) {
                    if (strchr(flags, argv[i][j]) != NULL) {
                        if (argv[i][j] == 'T') {
                            flags_files->flags[count_flags++] = 't';
                        } else if (argv[i][j] == 'E') {
                            flags_files->flags[count_flags++] = 'e';
                        } else {
                            flags_files->flags[count_flags++] = argv[i][j];
                        }
                    } else {
                        status = 1;
                        *err_char = argv[i][j];
                    }
                    j++;
                }
            }
        } else {
            snprintf(flags_files->files[count_files], sizeof(flags_files->files[count_files]), "%s", argv[i]);
            count_files++;
            end_flag = 1;
        }
        i++;
    }

    flags_files->flags[count_flags] = 0;
    flags_files->count_files = count_files;
    return status;
}

void add_long_flag(char** argv, int i, flag_struct* flags_files, int* count_flags) {
    char* long_b_flag = "--number-nonblank";
    char* long_n_flag = "--number";
    char* long_s_flag = "--squeeze-blank";
    if (strcmp(argv[i], long_b_flag) == 0) {
        flags_files->flags[(*count_flags)++] = 'b';
    }
    if (strcmp(argv[i], long_n_flag) == 0) {
        flags_files->flags[(*count_flags)++] = 'n';
    }
    if (strcmp(argv[i], long_s_flag) == 0) {
        flags_files->flags[(*count_flags)++] = 's';
    }
}


int read_line(FILE* file, char** tmp, int* LEN) {
    int c = 0;
    int i = 0;
    while (1) {
        c = fgetc(file);
        if (c == EOF || c == '\n') break;
        (*tmp)[i++] = c;
        if (i == *LEN) {
            *LEN = *LEN * 2 + 10;
            *tmp = realloc(*tmp, *LEN);
        }
    }

    (*tmp)[i++] = 0;
    return c;
}
