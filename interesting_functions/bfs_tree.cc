#include <iostream>
#include <queue>

using namespace std;

struct tree {
    tree *right;
    tree *left; 
    int value; 
};

void bfs (tree *&t) {

    queue <tree*> q;
    q.push(t);
    while (!q.empty()){
        tree *u = q.front();
        if (u -> left != NULL) {
            q.push(u->left);
        }
        if (u -> right != NULL) {
            q.push(u->right);
        }
    }
}
