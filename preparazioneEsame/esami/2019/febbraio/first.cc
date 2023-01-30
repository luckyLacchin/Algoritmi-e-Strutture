#include <iostream>
#include <vector>

using namespace std;

int first (vector<int> a, int n, int v);
int first_aux (vector<int> a, int first, int last,int v);

int main () {

    int n = 10;
    vector<int> a;
    a.resize(n);
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    a[4] = 2;
    a[5] = 3;
    a[6] = 4;
    a[7] = 5;
    a[8] = 6;
    a[9] = 6;
    cout << "La prima occorrenza di v e': " << first (a,n,4) << endl;


    return 0; 
}

int first (vector<int> a, int n, int v) {

    return first_aux (a,0,n-1,v);
}

int first_aux (vector<int> a, int first, int last,int v) {
    
    if (first >= last) {
        return first + 1;
    }
    else {
        int m = (first + last) / 2;
        if (a[m] >= v) {
            return first_aux (a,first,m,v);
        }
        else if (a[m] < v) {
            return first_aux (a,m+1,last,v);
        }
        /*
        if (a[m] == v) {
            if (a[m-1] == a[m]) {
                return first_aux (a,first,m-1,v);
            }
            else {
                return m + 1;
            }
        }
        qua bisognava stare attenti che m-1 non uscisse dai bordi attento!
        */
    }
}