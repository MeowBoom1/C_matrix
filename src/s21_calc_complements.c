#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int result_code = OK;
  if (!s21_valid(A)) {
    result_code = MATRIX_ERROR;
  } else if (A->rows != A->columns) {
    result_code = CALC_ERROR;
  } else {
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          matrix_t minor;
          double determinant = 0;
          s21_calc_minor(A, i, j, &minor);
          s21_determinant(&minor, &determinant);
          result->matrix[i][j] = pow(-1, i + j) * determinant;
          s21_remove_matrix(&minor);
        }
      }
    } else {
      result_code = MATRIX_ERROR;
    }
  }
  return result_code;
}
