#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tree {
    
    tree *left;
    tree *right;
    int brilliance;
};

bool natale (tree *&t);

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
    t -> brilliance = 16;

    _1 -> left = _3;
    _1 -> right = _4;
    _1 -> brilliance = 3;

    _2 -> left = _5;
    _2 -> right = _6;
    _2 -> brilliance = 13;

    _3 -> left = NULL;
    _3 -> right = NULL;
    _3 -> brilliance = -6;
    
    _4 -> left = NULL;
    _4 -> right = NULL;
    _4 -> brilliance = +6;

    _5 -> left = _7;
    _5 -> right = _8;
    _5 -> brilliance = 23;

    _6 -> left = _9;
    _6 -> right = _10;
    _6 -> brilliance = -7;

    _7 -> brilliance = 3;
    _7 -> left = NULL;
    _7 -> right = NULL;

    _8 -> brilliance = 7;
    _8 -> left = NULL;
    _8 -> right = NULL;

    _9 -> brilliance = 3;
    _9 -> left = NULL;
    _9 -> right = NULL;

    _10 -> brilliance = 3;
    _10 -> left = NULL;
    _10 -> right = NULL;

    cout << "L'albero binario è un albero binario di Natale? " << (natale(t) ? "Si" : "No");


    return 0;
}

bool natale (tree *&t) {
    queue <tree*> q;
    q.push(t);
    bool merry = true;
    int count = 1, brillianceSoFar = 0;
    int brill = t -> brilliance;
    while ((!q.empty()) && (merry)) {
        tree *u = q.front();
        q.pop();
        if (t -> left != NULL)
            q.push(t -> left);
        if (t -> right != NULL )
            q.push(t->right);
        --count;
        brillianceSoFar += u -> brilliance;
        if (count == 0) {
            count = q.size();
            if (brillianceSoFar != brill)
                merry = false;
            else {
                brillianceSoFar = 0;
            }
        }

    }
    return merry;
}
