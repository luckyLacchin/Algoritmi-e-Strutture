#include <vector>
#include <iostream>
#include <queue>

using namespace std;

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

/*vedere sul libro pg 181*/