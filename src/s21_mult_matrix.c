#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (A == NULL || B == NULL || result == NULL)
    error = MATRIX_ERROR;
  else if (A->columns != B->rows)
    error = CALC_ERROR;
  else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++)
      for (int k = 0; k < B->columns; k++)
        for (int j = 0; j < A->columns; j++)
          result->matrix[i][k] += A->matrix[i][j] * B->matrix[j][k];
  }
  return error;
}