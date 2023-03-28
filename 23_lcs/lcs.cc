#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//int occorrenze (string a, string b);

int main () {

    string a,b;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> a >> b;
        int ** DP = new int *[a.size()+1];
    for (int i = 0; i < a.size()+1; i++)
        DP[i] = new int [b.size()+1];
    for (int j = 0; j < b.size()+1; j++) {
        DP[0][j] = 0;
    }
    for (int i = 0; i < a.size()+1; i++)
        DP[i][0] = 0;
    for (int i = 1; i  < a.size()+1; i++) {
        for (int j = 1; j < b.size()+1; j++) {
            if (a[i-1] == b[j-1]) {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else {
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    out << DP[a.size()][b.size()];
    for (int i = 0; i < a.size()+1; i++) {
        delete [] DP[i];
    }
    delete DP;
    in.close();
    out.close();
    return 0;
}
/*
int occorrenze (string a, string b) {
    int ** DP = new int *[a.size()+1];
    for (int i = 0; i < a.size()+1; i++)
        DP[i] = new int [b.size()+1];
    for (int j = 0; j < b.size()+1; j++) {
        DP[0][j] = 0;
    }
    for (int i = 0; i < a.size()+1; i++)
        DP[i][0] = 0;
    for (int i = 1; i  < a.size()+1; i++) {
        for (int j = 1; j < b.size()+1; j++) {
            if (a[i] == b[j]) {
                DP[i][j] = DP[i-1][j-1] + 1;
            }
            else {
                DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    for (int i = 0; i < a.size()+1; i++) {
        delete [] DP[i];
    }
    delete DP;
    return DP[a.size()][b.size()];
}
*/