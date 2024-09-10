#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (!s21_valid(A))
    error = MATRIX_ERROR;
  else if (A->rows != A->columns)
    error = CALC_ERROR;
  else {
    double det = 0;
    s21_determinant(A, &det);
    if (det == 0)
      error = CALC_ERROR;
    else {
      if ((A->rows == 1) &&
          (error = s21_create_matrix(A->rows, A->columns, result)) == OK) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        matrix_t algebr = {};
        if ((error = s21_calc_complements(A, &algebr)) == OK) {
          matrix_t transposed = {};
          if ((error = s21_transpose(&algebr, &transposed)) == OK) {
            s21_mult_number(&transposed, 1 / det, result);
            s21_remove_matrix(&transposed);
          }
        }
        s21_remove_matrix(&algebr);
      }
    }
  }
  return error;
}