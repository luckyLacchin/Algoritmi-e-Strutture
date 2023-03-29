#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main () {

    ifstream in("input.txt");
    ofstream out("output.txt");


    return 0;
}

int knapsack (int w[], int p[], int n, int C) {
    int **DP = new int *[n];
    for (int i = 0; i < n; i++)
        DP[i] = new int [C];
    
    for (int c = 0; c < C; c++) {
        DP[0][c] = 0;
    }
    for (int i = 0; i < n; i++) {
        DP[i][0] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int c = 1; c < C; c++) {

        }
    }
}