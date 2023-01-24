#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits.h>

using namespace std;

int mindist (vector<vector<int>> &g, set <int> &v1, set<int> &v2);

int main () {
    //facciamo che il grafo non sia orientato
    vector <vector<int>> g;
    g.resize(7);
    g[0].push_back(4);
    g[0].push_back(3);
    g[1].push_back(2);
    g[1].push_back(5);
    g[2].push_back(3);
    g[2].push_back(1);  
    g[3].push_back(0);
    g[3].push_back(2);
    g[4].push_back(0);
    g[5].push_back(1);
    g[5].push_back(6);
    g[6].push_back(5);

    set <int> v1, v2;
    v1.insert(0);
    v1.insert(2);
    v1.insert(3);
    v2.insert(6);
    cout << "La minima distanza tra i due insiemi e': " << mindist (g,v1,v2) << endl; 

    return 0;
}

int mindist (vector<vector<int>> &g, set <int> &v1, set<int> &v2) {
    
    vector <int> distance;
    distance.resize (g.size(), -1);
    queue <int> q;
    int s = *v1.begin(), min_dist = INT_MAX;
    q.push(s);
    distance[s] = 0; 
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i : g[t]) {
            
            if (distance[i] == -1) {
                if ((v1.find(i) != v1.end()) && (v2.find(i) != v2.end())) {
                    return 0; // è il caso in cui si intersecano i due insiemi;
                }
                else if (v1.find(i) != v1.end()) {
                    distance[i] = 0; // appartiene allo stesso insieme iniziale, dunque distanza uguale a 0
                }
                else if (v2.find(i) == v2.end()) {
                    distance[i] = distance [t] + 1; //arrivati a questo punto vuol dire che non appartiene nè a v1 nè a v2;
                }
                else if (v2.find(i) != v2.end()) {
                    min_dist = min(distance[i] = distance[t] + 1,min_dist); //siamo arrivati in nodo appartenente a v2 quindi restituiamo la distanza ottenuta, anche se non sappiamo fin da subito se è la minore
                }
                q.push(i);
            }
        }
    }
    return min_dist;
}
