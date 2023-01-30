#include <iostream>
#include <vector>

using namespace std;

struct tree {
    tree *left;
    tree *right;
    int weight;
};

int maxPath (tree *&t);
int maxPath_aux (tree *&t,int &maxSoFar);

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
    t -> weight = 8;

    _1 -> left = _3;
    _1 -> right = _4;
    _1 -> weight = -3;

    _2 -> left = _5;
    _2 -> right = _6;
    _2 -> weight = -3;

    _3 -> left = NULL;
    _3 -> right = NULL;
    _3 -> weight = 2;
    
    _4 -> left = NULL;
    _4 -> right = NULL;
    _4 -> weight = +3;

    _5 -> left = NULL;
    _5 -> right = NULL;
    _5 -> weight = 1;

    _6 -> left = _9;
    _6 -> right = _10;
    _6 -> weight = 5;

    _9 -> weight = 4;
    _9 -> left = NULL;
    _9 -> right = NULL;

    _10 -> weight = 5;
    _10 -> left = NULL;
    _10 -> right = NULL;

    cout << "Il massimo cammino dell'albero e': " << maxPath(t) << endl;
}

int maxPath (tree *&t) {
    int maxSoFar = 0;
    maxPath_aux (t,maxSoFar);

    return maxSoFar;
}

int maxPath_aux (tree *&t, int &maxSoFar) {
    if (t == NULL)
        return 0;
    else if (t -> right == NULL && t -> left == NULL)
        return t -> weight; // mi trovo su una foglia
    else if(t != NULL) {
        int maxll = maxPath_aux(t -> left,maxSoFar);
        int maxrr = maxPath_aux (t -> right,maxSoFar);
        if (maxll + maxrr + t -> weight > maxSoFar) {
            maxSoFar = maxll + maxrr + t -> weight;
        }
        return max(maxll,maxrr) + t -> weight;
    }
    else
        return 0;
}