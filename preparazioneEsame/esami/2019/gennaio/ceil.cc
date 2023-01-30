#include <iostream>
#include <vector>

using namespace std;

int ceil (vector<int> a, int n, int v);
int ceil_aux (vector<int> a,int first,int last,int v);

int main () {

    int n = 7;
    vector <int> a;
    a.resize(n);
    a[0] = 1;
    a[1] = 3;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a[5] = 5;
    a[6] = 8;
    cout << "Il piu' piccolo elemento maggiore di v e': " << ceil(a,n,6) << endl;

    return 0;
}

int ceil (vector<int> a, int n, int v) {

    if (a[n-1] < v) {
        return -1;
    }
    else if (a[0] >= v) {
        cout << "ciao" << endl;
        return a[0];
    }
    else {
        return ceil_aux(a,0,n-1,v);
    }
}

int ceil_aux (vector<int> a,int first,int last,int v) {

    if (first >= last) {
        return a[first];
    }
    else {
        int m = (first + last) / 2;
        if (a[m] == v)
            return a[m];
        else if (a[m] > v) {
            return ceil_aux (a,first,m,v);
        }
        else if (a[m] < v) {
            return ceil_aux (a,m+1,last,v);
        }
    }
}