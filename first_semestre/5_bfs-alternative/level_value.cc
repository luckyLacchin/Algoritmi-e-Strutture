#include <iostream> 
using namespace std;

struct tree {
    int value; 
    tree *left; 
    tree *right;
}; 

int level_value (tree *, int level);

void makeTree (tree *&root); 

int main () {

    tree *root = new tree(); 
    root -> value = 0; 
    makeTree(root); 
    int n = level_value(root,0);
    cout << "n = " << n << endl; 
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
    sub3 -> value = 4; 
    
    tree *sub4 = new tree(); 
    sub4 -> value = 1;

    sub2 -> right = sub3;
    right -> right = sub4; 
}


int level_value (tree *root, int level) {
    if (root ==  NULL)
        return 0;
    if (level == root->value)
        return 1+level_value(root->left,level+1)+level_value(root->right,level+1);
    else 
        return 0+level_value(root->left,level+1)+level_value(root->right,level+1);
    
}
