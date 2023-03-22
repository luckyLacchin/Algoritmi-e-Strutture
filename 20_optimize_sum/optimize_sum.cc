#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int knapsack (vector <int> &w, vector<int> &p, int n, int C);
int knapsackRec (vector<int> &w,vector<int> &p, int n, int c, vector<int> &DP, vector<int> &pos);

int main () {

    vector<int> v = {18,3,21,9,12,24};
    cout << "Il massimo valore e': " << knapsack(v,v,6,17) << endl;
    return 0;
}


int knapsack (vector <int> &w, vector<int> &p, int n, int C) {

    vector <int> DP;
    vector<int> pos;
    pos.resize(C,-1);
    DP.resize(C,-1);
    knapsackRec (w,p,n,C,DP,pos);
    return DP[C-1];
}

int knapsackRec (vector<int> &w,vector<int> &p, int n, int c, vector<int> &DP, vector<int> &pos) {
    
    //cout << "n = " << n << endl;
    //cout << "c = " << c << endl;
    if (c == 0) {
        return 0;
    }
    
    if (DP[c-1] < 0) {

        int maxSoFar = 0;
        for (int i = 0; i < n; i++) {
            if (w[i] <= c) {
                int val = knapsackRec (w,p,n,c-w[i],DP,pos) + p[i];
                //cout << "val = " << val << endl; 
                if (val >= DP[c-1]) {
                    DP[c-1] = val;
                    pos[c-1] = i;
                }
            }
        }
        //cout << "DP[" << c << "] = " << DP[c-1] << endl;
    }
    return (DP[c-1] == -1 ? 0 : DP[c-1]);
}

