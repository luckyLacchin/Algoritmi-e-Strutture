#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tree {
    tree *left;
    tree *right;
    int v;
};

int minColoring (tree *&t);
int minColoring_aux (tree *&t, int color);

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

    cout << "Il costo minore per la colorazione e': " << minColoring(t) << endl;
    return 0;
}

int minColoring (tree *&t) {

    vector <int> color; /*anche se non credo che mi serva questo vettore*/
    color.resize(2);
    color[0] = 1;
    color[1] = 2;
    return min(minColoring_aux (t,2),minColoring_aux(t,1));
}

int minColoring_aux (tree *&t, int color) {
    
    if (t != NULL) {
        return color + minColoring_aux (t->left,(color == 1? 2 : 1)) + minColoring_aux (t->right,(color == 1? 2 : 1)); 
    }
    else 
        return 0;
}
