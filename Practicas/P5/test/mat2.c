#include <stdio.h>
void escribe(int** a, int x, int y); // prototipo
void escribo(int (*a)[12], int x, int y); // prototipo

void main () {// =============
 int **dias = {
 { 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12},
 {13,14,15,16,17,18,19,20,21,22,23,24}
 };
 escribe(dias, 1, 3);
 escribe(dias, 0, 7);
 //escribo(12,dias, 1, 3);
 //escribo(12,dias, 0, 7);
}

void escribe(int **a, int f, int c) { // definición
 printf("Valor [%2i,%2i] = %3i\n", f, c, a[f][c]);
}

void escribo(int (*a)[12], int f, int c) { // definición
 printf("Valor [%2i,%2i] = %3i\n", f, c, a[f][c]);
}

