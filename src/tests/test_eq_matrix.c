#include "testing_matrix.h"

START_TEST(eq_matrix_1) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  s21_create_matrix(4, 4, &M1);
  s21_create_matrix(4, 4, &M2);
  s21_init_matrix(&M1, 0, 1);
  s21_init_matrix(&M2, 0, 1);
  ck_assert_int_eq(s21_eq_matrix(&M1, &M2), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

START_TEST(eq_matrix_2) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  s21_create_matrix(5, 5, &M1);
  s21_create_matrix(5, 5, &M2);
  ck_assert_int_eq(s21_eq_matrix(&M1, &M2), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

START_TEST(eq_matrix_3) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  s21_create_matrix(4, 3, &M1);
  s21_create_matrix(3, 4, &M2);
  ck_assert_int_eq(s21_eq_matrix(&M1, &M2), CALC_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

START_TEST(eq_matrix_4) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  s21_create_matrix(10, 10, &M1);
  ck_assert_int_eq(s21_eq_matrix(&M1, &M2), CALC_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

START_TEST(eq_matrix_5) {
  matrix_t M1 = {0};
  matrix_t M2 = {0};
  s21_create_matrix(5, 5, &M1);
  s21_create_matrix(5, 5, &M2);
  s21_init_matrix(&M1, 1, 1);
  s21_init_matrix(&M2, 25, -1);
  ck_assert_int_eq(s21_eq_matrix(&M1, &M2), FAILURE);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

Suite *test_eq_matrix() {
  Suite *s = suite_create("\033[36m< s21_eq_matrix >\033[0m");
  TCase *tc = tcase_create("eq_matrix_tc");

  tcase_add_test(tc, eq_matrix_1);
  tcase_add_test(tc, eq_matrix_2);
  tcase_add_test(tc, eq_matrix_3);
  tcase_add_test(tc, eq_matrix_4);
  tcase_add_test(tc, eq_matrix_5);

  suite_add_tcase(s, tc);
  return s;
}