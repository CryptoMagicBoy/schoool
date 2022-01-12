#include "test_grep.h"

int main(void) {
    int no_failed = 0;
    Suite *s = suite_create("Suite");
    TCase *tc = tcase_create("Case");
    SRunner *sr = srunner_create(s);
    suite_add_tcase(s, tc);

    tcase_add_test(tc, grep_empty);
    tcase_add_test(tc, grep_test_1);
    tcase_add_test(tc, grep_test_2);
    tcase_add_test(tc, grep_test_i);
    tcase_add_test(tc, grep_test_c);
    tcase_add_test(tc, grep_test_n);
    tcase_add_test(tc, grep_test_o);
    tcase_add_test(tc, grep_test_l);
    tcase_add_test(tc, grep_test_h);
    tcase_add_test(tc, grep_test_f);
    tcase_add_test(tc, grep_test_s);
    tcase_add_test(tc, grep_test_e);
    tcase_add_test(tc, grep_test_v);
    tcase_add_test(tc, grep_test_cases);

    srunner_run_all(sr, CK_VERBOSE);
    no_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return no_failed == 0 ? 0 : 1;
}
