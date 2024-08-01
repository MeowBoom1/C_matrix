#include "testing_matrix.h"

START_TEST(calc_complements_1) {
  matrix_t M = {0};
  s21_create_matrix(3, 3, &M);
  ck_assert_int_eq(s21_calc_complements(&M, NULL), MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(calc_complements_2) {
  matrix_t M = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 10, &M);
  s21_init_matrix(&M, 1, 1);
  ck_assert_int_eq(s21_calc_complements(&M, &result), CALC_ERROR);
  s21_remove_matrix(&M);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t M = {0};
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(3, 3, &M);
  s21_create_matrix(3, 3, &answer);
  M.matrix[0][0] = 1, M.matrix[0][1] = 2, M.matrix[0][2] = 3;
  M.matrix[1][0] = 0, M.matrix[1][1] = 4, M.matrix[1][2] = 2;
  M.matrix[2][0] = 5, M.matrix[2][1] = 2, M.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&M, &result), OK);
  answer.matrix[0][0] = 0;
  answer.matrix[0][1] = 10, answer.matrix[0][2] = -20;
  answer.matrix[1][0] = 4;
  answer.matrix[1][1] = -14, answer.matrix[1][2] = 8;
  answer.matrix[2][0] = -8;
  answer.matrix[2][1] = -2, answer.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&M);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t M = {0};
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(3, 3, &M);
  s21_create_matrix(3, 3, &answer);
  s21_init_matrix(&M, 9, -1);
  ck_assert_int_eq(s21_calc_complements(&M, &result), OK);
  answer.matrix[0][0] = -3, answer.matrix[0][1] = 6, answer.matrix[0][2] = -3;
  answer.matrix[1][0] = 6, answer.matrix[1][1] = -12, answer.matrix[1][2] = 6;
  answer.matrix[2][0] = -3, answer.matrix[2][1] = 6, answer.matrix[2][2] = -3;
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&M);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

Suite *test_calc_complements() {
  Suite *s = suite_create("\033[36m< s21_calc_complements >\033[0m");
  TCase *tc = tcase_create("calc_complements_tc");

  tcase_add_test(tc, calc_complements_1);
  tcase_add_test(tc, calc_complements_2);
  tcase_add_test(tc, calc_complements_3);
  tcase_add_test(tc, calc_complements_4);

  suite_add_tcase(s, tc);
  return s;
}