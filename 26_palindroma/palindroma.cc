#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int palindroma (string s, int n);
int palindroma_rec (string s, int i, int j);

int palindroma_iterative (string s, int n);

int main () {

    int n = 7;
    string s = "casacca";
    cout << "Il numero minimo di lettere per avere una parola palindroma e': " << palindroma (s,n) << endl;


    return 0;
}

int palindroma (string s, int n) {

    return palindroma_rec (s,0,n-1);
}

int palindroma_rec (string s, int i, int j) {
    if (i >= j)
        return 0;
    else {
        if (s[i] == s[j]) {
            return palindroma_rec (s,i+1,j-1);
        }
        else {
            int m1 = palindroma_rec(s,i,j-1) + 1;
            int m2 = palindroma_rec(s,i+1,j) + 1;
            return min (m1,m2);
        }
    }
}

//devo trovare un modo di farlo in modo iterativo, non mi viene è da finire
int palindroma_iterative (string s, int n) {
    
    int **DP = new int *[n+1];
    for (int i = 0; i  <= n; i++)
        DP[i] = new int [n+1];
    for (int i = 0; i <= n; i++) {
        DP[i][0] = INT_MAX;
    }
    for (int c = 0; c <= n; c++) {
        DP[0][c] = INT_MAX;
    }
    string r;
    for (int i = n-1, j = 0; i >= 0; i--,j++) {
        r[j] = s[i];
    }
    DP[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j--) {
            if (s[j-1] == r[i-1]) {
                DP[i][j] = DP[i-1][j-1];
            }
            else {
                DP[i][j] = min(DP[i-1][j], DP[i][j-1]) + 1;
            }
        }
    }

}