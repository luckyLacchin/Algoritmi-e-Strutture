#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct tree {
    tree *left;
    tree *right;
    char v;
};

int nicetree (char s[], int n);
tree *buildTree (char s[], int &index, int n);
void printTree (tree *t);
int height (tree *t);


int main () {

    char stringa[] = "ILIILLL";
    int n = 7;
    cout << "L'altezza dell'albero e': " << nicetree(stringa,n) << endl;

    return 0; 
}
/*mi conviene direttamente costruire l'albero e dopo calcolare la sua altezza*/
int nicetree (char s[], int n) {
    
    int index = 0;
    tree *t = buildTree (s,index,n);
    //printTree (t);
    return height(t)-1;
}

tree *buildTree (char s[], int &index, int n) {

    tree *t;
    if (index < n) {
        t = new tree();
        t -> v = s[index];
        if (s[index] == 'I') {
            ++index;
            t -> left = buildTree (s,index,n);
            ++index;
            t -> right = buildTree (s,index,n);
        }
        
    }
    else
        t = NULL;
    return t;
}

void printTree (tree *t) {

    if (t != NULL) {
        cout << t -> v << " ";
        printTree (t->left);
        //cout << t -> v << " ";
        printTree (t->right);
    }
}

int height (tree *t) {

    int maxHere;
    if (t != NULL) {
        int maxrr = height(t->right);
        int maxll = height(t->left);
        maxHere = max(maxrr,maxll);
        return 1 + maxHere;

    }
    else 
        return 0;
}

/* La complessità di tutte le funzioni fatte e' O(n). Questo sarebbe più 2n, invece la soluzione fatta dal prof è proprio O(n)*/