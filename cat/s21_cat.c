#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void out(char **argv, int fe, int ft, int fv, int fb, int fs, int fn);
int s21_cat(int argc, char **argv);
void parser(int argc, char **argv, int *fe, int *ft, int *fv, int *fb, int *fs,
            int *fn, int rez, int option_index);

int main(int argc, char **argv) {
  s21_cat(argc, argv);
  return 0;
}
int s21_cat(int argc, char **argv) {
  int rez = 0, option_index = 0, fe = 0, ft = 0, fv = 0, fb = 0, fs = 0, fn = 0;
  parser(argc, argv, &fe, &ft, &fv, &fb, &fs, &fn, rez, option_index);
  argv++;
  out(argv, fe, ft, fv, fb, fs, fn);
  return 0;
}
void out(char **argv, int fe, int ft, int fv, int fb, int fs, int fn) {
  int sym, count_s = 0, check_n = 1, check_b = 1;
  FILE *file;
  while (*argv) {
    if (**argv == '-') {
      argv++;
    } else {
      file = fopen(*argv, "r");
      if (fn && fb) {
        fn = 0;
      }
      int count_nb = 1;
      while (1) {
        if (fn && check_n == 1) {
          printf("%6d\t", count_nb);
          count_nb++;
          check_n = 0;
        }
        sym = fgetc(file);
        if (feof(file)) {
          break;
        }
        if (fb && check_b == 1 && sym != '\n') {
          printf("%6d\t", count_nb);
          count_nb++;
        }
        check_b = 0;
        if (count_s > 0 && sym != '\n' && fb) {
          printf("%6d\t", count_nb);
          count_nb++;
        }
        if (sym == '\n') {
          count_s++;
        } else {
          count_s = 0;
        }
        if (count_s < 3 || fs == 0) {
          if (sym == '\t' && ft) {
            printf("^I");
          } else if (fv && -1 < sym && sym != 9 && sym != 10 && sym < 32) {
            printf("^%c", sym + 64);
          } else {
            if (sym == '\n') {
              if (fe) {
                printf("$");
              }
              check_b = 0;
            }
            printf("%c", sym);
          }
          if (sym == '\n' && fn) {
            sym = fgetc(file);
            if (feof(file)) {
                break;
            }
            ungetc(sym, file);
            printf("%6d\t", count_nb);
            count_nb++;
          }
        }
      }
      fclose(file);
      argv++;
    }
  }
}
void parser(int argc, char **argv, int *fe, int *ft, int *fv, int *fb, int *fs,
            int *fn, int rez, int option_index) {
  const char *short_options = "bevnstTE";
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};
  while ((rez = getopt_long(argc, argv, short_options, long_options,
                            &option_index)) != -1) {
    switch (rez) {
      case 'b':
        ++*fb;
        break;
      case 'e':
        ++*fe;
        ++*fv;
        break;
      case 'v':
        ++*fv;
        break;
      case 'n':
        ++*fn;
        break;
      case 's':
        ++*fs;
        break;
      case 't':
        ++*ft;
        ++*fv;
        break;
      case 'T':
        ++*ft;
        break;
      case 'E':
        ++*fe;
    }
  }
}
