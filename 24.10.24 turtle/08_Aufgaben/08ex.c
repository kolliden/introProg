/*
Willkommen zum achten Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Pointer und Arrays.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall 08ex_test.c -o 08ex_test.o -lm && ./08ex_test.o
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "turtlecanvas.h"

/*
Aufgabe 1a:
Lesen Sie das Headerfile `turtlecanvas.h`. Diese Funktion soll die Turtle `d` Schritte vorwärts machen lassen.
*/
void turtle_advance_by(TurtleCanvas *c, uint32_t d) {
    for (size_t i = 0; i < d; i++){
        turtle_advance(c);
    }
    return;
}

/*
Aufgabe 1b:
Füllen Sie die Turtlecanvas mit horizontalen, abwechselnd schwarzen und weißen Linien (die unterste Zeile soll
schwarz gefärbt werden). Die Turtle ist anfangs an Position (0, 0), ist nach rechts orientiert, und zeichnet schwarz.
*/
void turtle_stripes(TurtleCanvas *c) {
    for (size_t i = 0; i < turtle_canvas_height(c); i+=2){
        turtle_advance_by(c, turtle_canvas_width(c));
        turtle_rotate_left(c);
        turtle_advance_by(c, 1);
        turtle_toggle_color(c);
        turtle_rotate_left(c);
        turtle_advance_by(c, turtle_canvas_width(c));
        turtle_rotate_right(c);
        turtle_advance_by(c, 1);
        turtle_toggle_color(c);
        turtle_rotate_right(c);
    }
    return;
}

/*
Aufgabe 1c:
Lesen Sie die Implementierungen der Turtlecanvas-Funktionen weiter unten in der "turtlecanvas.h".
Der Quellcode sollte vollständig verständlich und unüberraschend sein.
Hinweis: Diese Aufgabe wird nicht bewertet.
*/

/*
Aufgabe 2a:
Geben Sie einen Pointer auf das erste Vorkommen der größten Zahl im Eingabearray zurück.
*/
uint16_t* find_maximal_number(uint16_t numbers[], size_t numbers_len) {
    uint16_t max = 0;
    for (size_t i = 0; i < numbers_len; i++){
        if (numbers[i] > max){
            max = numbers[i];
        }
    }
    for (size_t i = 0; i < numbers_len; i++){
        if (numbers[i] == max){
            return &numbers[i];
        }
    }
    return numbers;
}

/*
Aufgabe 2b:
Geben Sie (einen Pointer auf) das Teilarray zurück, welches ab dem ersten Vorkommen der größten Zahl im Eingabearray beginnt.
*/
uint16_t* find_subarray_starting_at_maximal_number(uint16_t numbers[], size_t numbers_len) {
    uint16_t max = 0;
    for (size_t i = 0; i < numbers_len; i++){
        if (numbers[i] > max){
            max = numbers[i];
        }
    }
    for (size_t i = 0; i < numbers_len; i++){
        if (numbers[i] == max){
            return &numbers[i];
        }
    }
    return numbers;
}

/*
Aufgabe 2c:
Geben Sie die größtmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die größte Distanz die zwischen 1 und 7, und beträgt damit `6`.
*/
uint16_t find_maximum_distance(uint16_t numbers[], size_t numbers_len) {
    //Find the maximum and minimum value in the array
    uint16_t max = 0;
    uint16_t min = numbers[0];
    for (size_t i = 0; i < numbers_len; i++){
        if (numbers[i] > max){
            max = numbers[i];
        }
        if (numbers[i] < min){
            min = numbers[i];
        }
    }
    return max - min;
    return 0;
}
void sort(uint16_t numbers[], size_t numbers_len){
    for (size_t i = 0; i < numbers_len; i++){
        for (size_t j = i+1; j < numbers_len; j++){
            if (numbers[i] > numbers[j]){
                uint16_t temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}
/*
Aufgabe 2d:
Geben Sie die kleinstmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die kleinste Distanz die zwischen 3 und 4, und beträgt damit `1`.
*/
uint16_t find_minimum_distance(uint16_t numbers[], size_t numbers_len) {
    sort(numbers, numbers_len);
    uint16_t min_distance = numbers[1] - numbers[0];
    for(size_t i = 0; i < numbers_len-1; i++){
        if (numbers[i+1] - numbers[i] < min_distance){
            min_distance = numbers[i+1] - numbers[i];
        }
    }
    return min_distance;
}

/*
Aufgabe 2e:
Schreiben Sie die ersten `numbers_len` Quadratzahlen aufsteigend in das gegebene Array `numbers`.
Hinweis: Wir starten bei `1`. Sollte numbers_len also `5` sein, sind die ersten 5 Quadratzahlen bis
einschließlich die von 5 gemeint: 1, 4, 9, 16, 25.
*/
void square_ascending(uint16_t numbers[], size_t numbers_len) {
    for (size_t i = 0; i < numbers_len; i++){
        numbers[i] = (i+1)*(i+1);
    }
    return;
}

/*
Aufgabe 2f:
Füllen Sie das Array `out` mit den aufsteigend sortierten Zahlen aus dem `in` Array. Beide Arrays haben die Länge `len`.
Beispiel: Ist `in` {1, 4, 3, 7, 4}, so soll `out` am Ende {1, 3, 4, 4, 7} sein.
*/
void sort_ascending(uint16_t in[], uint16_t out[], size_t len) {
    sort(in, len);
    for (size_t i = 0; i < len; i++){
        out[i] = in[i];
    } // -_-
    return;
}
