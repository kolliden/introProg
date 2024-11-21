/*
Zur Abgabe einen branch `iprg-b02` erstellen und pushen, in dem als einzige Datei die `02ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 02ex_test.c -o 02ex_test.o -lm && ./02ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 02ex_test.c -o 02ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./02ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Visualisieren Sie (wie auf dem Semesteraufgabenblatt 1) den folgenden Sortieralgorithmus:

- Wiederhole `len + 1` mal:
    - In der ersten, dritten, fünften, etc. Wiederholung, tausche die Zahlen an allen *geraden* Positionen im Array mit ihrem rechten Nachbarn, falls der rechte Nachbar kleiner ist.
    - In den anderen Wiederholungen, tausche die Zahlen an allen *ungeraden* Positionen im Array mit ihrem rechten Nachbarn, falls der rechte Nachbar kleiner ist.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
Tipp 2: Jede weitere Zeile entspricht dem Array am Ende einer Wiederholung.
*/
void swap_sort(Visualizer *v, uint8_t *arr, size_t len) {
    visualizer_append_array(v, arr);
    for (size_t i = 0; i < len + 1; i++) {
        for (size_t j = i % 2; j < len - 1; j += 2) {
            if (arr[j] > arr[j + 1]) {
                uint8_t temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        visualizer_append_array(v, arr);
    }
}
