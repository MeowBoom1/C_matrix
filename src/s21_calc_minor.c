#include "s21_matrix.h"

void s21_calc_minor(matrix_t *M, int row, int column, matrix_t *result) {
  s21_create_matrix(M->rows - 1, M->columns - 1, result);
  int r = 0;
  int c = 0;
  for (int i = 0; i < M->rows; i++) {
    for (int j = 0; j < M->columns; j++) {
      if (i != row && j != column) {
        result->matrix[i - r][j - c] = M->matrix[i][j];
      } else if (i == row)
        r = 1;
      else if (j == column)
        c = 1;
    }
    c = 0;
  }
}
