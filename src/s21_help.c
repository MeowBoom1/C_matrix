#include "s21_matrix.h"

void s21_init_matrix(matrix_t* a, double num, double step) {
  if (a != NULL && a->matrix != NULL) {
    double num1 = num;
    for (int i = 0; i < a->rows; i++) {
      for (int j = 0; j < a->columns; j++) {
        a->matrix[i][j] = num1;
        num1 += step;
      }
    }
  }
}

void s21_init_E_matrix(matrix_t* M) {
  if (M != NULL && M->matrix != NULL && M->rows == M->columns) {
    for (int row = 0; row < M->rows; row++) {
      for (int col = 0; col < M->columns; col++) {
        M->matrix[row][col] = 1 ? row == col : 0;
      }
    }
  }
}