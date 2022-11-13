#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct node {
    int n; 
    bool visitato = false;
};

int cc (vector <vector <int>> adj,vector <int> temp, int partenza,int nodi);
void ccdfs (vector<vector<node*>> adj,node* u, int &res);
int main () {
    vector <vector <node *>> adj;
    int temp;
    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int nodi, archi, partenza;
    in >> nodi;
    in >> archi;
    in >> partenza;
    node *a = new node();
    node *b = new node();
    node *start = new node();
    start->n = partenza;
    adj.resize(nodi);
    while (in >> a->n && in >> b->n){
        cout << "a = " << a->n << " b = " << b->n << endl; 
        adj[a->n].push_back(b);
        a = new node();
        b = new node();
    }
    int res = 0;
    ccdfs (adj,start,res);
    res += 1;
    out << res;
    return 0;
}
/*
int cc (vector <vector <int>> adj,vector <int> temp, int partenza, int nodi) {
    int index = -1;
    int *id = new int [nodi];
    for (int i = 0; i < nodi; i++) {
        id[i] = 0;
    }
    int counter = 0;
    for (int u = 0; u < nodi; u++) {
        if(id[u] == 0) {
            temp.push_back(0);
            counter = counter + 1;
            ccdfs (adj,counter,u,id, temp, partenza, index);
        }
    }
    for (int i = 0; i < nodi; i++) {
        cout << "id[i] = " << id[i] << endl;
    }
    for (int i = 0; i < temp.size(); i++)
        cout << "temp = " << temp.at(i) << endl;
    cout << temp[index] << endl; 
    return temp[index];

}
*/

void ccdfs (vector<vector<node*>> adj,node* u, int &res) {
    
    if (u->visitato == false) {
        u->visitato = true;
        
        for (int i = 0; i < adj[u->n].size(); i++) {
            if (adj[u->n][i]->visitato == false) {
                cout << "u.n = " << adj[u->n][i]->n << endl;
                res +=  1; 
            }
            ccdfs (adj,adj[u->n][i],res);
        }
    }
    else {
    }
}
//il problema qui è che ho fatto un nodo diverso per anche nodi uguali! Dovrei fare prima 
//una lista di tutti i nodi e dopo prenderli uno ad uno per fare la lista di adiacenza