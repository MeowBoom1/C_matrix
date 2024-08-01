#include "testing_matrix.h"

START_TEST(remove_matrix_1) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_null(A.matrix);
}
END_TEST

START_TEST(remove_matrix_2) {
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(remove_matrix_3) {
  matrix_t A = {0};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

Suite *test_remove_matrix() {
  Suite *s = suite_create("\033[36m< s21_remove_matrix >\033[0m");
  TCase *tc = tcase_create("remove_matrix_tc");

  tcase_add_test(tc, remove_matrix_1);
  tcase_add_test(tc, remove_matrix_2);
  tcase_add_test(tc, remove_matrix_3);

  suite_add_tcase(s, tc);
  return s;
}