/*
Willkommen zum fünften Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Rekursion.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall 05ex_test.c -o 05ex_test.o -lm && ./05ex_test.o
*/

#include "05_canvas.h"
#include <stdio.h>
#include <math.h>

/*
Aufgabe 1a:
Zeichnen Sie eine horizontale Linie der Länge `width`, deren am weitesten links liegender Pixel bei `(x, y)` ist.

_Benutzen Sie keine Schleifen - Die Aufgabe soll über Rekursion gelöst werden!_

*/

// Return 0 if not valid | 1 if valid
int is_valid_coord(Canvas c, int x, int y){
    if (x >= 0 && x < canvas_width(c)){
        if (y >= 0 && y < canvas_height(c)){ // Check if valid coord
            return 1;
        }
    }
    return 0;
}

Canvas recursive_line(Canvas c, int x, int y, int width) {
    if(is_valid_coord(c, x, y)){
        c = canvas_set_black(c, x, y);
    }
    if(width != 1){
        recursive_line(c, x+1, y, width-1);
    }
    return c;
}

/*
Aufgabe 1b:
Zeichnen Sie ein Rechteck mit der Breite `width` und der Höhe `height`. Der Pixel der linken unteren Ecke liegt bei `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
Canvas recursive_rectangle(Canvas c, int x, int y, int width, int height) {
    recursive_line(c, x, y, width);

    if (height != 1){
        recursive_rectangle(c, x, y+1, width, height-1);
    }
    return c;
}

/*
Aufgabe 2:
Die Fibonaccizahlen sind wie folgt definiert:

- die nullte Fibonaccizahl ist 1,
- die erste Fibonaccizahl ist ebenfalls 1, und
- jede weitere Fibonaccizahl ist die Summe der zwei vorigen Fibonaccizahlen.

Berechne die `n`-te Fibonaccizahl.
*/
int fibonacci(int n) {
    if(n == 0 | n == 1){
        return 1;
    } else {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}

/*
Aufgabe 3:
Implementieren Sie einen schwarzen Fülleimer. Gegeben eine Koordinate `(x, y)` auf einer (bereits bemalten) Canvas, soll die komplette
zusammenhängende Fläche aller Pixel der selben Farbe (schwarz oder weiß) schwarz gefärbt werden.
Zwei Pixel sind Teil der selben Fläche wenn sie die selbe Farbe haben und direkt benachbart sind. Jeder Pixel hat bis
zu vier direkte Nachbarn - die Diagonalen zählen nicht.

Funktionen, um die Farbe eines Pixels auf der Canvas zu bestimmen, sind im Headerfile der Canvas dokumentiert.
*/

Canvas fill_neighbour(Canvas c, int x, int y){
    if(is_valid_coord(c, x, y) && pixel_is_white(c, x, y)){
        bucket_fill(c, x, y);
    }
    return c;
}

Canvas bucket_fill(Canvas c, int x, int y) {
    if(!pixel_is_black(c, x, y)){
        c = canvas_set_black(c, x, y);
    }
    fill_neighbour(c, x + 1,y);
    fill_neighbour(c, x - 1,y);
    fill_neighbour(c, x,    y + 1);
    fill_neighbour(c, x,    y - 1);

    return c;
}