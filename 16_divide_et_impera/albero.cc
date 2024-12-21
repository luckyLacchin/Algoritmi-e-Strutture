#include <iostream>
#include <vector>

using namespace std;

struct tree{

    tree *left;
    tree *right;
    int value;
};

void faiTree (vector <int> a);
void faiTree_aux (vector <int> a, tree *t);

int main () {

    vector <int> a;
    faiTree (a);
    return 0;
}

void inserisci (tree &t) {

}

void faiTree (vector <int> a) {
    tree *t = new tree ();
    faiTree_aux (a,t);
}

void faiTree_aux (vector <int> a, tree *t) {
    //guarda roveri, fai anche tutti gli altri esercizi.
}