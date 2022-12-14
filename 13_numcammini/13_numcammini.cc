#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

void distance (vector<vector<int>> &g, int start, int finish, int nodi, int &path, int &num);

int main () {
    vector <vector <int>> g;
    ifstream in ("input.txt"); 
    ofstream out ("output.txt");
    int nodi, archi, start, finish, path = -1, num = -1;
    in >> nodi;
    in >> archi;
    in >> start;
    in >> finish;
    int a,b;
    g.resize(nodi);
    for(int i=0;i<archi;i++){
        in >> a;
        in >> b;
        g[a].push_back(b);
    }
    if (start != finish){
        distance (g,start,finish,nodi, path, num);
        if (path != -1 && num != -1)
            out << path << " " << num;
        else 
            out << 0 << " " << 0;
    }
    else 
        out << 0 << " " << 1;
    return 0;
}


void distance (vector<vector<int>> &g, int start, int finish, int nodi, int &path, int &num) {
    int **distance = new int *[nodi]; //il numero dovrebbe essere minore degli archi!
    for (int i = 0; i < nodi; i++) {
        distance[i] = new int [2];
    }
    queue <int> q;
    q.push (start);
    for (int j = 0; j < nodi; j++) {
            distance[j][0] = -1;
            distance [j][1] = 0;
    }
   distance[start][0] = 0;
   ++distance[start][1];
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        //for(int v: g[u])
        for (int i = 0; i < g[u].size(); i++) {
            if (distance[g[u][i]][0] == -1) { 
                    distance[g[u][i]][0] = distance[u][0] + 1;
                    q.push(g[u][i]);
                    ++distance[g[u][i]][1];
            }
            /*
            else if ((distance[u][0]+1) < distance[g[u][i]][0]) {
                distance[g[u][i]][1] = 1;
                distance[g[u][i]][0] = distance[u][0] + 1; //credo che questo non possa accedere
            }
            */
            else if ((distance[u][0]+1) == distance[g[u][i]][0]) {
                ++distance[g[u][i]][1];
                q.push(g[u][i]);
            }
        }
    }
    
    path = distance[finish][0];
    num = distance[finish][1];
    
    for (int i = 0; i < nodi; i++) {
        delete []distance[i];
    }
    delete [] distance;
}

/*allora il problema che dobbiamo valutare è distance che in questo caso dobbiamo tenere conto di tutte le possibilità e non solo di quella minore quindi calcolare la distance solo quando distance[v] = -1 è sbagliato, ma in realtà il giochetto dovremmo farlo per ogni volta. Potremmo fare che ogni volta che becca finish aumentiamo di 1 indipendemente da tutto*/

// || g[u][i] == finish --> if (distance[u]+1 == g[u][i] || distance[finish] == -1) {++count} così aumentiamo il numero di path con quella lunghezza.
            /*in realtà dopo dobbiamo mettere un'altra condizione per vedere che non sia minore nel caso lo fosse azzeriamo count, e dopo lo mettiamo count = 1 e andiamo avanti. Così dovrebbe andare*/