#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int parser(char **argv, int *fe, int *fi, int *fv, int *fc, int *fl,
            int *fn, int *fh, int *fs, int *ff, int *fo, char *mas, int *k);
int s21_grep(int argc, char **argv);
void grep_plus(int fi, int fv, int fc, int fl, int fn, int fh, \
               int fo, char **argv_clone, char *mas, FILE *file, int k);

int main(int argc, char **argv) {
  s21_grep(argc, argv);
  return 0;
}
int s21_grep(int argc, char **argv) {
  int fe = 0, fi = 0, fv = 0, fc = 0, fl = 0, fn = 0, fh = 0, fs = 0, ff = 0, fo = 0, k = 0;
    argc = argc;
  char *mas = (char*)malloc(8096);
  char **argv_clone = argv;
  int check = parser(argv, &fe, &fi, &fv, &fc, &fl, &fn, &fh, &fs, &ff, &fo, mas, &k);
  if (check) {
      strcat(mas, ")");
      argv_clone++;
      for (int i = 0; i < k; ++i) {
          while (*argv_clone == NULL) {
              argv_clone++;
          }
          FILE *file;
          if (!fe && !ff) {
              k--;
              mas[1] = '\0';
              strcat(mas, *argv_clone);
              strcat(mas, ")");
              argv_clone++;
              fe++;
          }
          if ((file = fopen(*argv_clone, "r")) != NULL) {
              grep_plus(fi, fv, fc, fl, fn, fh, fo, argv_clone, mas, file, k);
          } else if (!fs) {
              printf("grep: %s : No such file of directory\n", *argv_clone);
          }
          argv_clone++;
      }
  }
  free(mas);
  return 0;
}

int parser(char **argv, int *fe, int *fi, int *fv, int *fc, int *fl,
            int *fn, int *fh, int *fs, int *ff, int *fo, char *mas, int *k) {
    int error = 1, sym;
    strcpy(mas, "(");
    argv++;
    while (*argv) {
        if (**argv == '-') {
            *argv += 1;
            while (**argv != '\0') {
                if (**argv == 'e') {
                    if (*fe > 0 || *ff > 0) {
                        strcat(mas, "|");
                    }
                    *fe = 1;
                    *argv += 1;
                    if (**argv == '\0') {
                        *argv = NULL;
                        argv++;
                    }
                    strcat(mas, *argv);
                    *argv = NULL;
                } else if (**argv == 'i') {
                    *fi = 1;
                } else if (**argv == 'v') {
                    *fv = 1;
                } else if (**argv == 'c') {
                    *fc = 1;
                } else if (**argv == 'l') {
                    *fl = 1;
                } else if (**argv == 'n') {
                    *fn = 1;
                } else if (**argv == 'h') {
                    *fh = 1;
                } else if (**argv == 's') {
                    *fs = 1;
                } else if (**argv == 'f') {
                    *ff = 1;
                    FILE* file;
                    *argv += 1;
                    if (**argv == '\0') {
                        *argv = NULL;
                        argv++;
                    }
                    file = fopen(*argv, "r");
                    while (*mas != '\0') {
                        mas++;
                    }
                    while (1) {
                        sym = fgetc(file);
                        if (feof(file)) {
                            break;
                        }
                        *mas++ = sym;
                        if (sym == '\n')
                            *mas++ = '|';
                    }
                    fclose(file);
                } else if (**argv == 'o') {
                    *fo = 1;
                } else {
                    error = 0;
                }
                if (*argv == NULL)
                    break;
                *argv += 1;
            }
            *argv = NULL;
        } else {
            *k += 1;
        }
        argv++;
    }
    return error;
}

void grep_plus(int fi, int fv, int fc, int fl, int fn, int fh, \
               int fo, char **argv_clone, char *mas, FILE *file, int k) {
    regex_t r;
    char *line = NULL;
    size_t size, nmatch = 2;
    regmatch_t pmatch[2];
    int count = 0, count_n = 0;
    if (fi > 0) {
        regcomp(&r, mas, REG_EXTENDED | REG_ICASE);
    } else {
        regcomp(&r, mas, REG_EXTENDED);
    }
    while (getline(&line, &size, file) != EOF) {
        count_n++;
        int isMatch = regexec(&r, line, nmatch, pmatch, 0);
        if (isMatch != REG_NOMATCH && !fv) {
            if (fn) {
                if (k > 1 && !fh) {
                    printf("%s:", *argv_clone);
                }
                printf("%d:", count_n);
            }
            if (!fc && !fl) {
                if (fo) {
                    while (isMatch != REG_NOMATCH) {
                        char *line_buf = line;
                        printf("%.*s\n", (int)(pmatch[1].rm_eo - \
                                               pmatch[1].rm_so), line_buf + pmatch[1].rm_so);
                        line_buf += pmatch[1].rm_eo;
                        isMatch = regexec(&r, line_buf, 0, pmatch, 0);
                    }
                } else {
                    if (k > 1 && !fn && !fh) {
                        printf("%s:", *argv_clone);
                    }
                    printf("%s", line);
                }
            }
            count++;
        } else if (isMatch == REG_NOMATCH && fv) {
            if (fn) {
                if (k > 1 && !fh) {
                    printf("%s:", *argv_clone);
                }
                printf("%d:", count_n);
            }
            if (!fc && !fl) {
                if (k > 1 && !fn && !fh) {
                    printf("%s:", *argv_clone);
                }
                printf("%s", line);
            }
            count++;
        }
    }
    if (fc) {
        printf("%d\n", count);
    } else if (fl && count) {
        printf("%s", *argv_clone);
    }
}
