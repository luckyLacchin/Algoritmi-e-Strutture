#include <iostream>
#include <vector>

using namespace std;

bool four (vector<int> a,int n,int k);

int main () {

    int n = 6;
    vector<int> a;
    a.resize(n);
    a[0] = 7;
    a[1] = 1;
    a[2] = 13;
    a[3] = 12;
    a[4] = -3;
    a[5] = 7;
    int k = 35;
    cout << "Esiste un intervallo di valore k? " << (four (a,n,k) ? "Si" : "No") << endl;

}

bool four (vector<int> a,int n,int k) {

}
/* guarda soluzione http://disi.unitn.it/~montreso/asd/compiti/19-07-18.soluzione.pdf */