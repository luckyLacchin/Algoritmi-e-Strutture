#include <iostream>
#include <vector>

using namespace std;

int chi_manca (vector<int> a, int size);
int chi_manca_aux (vector<int> a, int first, int last);

int main () {

    vector <int> a;
    int n = 6;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    //a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);

    cout << "Manca il seguente elemento: " << chi_manca (a,n) << endl;
    return 0;
}

int chi_manca (vector<int> a, int size) {

    if (a[size-1] == size)
        return size+1;
    else 
        return chi_manca_aux (a,0,size-1);

}
/*
int chi_manca_aux (vector<int> a, int first, int last) {

    if (first <= last) {
        int m = (first + last) / 2;
        if (a[m]-1 == m) {
            return chi_manca_aux (a,m+1,last);
        }
        else if (a[m] > m) {
            if (a[m-1] == a[m]-1)
                return chi_manca_aux(a,first,m-1);
            else 
                return (a[m] - 1);
        }
    }
}
*/

int chi_manca_aux (vector <int> a, int first, int last) {

    if (first == last) {
        return first + 1;
    }
    else {
        int m = (last + first) / 2;
        if (a[m] == m+1)
            return chi_manca_aux(a,m+1,last);
        else 
            return chi_manca_aux (a,first,m);
    }
}

