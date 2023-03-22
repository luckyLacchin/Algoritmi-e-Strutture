#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

int scacchiera (vector<vector<int>> &P, int n);
int scacchiera_aux (vector<vector<int>> &P, int n, int i, int j, vector<vector<int>> &DP);

int main () {

    ifstream in ("input.txt"); 
    int row,column,sol;
    in >> row;
    in >> column;  
    vector <vector <int>> matrix; 
    matrix.resize(row); 
    for (int i = 0; i < row; i++) {
        matrix[i].resize(column); 
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            in >> matrix [i] [j];
            //cout << "matrix [i] [j] = " << matrix[i][j] << endl;  
        }
        cout << endl;
    }

    cout << "Il massimo profitto e': " << scacchiera (matrix,row) << endl;

    in.close();
    return 0;
}

int scacchiera (vector<vector<int>> &P, int n) {

    int maxSoFar = INT_MIN;
    vector<vector<int>> DP;
    DP.resize(n);

    for (int i = 0; i < n; i++)
        DP[i].resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            DP[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        int val = scacchiera_aux (P,n,n-1,i,DP);
        maxSoFar = max (val,maxSoFar);
    }
    return maxSoFar;
}

int scacchiera_aux (vector<vector<int>> &P, int n, int i, int j, vector<vector<int>> &DP) {
    //cout << "i = " << i << endl;
    //cout << "j = " << j << endl;
    if (i >= 0 && i < n && j >= 0 && j < n) {
        if (DP[i][j] < 0) {
            int val1 = scacchiera_aux (P,n,i-1,j,DP);
            int val2 = scacchiera_aux (P,n,i-1,j+1,DP);
            int val3 = scacchiera_aux (P,n,i-1,j-1,DP);
            //cout << "val1 = " << val1 << endl;
            //cout << "val2 = " << val2 << endl;
            //cout << "val3 = " << val3 << endl;
            //DP[i][j] = (val1 == val2 == val3 == INT_MIN ? P[i][j] : max(val1,max(val2,val3)) + P[i][j]);
            //cout << "P[i][j] = " << P[i][j] << endl;
            DP[i][j] = max(val1,max(val2,val3)) + P[i][j]; 
        }
        //cout << "DP[" << i << "][" << j << "] = " << DP[i][j] << endl;
        return DP[i][j];
    }
    else {
        //cout << "ciao" << endl;
        //return INT_MIN;
        return 0;
    }

}