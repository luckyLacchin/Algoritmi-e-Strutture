#include <vector>
#include <iostream>

using namespace std;

bool containsZero (vector<int> a, int n);

int main () {

    vector <int> a = {-5,-4,-1, 2, 3, 4, 7};
    int n = 7;
    cout << "Esiste un sottovettore di somma 0: " << (containsZero (a,n) ? "Si" : "No") << endl;
}

bool containsZero (vector<int> a, int n) {

    vector<bool> visited;
    visited.resize(n,false);
    int i = 0, j = i + 1;
    int maxSoFar = a[i];
    visited[i] = true;
    while (i <= j) {
        if (!visited[j]) {
            visited[j] = true;
            maxSoFar += a[j];
        }
        if (maxSoFar < 0) {
            if (j == n-1 || visited[j+1] == true) {
                maxSoFar = maxSoFar - a[i];
                ++i;
            }
            else
                ++j;
        }
        else if (maxSoFar > 0) {
            maxSoFar = maxSoFar - a[j];
            --j;
        }
        else
            return true;
    }
    return false;
}