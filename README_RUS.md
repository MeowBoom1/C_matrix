# s21_matrix

Реализация библиотеки matrix.h.

## Task. Реализация функции библиотеки matrix.h

Реализовать основные действия с матрицами : create_matrix, remove_matrix, eq_matrix, sum_matrix, sub_matrix, mult_matrix, mult_number, transpose, determinant, calc_complements, inverse_matrix. 

- Библиотека должна быть разработана на языке С стандарта C11 с использованием компилятора gcc;  
- Подготовить полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check;
- Unit-тесты должны покрывать не менее 80% каждой функции;
- Предусмотреть Makefile для сборки библиотеки и тестов (с целями all, clean, test, s21_matrix.a, gcov_report);
- В цели gcov_report должен формироваться отчёт gcov в виде html страницы. Для этого unit-тесты должны запускаться с флагами gcov;
- Проверяемая точность дробной части - максимум 6 знаков после запятой.

