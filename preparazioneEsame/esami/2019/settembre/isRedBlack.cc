#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

bool isRedBlack (tree *&t);
bool controlLeaves (tree *&t);
pair<int,bool> controlWalk (tree *&t);
bool controlRed (tree *&t);
struct tree {
    tree *left;
    tree *right;
    char *color;
    int value;
};

int main () {

    tree *t = new tree();
    tree *_1 = new tree();
    tree *_2 = new tree();
    tree *_3 = new tree();
    tree *_4 = new tree();
    tree *_5 = new tree();
    tree *_6 = new tree();
    tree *_7 = new tree();
    tree *_8 = new tree();
    tree *_9 = new tree();
    tree *nil = new tree();

    t -> left = _1;
    t -> right = _2;
    t -> color = "BLACK";
    t -> value = 17;

    _1 -> left = _3;
    _1 -> right = _4;
    _1 -> color = "RED";
    _1 -> value = 8;

    _2 -> left = _5;
    _2 -> right = _6;
    _2 -> color = "RED";
    _2 -> value = 23;

    _3 -> left = nil;
    _3 -> right = _7;
    _3 -> color = "BLACK";
    _3 -> value = 1;
    
    _4 -> left = nil;
    _4 -> right = nil;
    _4 -> color = "BLACK";
    _4 -> value = 11;

    _5 -> left = _8;
    _5 -> right = _9;
    _5 -> color = "BLACK";
    _5 -> value = 20;

    _6 -> left = nil;
    _6 -> right = nil;
    _6 -> color = "BLACK";
    _6 -> value = 27;

    _7 -> value = 7;
    _7 -> left = nil;
    _7 -> right = nil;
    _7 -> color = "RED";

    _8 -> value = 18;
    _8 -> left = nil;
    _8 -> right = nil;
    _8 -> color = "RED";

    _9 -> color = "RED";
    _9 -> left = nil;
    _9 -> right = nil;
    _9 -> value = 22;

    nil -> color = "BLACK";
    nil -> left = NULL;
    nil -> right = NULL;

    return 0;
}

bool isRedBlack (tree *t) {
    /*Cose che devo controllare:
    - la radice deve essere nera
    - tutte le foglie devono essere nere
    - entrambi i figli di un nodo rosso sono neri
    -tutti i cammini semplici da ogni nodo u ad una delle foglie contenute nel sottoalbero contenuto in u hanno lo stesso numero di nodi neri*/

    if (strcmp(t->color,"BLACK") == 0)
        return false;
    if (!controlLeaves(t))
        return false; //O(n)
    if (!controlWalk(t).second)
        return false; //O(n)
    if (!controlRed(t))
        return false;
    return true; /*il risultato totale ha complessità O(n)*/
}

bool controlLeaves (tree *&t) {
    if (t -> left == NULL && t -> right == NULL) {
        if (strcmp(t->color,"BLACK") == 0)
            return true;
        else
            return false;
    }
    else {
        return controlLeaves (t->left) && controlLeaves (t->right);
    }
}

pair<int,bool> controlWalk (tree *&t) {

    if (t == NULL)
        return make_pair(0,true);
    else {
        pair<int,bool> rr,ll;
        rr = controlWalk(t->left);
        ll = controlWalk (t->right);
        if ((rr.first != ll.first) || (!rr.second) || (!ll.second))
            return make_pair(-1,false);
        if (strcmp(t->color,"BLACK")) {
            ++rr.first;
            ++ll.first;
        }
        else
            return make_pair(rr.first,true); /*non cambia se mettiamo maxrr o maxll tanto hanno lo stesso valore*/
    }
}

bool controlRed (tree *&t) {

    if (t == NULL)
        return true;
    else {
        if (strcmp(t->color,"RED") == 0) {
            if ((strcmp(t -> left -> color,"BLACK") != 0) || (strcmp(t -> right -> color,"BLACK") != 0))
                return false;
            else
                return controlRed (t->left) && controlRed(t->right);
        }
    }
}