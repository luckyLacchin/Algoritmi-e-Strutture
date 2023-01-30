#include <iostream>
#include <vector>
#include <fstream>
#include <queue> 

using namespace std;

int minSessions(vector<vector<int>> g);

int main () {
    vector<vector<int>> g;
    ifstream in ("input.txt");
    int n = 4; 
    int a,b;
    g.resize(n);
    while((in >> a) && (in >> b)){
        g[a].push_back(b);
    }
    cout << "Il minimo di sessioni necessarie per finire il percorso di laurea e' di: " << minSessions(g) << endl;

    return 0;
}

int minSessions(vector<vector<int>> g) {
    
    queue <int> q;
    vector<int> entries;
    int sessions = 0;
    int count = 0;
    entries.resize(g.size(),0);
    for (int i = 0; i < g.size();i++) {
        for (int v : g[i]) {
            ++entries[v];
        } 
    }

    for (int v = 0; v < entries.size();v++) {
        if (entries[v] == 0) {
            q.push(v);
            ++count;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            --entries[v];
            if (entries[v] == 0) {
                q.push(v);
            }
        }
        --count;
        if (count == 0) {
            ++sessions;
            count = q.size();
        }
    }
    return sessions;
}
/*Secondo me anche il mio algoritmo va bene, guarda http://disi.unitn.it/~montreso/asd/compiti/19-08-22.soluzione.pdf*/