#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

int cam_max_aux (vector<vector<int>> &g);
pair<int,int> cam_max (vector<vector<int>> &g, int start);
stack <int> topSort (vector<vector<int>> &g);
void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s);
vector <vector <int>> transpose (vector<vector<int>> &g);
pair <int,vector<int>> cc (vector<vector<int>> &g, stack <int> s);
void ccdfs (vector<vector<int>> &g, int counter, int u, vector <int> &id);
pair <int,vector<int>> scc(vector<vector<int>> &g);

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
    cam_max_aux(g);
    //cout << "Il cammino piu' lungo nel grafo e': " << cam_max_aux(g) << endl;
    

    return 0;
}


/* la soluzione n(n+m) ovviamente è facile da fare. Sto pensando se esista un'altra soluzione con complessità minore ma non mi viene in mente*/

/*In this post, a different DFS-based solution is discussed. After observing the above tree we can see that the longest path will always occur between two leaf nodes. We start DFS from a random node and then see which node is farthest from it. Let the node farthest be X. It is clear that X will always be a leaf node and a corner of DFS. Now if we start DFS from X and check the farthest node from it, we will get the diameter of the tree. 
The C++ implementation uses an adjacency list representation of graphs. STL‘s list container is used to store lists of adjacent nodes. */

int cam_max_aux (vector<vector<int>> &g) {

    int counter = 0, index = 0, mlength = -1, maxHere = -1;
    pair <int,int> max_cammino;
    pair<int,vector<int>> c = scc (g);
    cout << "Nel mio grafo ci sono: " << c.first << " componente connesse." << endl;
    for (int i : c.second) {
        if (counter != i) {
            ++counter;
            max_cammino = cam_max(g,index);
            maxHere = max(max_cammino.first,cam_max(g,max_cammino.second).first);
            mlength = max(maxHere, mlength);
        }
        ++index;
    }
    return mlength;
}

pair<int,int> cam_max (vector<vector<int>> &g, int start) {
    
    stack <int> s;
    s.push(start);
    pair <int,int> max_distance = make_pair (0,-1);
    vector <int> visited;
    visited.resize(g.size(),-1);
    visited[start] = 0;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (int i : g[u]) {
            if (visited[i] == -1) { 
                visited[i] = visited[u] + 1;
                s.push(i);
                if (visited[i] > max_distance.second) {
                    max_distance = make_pair (visited[i],i);
                }
            }
        }
    }
    return max_distance;
}
/*
pair <int,vector<int>> cc (vector<vector<int>> &g) {

    vector <int> id;
    id.resize (g.size(),0);
    int counter = 0;
    for (int i = 0; i < g.size(); i++) {
        if (id[i] == 0) {
            counter = counter + 1;
            ccdfs (g,counter,i,id);
        }
    }
    return (make_pair(counter,id)); /*così con counter so fin da subito quanti sono le c.c del mio grafo
}

void ccdfs (vector<vector<int>> &g, int counter, int u, vector <int> &id) {
    
    stack <int> s;
    s.push(u);
    while (!s.empty()) {
        int t = s.top();
        s.pop();
        id[t] = counter;
        for (int v : g[t]) {
            if (id[v] == 0) {
                s.push(v);
            }
        }

    }
}

void ccdfs_rec (vector<vector<int>> &g, int counter, int u, vector <int> &id) {

    id[u] = counter;

    for (int v : g[u]) {
        if (id[v] == 0)
            ccdfs_rec(g,counter,v,id);
    }
}
*/

stack <int> topSort (vector<vector<int>> &g) {

    stack <int> s;
    bool *visited = new bool [g.size()];
    for (int i = 0; i < g.size(); i++) {
        visited[i] = false;
    }
    for (int i = 0; i < g.size(); i++) {
        if (visited[i] == false) {
            ts_dfs(g,i,visited,s);
        }
    }

    delete [] visited;
    return s;
}

void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s) {
    visited[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        if(visited[g[u][i]] == false) {
            ts_dfs (g,g[u][i],visited,s);
        }
    }
    s.push(u);
    //cout << s.top() << " ";
}

vector <vector <int>> transpose (vector<vector<int>> &g) {

    vector<vector<int>> trasposta;
    trasposta.resize(g.size());
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            trasposta[g[i][j]].push_back(i);
        }
    }
    return  trasposta;
}

pair <int,vector<int>> cc (vector<vector<int>> &g, stack <int> s) {
    
    vector <int> id;
    id.resize(g.size(), 0);
    int counter = 0;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (id[u]==0){
            counter = counter + 1;
            ccdfs(g,counter,u,id);
        }
    }
    return (make_pair(counter,id));
}

void ccdfs (vector<vector<int>> &g, int counter, int u, vector <int> &id) {
    
    stack <int> s;
    s.push(u);
    while (!s.empty()) {
        int t = s.top();
        s.pop();
        id[t] = counter;
        for (int v : g[t]) {
            if (id[v] == 0) {
                s.push(v);
            }
        }

    }
}

pair <int,vector<int>> scc(vector<vector<int>> &g) {
    stack <int> s = topSort (g);
    /*
    cout << "s.front() = " << s.top () << endl;
    cout << "s.size() = " << s.size () << endl;
    cout << endl;
    */
    vector<vector<int>> trasposta = transpose (g);
    /*
    for (int i = 0; i < trasposta.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < trasposta[i].size(); j++){
            cout << trasposta[i][j] << " ";
        }
        cout << endl;
    }
    */
    pair <int,vector<int>> res = cc(trasposta, s); //non ci ritorna quello standard visto in classe ma temp
    //cout << "res = " << res[0] << endl;
    return res;
}