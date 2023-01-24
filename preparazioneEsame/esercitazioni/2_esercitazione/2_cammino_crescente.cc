#include <iostream>
#include <queue>
using namespace std;

struct tree
{
    tree *left;
    tree *right;
    int value;
};

int cam (tree *&t); 

int main()
{

    tree *t = new tree();
    t->value = 0;
    tree *l = new tree();
    l->value = 3;
    tree *r = new tree();
    r->value = 1;
    tree *ll = new tree();
    ll->value = 1;
    tree *rr = new tree();
    rr->value = 2;
    tree *rrr = new tree();
    rrr->value = 5;

    t->left = l;
    t->right = r;
    l->left = ll;
    l->right = rr;
    r->right = rrr;
    r->left = NULL;
    ll->left = NULL;
    ll->right = NULL;
    rr->left = NULL;
    rr->right = NULL;
    rrr->left = NULL;
    rrr->right = NULL;

    cout << "La lunghezza del piu' lungo cammino monotono crescente e' : " << cam(t) << endl; 
    return 0;
}

int cam (tree *&t) {

    int ll = 0, rr = 0;
    if (t != NULL) {

        if ((t -> left != NULL) && (t -> value < t -> left -> value))
            ll = 1 + cam(t -> left);
        else
            ll = 0;
        
        if ((t -> right != NULL) && (t -> value < t -> right -> value))
            rr = 1 + cam (t -> right);
        else
            rr = 0;
    }
    return max(ll,rr);


}

/* la complessità con questa implementazione rimane O(n), ma credo di poterla migliorare se faccio che controllo qual è il valore maggiore tra ll e rr e dopo vado ad iterare o t -> left
o t -> right rispettivamente a seconda di quale ha il valore maggiore e quindi il cammino crescente monotono è maggiore*/