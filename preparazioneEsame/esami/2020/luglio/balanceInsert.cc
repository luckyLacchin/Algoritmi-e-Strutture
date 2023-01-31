#include <vector>
#include <iostream>
/*il secondo esercizio lo ho fatto a mano, poi cosa intessante per luglio 2020 ci sono stati fatti due appelli (uno il 24 luglio): 
link delle varie soluzioni: http://disi.unitn.it/~montreso/asd/compiti/20-06-12.soluzione.pdf , http://disi.unitn.it/~montreso/asd/compiti/20-07-24.soluzione.pdf */
using namespace std;

struct tree {
    tree *left;
    tree *right;
    int size;
    int value;
};

void binaryInsert (tree *&t, vector<int> &a, int n);
void binaryInsert_rec (tree *&t, vector<int> &a, int n,int i);
void printTree (tree *t);

int main () {

    vector<int> a = {11,13,15,19,21,22,25,27,28,31};
    vector<vector<int>> g;
    int n = 10;
    g.resize(n);

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

    t -> left = _1;
    t -> right = _2;
    t -> size = n;
    t -> value = 0;

    _1 -> left = _3;
    _1 -> right = _4;
    _1 -> size = 6;
    _1 -> value = 0;

    _2 -> left = _5;
    _2 -> right = _6;
    _2 -> size = 3;
    _2 -> value = 0;

    _3 -> left = _7;
    _3 -> right = _8;
    _3 -> size = 3;
    _3 -> value = 0;
    
    _4 -> left = _9;
    _4 -> right = NULL;
    _4 -> size = 2;
    _4 -> value = 0;

    _5 -> left = NULL;
    _5 -> right = NULL;
    _5 -> size = 1;
    _5 -> value = 0;

    _6 -> left = NULL;
    _6 -> right = NULL;
    _6 -> size = 1;
    _6 -> value = 0;

    _7 -> value = 0;
    _7 -> left = NULL;
    _7 -> right = NULL;
    _7 -> size = 1;

    _8 -> value = 0;
    _8 -> left = NULL;
    _8 -> right = NULL;
    _8 -> size = 1;

    _9 -> size = 1;
    _9 -> left = NULL;
    _9 -> right = NULL;
    _9 -> value = 0;

    binaryInsert(t,a,n);
    printTree(t);

    return 0;
}

void binaryInsert (tree *&t, vector<int> &a, int n) {

    binaryInsert_rec(t,a,n,0);
}
void binaryInsert_rec (tree *&t, vector<int> &a, int n,int i) {

    int leftSize = 0;
    if (t -> left != NULL) {
        leftSize = t -> left -> size;
        binaryInsert_rec(t->left,a,n,i);
    }
    t -> value = a[i+leftSize];
    if (t -> right != NULL) {
        binaryInsert_rec(t -> right,a,n,leftSize+i+1);
    }
}

void printTree (tree *t) {
    if (t != NULL) {
        printTree (t -> left);
        cout << t -> value << " ";
        printTree (t -> right);
    }
}