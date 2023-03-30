#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int knapsack (int w[], int p[], int n, int C);
int knapsack_first (int w[], int p[], int n, int C);

int main () {

    ifstream in("input.txt");
    ofstream out("output.txt");
    int capacity, objects, weight, value,index = 1;
    in >> capacity >> objects;
    int *w = new int [objects];
    int *p = new int [objects];
    w[0] = 0;
    p[0] = 0;
    while (in >> weight && in >> value) {
        w[index] = weight;
        p[index] = value;
        ++index;
    }
    out << knapsack(w,p,objects,capacity);

    delete [] w;
    delete [] p;
    in.close();
    out.close();
    return 0;
}

int knapsack (int w[], int p[], int n, int C) {
    bool alternate = true;
    int *DP = new int [C+1];
    int *DP1 = new int [C+1];
    DP[0] = DP1[0] = 0;
    for (int c = 0; c <= C; c++)
        DP1[c] = 0;
    //cout << "ALTERNATE = " << alternate << endl;
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= C; c++) {
            if (w[i] <= c) {
                //cout << "w[i] = " << w[i] << endl;
                //cout << "p[i] = " << p[i] << endl;
                if (alternate)
                    DP[c] = max(DP1[c-w[i]]+p[i],DP1[c]);
                else {
                    //cout << "DP[0][c-w[i]]+p[i] = " << DP[0][c-w[i]]+p[i] << endl;
                    //cout << "DP[0][c] = " << DP[0][c] << endl;
                    DP1[c] = max(DP[c-w[i]]+p[i],DP[c]);
                }
            }
            else {
                //cout << "w1[i] = " << w[i] << endl;
                //cout << "p1[i] = " << p[i] << endl;
                if (alternate)
                    DP[c] = DP1[c];
                else
                    DP1[c] = DP[c];
            }
            //if (alternate)
                //cout << "DP[" << i << "][" << c << "] = " << DP[0][c] << endl;
            //else
                //cout << "DP1[" << i << "][" << c << "] = " << DP[1][c] << endl;
        }
        alternate = (alternate == true ? false : true);
        //cout << "alternate = " << alternate << endl;
        /*for (int i = 0; i < 2; i++) {
            for (int c = 0; c <= C; c++)
                cout << DP[i][c] << " ";
            cout << endl;
        }
        */
    }
    int res = (alternate == true ? DP1[C] : DP[C]);
    delete [] DP;
    delete [] DP1;
    //cout << "res = " << res << endl;
    return res;
}

int knapsack_first (int w[], int p[], int n, int C) {
    int **DP = new int *[n+1];
    for (int i = 0; i <= n; i++)
        DP[i] = new int [C+1];
    for (int i = 0; i <= n; i++) {
        DP[i][0] = 0;
    }
    for (int c = 0; c <= C; c++) {
        DP[0][c] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= C; c++) {
            if (w[i] <= c) {
                DP[i][c] = max(DP[i-1][c-w[i]]+p[i],DP[i-1][c]);
            }
            else
                DP[i][c] = DP[i-1][c];
            //cout << "DP[" << i << "][" << c << "] = " << DP[i][c] << endl;
        }
    }
    return DP[n][C];
}