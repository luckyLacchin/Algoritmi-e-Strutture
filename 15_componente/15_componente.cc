#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;


stack <int> topSort (vector<vector<int>> &g, int nodi);
void ts_dfs (vector <vector <int>> &g, int u, bool *visited, stack<int>&s);
vector <vector <int>> transpose (vector<vector<int>> &g, int nodi);
void ccdfs (vector<vector<int>> &g, int counter, int u, int *id, int *&temp);
int *scc(vector<vector<int>> &g, int nodi);

int main () {
    vector <vector <int>> adj;
    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int nodi, archi, massimo = 0; 
    in >> nodi;
    in >> archi;
    int a,b;
    adj.resize(nodi);
    for(int i=0;i<archi;i++){
        in >> a;
        in >> b;
        adj[a].push_back(b);
    }
    /*
    for (int i = 0; i < adj.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */
    int *res = scc (adj,nodi);
    for (int i = 0; i < nodi && res[i]!=0; i++){
        massimo = max (massimo,res[i]);
        //cout << "res[i] = " << res[i] << endl;
    }
    out << massimo; 
    return 0;
}

stack <int> topSort (vector<vector<int>> &g, int nodi) {

    stack <int> s;
    bool *visited = new bool [nodi];
    for (int i = 0; i < nodi; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < nodi; i++) {
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

vector <vector <int>> transpose (vector<vector<int>> &g,int nodi) {

    vector<vector<int>> trasposta;
    trasposta.resize(nodi);
    for (int i = 0; i < nodi; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            trasposta[g[i][j]].push_back(i);
        }
    }
    return  trasposta;
}

/*
int *cc (vector<vector<int>> &g, int nodi) {

    int *id = new int [nodi];
    for (int i = 0; i < nodi; i++){
        id[i] = 0; 
    }
    int counter = 0; 
    for (int u = 0; u < nodi; u++) {
        if (id[u]==0) {
            counter = counter + 1;
            ccdfs (g,counter,u,id);
        }
    }
}
questo è il cc vecchio che utilizzi per i grafi non orientati, per quelli
orientati devi usare lo stack
*/
int *cc (vector<vector<int>> &g, int nodi, stack <int> s) {
    
    int *id = new int [nodi];
    int *temp = new int [nodi];
    
    for (int i = 0; i < nodi; i++){
        id[i] = 0; 
        temp[i] = 0; 
    }
    int counter = 0;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (id[u]==0){
            counter = counter + 1;
            ccdfs(g,counter,u,id,temp);
        }
    }
    //return id; questa sarebbe l'implementazione standard vista in classe, ma a noi in questo caso non ci interessa, ma dobbiamo fare altro.
    //cout << "temp[ciao] = " << temp[0] << endl;
    return temp;
}

void ccdfs (vector<vector<int>> &g, int counter, int u, int *id, int *&temp) {
    id[u] = counter;
    ++temp[counter-1];
    //cout << "temp[" << counter << "] = " << temp[counter] << endl;
    for (int v = 0; v < g[u].size(); v++) {
        if(id[g[u][v]] == 0) {
            ccdfs (g,counter,g[u][v],id,temp);
        }
    }
}

int *scc(vector<vector<int>> &g, int nodi) {
    stack <int> s = topSort (g, nodi);
    /*
    cout << "s.front() = " << s.top () << endl;
    cout << "s.size() = " << s.size () << endl;
    cout << endl;
    */
    vector<vector<int>> trasposta = transpose (g,nodi);
    /*
    for (int i = 0; i < trasposta.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < trasposta[i].size(); j++){
            cout << trasposta[i][j] << " ";
        }
        cout << endl;
    }
    */
    int *res = cc(trasposta,nodi, s); //non ci ritorna quello standard visto in classe ma temp
    //cout << "res = " << res[0] << endl;
    return res;
}