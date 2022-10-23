#include <iostream>

using namespace std;

struct tree{

    tree *parent;
    tree *left;
    tree *right;
    bool color; // facciamo che false è black e true è red
    int key;
    int value;
};

tree *rotateLeft (tree *x);
void balanceInsert (tree *n);
tree *rotateRight (tree *x);
tree *insertNode (tree *t, int k, int v);

int main () {

}

tree *rotateLeft (tree *x) {

    tree *y = x ->right;
    tree *p = x -> parent;
    x -> right = y -> left; // Il sottoalbero B diventa figlio destro di x
    if (y -> left != NULL) {
        y -> left -> parent = x;
    }
    y -> left = x;
    x -> parent = y;
    y -> parent = p;
    if (p != NULL) {
        if (p -> left == x) {
            p -> left = y;
        }
        else 
            p -> right = y;
    }
    return y;
}

tree *rotateRight (tree *x) {

    tree *y = x ->left;
    tree *p = x -> parent;
    x -> left = y -> right; // Il sottoalbero B diventa figlio destro di x
    if (y -> right != NULL) {
        y -> right -> parent = x;
    }
    y -> right = x;
    x -> parent = y;
    y -> parent = p;
    if (p != NULL) {
        if (p -> right == x) {
            p -> right = y;
        }
        else 
            p -> right = y;
    }
    return y;
}

tree *insertNode (tree *t, int k, int v) {

    tree *p = NULL;
    tree *u = t;
    while (u != NULL && u -> key != k) {
        p = u;
        if (k < u -> key) {
            u = u -> left;
        }
        else 
            u = u -> right;
    }
    if ((u != NULL) && (u -> key = k)) {
        u -> value = v;
    }
    else {
        tree * NEW = new tree; 
        NEW -> key = k;
        NEW -> value = v;
        balanceInsert (NEW); 
        if (p == NULL)
            t = NEW;
    }
}

void balanceInsert (tree *t) {
    t -> color = true; //vuol dire che è rosso il nodo.
    while (t !=NULL) {
        tree *p = t -> parent;
        tree *n;
        if (p != NULL) 
            n = p -> parent;
        else 
            n = NULL;
        tree *z;
        if (n == NULL) 
            z = NULL;
        else {
            if (n -> left == p){
                z = n -> right;
            }
            else
                z = n -> left;
        }
        if (p == NULL) {
            t -> color = false;
            t = NULL; // in questo caso t è radice del mio albero!
        }
        else if (p -> color == false) {
            t = NULL; // in questo caso il suo parent è nero, quindi non violiamo nessun vincolo
        }
        else if (z -> color == true) {
            p -> color = z -> color = false; //colore di nero sia p e z, visto che z, è zio del nodo t da inserire
            n -> color = true; // qua, visto che n è nonno di t, bisogna stare attenti che n non sia radice del nostro albero, nel caso lo fosse il ciclo va avanti per sistemare tutto;
            t = n; //preso l'albero d'esempio del pdf, nel ciclo successivo notando che n è radice dell'albero e ha parent = null, l'algoritmo lo trasforma come nero!
        }
        else {
            if ((t == p -> right) && (p == n -> left)){
                n -> left = rotateLeft(p);
                t = p; // si scambiano i ruoli tra p e t, in quanto adesso t diventa padre di p, quindi alla fine del rotate si mette t = p, in quanto i ruoli adesso sono invertiti.  Questo caso porta alla soluzione dopo, la 5a
            }
            else if ((t == p->left) && (p == n->right)) {
                n -> right = rotateRight(p);
                t = p; //questo passaggio porta alla soluzione 5b
            } 
            else { // soluzione 5a e 5b
                if ((t == p -> left) && (p == n->left)) {
                    n -> left = rotateRight(n);
                }
                else if ((t == p -> right) && (p == n->right)) {
                    n -> right = rotateLeft (n); // non capisco perché faccia n -> right e n -> left, quando in realtà n diventa uno dei figli di p?! Da chiedere
                }
                p -> color = false;
                n -> color = true;
                t = NULL; //così finisco il CICLO!
            }
        }
    }
}

/*chiedere riga 136 e cosa succede se l'elemento da inserire è nero? L'altezza nera come la sistemiamo?
La cancellazioen non la chiede, giusto?
La vera utilità dei gli alberi red & black è mantenere l'albero per lo più bilanciato, giusto?
*/