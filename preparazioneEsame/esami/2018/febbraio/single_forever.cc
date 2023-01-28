#include <iostream>
#include <vector>

using namespace std;

int single (vector<int> a, int n);
int single_aux (vector<int> a, int first,int last);

int main () {
    
    vector <int> a;
    int n = 11;
    a.resize(n);
    a[1-1] = 1;
    a[2-1] = 1;
    a[3-1] = 3;
    a[4-1] = 3;
    a[5-1] = 4;
    a[6-1] = 4;
    a[7-1] = 5;
    a[8-1] = 5;
    a[9-1] = 7;
    a[10-1] = 7;
    a[11-1] = 8;

    cout << "Qual è il valore singolo ? " << single (a,n) << endl;
}

int single (vector<int> a, int n) {

    return single_aux(a,0,n-1);
}

int single_aux (vector<int> a, int first,int last) {

    if (first >= last)
        return a[first];
    else {
        int m = (first + last) / 2;
        cout << "m = " << m << endl;
        if ((m%2) != 0) {
            if (a[m] == a[m-1])
                return single_aux(a,m+1,last);
            else
                return single_aux(a,first,m-1); 
        }
        else {
            if (a[m] == a[m+1])
                return single_aux(a,m+2,last);
            else
                return single_aux(a,first,m);
        }
            
    }
}