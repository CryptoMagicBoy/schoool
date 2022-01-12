#include "./s21_grep.h"

//  †
// † †
//  †
//  †
int init_grep(char** argv, int argc, flag_struct* flags_files_reg, int* err_char);
int get_file_size(FILE* file);
int regex_init(flag_struct* flags_files_reg, regex_t* re);
int start_grep(flag_struct* flags_files_reg, regex_t* re);
void fill_result_str(regex_t* re, char* tmp, flag_struct* flags_files_reg, int file_id);
int get_count_line(char* tmp);
void add_flag(char** argv, flag_struct* flags_files_reg, int* err_char, char* reg_file, \
                                    int* count_flags, char* flags, int* status, int* i1);
void add_new_reg(char** argv, flag_struct* flags_files_reg, int i, int count_flag);
int reg_from_file(char* reg_file, flag_struct* flags_files_reg);


char* result_str_cat(regmatch_t* m, char** tmp, char* p, \
                        flag_struct* flags_files_reg, int* count_row, int file_id, int* old_row_number);
char* output_result(char *tmp, int LEN, flag_struct* flags_files_reg, int file_if, \
                                        int row_number, int old_row_count, int v_flag);
void shift_start(int* start,  char* tmp);
void shift_finish(int* finish,  char* tmp);
void output_c(char* file, int count, int count_file);
int get_row_count(char** tmp, char** p, int start);
char* fill_vmass(char* str, int LEN);
void output_v(flag_struct* flags_files_reg, char* p, int file_id);


int main(int argc, char** argv) {
    return s21_grep(argv, argc);
}

int s21_grep(char** argv, int argc) {
    int status = 0;
    flag_struct flag_files_reg;
    int err_char = 0;
    status = init_grep(argv, argc, &flag_files_reg, &err_char);
    if (status == 0) {
        regex_t re;
        status = regex_init(&flag_files_reg, &re);
        if (status != 0) {
            char error_s[100];
            regerror(status, &re, error_s, 100);
        } else {
            status = start_grep(&flag_files_reg, &re);
            regfree(&re);
        }

    } else {
        printf("grep: invalid option -- %c", err_char);
    }
    return status;
}

int regex_init(flag_struct* flags_files_reg, regex_t* re) {
    int status = 0;
    int options = REG_EXTENDED|REG_NEWLINE;
    if (strchr(flags_files_reg->flags, 'i') != NULL) {
        options = options|REG_ICASE;
    }
    status = regcomp(re, flags_files_reg->reg, options);
    return status;
}
int start_grep(flag_struct* flags_files_reg, regex_t* re) {
    int status = 0;
    FILE* file = NULL;
    char *result_str = NULL;
    char *tmp = NULL;
    for (int i = 0; i < flags_files_reg->count_files; i++) {
        file = fopen(flags_files_reg->files[i], "r");
        if (file != NULL) {
            int file_size = get_file_size(file) + 1;
            tmp = calloc(file_size + 1, 1);
            result_str = calloc(file_size * 20, 1);
            if (tmp != NULL && result_str != NULL) {
                fread(tmp, 1, file_size, file);
                fill_result_str(re, tmp, flags_files_reg, i);
            }

            if (tmp != NULL) free(tmp);
            if (result_str != NULL) free(result_str);
            fclose(file);
        } else {
            if (strchr(flags_files_reg->flags, 's') == NULL)
                printf("grep: %s: No such file or directory\n", flags_files_reg->files[i]);
        }
    }
    return status;
}

void fill_result_str(regex_t* re, char* tmp, flag_struct* flags_files_reg, int file_id) {
    int count = 0;
    int LEN = strlen(tmp);
    int old_row_number = -1;
    char* p = tmp;
    int flag = 0;
    char* v_str = NULL;
    regmatch_t m[LEN];
    while (1) {
        int nomatch = regexec(re, tmp, LEN, m, 0);
        if (nomatch || flag == 1) {
            break;
        }
        v_str = result_str_cat(m, &tmp, p, flags_files_reg, &count, file_id, &old_row_number);
        if (strchr(flags_files_reg->flags, 'l') != NULL) {
            flag = 1;
        }
    }
    if (v_str != 0) {
        output_v(flags_files_reg, p, file_id);
    }
    if (strchr(flags_files_reg->flags, 'c') != NULL) {
        output_c(flags_files_reg->files[file_id], count, flags_files_reg->count_files);
    }
}

void output_v(flag_struct* flags_files_reg, char* p, int file_id) {
    char* copy = "";
    copy = fill_vmass(copy, 0);
    copy[strlen(copy) - 2] = 0;
    int find_flag = 0;
    char qwe[1000];
    char qwe1[1000];
    int j = 0;
    while (p[j] != 0) {
        find_flag = 0;
        int i = 0;
        for (; p[j] != '\n' && p[j] != 0; i++, j++) {
            qwe[i] = p[j];
        }
        qwe[i] = 0;
        int i1 = 0;
        while (copy[i1] != 0 && find_flag == 0) {
        int j1 = 0;
            for (; copy[i1] != '\n' && copy[i1] != 0; i1++, j1++) {
                qwe1[j1] = copy[i1];
            }
            i1++;
            qwe1[j1] = 0;
            if (strcmp(qwe1, qwe) == 0) {
                find_flag = 1;
            }
        }
        if (find_flag == 0 || i == 0) {
            output_result(qwe, strlen(qwe), flags_files_reg, file_id, 0, 0, 1);
        }
        j++;
    }
    fill_vmass(copy, -1);
}

void output_c(char* file, int count, int count_file) {
    if (count_file > 1) {
        printf("%s:%d\n", file, count);
    } else {
        printf("%d\n", count);
    }
}


char* result_str_cat(regmatch_t* m, char** tmp, char* p, flag_struct* flags_files_reg, \
                                                int* count_row, int file_id, int* old_row_number) {
    int start = 0;
    int finish = 0;
    char* copy = NULL;
    start = m[0].rm_so;
    finish = m[0].rm_eo;
    if (strchr(flags_files_reg->flags, 'o') == NULL) {
        shift_start(&start, *tmp);
        shift_finish(&finish, *tmp);
    }
    if (strchr(flags_files_reg->flags, 'c') != NULL) {
        (*count_row)++;
    } else {
        int row_count = get_row_count(tmp, &p, start);
        copy = output_result(*tmp + start, finish - start, \
                    flags_files_reg, file_id, row_count, *old_row_number, 0);
        *old_row_number = row_count;
        }
    *tmp += finish;
    return copy;
}

int get_row_count(char** tmp, char** p, int start) {
    int count = 1;
    char* tmp2 = *p;
    while (tmp2 != *tmp + start) {
        if (*tmp2 == '\n') {
            count++;
        }
        tmp2++;
    }
    return count;
}

char* output_result(char *tmp, int LEN, flag_struct* flags_files_reg, \
                            int file_id, int row_number, int old_row_count, int v_flag) {
    char result_str[1024] = {0};
    char* copy = NULL;
    if (flags_files_reg->count_files > 1 && strchr(flags_files_reg->flags, 'h') == NULL) {
        char sym = strchr(flags_files_reg->flags, 'l') == NULL ? ':' : 0;
        snprintf(result_str, sizeof(result_str), "%s%c", flags_files_reg->files[file_id], sym);
    }
    if (strchr(flags_files_reg->flags, 'n') != NULL && row_number != old_row_count) {
        snprintf(result_str, sizeof(result_str), "%s%d%c", result_str, row_number, ':');
    }

    if (strchr(flags_files_reg->flags, 'l') == NULL) {
        snprintf(result_str, sizeof(result_str), "%s%.*s", result_str, LEN, tmp);
    }

    if (strchr(flags_files_reg->flags, 'v') != NULL && v_flag == 0) {
        copy = fill_vmass(tmp, LEN);
    } else {
        printf("%s\n", result_str);
    }
    return copy;
}

char* fill_vmass(char* str, int LEN) {
    static char mas[10024];
    if (LEN == -1) {
        snprintf(mas, sizeof(mas), "%s", "");
    } else {
        snprintf(mas, sizeof(mas), "%s%.*s\n", mas, LEN, str);
    }
    return mas;
}

void shift_start(int* start, char* tmp) {
    while (1) {
        if (*start == 0 || tmp[*start - 1] == '\n') {
            break;
        }
        (*start)--;
    }
}

void shift_finish(int* finish, char* tmp) {
    while (1) {
        if (tmp[*finish] == 0 || tmp[*finish] == '\n') {
            break;
        }
        (*finish)++;
    }
}

int get_file_size(FILE* file) {
    fseek(file, 0, SEEK_END);
    int result = ftell(file);
    fseek(file, 0, SEEK_SET);
    return result;
}

int init_grep(char** argv, int argc, flag_struct* flags_files_reg, int* err_char) {
    int status = 0;
    char* flags = "eivclnhsfo";
    char reg_file[50] = "";
    flags_files_reg->reg[0] = 0;
    int i = 1;
    int count_flags = 0;
    flags_files_reg->count_files = 0;
    while (i < argc && status == 0) {
        if (argv[i][0] == '-') {
            add_flag(argv, flags_files_reg, err_char, reg_file, &count_flags, flags, &status, &i);
        } else {
            if (strcmp(flags_files_reg->reg, "") == 0) {
                if (strcmp(reg_file, "") == 0) {
                    snprintf(flags_files_reg->reg, strlen(flags_files_reg->reg) + strlen(argv[i]) + 1, \
                                                                    "%s%s", flags_files_reg->reg, argv[i]);
                } else {
                    status = reg_from_file(reg_file, flags_files_reg);
                }
            }
            if (strchr(flags_files_reg->flags, 'e') != NULL) {
                i--;
            }
            if (argv[i + 1][0] != '-') {
                while (i < argc - 1) {
                    snprintf(flags_files_reg->files[flags_files_reg->count_files], \
                            sizeof(flags_files_reg->files[flags_files_reg->count_files]), "%s", argv[++i]);
                    flags_files_reg->count_files++;
                }
            } else {
                add_flag(argv, flags_files_reg, err_char, reg_file, &count_flags, flags, &status, &i);
            }
        }
        i++;
    }
    flags_files_reg->flags[count_flags] = 0;
    return status;
}
int reg_from_file(char* reg_file, flag_struct* flags_files_reg) {
    int status = 0;
    FILE* file = fopen(reg_file, "r");
    if (file != NULL) {
        char copy_char[50] = {0};
        int file_size = get_file_size(file);
        fread(copy_char, 1, file_size, file);
        snprintf(flags_files_reg->reg, strlen(flags_files_reg->reg) + strlen(copy_char) + 1, \
                                                                    "%s%s", flags_files_reg->reg, copy_char);
        fclose(file);
    } else {
        if (strchr(flags_files_reg->flags, 's') == NULL)
            printf("grep: %s: No such file or directory\n", reg_file);
        status = 1;
    }
    return status;
}

void add_flag(char** argv, flag_struct* flags_files_reg, int* err_char, char* reg_file, \
                                            int* count_flags, char* flags, int* status, int* i1) {
    int i = *i1;
    int j = 1;
    while (argv[i][j] != 0 && *status == 0 && strcmp(reg_file, "") == 0 && i == *i1) {
        if (strchr(flags, argv[i][j]) != NULL) {
            if (argv[i][j] == 'f') {
                snprintf(reg_file, strlen(argv[i + 1]) + 2, "%s", argv[i + 1]);
            } else if (argv[i][j] == 'e') {
                flags_files_reg->flags[(*count_flags)++] = argv[i][j];
                if (strcmp(flags_files_reg->reg, "") != 0) {
                    int LEN = strlen(flags_files_reg->reg);
                    flags_files_reg->reg[LEN++] = '|';
                    flags_files_reg->reg[LEN] = 0;
                }
                snprintf(flags_files_reg->reg, strlen(flags_files_reg->reg) + strlen(argv[i + 1]) + 1, \
                                                            "%s%s", flags_files_reg->reg, argv[i + 1]);
                *i1 = *i1 + 1;
            } else {
                flags_files_reg->flags[(*count_flags)++] = argv[i][j];
            }
        } else {
            if (strchr(flags, argv[i][j]) == NULL) {
                *status = 1;
                *err_char = argv[i][j];
            }
        }
        j++;
    }
}
