#include "testing_matrix.h"

START_TEST(determinant_1) {
  matrix_t M = {0};
  ck_assert_int_eq(s21_determinant(&M, NULL), MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t M = {0};
  double result = 0;
  ck_assert_int_eq(s21_determinant(&M, &result), MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(determinant_3) {
  matrix_t M = {0};
  double result = 0;
  double answer = 0;
  s21_create_matrix(2, 2, &M);
  s21_init_matrix(&M, 100, 0);
  s21_determinant(&M, &result);
  ck_assert_double_eq_tol(result, answer, 1e-7);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t M = {0};
  double result = 0;
  double answer = -2;
  s21_create_matrix(2, 2, &M);
  s21_init_matrix(&M, 1, 1);
  s21_determinant(&M, &result);
  ck_assert_float_eq_tol(result, answer, 1e-7);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t M = {0};
  double result = 0;
  double answer = 0;
  s21_create_matrix(3, 3, &M);
  s21_init_matrix(&M, 1, 1);
  s21_determinant(&M, &result);
  ck_assert_float_eq_tol(result, answer, 1e-7);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(determinant_6) {
  matrix_t M = {0};
  double result = 0;
  s21_create_matrix(3, 4, &M);
  s21_init_matrix(&M, 1, 1);
  ck_assert_int_eq(s21_determinant(&M, &result), MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

Suite *test_determinant() {
  Suite *s = suite_create("\033[36m< s21_determinant >\033[0m");
  TCase *tc = tcase_create("determinant_tc");

  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);
  tcase_add_test(tc, determinant_6);

  suite_add_tcase(s, tc);
  return s;
}