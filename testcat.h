#include <check.h>
#include <stdlib.h>
#include <stdio.h>

START_TEST(cat_empty) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat ../common/empty_file > tmp_cat");
    system("./s21_cat ../common/empty_file > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST

START_TEST(cat_enter) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat ../common/file_with_enter > tmp_cat");
    system("./s21_cat ../common/file_with_enter > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST

START_TEST(cat_test_1) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat ../common/test_file_1 > tmp_cat");
    system("./s21_cat ../common/test_file_1 > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST

START_TEST(cat_test_2) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat ../common/test_file_2 > tmp_cat");
    system("./s21_cat ../common/test_file_2 > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST

START_TEST(cat_test_n) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat -n ../common/test_file_2 > tmp_cat");
    system("./s21_cat -n ../common/test_file_2 > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST

START_TEST(cat_test_bn) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat -bn ../common/test_file_2 > tmp_cat");
    system("./s21_cat -bn ../common/test_file_2 > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST

START_TEST(cat_test_e) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat -e ../common/test_file_2 > tmp_cat");
    system("./s21_cat -e ../common/test_file_2 > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST

START_TEST(cat_test_s) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat -s ../common/test_file_2 > tmp_cat");
    system("./s21_cat -s ../common/test_file_2 > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST

START_TEST(cat_test_t) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat -t ../common/test_file_2 > tmp_cat");
    system("./s21_cat -t ../common/test_file_2 > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST


START_TEST(cat_test_v) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat -vte ../common/f4 > tmp_cat");
    system("./s21_cat -vte ../common/f4 > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST

START_TEST(cat_files) {
    char tmp[150];
    char tmp1[150];
    int c = 0;
    int i = 0;
    system("cat -nte ../common/test_file_2 ../common/test_file_1 ../common/empty_file ../common/file_with_enter > tmp_cat");
    system("./s21_cat -nte ../common/test_file_2 ../common/test_file_1 ../common/empty_file ../common/file_with_enter > tmp_s21_cat");
    system("shasum -a 512 tmp_cat > tmp_file");
    FILE* file = fopen("./tmp_file", "r");
    while ((c = fgetc(file))!= ' ') {
        tmp[i++] = c;
    }
    tmp[i] = 0;
    fclose(file);
    system("shasum -a 512 tmp_s21_cat > tmp_file");
    file = fopen("./tmp_file", "r");
    i = 0;
    while ((c = fgetc(file))!= ' ') {
        tmp1[i++] = c;
    }
    tmp1[i] = 0;
    fclose(file);
    ck_assert_int_eq(strcmp(tmp, tmp1), 0);
    system("rm tmp_file");
    system("rm tmp_cat");
    system("rm tmp_s21_cat");
}
END_TEST
