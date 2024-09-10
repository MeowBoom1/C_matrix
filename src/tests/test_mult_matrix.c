#include "testing_matrix.h"

START_TEST(mult_matrix_1) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  ck_assert_int_eq(s21_mult_matrix(&M1, &M2, NULL), MATRIX_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  int answer = CALC_ERROR;
  matrix_t result = {0};
  s21_create_matrix(4, 3, &M1);
  s21_create_matrix(5, 5, &M2);
  answer = s21_mult_matrix(&M1, &M2, &result);

  ck_assert_int_eq(answer, CALC_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  matrix_t answer = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 3, &M1);
  s21_create_matrix(3, 4, &M2);
  s21_mult_matrix(&M1, &M2, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &answer), CALC_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&answer);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_4) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(2, 3, &M1);
  s21_create_matrix(3, 2, &M2);
  s21_create_matrix(2, 2, &answer);
  s21_init_matrix(&M1, 1, 2);
  s21_init_matrix(&M2, 3, 4);
  answer.matrix[0][0] = 131;
  answer.matrix[0][1] = 167;
  answer.matrix[1][0] = 329;
  answer.matrix[1][1] = 437;

  s21_mult_matrix(&M1, &M2, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

START_TEST(mult_matrix_5) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  matrix_t result = {0};
  s21_create_matrix(5, 5, &M1);
  s21_create_matrix(5, 5, &M2);
  s21_init_matrix(&M1, 1, 1);
  s21_init_E_matrix(&M2);
  s21_mult_matrix(&M1, &M2, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &M1), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_6) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(10, 4, &M1);
  s21_create_matrix(5, 10, &M2);
  s21_create_matrix(4, 5, &answer);
  s21_init_matrix(&M1, 1, 3);
  s21_init_matrix(&M2, 0, 0);
  s21_init_matrix(&answer, 0, 0);
  s21_mult_matrix(&M1, &M2, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &answer), CALC_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

Suite *test_mult_matrix() {
  Suite *s = suite_create("\033[36m< s21_mult_matrix >\033[0m");
  TCase *tc = tcase_create("mult_matrix_tc");

  tcase_add_test(tc, mult_matrix_1);
  tcase_add_test(tc, mult_matrix_2);
  tcase_add_test(tc, mult_matrix_3);
  tcase_add_test(tc, mult_matrix_4);
  tcase_add_test(tc, mult_matrix_5);
  tcase_add_test(tc, mult_matrix_6);

  suite_add_tcase(s, tc);
  return s;
}