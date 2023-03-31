#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int sottocres (int *v, int n, int prec, int i, bool *&visited);
int wrapper (int *v, int n);
int sottocres_iterative (int *v, int n);

int main () {

    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int n,t,i = 0;
    int *v;
    in >> n;
    v = new int [n];
    while (in >> t) {
        v[i] = t;
        ++i;
    }
    //out << wrapper (v,n);
    out << sottocres_iterative(v,n);
    return 0;
}

int wrapper (int *v, int n) {
    bool *visited = new bool [n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int maxSoFar = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            maxSoFar = max(maxSoFar,sottocres(v,n,INT_MIN,i,visited));
        }
    }
    return maxSoFar;
}

int sottocres (int *v, int n, int prec, int i, bool *&visited) {
    if (i >= n) {
        return 0;
    }
    else if (v[i] <= prec) {
        return sottocres(v,n,prec,i+1,visited);
    }
    else {
        int nottaken = sottocres (v,n,prec,i+1,visited);
        int taken = sottocres (v,n,v[i],i+1,visited) + v[i];
        visited[i] = true;
        return max(nottaken,taken);
    }
}
/*mi sa che per arrivarea al 100% devo fare qualcosa di iterativo*/

int sottocres_iterative (int *v, int n) {
    int maxSoFar = INT_MIN;
    int *DP = new int [n];
    for (int i = 0; i < n; i++) {
        DP[i] = v[i];
        for (int j = 0; j < i; j++) {
            if (v[j] <= v[i])
                DP[i] = max(DP[i],DP[j]+v[i]);
        }
        maxSoFar = max(DP[i],maxSoFar);
    }
    return maxSoFar;
}