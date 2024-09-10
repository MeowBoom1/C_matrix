#include "testing_matrix.h"

START_TEST(sub_matrix_1) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  ck_assert_int_eq(s21_sub_matrix(&M1, &M2, NULL), MATRIX_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

START_TEST(sub_matrix_2) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 3, &M1);
  s21_create_matrix(3, 4, &M2);
  ck_assert_int_eq(s21_sub_matrix(&M1, &M2, &result), CALC_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_3) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(5, 5, &M1);
  s21_create_matrix(5, 5, &M2);
  s21_create_matrix(5, 5, &answer);
  s21_init_matrix(&M1, 1, 1);
  s21_init_matrix(&M2, 1, 1);
  s21_init_matrix(&answer, 0, 0);
  s21_sub_matrix(&M1, &M2, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

START_TEST(sub_matrix_4) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  matrix_t result = {0};
  matrix_t answer = {0};
  s21_create_matrix(5, 5, &M1);
  s21_create_matrix(5, 5, &M2);
  s21_create_matrix(5, 5, &answer);
  s21_init_matrix(&M1, 3, 0);
  s21_init_matrix(&M2, 1, 0);
  s21_init_matrix(&answer, 2, 0);
  s21_sub_matrix(&M1, &M2, &result);
  ck_assert_int_eq(s21_eq_matrix(&result, &answer), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&answer);
}
END_TEST

Suite *test_sub_matrix() {
  Suite *s = suite_create("\033[36m< s21_sub_matrix >\033[0m");
  TCase *tc = tcase_create("sub_matrix_tc");

  tcase_add_test(tc, sub_matrix_1);
  tcase_add_test(tc, sub_matrix_2);
  tcase_add_test(tc, sub_matrix_3);
  tcase_add_test(tc, sub_matrix_4);

  suite_add_tcase(s, tc);
  return s;
}