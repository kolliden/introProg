/*
Zur Abgabe einen branch `iprg-b01` erstellen und pushen, in dem als einzige Datei die `01ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && ./01ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./01ex_test.o
MacOS:
clang -std=c11 -g -Wall -Werror 01ex_test.c -o 01ex_test.o -lm && leaks -atExit -- ./01ex_test.o
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
void warmup(Visualizer *v, uint8_t *arr, size_t len)
{
    uint8_t *tempArr = malloc(len * sizeof(uint8_t));
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            if (j < i)
            {
                tempArr[j] = arr[0];
            }
            else
            {
                tempArr[j] = arr[j - i];
            }
        }
        visualizer_append_array(v, tempArr);
    }
    free(tempArr);
}

/*
Aufgabe 2:
Bringen Sie die Tests zum durchlaufen.

Tipp: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void sort_it(Visualizer *v, uint8_t *arr, size_t len)
{
    visualizer_append_array(v, arr); // Append the array to the visualizer
    for (size_t i = 1; i < len; i++)
    { // Loop through the array
        //Using insertion sort
        uint8_t key = arr[i]; // Get the key
        int j = i - 1;     // Get the index of the previous element
        while (j >= 0 && arr[j] > key)
        { // Loop through the array until the key is greater than the previous element
            arr[j + 1] = arr[j]; // Move the previous element to the next index
            j--;                 // Decrement the index
        }
        arr[j + 1] = key; // Insert the key in the correct position
        visualizer_append_array(v, arr); // Append the array to the visualizer
    }
}
