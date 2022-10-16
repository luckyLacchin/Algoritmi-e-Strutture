#include <iostream> 
#include <cmath>
using namespace std;

struct tree {
    int value; 
    tree *left; 
    tree *right;
}; 

void makeTree (tree *&root); 
int displacement_level (tree *r, int Max);
int number_leaf (tree *t);
void inOrderPrint (tree *t);
int main () {

    tree *root = new tree();
    makeTree(root); 
    inOrderPrint(root);
    cout << endl;
    int max = 0; 
    int n = displacement_level (root,max);
    cout << "Il massimo grado di sbilanciamento e': " << n << endl;
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

    tree *sub5 = new tree(); 
    sub5 -> value = 5;

    sub2 -> right = sub3;
    //sub2 -> left = sub5;

    right -> right = sub4; 
}



int displacement_level (tree *r, int Max) {

    if (r!=NULL) {
        /*cout << "r -> value = " << r -> value << endl;
        cout << "foglie sinistre = " << number_leaf(r->left) << endl;
        cout << "foglie destre = " << number_leaf(r->right) << endl;
        */
        int displace1 = fabs (number_leaf(r->left)-number_leaf(r->right));
        //cout << "displace = " << displace1 << endl; 
        Max = max(displace1,Max);
        //cout << "Max = " << Max << endl << endl;
        return max(displacement_level(r->left,Max),displacement_level(r->right,Max)); 
    }
    else {
        return Max;
    }


}

int number_leaf (tree *t) {
    
    if (t == NULL)
        return 0;
    if (t -> left == NULL && t->right == NULL)
        return 1;
    else {
        return number_leaf(t->left) + number_leaf(t->right);
    }
}

void inOrderPrint (tree *t) {
    if (t != NULL) {
        inOrderPrint(t->left);
        cout << t -> value << " ";
        inOrderPrint(t->right);
    }
}