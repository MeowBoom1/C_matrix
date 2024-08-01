#include "testing_matrix.h"

START_TEST(inverse_matrix_1) {
  matrix_t M = {0};
  ck_assert_int_eq(s21_inverse_matrix(&M, NULL), MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(inverse_matrix_2) {
  matrix_t M = {0};
  matrix_t M_r = {0};
  s21_create_matrix(3, 4, &M);
  s21_init_matrix(&M, 1, 2);
  ck_assert_int_eq(s21_inverse_matrix(&M, &M_r), CALC_ERROR);
  s21_remove_matrix(&M);
  s21_remove_matrix(&M_r);
}
END_TEST

START_TEST(inverse_matrix_3) {
  matrix_t M = {0};
  matrix_t M_r = {0};
  s21_create_matrix(3, 3, &M);
  s21_init_matrix(&M, 1, 2);
  ck_assert_int_eq(s21_inverse_matrix(&M, &M_r), CALC_ERROR);
  s21_remove_matrix(&M);
  s21_remove_matrix(&M_r);
}
END_TEST

START_TEST(inverse_matrix_4) {
  matrix_t M = {0};
  matrix_t M_r = {0};
  matrix_t prob_E = {0};
  matrix_t E = {0};
  s21_create_matrix(3, 3, &M);
  s21_create_matrix(M.columns, M.columns, &E);
  s21_init_matrix(&M, 0, 0);
  s21_init_E_matrix(&E);
  s21_inverse_matrix(&M, &M_r);
  s21_mult_matrix(&M, &M_r, &prob_E);
  ck_assert_int_eq(s21_eq_matrix(&prob_E, &E), CALC_ERROR);
  s21_remove_matrix(&M);
  s21_remove_matrix(&M_r);
  s21_remove_matrix(&prob_E);
  s21_remove_matrix(&E);
}
END_TEST

START_TEST(inverse_matrix_5) {
  matrix_t M = {0};
  matrix_t M_r = {0};
  matrix_t prob_E = {0};
  matrix_t E = {0};
  s21_create_matrix(1, 1, &M);
  s21_create_matrix(M.columns, M.columns, &E);
  s21_init_matrix(&M, 3, 0);
  s21_init_E_matrix(&E);
  s21_inverse_matrix(&M, &M_r);
  s21_mult_matrix(&M, &M_r, &prob_E);
  ck_assert_int_eq(s21_eq_matrix(&prob_E, &E), SUCCESS);
  s21_remove_matrix(&M);
  s21_remove_matrix(&M_r);
  s21_remove_matrix(&prob_E);
  s21_remove_matrix(&E);
}
END_TEST

Suite *test_inverse_matrix() {
  Suite *s = suite_create("\033[36m< s21_inverse_matrix >\033[0m");
  TCase *tc = tcase_create("inverse_matrix_tc");

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);
  tcase_add_test(tc, inverse_matrix_5);
  suite_add_tcase(s, tc);
  return s;
}