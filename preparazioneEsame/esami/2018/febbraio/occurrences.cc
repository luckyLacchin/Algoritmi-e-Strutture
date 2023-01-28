#include <iostream>

using namespace std;

struct tree {
    
    tree *right;
    tree *left;
    int v;
};

int occurrences (tree *&root, int min, int max);
int occurrences_aux (tree *&t, int min, int max);

int main () {

    tree *t = new tree();
    tree *_1 = new tree();
    tree *_2 = new tree();
    tree *_3 = new tree();
    tree *_4 = new tree();
    tree *_5 = new tree();
    tree *_6 = new tree();

    t -> left = _1;
    t -> right = _2;
    t -> v = 15;

    _1 -> left = _3;
    _1 -> right = _4;
    _1 -> v = 10;

    _2 -> left = _5;
    _2 -> right = _6;
    _2 -> v = 20;

    _3 -> left = NULL;
    _3 -> right = NULL;
    _3 -> v = 3;
    
    _4 -> left = NULL;
    _4 -> right = NULL;
    _4 -> v = 12;

    _5 -> left = NULL;
    _5 -> right = NULL;
    _5 -> v = 18;

    _6 -> left = NULL;
    _6 -> right = NULL;
    _6 -> v = 23;

    int min = 11;
    int max = 18;

    cout << "Qual e' il numero di occorrenze: " << occurrences(t,min,max) << endl;


    return 0;
}

int occurrences (tree *&root, int min, int max) {
    
    if (root == NULL)
        return 0;
    if (root->v < min)
        return occurrences_aux (root->left,min,max);
    else if (root -> v > max)
        return occurrences_aux (root -> right, min, max);
    else
        return occurrences_aux (root,min,max);
}

int occurrences_aux (tree *&t, int min, int max) {
    if (t == NULL)
        return 0;
    else {
        if ((t->v >= min) && (t->v <= max)) {
            return 1 + occurrences_aux (t->left,min,max) + occurrences_aux(t->right,min,max);
        }
        else if (t -> v < min) {
            return 0 + occurrences_aux (t->right,min,max);
        }
        else if (t -> v > max) {
            return 0 + occurrences_aux (t->left,min,max);
        }
    }
}