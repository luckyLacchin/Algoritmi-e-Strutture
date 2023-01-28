#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int navi(int n, vector<int> V);
int navi_rec (vector<int> V, int p, int n);
int trasformation (vector<int> &v, int n);
void distance (vector<vector<int>> adj, int r, vector <int> &distance);


int main () {

    int n;
    vector <int> V;
    V.resize(n*n);
    /*cout << "Il numero minimo di tiri di dati necessari per vincere è: " << navi(n,V) << endl;
    */
   cout << "Il numero minimo di tiri di dati necessari per vincere è: " << trasformation(V,n) << endl;


    return 0;
}

int navi (int n, vector<int> V) {
    /*Allora se sono su una casella normale cerco di fare sempre 6, eccetto se arrivo in una casella con serpente. Oppure faccio un numero che mi porti in una scala (guarda che se aggiungo a quel numero 6 sia sempre minore rispetto alla casella con cui potrei arrivare usando la scala)*/

    return navi_rec (V,0,n);
}

int navi_rec (vector<int> v, int p, int n) {

    bool serpente = true;
    bool scala = false;
    int max = -1;
    if (v[p] != n*n) {
        if (v[p] == p) {
            for (int i = 6; (i >= 0) && (serpente) && (!scala); i--) {
                if (v[p+i] > p+1) {/*vuol dire che c'è una scala, una scala può condurmi da un serpente? Non credo*/
                    scala = true;
                    return 1 + navi_rec(v,p+i,n);
                }
                else if ((v[p+i] == p+1) && (max == -1)) {
                    max = p+1;
                }
            }
            if (!scala && max != -1)
                return 1 + navi_rec(v,p+max,n);
        }
    }
    return 0;
}

/*dovevo trasformarlo in un grafo e farci erdos. La soluzione scritta sopra non va bene!*/

int trasformation (vector<int> &v, int n) {

    vector<vector<int>> g;
    g.resize(n*n);
    for (int i = 0; i  < n*n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j < n*n)
                g[i].push_back(v[i+j]);
        }
    }

    vector <int> distance;
    return distance[n*n-2];

}

void distance (vector<vector<int>> adj, int r, vector <int> &distance) {
    distance.resize (adj.size(),-1);
    queue <int> q;
    q.push (r);
    distance[r] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
}