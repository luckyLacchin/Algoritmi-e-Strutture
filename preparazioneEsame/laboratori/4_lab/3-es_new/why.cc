#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

pair<int,int> cam_max (vector<vector<int>> &g, vector <bool> &visited, int start);
int cam_max_aux (vector<vector<int>> &g);

int main () {

    vector<vector<int>> g;
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t,s, nodi, archi;
    in >> nodi >> archi;
    g.resize(nodi);
    while ((in >> t) && (in  >> s)) {
        g[t].push_back(s);
    }
    out << cam_max_aux (g);

    return 0;
}

int cam_max_aux (vector<vector<int>> &g) {

    int counter = 0, mlength = -1, maxHere = -1, index = 0;
    bool isntVisited = true;
    pair<int,int> cammino, secondcam; 
    vector <bool> visited;
    visited.resize(g.size(),false);
    while (isntVisited) {
        isntVisited = false;
        cammino = cam_max(g,visited,index);
        secondcam = cam_max(g,visited,cammino.second);
        maxHere = max(cammino.first,secondcam.first);
        mlength = max(maxHere, mlength);
        cout << "maxHere = " << mlength << endl;
        cout << "length = " << mlength << endl;
        for (int i = 0; (i < visited.size()) && (isntVisited == false); i++) {
            if (visited[i] == false) {
                index = i;
                isntVisited = true;
            }
        }
        cout << "index = " << index << endl;
    }
    
    cout << "length = " << mlength << endl;
    return mlength;
}

pair<int,int> cam_max (vector<vector<int>> &g, vector <bool> &visited, int start) {
    
    stack <int> s;
    s.push(start);
    pair <int,int> max_distance = make_pair (0,-1);
    vector <int> length;
    length.resize(g.size(),-1);
    length[start] = 0;
    visited[start] = true; 
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (int i : g[u]) {
            if (length[i] == -1) {
                visited[u] = true; 
                length[i] = length[u] + 1;
                s.push(i);
                if (length[i] > max_distance.first) {
                    max_distance = make_pair (length[i],i);
                }
            }
        }
    }
    cout << "max_distance.first = " << max_distance.first << endl;
    cout << "max_distance.second = " << max_distance.second << endl; 
    return max_distance;
}