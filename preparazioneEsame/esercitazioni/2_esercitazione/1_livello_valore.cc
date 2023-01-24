#include <iostream>
#include <queue>
using namespace std;

struct tree
{
    tree *left;
    tree *right;
    int value;
};

int bfs(tree *&t);

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

    cout << "Il numero di nodi dell'albero il cui valore e' uguale al livello del nodo e': " << bfs(t) << endl;
    return 0;
}

int bfs(tree *&t)
{

    int res = 0;
    queue<pair<tree *, int>> q;
    pair<tree *, int> temp;
    pair<tree *, int> temp_1;
    temp.first = t;
    temp.second = 0;
    q.push(temp);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp.first->value == temp.second) {
            ++res;
        }
        if (temp.first->left != NULL)
        {
            temp_1.first = temp.first->left;
            temp_1.second = temp.second + 1;
            q.push(temp_1);
        }
        if (temp.first->right != NULL)
        {
            temp_1.first = temp.first->right;
            temp_1.second = temp.second + 1;
            q.push(temp_1);
        }
    }
    return res;
}