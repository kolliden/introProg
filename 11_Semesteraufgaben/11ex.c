/*
Zur Abgabe einen branch `iprg-b11` erstellen und pushen, in dem als einzige Datei die `11ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall -Werror 11ex_test.c -o 11ex_test.o -lm && ./11ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
clang -std=c11 -g -Wall -Werror 11ex_test.c -o 11ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./11ex_test.o
*/

#include "height_tree.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

size_t height_or_zero(HeightTreeNode *t) {
    if (t == NULL) {
        return 0;
    } else {
        return t->height;
    }
}

/*
Aufgabe 1a:

Führen Sie eine Linksrotation auf dem gegebenen Baum durch, und geben Sie einen Pointer auf
die Wurzel des neuen Baumes zurück.
Der Baum ist nichtleer, und die Wurzel hat einen nichtleeren rechten Teilbaum.

Denken Sie daran, auch die Höhen und die Elternpointer anzupassen.

Die Baumausgabe im Terminal enthält in jedem Knoten erst das Item, dann die Höhe, und zuletzt
das Item des Elternkotens (oder NULL für die Wurzel).

Die Baumausgabe nimmt den zurückgegebenen Knoten als Wurzel. Sollte die Baumausgabe komplett
überraschend aussehen, könnte das gut an einer falsch zurückgegebenen Wurzel liegen.
*/
HeightTreeNode *rotate_left(HeightTreeNode *t) {
    HeightTreeNode *new_root = t->right;
    t->right = new_root->left;
    if (new_root->left != NULL) {
        new_root->left->parent = t;
    }
    new_root->left = t;
    new_root->parent = t->parent;
    t->parent = new_root;

    t->height = 1 + (height_or_zero(t->left) > height_or_zero(t->right) ? height_or_zero(t->left) : height_or_zero(t->right));
    new_root->height = 1 + (height_or_zero(new_root->left) > height_or_zero(new_root->right) ? height_or_zero(new_root->left) : height_or_zero(new_root->right));

    return new_root;
}

/*
Die vier möglichen Sequenzen von Rotationen, um einen Beinahe-AVL-Baum in einen AVL-Baum zu überführen.
*/
typedef enum Rotations_ {
    Left, /* eine Linksrotation */
    Right, /* eine Rechtsrotation */
    DoubleRotationLeftRight, /* Doppelrotation: erst Linksrotation, dann Rechtsrotation */
    DoubleRotationRightLeft, /* Doppelrotation: erst Rechtsrotation, dann Linksrotation */
} Rotations;

/*
Aufgabe 2:

Gegeben ein Beinahe-AVL-Baum mit korrekten Höhenwerten, geben Sie zurück, welche Rotationen ihn zu einem AVL-Baum machen.
*/
Rotations determine_rotations(HeightTreeNode *t) {
    if (t == NULL) {
        return Left;
    }

    int left_height = height_or_zero(t->left);
    int right_height = height_or_zero(t->right);

    if (left_height > right_height + 1) {
        int left_left_height = height_or_zero(t->left->left);
        int left_right_height = height_or_zero(t->left->right);
        if (left_left_height >= left_right_height) {
            return Right;
        } else {
            return DoubleRotationLeftRight;
        }
    } else if (right_height > left_height + 1) {
        int right_left_height = height_or_zero(t->right->left);
        int right_right_height = height_or_zero(t->right->right);
        if (right_right_height >= right_left_height) {
            return Left;
        } else {
            return DoubleRotationRightLeft;
        }
    }
    return Left;
}