#include <iostream>
#include <vector>
#include <queue> 

using namespace std;


vector <int> color (vector<vector<int>> g);

int main () {

    vector <vector<int>> g;
    g.resize(6);
    g[0].push_back(5);
    g[0].push_back(3);
    g[1].push_back(2);
    g[4].push_back(2);
    g[4].push_back(5);  

    g[5].push_back(1);
    g[3].push_back(0);
    g[2].push_back(4);

    vector <int> c;
    c = color (g);

    for (int i : c)
        cout << i << " ";
    cout << endl;

    return 0;
}

vector <int> color (vector<vector<int>> g) {

    vector <int> c;
    c.resize (g.size(), -1);
    queue <int> q;
    q.push(0);
    c[0] = 1;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i : g[t]) {
            if (c[i] == -1) {
                c[i] = ((c[t] == 1) ? 0 : 1);
                q.push(i);  
            }
        }
    }
    return c;
}