#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;

struct tree
{
    tree *left;
    tree *right;
    int value;
};

pair<int,pair<int,int>> sbilanciamento (tree *&t);
pair<int,int> unbalance (tree *&t);
int max_ (int a,int b) {
    if (a>=b)
        return a;
    else
        return b;
}

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
    tree *lll = new tree();
    lll->value = 6;

    t->left = l;
    t->right = r;
    l->left = ll;
    l->right = NULL;
    r->right = rrr;
    r->left = lll;
    ll->left = rr;
    ll->right = NULL;
    rr->left = NULL;
    rr->right = NULL;
    rrr->left = NULL;
    rrr->right = NULL;
    lll->left = NULL;
    lll->right = NULL;

    cout << "Il massimo grado di sbilanciamento all'interno dell'albero e': " << sbilanciamento(t).second.second << endl;

    
    return 0;
}

pair<int,pair<int,int>> sbilanciamento (tree *&t) {

    pair<int,pair<int,int>> ll, rr, res;
    int sbilanciato = 0, maxHere = 0, maxSoFar = 0;
    ll.first = 0;
    ll.second.second = 0;
    ll.second.first = 0;
    rr.first = 0;
    rr.second.first = 0;
    rr.second.second = 0;

    if (t != NULL) {
        if ((t -> left != NULL)) {
            ll = sbilanciamento(t -> left);
            ++ll.first;
        }
        if (t -> right != NULL) {
            rr = sbilanciamento (t -> right);
            ++rr.second.first;
        }
    }
    maxHere = max_(ll.second.second,rr.second.second);
    sbilanciato = abs((ll.first+ll.second.first)-(rr.second.first+rr.first));
    maxSoFar = max_ (maxHere,sbilanciato);
    res = make_pair (ll.first,make_pair(rr.second.first,maxSoFar));
    return res;
    
} 
/*credo che questo sia giusto e valuta lo sbilanciamento dei nodi*/

pair<int,int> unbalance (tree *&t) {
    if (t != NULL)
        return (make_pair(0,0));
    if ((t -> left == NULL) && (t->right == NULL)) {
        return (make_pair(1,0));
    }
    pair<int,int> ll, rr;
    int balance = 0;
    ll = unbalance (t->right);
    rr = unbalance (t->left);
    //return make_pair(ll.first + rr.first, max_(ll.second,rr.second,abs(ll.first-rr.first)));
     
}

/*questo valuta lo sbilanciamento delle foglie*/