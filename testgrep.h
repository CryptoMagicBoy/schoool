#include <check.h>
#include <stdlib.h>
#include <stdio.h>

START_TEST(grep_empty) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep e ../common/empty_file > tmp_grep");
    system("./s21_grep e ../common/empty_file > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_1) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep e ../common/test_file_1 > tmp_grep");
    system("./s21_grep e ../common/test_file_1 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_2) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep e ../common/test_file_2 > tmp_grep");
    system("./s21_grep e ../common/test_file_2 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_i) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -i e ../common/test_file_1 > tmp_grep");
    system("./s21_grep -i e ../common/test_file_1 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_c) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -c e ../common/test_file_2 > tmp_grep");
    system("./s21_grep -c e ../common/test_file_2 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_n) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -n s ../common/test_file_2 ./s21_grep.c > tmp_grep");
    system("./s21_grep -n s ../common/test_file_2 ./s21_grep.c > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_o) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -no e ../common/test_file_2 > tmp_grep");
    system("./s21_grep -no e ../common/test_file_2 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_l) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -l e ../common/test_file_2 ../common/test_file_1 ../common/empty_file > tmp_grep");
    system("./s21_grep -l e ../common/test_file_2 ../common/test_file_1 ../common/empty_file > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_v) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -v s ../common/test_file_2 ../common/test_file_1 ../common/empty_file > tmp_grep");
    system("./s21_grep -v s ../common/test_file_2 ../common/test_file_1 ../common/empty_file > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_h) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -h e ../common/test_file_2 ../common/test_file_1 > tmp_grep");
    system("./s21_grep -h e ../common/test_file_2 ../common/test_file_1 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_f) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -f ../common/reg_file ../common/test_file_2 ../common/test_file_1 > tmp_grep");
    system("./s21_grep -f ../common/reg_file ../common/test_file_2 ../common/test_file_1 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_s) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep s -s ../common/reg_file ../common/aqwedasd ../common/test_file_1 > tmp_grep");
    system("./s21_grep s -s ../common/reg_file ../common/aqwedasd ../common/test_file_1 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_e) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -e e -e a ../common/test_file_1 > tmp_grep");
    system("./s21_grep -e e -e a ../common/test_file_1 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST

START_TEST(grep_test_cases) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("grep -s  '^dog' ../common/reg_file ../common/aqwedasd ../common/test_file_1 > tmp_grep");
    system("./s21_grep -s '^dog' ../common/reg_file ../common/aqwedasd ../common/test_file_1 > tmp_s21_grep");
    system("shasum -a 512 tmp_grep > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_grep > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_grep");
    system("rm tmp_s21_grep");
}
END_TEST
