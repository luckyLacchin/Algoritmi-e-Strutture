#include <iostream>
#include <fstream>
using namespace std;

struct tree {
    tree *left;
    tree *right;
    tree *parent;
    int key;
    int value;
};

int occurrences (tree *t, int min, int max);
void insert (tree *&t, int k, int val);
void deleteTree (tree *t);

int main () {

    tree *t = new tree ();
    int min, max;
    insert(t,15,0);
    insert(t,10,0);
    insert(t,20,0);
    insert(t,3,0);
    insert(t,12,0);
    insert(t,3,0);
    insert(t,18,0);
    insert(t,23,0);

    int res = occurrences (t,11,18);
    cout << "res = " << res << endl;
    deleteTree (t);
    return 0;
}

int occurrences (tree *t, int min, int max)  {
    
    if (t == NULL) {
        return 0;
    }
    else if (t->key >= min && t->key <= max) {
        return 1 + occurrences(t->left,min,max) + occurrences (t->right,min,max);
    }
    else if (t->key < min) {
        return 0 + occurrences (t->right,min,max);
    }
    else if (t->key > max) {
        return 0 + occurrences (t->left,min,max);
    }
    return 0;
}

void insert (tree *&t, int k, int val) {
    if (t == NULL) {
        t = new tree ();
        t -> left = NULL;
        t -> right = NULL;
        t -> parent = NULL;
        t -> key = k;
        t -> value = val;
    }
    else if (t != NULL && t->key == k) {
        t -> value = val;
    }
    else if (t -> key > k) {
        insert (t->left, k, val);
    }
    else if (t->key < k) {
        insert(t->right,k,val);
    }
    return;
}

void deleteTree (tree *t) {
    if (t!=NULL) {
        deleteTree (t->left);
        deleteTree (t->right);
        delete t;
    }
    return;
}