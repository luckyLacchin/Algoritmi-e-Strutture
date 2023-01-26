#include <vector>
#include <iostream>

using namespace std;

int unimodulare (vector<int> a, int size);
int unimodulare_aux (vector<int> a, int first, int last);

int main () {

    vector <int> a;
    int n = 6;
    a.push_back(5);
    a.push_back(10);
    a.push_back(9);
    a.push_back(8);
    a.push_back(7);
    a.push_back(6);

    cout << "Il valore h e': " << unimodulare(a,n) << endl;
    return 0;
}

int unimodulare (vector<int> a, int size) {

    return unimodulare_aux(a,0,size-1);
}
/*
int unimodulare_aux (vector<int> a, int first, int last, int size) {

    if (first <= last) {
        int m = (first + last) / 2;
        if (m > 0 && m < size) {
            if (a[m] > a[m+1] && a[m] < a[m-1]) {
                return unimodulare_aux (a,m+1,last,size);
            }
            else if (a[m] < a[m+1] && a[m] > a[m-1])
                return unimodulare_aux (a,first,m-1,size);
            else if (a[m] < a[m+1] && a[m] < a[m-1])
                return m+1;
            
        }
        else if (m == 0 && a[m] < a[m+1])
            return m+1;
        else if (m == 0 && a[m] > a[m+1])
            return unimodulare_aux (a,m+1,last,size);
        else if (m == size - 1 && a[m] < a[m-1])
            return m+1;
        else if (m == size - 1 && a[m] > a[m-1])
            return unimodulare_aux (a,first,m-1,size);
    }
}
*/

int unimodulare_aux (vector<int> a, int first, int last) {

    if (first == last) {
        return a[first];    
    }else {
        int m = (last + first) / 2;
        if (a[m] < a[m+1])
            return unimodulare_aux(a,first,m);
        else
            return unimodulare_aux(a,m+1,last);
    }
}   