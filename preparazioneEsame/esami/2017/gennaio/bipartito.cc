// ho un grafo non orientato, faccio l'algoritmo dei bipartiti!
//senza andare a prendere l'algoritmo già fatto, cerco di farne uno da capo

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool wrestler (vector<vector<int>> g);

int main () {

    vector<vector<int>> g;
    g.resize(6);
    g[0].push_back(5);
    //g[0].push_back(4);
    g[0].push_back(3);
    g[0].push_back(1);
    g[1].push_back(2);
    //g[1].push_back(5);
    g[1].push_back(0);
    //g[4].push_back(2);
    g[4].push_back(5);  
    //g[4].push_back(0); 
    //g[5].push_back(1);
    g[5].push_back(4);
    g[5].push_back(0);
    g[3].push_back(0);
    //g[2].push_back(4);
    g[2].push_back(1);

    cout << "Si possono suddividere i wrestler professionisti in buoni e cattivi? " << (wrestler(g)? "Si" : "No");

    return 0;
}

bool wrestler (vector<vector<int>> g) {
    vector <int> insiemi;
    insiemi.resize(g.size(),-1);
    queue <int> q;
    q.push(0);
    insiemi[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (insiemi[v] == -1) {
                insiemi[v] = (insiemi[u] == 0? 1 : 0);
                q.push(v);
            }
            else {
                if (insiemi[v] == insiemi[u])
                    return false;
            }
        }
    }
    return true;
}