/*
Zur Abgabe einen branch `iprg-b08` erstellen und pushen, in dem als einzige Datei die `08ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 08ex_test.c -o 08ex_test.o -lm && ./08ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 08ex_test.c -o 08ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./08ex_test.o
*/

#include "sphinx.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:

Da spaziert man entspannt durch Theben, und plötzlich kommt eine Sphinx angeflogen
und spricht: "Ich habe mir ein Array überlegt, das aus beliebig vielen Nullen gefolgt von
beliebig vielen Einsen besteht. Du darfst mich nach dem Wert an 1 + log2(n) (aufgerundet)
vielen Positionen fragen. Und wenn du mir danach nicht sagen kannst, wo die erste Eins
steht, dann fresse ich dich. Falls es keine Eins gibt, dann hätte ich gerne die Länge
des Arrays als Antwort".

Geben Sie den Index der ersten Eins zurück, oder die Arraylänge, falls es keine Eins gibt.
Um den Wert an Position `i` zu erfragen, rufen Sie `sphinx_ask(s, i)` auf. Aber Achtung:
Wenn Sie diese Funktion mehr als 1 + log2(n) (aufgerundet) mal aufrufen, stürzt das Programm
fehlerhaft ab.
*/
size_t zero_one_sphinx(Sphinx *s, size_t n) {
    size_t left = 0;
    size_t right = n;
    size_t mid = 0;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (sphinx_ask(s, mid) == 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
