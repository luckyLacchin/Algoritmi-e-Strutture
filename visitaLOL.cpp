#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int cc (vector <vector <int>> adj,vector <int> temp, int partenza,int nodi);
void ccdfs (vector<vector<int>> adj, int *id,int u,int &res);
int main () {
    vector <vector <int>> adj;
    int temp;
    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int nodi, archi, partenza;
    in >> nodi;
    in >> archi;
    in >> partenza;
    int a,b;
    adj.resize(nodi);
    while (in >> a && in >> b){
        cout << "a = " << a << " b = " << b << endl; 
        adj[a].push_back(b);
    }
    int *id = new int [nodi];
    for (int i = 0; i < nodi; i++) {
        id[i] = 0;
    }
    int res = 0;
    ccdfs (adj,id,partenza,res);
    res += 1;
    out << res;
    delete [] id;
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

void ccdfs (vector<vector<int>> adj,int *id,int u,int &res) {
    int c = -1;
    id[u] = 1;
    cout << adj[u].size() << endl;
    for (int i = 0; i < adj[u].size(); i++) {
        c = adj[u][i];
        cout << "c1 = " << c << endl;
        if (id[c] == 0) {
            cout << "c = " << c << endl;
            res += 1;
            ccdfs (adj,id,c,res);
        }
    }
}