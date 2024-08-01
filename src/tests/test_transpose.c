#include "testing_matrix.h"

START_TEST(transpose_1) {
  matrix_t M = {0};
  ck_assert_int_eq(s21_transpose(&M, NULL), MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(transpose_2) {
  matrix_t M = {0};
  matrix_t T = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 5, &M);
  s21_init_matrix(&M, 0, 0);
  s21_transpose(&M, &T);
  s21_transpose(&T, &result);
  ck_assert_int_eq(s21_eq_matrix(&M, &result), SUCCESS);
  s21_remove_matrix(&M);
  s21_remove_matrix(&T);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_4) {
  matrix_t T = {0};
  matrix_t E = {0};
  s21_create_matrix(10, 10, &E);
  s21_init_E_matrix(&E);
  s21_transpose(&E, &T);
  ck_assert_int_eq(s21_eq_matrix(&T, &E), SUCCESS);
  s21_remove_matrix(&E);
  s21_remove_matrix(&T);
}
END_TEST

Suite *test_transpose() {
  Suite *s = suite_create("\033[36m< s21_transpose >\033[0m");
  TCase *tc = tcase_create("transpose_tc");

  tcase_add_test(tc, transpose_1);
  tcase_add_test(tc, transpose_2);
  tcase_add_test(tc, transpose_4);

  suite_add_tcase(s, tc);
  return s;
}