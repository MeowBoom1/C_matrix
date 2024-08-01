#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (!A || !A->matrix || A->rows != A->columns || A->rows < 1 || !result) {
    error = MATRIX_ERROR;
  } else {
    double det = 0;
    if (A->rows == 1) {
      det = A->matrix[0][0];
    } else if (A->rows == 2) {
      det =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    } else {
      for (int i = 0; i < A->rows; i++) {
        matrix_t minor = {0};
        s21_calc_minor(A, 0, i, &minor);
        double minor_det = 0;
        int minor_error = s21_determinant(&minor, &minor_det);
        if (minor_error == OK) {
          det += pow((-1), i) * A->matrix[0][i] * minor_det;
        } else {
          error = minor_error;
          break;
        }
        s21_remove_matrix(&minor);
      }
    }
    *result = det;
  }

  return error;
}