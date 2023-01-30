#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;

int elezioni (vector<vector<int>>  &g, vector<int> &status);
//PE = 1
//PP = 2
//I = 0
int main () {

    int n = 10;
    vector<vector<int>> g;
    g.resize(n);
    fstream in ("input.txt");
    int a,b;
    while ((in >> a) && (in >> b)) {
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> status;
    status.push_back(1);
    status.push_back(1);
    status.push_back(0);
    status.push_back(2);
    status.push_back(2);
    status.push_back(0);
    status.push_back(0);
    status.push_back(0);
    status.push_back(0);
    status.push_back(0);

    cout << "Il numero degli indecisi rimasti e': " << elezioni (g,status) << endl; 

    return 0;
}

int elezioni (vector<vector<int>> &g, vector<int> &status) {
    queue <int> pe;
    queue <int> pp;
    vector<int> dpe;
    vector<int> dpp;
    int count = 0;
    dpe.resize(g.size(),-1);
    dpp.resize(g.size(),-1);
    for (int u = 0; u < g.size(); u++) {
        if (status[u] == 1) {
            dpe[u] = 0;
            pe.push(u);
        }
        else if (status[u] == 2) {
            dpp[u] = 0;
            pp.push(u);
        }
    }
    while ((!pe.empty()) || (!pp.empty())) {
        if (!pe.empty()) {
            int u = pe.front();
            pe.pop();
            for (int v : g[u]) {
                if (dpe[v] == -1) {
                    dpe[v] = dpe[u] + 1;
                    if (dpp[v] != -1) {
                        if (dpe[v] < dpp[v]) {
                            status[v] = 1;
                        }
                        else if (dpe[v] > dpp[v]) {
                            status[v] = 2;
                        }
                        else if (dpe[v] == dpp[v]) {
                            ++count;
                        }
                    }
                    pe.push(v);
                }
            }
        }
        if (!pp.empty()) {
            int u = pp.front();
            pp.pop();
            for (int v : g[u]) {
                if (dpp[v] == -1) {
                    dpp[v] = dpp[u] + 1;
                    if (dpp[v] != -1) {
                        if (dpp[v] < dpe[v]) {
                            status[v] = 2;
                        }
                        else if (dpp[v] > dpe[v]) {
                            status[v] = 1;
                        }
                        else if (dpe[v] == dpp[v]) {
                            ++count;
                        }
                    }
                    pp.push(v);
                }
            }
        }
    }
    return count;
}