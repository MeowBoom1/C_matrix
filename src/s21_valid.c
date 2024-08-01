#include "s21_matrix.h"

int s21_valid(matrix_t *A) {
  int result = 1;
  if (A == NULL || A->rows < 1 || A->columns < 1) {
    result = 0;
  }
  return result;
}