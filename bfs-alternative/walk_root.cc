#include <iostream> 
using namespace std;

struct tree {
    int value; 
    tree *left; 
    tree *right;
}; 

void makeTree (tree *&root); 
int walk (tree *root); 
int max (int a,int b);


int main () {

    tree *root = new tree();
    makeTree(root); 
    int n = walk (root);
    cout << "Il cammino massimo radice-discendente crescente è: " << n << endl;
    return 0;
}

void makeTree (tree *&root) {
    
    tree *left = new tree(); 
    left -> value = 2; 
    
    tree *right = new tree(); 
    right -> value = 1; 
    
    root -> left = left; 
    root -> right = right; 
    
    tree *sub1 = new tree(); 
    sub1 -> value = 2; 
    
    tree *sub2 = new tree(); 
    sub2 -> value = 3; 
    
    left -> left = sub1; 
    left -> right = sub2;

    tree *sub3 = new tree(); 
    sub3 -> value = 3; 
    
    tree *sub4 = new tree(); 
    sub4 -> value = 1;

    sub2 -> right = sub3;
    right -> right = sub4; 
}

int walk (tree *root) {

    if (root == NULL)
        return 0; 
    else {
        int max1 = 0;
        int max2 = 0;
        //devo controllare che non abbia un valore maggiore...
        if (root->left != NULL && root->left->value > root -> value)
            max1 = 1+walk(root->left);
        if (root->right != NULL && root->right->value > root -> value)
            max2 = 1+walk(root->right);
        return max(max1,max2);
    }
}

int max (int a,int b) {
    if(a>=b)
        return a;
    else 
        return b;
}