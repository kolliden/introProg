/*
Zur Abgabe einen branch `iprg-b07` erstellen und pushen, in dem als einzige Datei die `07ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 07ex_test.c -o 07ex_test.o -lm && ./07ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 07ex_test.c -o 07ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./07ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Bringen Sie die Tests zum durchlaufen.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/

void merge(uint8_t *arr, uint8_t *left_arr, size_t left_len, uint8_t *right_arr, size_t right_len) {
    size_t i = 0, j = 0, k = 0;
    while (i < left_len && j < right_len) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < left_len) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < right_len) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}
// Iterativer Merge Sort
uint8_t* sort_it(Visualizer *v, uint8_t *arr, size_t len) {
    visualizer_append_array(v, arr);
    size_t step = 1;
    uint8_t *left_arr = (uint8_t *)malloc(len / 2 * sizeof(uint8_t));
    if (left_arr == NULL) {
        fprintf(stderr, "Memory allocation failed for left_arr\n");
        exit(EXIT_FAILURE);
    }
    uint8_t *right_arr = (uint8_t *)malloc(len / 2 * sizeof(uint8_t));
    if (right_arr == NULL) {
        fprintf(stderr, "Memory allocation failed for right_arr\n");
        free(left_arr);
        exit(EXIT_FAILURE);
    }
    while (step < len) {
        size_t left = 0;
        while (left <= len - step) {
            size_t mid = left + step;
            size_t right = (left + 2 * step < len) ? left + 2 * step : len;
            size_t left_len = mid - left;
            size_t right_len = right - mid;

            for (size_t i = 0; i < left_len; i++) {
                left_arr[i] = arr[left + i];
            }
            for (size_t i = 0; i < right_len; i++) {
                right_arr[i] = arr[mid + i];
            }

            merge(arr + left, left_arr, left_len, right_arr, right_len);
            visualizer_append_array(v, arr);

            left += 2 * step;
            }
            step *= 2;
        }
    free(left_arr);
    free(right_arr);
    return arr;
}
