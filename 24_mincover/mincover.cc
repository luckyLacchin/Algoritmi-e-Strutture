#include <iostream>
#include <fstream>

using namespace std;

struct node {
    int v;
    int f;
    int p;
};

int main () {

    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int p,f;
    vector <node> tree;

    while (in >> p && in  >> f) {
        node *t = new node();
        t -> v = p;
        t -> f = f;  
        tree.push_back()
    }

    return 0;
}