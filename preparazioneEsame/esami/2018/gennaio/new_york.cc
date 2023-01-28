#include <iostream>
#include <vector>

using namespace std;

int maxCrime (vector<int> a, int n, int t);

int main () {

    vector <int> deaths;
    int n = 8;
    deaths.resize(n);
    deaths[0] = 10;
    deaths[1] = 17;
    deaths[2] = 19;
    deaths[3] = 22;
    deaths[4] = 24;
    deaths[5] = 25;
    deaths[6] = 26;
    deaths[7] = 27;
    cout << "Il maggior numero di omicidi nel periodo t e': " << maxCrime(deaths,n,4) << endl;

    return 0;
}

int maxCrime (vector<int> a, int n, int t) {
    int maxHere = 1, maxSoFar = 0, start = 0, v = 0;

    while(v < n) {
        if (a[v] - a[start] + 1 <= t) {
            maxHere = v - start + 1; /* conto un i in più -> una morte in più*/
            maxSoFar = max(maxHere, maxSoFar);
            ++v;
        }
        else if (a[v] - a[start] + 1 > t) {
            ++start;
        }

    }
    return maxSoFar;
}