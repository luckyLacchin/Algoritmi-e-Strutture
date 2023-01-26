#include <vector>

using namespace std;



vector <vector <int>> transpose (vector<vector<int>> &g,int nodi) {

    vector<vector<int>> trasposta;
    trasposta.resize(nodi);
    for (int i = 0; i < nodi; i++) {
        for (int j : g[i]){
            trasposta[j].push_back(i);
        }
    }
    /*
    for (int i = 0; i < nodi; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            trasposta[g[i][j]].push_back(i);
        }
    }
    */
    return  trasposta;
}
