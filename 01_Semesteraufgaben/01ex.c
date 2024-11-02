/*
Zur Abgabe einen branch `iprg-b01` erstellen und pushen, in dem als einzige Datei die `01ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && ./01ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./01ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Machen Sie sich in dieser Aufgabe mit dem `Visualizer` (siehe array_visualizer.h) vertraut.
Nutzen Sie die `visualizer_append_array` Funktion, um die Tests zum durchlaufen zu bringen.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
Tipp 2: Jede weitere Zeile wird aus der Zeile davor durch eine einfache Modifikation gewonnen. Die Modifikation ist immer die gleiche.
*/
void warmup(Visualizer *v, uint8_t *arr, size_t len) {
    for (size_t i = 0; i < len; i++) {
        uint8_t *tempArr = malloc(len * sizeof(uint8_t));
        for (size_t j = 0; j < len; j++) {
            if(j < i) {
                tempArr[j] = arr[0];
            } else {
                tempArr[j] = arr[j-i];
            }
        }
        visualizer_append_array(v, tempArr);
    }
}

/*
Aufgabe 2:
Bringen Sie die Tests zum durchlaufen.

Tipp: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void sort_it(Visualizer *v, uint8_t *arr, size_t len) {
    //Sort the array starting by just juving the starting array. Then Sort the first 2 elements, then the first 3 and so on.
    for (size_t i = 0; i < len; i++) { // Loop through the array
        uint8_t *tempArr = malloc(len * sizeof(uint8_t));
        for (size_t j = 0; j < len; j++) {
            tempArr[j] = arr[j];
        }

        for (size_t j = 0; j < i; j++) { // Loop through the array to sort the first i elements
            for (size_t k = 0; k < i; k++) { // Sort using bubble sort
                if (tempArr[k] > tempArr[k + 1]) { // Swap the elements if they are in the wrong order
                    uint8_t temp = tempArr[k];
                    tempArr[k] = tempArr[k + 1];
                    tempArr[k + 1] = temp;
                }
            }
        }

        visualizer_append_array(v, tempArr); // Append the array to the visualizer
        free(tempArr);
    }
}
