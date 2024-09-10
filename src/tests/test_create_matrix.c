#include "testing_matrix.h"

START_TEST(create_matrix_1) {
  int resCode = 0;
  matrix_t M = {0};
  resCode = s21_create_matrix(1, 1, &M);
  ck_assert_int_eq(resCode, OK);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(create_matrix_2) {
  int resCode = 0;
  matrix_t M = {0};
  resCode = s21_create_matrix(2, 3, &M);
  ck_assert_int_eq(resCode, OK);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(create_matrix_3) {
  int resCode = 0;
  matrix_t M = {0};

  resCode = s21_create_matrix(0, 0, &M);
  ck_assert_int_eq(resCode, MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(create_matrix_4) {
  int resCode = 0;

  resCode = s21_create_matrix(2, 10, NULL);
  ck_assert_int_eq(resCode, MATRIX_ERROR);
}
END_TEST

START_TEST(create_matrix_5) {
  int resCode = 0;
  matrix_t M = {0};

  resCode = s21_create_matrix(-5, -5, &M);
  ck_assert_int_eq(resCode, MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(create_matrix_6) {
  int resCode = 0;
  matrix_t M = {0};

  resCode = s21_create_matrix(5, -5, &M);
  ck_assert_int_eq(resCode, MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(create_matrix_7) {
  int resCode = 0;
  matrix_t M = {0};
  resCode = s21_create_matrix(-5, 5, &M);
  ck_assert_int_eq(resCode, MATRIX_ERROR);
  s21_remove_matrix(&M);
}
END_TEST

Suite *test_create_matrix() {
  Suite *s = suite_create("\033[36m< s21_create_matrix >\033[0m");
  TCase *tc = tcase_create("create_matrix_tc");

  tcase_add_test(tc, create_matrix_1);
  tcase_add_test(tc, create_matrix_2);
  tcase_add_test(tc, create_matrix_3);
  tcase_add_test(tc, create_matrix_4);
  tcase_add_test(tc, create_matrix_5);
  tcase_add_test(tc, create_matrix_6);
  tcase_add_test(tc, create_matrix_7);

  suite_add_tcase(s, tc);
  return s;
}
