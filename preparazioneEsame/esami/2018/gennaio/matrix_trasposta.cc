#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void traspose (vector<vector<bool>> &m, int n);

int main () {

    vector<vector<bool>> g;
    fstream in ("input.txt");
    int nodi, archi, x, y;
    in >> nodi >> archi;
    g.resize(nodi);
    for (int i = 0; i < nodi; i++)
        g[i].resize(nodi,false);
    while (in >> x && in >> y) {
        g[x][y] = true;
    }


    return 0;
}

void traspose (vector<vector<bool>> &m, int n) {

    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == 1) {
                v.push_back(make_pair(i,j));
                m[i][j] = 0;
            }
        }
    }

    for (pair<int,int> p : v) {
        m[p.second][p.first] = 1;
    }
}
/*La complessità di questo algoritmo è O(n^2)*/