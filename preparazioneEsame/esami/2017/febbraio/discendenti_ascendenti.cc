#include <iostream>
#include <queue>

using namespace std;

struct tree {
    tree *left = NULL;
    tree  *right = NULL;
    int value;
};

int anchestor_wrapper (tree *&t, int ascendenti, int &count);
int anchestors (tree *&t);

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
    tree *_10 = new tree();

    t -> left = _1;
    t -> right = _2;
    _1 -> left = _3;
    _1 -> right = _4;
    _2 -> left = _5;
    _2 -> right = _6;
    _3 -> left = _7;
    _3 -> right = _8;
    _6 -> left = _9;
    _6 -> right = _10;

    cout << "Quanti nodi hanno lo stesso numero di discendenti/ascendenti? " << anchestors(t) << endl;
    return 0;
}

int anchestors (tree *&t) {

    int count = 0;
    anchestor_wrapper (t,0, count); 

    return count;
}

int anchestor_wrapper (tree *&t, int ascendenti, int &count) {
    if (t != NULL) {
        int ll = anchestor_wrapper(t->left,ascendenti+1,count);
        int rr = anchestor_wrapper(t->right,ascendenti+1,count);
        if (ascendenti == ll + rr)
            ++count;
        return 1 + ll + rr;
    }
    else {
        return 0;
    }
}
/*E' una semplice dfs di tutti i nodi del mio albero in cui vado ad aggiungere i parametri ascendenti e count in modo tale di tener conto dell'ascendente di ciascun nodo e di quanti nodi con equivalente numero di ascedenti e discendenti ho. Il valore che viene ritornato dalla funzione è il numero di discendenti, che vado a calcolare sia del sottoalbero sx che dx, andando ad aggiungere il nodo stesso. Visto che è una dfs con l'aggiunta di operazioni di costo costante, la complessità di questo algoritmo rimane teta(n), in quanto visito ciascun nodo solo una volta*/